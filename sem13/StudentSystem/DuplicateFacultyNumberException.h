#pragma once
#include <exception>
#include <string>

class DuplicateFacultyNumberException : public std::exception
{
private:
	std::string errorMessage;

public:
	DuplicateFacultyNumberException(const std::string& m);
	const char* what() const noexcept override;
};

