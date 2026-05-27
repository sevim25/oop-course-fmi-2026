#include "InvalidRequirementConfigurationException.h"

InvalidRequirementConfigurationException::InvalidRequirementConfigurationException(const std::string& m)
	: errorMessage(m) {}

const char* InvalidRequirementConfigurationException::what() const noexcept
{
	return errorMessage.c_str();
}
