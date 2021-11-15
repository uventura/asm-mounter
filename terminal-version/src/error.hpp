#pragma once
#include "depLib.hpp"

namespace AsmMounter
{
    enum State{NO_ERROR, WITH_ERRORS, WARNING};
    struct ErrorStatus;

    // Errors Type
    struct ConvertError;
    struct BitSizeError;
    struct WrongInstruction;
    struct WrongData;
    struct MissingData;
};

struct AsmMounter::ErrorStatus
{
    AsmMounter::State status;
    std::string msg="";
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

struct AsmMounter::MissingData:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Missing Data on Instruction.";
	}
};