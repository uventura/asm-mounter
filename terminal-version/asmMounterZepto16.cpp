#include "src/mainHeader.hpp"
#include "dep/nlohmann/json.hpp"

int main()
{	
	std::cout << "Type the asm file (without .asm): ";
	std::string asm_filename;
	std::getline(std::cin, asm_filename);

	std::ifstream asm_file;
	asm_file.open(asm_filename+".asm");

	if(asm_file.is_open())
	{
		std::ifstream config_file;
		config_file.open("zepto16.json");

		nlohmann::json config_json;
		config_file >> config_json;

		AsmMounter::ErrorStatus error;

		std::string current_line;
		while(std::getline(asm_file, current_line))
		{
			// String Output
			//std::string hex = AsmMounter::GetHexInstructionStr(current_line, config_json, error);

			// Vector Output
			std::vector<std::string> hex_vec = AsmMounter::GetHexInstructionVec(current_line, config_json, error);
			std::reverse(hex_vec.begin(), hex_vec.end());

			if(!error.status)
				std::cout<<"0X"<<hex_vec[0]<<" "<<hex_vec[1]<<hex_vec[2]<<hex_vec[3]<<hex_vec[4]<<"\n";
			else
				std::cout<<error.msg<<"\n";
		}

		config_file.close();
	}
	else
	{
		std::cout<<"[FILE ERROR] Could not open file.\n";
	}

	asm_file.close();
}
