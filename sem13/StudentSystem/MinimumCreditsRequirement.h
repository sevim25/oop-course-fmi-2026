#pragma once
#include "Requirement.h"

class MinimumCreditsRequirement : public Requirement
{
private:
	size_t requiredTotalCredits;
	size_t requiredElectiveCredits;


public:
	MinimumCreditsRequirement(size_t total, size_t elective = 0);
	
	bool isMet(const Student& student) const override;
	std::string getErrorMessage(const Student& student) const override;

};

