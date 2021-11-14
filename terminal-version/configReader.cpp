#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <bitset>
#include <math.h>
#include <exception>

#include "nlohmann/json.hpp"
//////////////////////////////////////////////////////////
struct AsmMounterConvertError:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Cannot Convert this number.";
	}
};

struct AsmMounterWrongInstruction:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Wrong Instruction Was Given.";
	}
};

struct AsmMounterWrongData:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] A Wrong Data Was Given.";
	}
};

//////////////////////////////////////////////////////////
struct Instruction
{
	//[TODO] => std::vector<std::string> prefixes;
	std::string inst_name;
	std::vector<std::pair<std::string, std::string>> data;

	std::vector<std::string> hex_repr;
};

// binarie_value: Binarie Value String.
// bit_num: Bit's number used.
/*std::string binToHex(std::string binarie_value, uint32_t bit_num)
{
	if(binarie_value.size() > bit_num || binarie_value.size()==0)
		return "";

	uint32_t countZeros = bit_num - binarie_value.size();
	std::string zerosMissing="";

	// O(n)
	for(uint32_t i=0;i<countZeros;++i)
		zerosMissing+='0';
	binarie_value = zerosMissing+binarie_value;

	std::map<std::string, std::string> bin_hex_table;
	bin_hex_table["0000"]="0";
	bin_hex_table["0001"]="1";
	bin_hex_table["0010"]="2";
	bin_hex_table["0011"]="3";
	bin_hex_table["0100"]="4";
	bin_hex_table["0101"]="5";
	bin_hex_table["0110"]="6";
	bin_hex_table["0111"]="7";
	bin_hex_table["1000"]="8";
	bin_hex_table["1001"]="9";
	bin_hex_table["1010"]="A";
	bin_hex_table["1011"]="B";
	bin_hex_table["1100"]="C";
	bin_hex_table["1101"]="D";
	bin_hex_table["1110"]="E";
	bin_hex_table["1111"]="F";

	std::string result = "";
	std::string current_val = "";

	// ~O(nlog(n)) -> Disregarding the + operator.
	for(uint32_t i=0;i<binarie_value.size();i+=4)
		result += bin_hex_table[binarie_value.substr(i,4)];

	return result;
}*/

std::vector<std::string> decomposition(std::string inst)
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
		throw AsmMounterConvertError();
	
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
		throw AsmMounterConvertError();
	
	return value>=0 ? decToHex(value, bit_size) : decToHex(max_value + value, bit_size);
}	

Instruction buildInstruction(std::vector<std::string> inst_decomp, nlohmann::json config_file)
{
	Instruction result;
	result.inst_name = inst_decomp[0];
	if(config_file["instruction"][result.inst_name].is_null())
		throw AsmMounterWrongInstruction();

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
				throw AsmMounterWrongData();
			}
			else if(config_file["fields"][inst_field]["default_set"].size() == 0)
			{
				try
				{
					result.data.push_back({twoComplement(current_data, config_file["fields"][inst_field]["bits"]), inst_field});
				}
				catch(AsmMounterConvertError& error)
				{
					throw AsmMounterConvertError();
				}
				catch(...)
				{
					throw AsmMounterWrongData();
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

	std::string inst = "addi r15 r10 r12 0";
	try
	{
		Instruction current = buildInstruction(decomposition(inst), configJson);

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
