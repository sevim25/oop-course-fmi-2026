#pragma once
#include "Requirement.h"

class RemainingElectivesRequirement : public Requirement
{
private:
	size_t totalRequiredElectives;
	size_t maxAllowedRemaining;

public:
	RemainingElectivesRequirement(size_t totalRequired, size_t maxRemaining);

	bool isMet(const Student& student) const override;
	std::string getErrorMessage(const Student& student) const override;
};

