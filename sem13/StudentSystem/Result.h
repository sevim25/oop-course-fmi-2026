#pragma once
#include <string>
#include <vector>

class Result
{
private:
	std::vector<std::string> messages;

public:
	Result(const std::vector<std::string>& message);

	bool isAdmitted()const;
	void printResult() const;

};

