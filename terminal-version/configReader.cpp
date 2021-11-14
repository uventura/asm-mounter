#include "src/mainHeader.hpp"
#include "dep/nlohmann/json.hpp"

struct Instruction
{
	//[TODO] => std::vector<std::string> prefixes;
	std::string inst_name;
	std::vector<std::pair<std::string, std::string>> data;

	std::vector<std::string> hex_repr;
};

// Decompose Instruction in a Vector
std::vector<std::string> decompInstruction(std::string inst)
{
	std::string word="";
	std::vector<std::string> result;

	for(auto symb: inst)
	{
		if(symb!=' ' && symb!=',')
			word += symb;
		else if(word!="" && word[0]!='#')
			result.push_back(word),word="";
		else if(word!="" && word[0]=='#')
		{
			word="";
			break;
		}
	}

	if(word != "") result.push_back(word);

	return result;
}

std::string decToHex(uint32_t decimal, uint32_t bit_size)
{
	if((uint32_t)log2(decimal) >= bit_size)
		throw AsmMounter::ConvertError();
	
	///////////////////////////////////////////////////////////////
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

// Return the two complement in Hexadecimal.
std::string twoComplement(std::string decimal_value, uint32_t bit_size)
{
	uint32_t max_value = pow(2, bit_size);
	long long value = std::stoi(decimal_value);

	if(abs(value) > max_value)
		throw AsmMounter::BitSizeError();
	
	return value>=0 ? decToHex(value, bit_size) : decToHex(max_value + value, bit_size);
}	

Instruction buildInstruction(std::vector<std::string> inst_decomp, nlohmann::json config_file)
{
	Instruction result;
	result.inst_name = inst_decomp[0];
	if(config_file["instruction"][result.inst_name].is_null())
		throw AsmMounter::WrongInstruction();

	std::string type = config_file["instruction"][result.inst_name]["type"];
	uint32_t current_pos = 0;

	for(auto inst_type_element: config_file["struct_inst"][type])
	{
		if(current_pos != 0)
		{
			std::string current_data = inst_decomp[current_pos];
			std::string inst_field = inst_type_element; 

			if(inst_field.substr(0,4)=="null")
			{
				result.data.push_back({decToHex(0,config_file["fields"][inst_field]["bits"]),"null"});
			}
			else if( config_file["fields"][inst_field]["default_set"].size() != 0 &&
				config_file["fields"][inst_field]["default_set"][current_data].is_null())
			{
				throw AsmMounter::WrongData();
			}
			else if(config_file["fields"][inst_field]["default_set"].size() == 0)
			{
				try
				{
					result.data.push_back({twoComplement(current_data, config_file["fields"][inst_field]["bits"]), inst_field});
				}
				catch(AsmMounter::BitSizeError& error)
				{
					throw AsmMounter::BitSizeError();
				}
				catch(...)
				{
					throw AsmMounter::WrongData();
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

int main()
{
	/*
	std::string inst;
	std::getline(std::cin, inst);
	std::cout<<"->"<<inst<<"<-\n";
	std::vector<std::string> cmd=decomposition(inst);
	std::cout<<cmd.size()<<"\n";
	for(auto word: cmd)	
		std::cout<<word<<"\n";*/
	
	std::ifstream configFile;
    configFile.open("ola.json");

    nlohmann::json configJson;
    configFile>>configJson;

	std::string inst = "addi r15 r10 r12 0aaa";
	try
	{
		Instruction current = buildInstruction(decompInstruction(inst), configJson);

		for(auto i:current.data)
		{	
			std::cout<<i.first<<","<<i.second<<"\n";
		}	
	}
	catch(std::exception& error)
	{
		std::cout<<error.what()<<"\n";
	}
}
