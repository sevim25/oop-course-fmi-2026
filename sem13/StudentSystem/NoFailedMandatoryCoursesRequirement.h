#pragma once
#include "Requirement.h"

class NoFailedMandatoryCoursesRequirement : public Requirement
{
private:
	size_t requiredCountOfMandatoryCourses;
public:
	NoFailedMandatoryCoursesRequirement(size_t count);

	bool isMet(const Student& s) const override;
	std::string getErrorMessage(const Student& student) const override;
};


