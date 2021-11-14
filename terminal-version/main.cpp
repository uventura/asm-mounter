#include <iostream>
#include <fstream>

#include "nlohmann/json.hpp"

int main()
{
    /*
    // create object from string literal
nlohmann::json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;

// or even nicer with a raw string literal
auto j2 = R"(
  {
    "happy": true,
    "pi": 3.141
  }
)"_json;

std::cout<<j2["happy"]<<"\n";*/

/*
    std::ifstream configFile;
    configFile.open("ola.json");

    nlohmann::json configJson;
    configFile>>configJson;

    std::cout<<configJson["struct_inst"]<<"\n\n";
    for(auto instruction: configJson["struct_inst"])
    {
        for(auto element: instruction)
        {
            std::cout<<element<<"\n";
        }
        std::cout<<instruction["fields_list"].size()<<"\n";
    }
*/

    nlohmann::json j = "{ \"happy\": {}, \"pi\": 3.141 }"_json;
    std::cout<<j.type_name()<<"\n";

}