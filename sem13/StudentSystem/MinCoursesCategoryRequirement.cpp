#include "MinCoursesCategoryRequirement.h"

MinCoursesCategoryRequirement::MinCoursesCategoryRequirement(const Category& category, size_t minCount)
	: requiredCategory(category), requiredCount(minCount)
{
}

bool MinCoursesCategoryRequirement::isMet(const Student& s) const
{
	return s.takenSubjectBy(requiredCategory) >= requiredCount;
}

std::string MinCoursesCategoryRequirement::getErrorMessage(const Student& student) const
{
	return "";
}
