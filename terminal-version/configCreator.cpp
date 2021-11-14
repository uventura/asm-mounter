#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp"

std::string createField(std::string name, std::string bitsize, std::string default_value="null")
{
    std::string jsonField="";
    jsonField+="\t\t\""+name+"\":{\n";
        jsonField+="\t\t\t\"bits\":"+bitsize+",\n";
        jsonField+="\t\t\t\"default\":"+(default_value=="null"?"{}":default_value)+"\n";
    jsonField+="\t\t}\n";

    return jsonField;
}

int main()
{
    std::ofstream newJsonConfigFile;
    std::string value;

    newJsonConfigFile.open("config.json");
    newJsonConfigFile<<"{\n";

    std::cout<<"Bitset size: ";
    std::cin>>value;
    newJsonConfigFile<<"\t\"bitset\":"+value<<",\n\n";

    //==============================================
    // FIELD SET
    //==============================================
    
    newJsonConfigFile<<"\t\"fields\":{"<<"\n";
        std::cout<<"Opcode size: ";
        std::cin>>value;
        newJsonConfigFile<<createField("opcode", value);

        

    newJsonConfigFile<<"\t}"<<"\n";

    //==============================================
    // TYPE STRUCTION SET
    //==============================================

    newJsonConfigFile<<"}";
}