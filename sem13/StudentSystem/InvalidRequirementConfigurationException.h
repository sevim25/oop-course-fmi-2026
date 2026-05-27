#pragma once
#include <exception>
#include <string>

class InvalidRequirementConfigurationException : public std::exception
{
private:
	std::string errorMessage;

public:
	InvalidRequirementConfigurationException(const std::string& m);
	const char* what() const noexcept override;
};

