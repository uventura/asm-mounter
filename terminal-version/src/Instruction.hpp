#pragma once
#include "depLib.hpp"

namespace AsmMounter
{
    struct Instruction;
}

struct AsmMounter::Instruction
{
	//[TODO] => std::vector<std::string> prefixes;
	std::string inst_name;
	std::vector<std::pair<std::string, std::string>> data;

	std::vector<std::string> hex_repr;
};