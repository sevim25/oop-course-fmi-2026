#include "MinimumCreditsRequirement.h"

MinimumCreditsRequirement::MinimumCreditsRequirement(size_t total, size_t elective)
	: requiredTotalCredits(total), requiredElectiveCredits(elective) {}

bool MinimumCreditsRequirement::isMet(const Student& student) const
{
	return student.getTotalCredits() >= requiredTotalCredits
		&& student.getElectiveCreditsCount() >= requiredElectiveCredits;
}

std::string MinimumCreditsRequirement::getErrorMessage(const Student& student) const
{
	return "Student has " + std::to_string(student.getTotalCredits()) + " credits, but at least " + std::to_string(requiredTotalCredits) + " are required.\n";
}
