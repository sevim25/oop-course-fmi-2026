#pragma once
#include <exception>
#include <string>

class StudentNotFoundException : public std::exception
{
private:
	std::string errorMessage;

public:
	StudentNotFoundException(const std::string& message);

	const char* what() const noexcept override;
};

