#pragma once
#include <string>
#include <vector>
#include <memory>

enum class Category {
	PROGRAMMING,
	MATHEMATICS,
	APPLIED_MATHEMATICS, 
	OTHER
};

class Subject
{
	std::string name;
	size_t creditsCount = 0;
	Category category;

	bool mandatory = true;

public:
	Subject(std::string name, size_t creditsCount, Category category, bool isMandatory);

	const std::string& getSubjectName() const;
	size_t getCreditsCountPerSub() const;
	Category getCategory() const;

	bool isMandatory() const;
}; 

