#pragma once
#include "depLib.hpp"

namespace AsmMounter
{
    struct ConvertError;
    struct BitSizeError;
    struct WrongInstruction;
    struct WrongData;
};

struct AsmMounter::ConvertError:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Cannot Convert this number.";
	}
};

struct AsmMounter::BitSizeError:public std::exception
{
    const char* what() const throw()
	{
		return "[MOUNTER ERROR] The value causes an underflow.";
	}
};

struct AsmMounter::WrongInstruction:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Wrong Instruction Was Given.";
	}
};

struct AsmMounter::WrongData:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] A Wrong Data Was Given.";
	}
};