#include "StudentNotFoundException.h"

StudentNotFoundException::StudentNotFoundException(const std::string& message)
	: errorMessage(message) {}

const char* StudentNotFoundException::what() const noexcept
{
	return errorMessage.c_str();
}
