#pragma once
#include "Requirement.h"

class MinCoursesCategoryRequirement : public Requirement
{
private:
	Category requiredCategory;
	size_t requiredCount;

public:
	MinCoursesCategoryRequirement(const Category& category, size_t minCount);

	bool isMet(const Student& s) const override;
	std::string getErrorMessage(const Student& student) const override;
};

