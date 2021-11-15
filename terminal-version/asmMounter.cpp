#include "src/mainHeader.hpp"
#include "dep/nlohmann/json.hpp"

int main()
{	
	std::ifstream config_file;
	config_file.open("basics.json");

	nlohmann::json config_json;
	config_file >> config_json;

	AsmMounter::ErrorStatus error;
	std::string hex = AsmMounter::GetHexInstructionStr("bleu r2,r1,10", config_json, error);

	if(!error.status)
		std::cout<<hex<<"\n";
	else
		std::cout<<error.msg<<"\n";

	config_file.close();
}
