#include "DuplicateFacultyNumberException.h"

DuplicateFacultyNumberException::DuplicateFacultyNumberException(const std::string& m)
	: errorMessage(m) {}

const char* DuplicateFacultyNumberException::what() const noexcept
{
	return errorMessage.c_str();
}
