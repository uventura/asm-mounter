#pragma once
#include "error.hpp"
#include "depLib.hpp"

#include "Instruction.hpp"
#include "../dep/nlohmann/json.hpp"

namespace AsmMounter
{
    //==========================
    //| MOUNTER MATH FUNCTIONS |
    //==========================

    bool IsNumeric(std::string data, bool is_signed = true);
    std::string DecToHex(uint32_t decimal, uint32_t bit_size);

    // Return the two complement in Hexadecimal.
    std::string TwoComplement(std::string decimal_value, uint32_t bit_size);
    
    //=====================
    //| MOUNTER FUNCTIONS |
    //=====================

    std::vector<std::string> DecompInstruction(std::string inst);
    AsmMounter::Instruction BuildInstruction(std::vector<std::string> inst_decomp, nlohmann::json config_file);

    AsmMounter::Instruction AnalyzeInstruction(std::string inst, nlohmann::json config_file, AsmMounter::ErrorStatus& error_handling);

    // If failed then "msg_error" will not be empty.
    std::string GetHexInstructionStr(std::string inst, nlohmann::json config_file, AsmMounter::ErrorStatus& error_handling);
    std::vector<std::string> GetHexInstructionVec(std::string inst, nlohmann::json config_file, AsmMounter::ErrorStatus& error_handling);
}


bool AsmMounter::IsNumeric(std::string data, bool is_signed)
{
    if(data.size() == 0)
    {
        return false;
    }

    uint32_t pos=(data[0]=='-'?1 && is_signed:0);

	for(;pos<data.size();++pos)
		if(not(data[pos] >= '0' && data[pos] <= '9'))
			return false;

	return true;
}

std::string AsmMounter::DecToHex(uint32_t decimal, uint32_t bit_size)
{
	if((uint32_t)log2(decimal) >= bit_size)
		throw AsmMounter::Error::Conversion();
	
	std::string result="";
	uint32_t current=decimal, rem;

	while(current != 0)
	{
		rem = current % 16;
		current /= 16;
		result = (char)(rem>9?'A'+(rem-10):'0'+rem)+result;
	}
	
	long long zeros = bit_size - result.size()*4;
	std::string zerosMissing = "";
	
	for(uint32_t i=0;i<zeros;i+=4)
		zerosMissing+="0";

	return zerosMissing+result;
}

std::string AsmMounter::TwoComplement(std::string decimal_value, uint32_t bit_size)
{
	if(not IsNumeric(decimal_value))
		throw AsmMounter::Error::WrongData();

	uint32_t max_value = pow(2, bit_size);
	long long value = std::stoi(decimal_value);

	if(abs(value) > max_value)
		throw AsmMounter::Error::BitSize();
	
	return value>=0 ? DecToHex(value, bit_size) : DecToHex(max_value + value, bit_size);
}

std::vector<std::string> AsmMounter::DecompInstruction(std::string inst)
{
	std::string word="";
	std::vector<std::string> result;

	for(auto symb: inst)
	{
        if(word[0] == '#')
        {
            word = "";
            break;
        }

		if(symb!=' ' && symb!=',')
			word += symb;
		else if(word!="")
			result.push_back(word),word="";
	}

	if(word != "") result.push_back(word);

	return result;
}	

AsmMounter::Instruction AsmMounter::BuildInstruction(std::vector<std::string> inst_decomp, nlohmann::json config_file)
{
	AsmMounter::Instruction result;
	result.inst_name = inst_decomp[0];
	if(config_file["instruction"][result.inst_name].is_null())
		throw AsmMounter::Error::WrongInstruction();

	std::string type = config_file["instruction"][result.inst_name]["type"];
	uint32_t current_pos = 0;

    if(config_file["struct_inst"][type].size() < inst_decomp.size())
    {
        throw AsmMounter::Error::WrongData();
    }

	for(auto inst_type_element: config_file["struct_inst"][type])
	{
        if(current_pos >= inst_decomp.size())
            throw AsmMounter::Error::MissingData();

		if(current_pos != 0)
		{
			std::string current_data = inst_decomp[current_pos];
			std::string inst_field = inst_type_element; 

			if(inst_field.substr(0,4)=="null" && IsNumeric(inst_field.substr(4), false))
			{
				result.data.push_back({DecToHex(0,std::stoi(inst_field.substr(4))),"null"});
                current_pos -= 1;
			}
            else if(inst_field.substr(0,4)=="null"
            ||      config_file["fields"][inst_field].is_null()                     // Not Found the field
            ||     (config_file["fields"][inst_field]["default_set"].size() != 0    // Found The Field But Has a Wrong Data
            &&      config_file["fields"][inst_field]["default_set"][current_data].is_null()))
            {
                throw AsmMounter::Error::WrongData();
            }
			else if(config_file["fields"][inst_field]["default_set"].size() == 0)
			{
				try
				{
					result.data.push_back({TwoComplement(current_data, config_file["fields"][inst_field]["bits"]), inst_field});
				}
				catch(AsmMounter::Error::BitSize& error)
				{
					throw AsmMounter::Error::BitSize();
				}
				catch(...)
				{
					throw AsmMounter::Error::WrongData();
				}
			}
			else
			{
				result.data.push_back({config_file["fields"][inst_field]["default_set"][current_data], inst_field});
			}
		}
		else
		{
			result.data.push_back({config_file["instruction"][result.inst_name]["opcode"], "opcode"});
		}

		current_pos++;
	}

	return result;
}

AsmMounter::Instruction AsmMounter::AnalyzeInstruction(std::string inst, nlohmann::json config_file, AsmMounter::ErrorStatus& error_handling)
{
    AsmMounter::Instruction current;
    error_handling.status = AsmMounter::State::NO_ERROR;

	try
	{
        std::vector<std::string> decomp_inst = AsmMounter::DecompInstruction(inst);
        
        if(decomp_inst.size() == 0)
            return AsmMounter::Instruction();

		current = AsmMounter::BuildInstruction(decomp_inst, config_file);
	}
	catch(std::exception& error)
	{
        error_handling.status = AsmMounter::State::WITH_ERRORS;
		error_handling.msg = error.what();
        return AsmMounter::Instruction();
    }

    return current;
}

std::string AsmMounter::GetHexInstructionStr(std::string inst, nlohmann::json config_file, AsmMounter::ErrorStatus& error_handling)
{
    AsmMounter::Instruction current = AsmMounter::AnalyzeInstruction(inst, config_file, error_handling);

    if(error_handling.status == AsmMounter::State::NO_ERROR)
    {
        std::string result="";
        for(uint32_t pos=0;pos<current.data.size();++pos)
            result += current.data[pos].first+(pos+1==current.data.size()?"":" ");

        return result;
    }

    return "";
}

std::vector<std::string> AsmMounter::GetHexInstructionVec(std::string inst, nlohmann::json config_file, AsmMounter::ErrorStatus& error_handling)
{
    AsmMounter::Instruction current = AsmMounter::AnalyzeInstruction(inst, config_file, error_handling);
    std::vector<std::string> result;

    if(error_handling.status == AsmMounter::State::NO_ERROR)
    {
        for(uint32_t pos=0;pos<current.data.size();++pos)
            result.push_back(current.data[pos].first);

        return result;
    }

    return result;
}