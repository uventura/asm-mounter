#pragma once
#include "depLib.hpp"

namespace AsmMounter
{
    enum State{NO_ERROR, WITH_ERRORS, WARNING};
    struct ErrorStatus;

    namespace Error
    {
        // Errors Type
        struct Conversion;
        struct BitSize;
        struct WrongInstruction;
        struct WrongData;
        struct MissingData;
    }
};

struct AsmMounter::ErrorStatus
{
    AsmMounter::State status;
    std::string msg="";
};

struct AsmMounter::Error::Conversion:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Cannot Convert this number.";
	}
};

struct AsmMounter::Error::BitSize:public std::exception
{
    const char* what() const throw()
	{
		return "[MOUNTER ERROR] The value causes an underflow.";
	}
};

struct AsmMounter::Error::WrongInstruction:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Wrong Instruction Was Given.";
	}
};

struct AsmMounter::Error::WrongData:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] A Wrong Data Was Given.";
	}
};

struct AsmMounter::Error::MissingData:public std::exception
{
	const char* what() const throw()
	{
		return "[MOUNTER ERROR] Missing Data on Instruction.";
	}
};