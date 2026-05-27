#include "RemainingElectivesRequirement.h"


RemainingElectivesRequirement::RemainingElectivesRequirement(size_t totalRequired, size_t maxRemaining)
	: totalRequiredElectives(totalRequired), maxAllowedRemaining(maxRemaining) {}

bool RemainingElectivesRequirement::isMet(const Student& s) const
{
	size_t completed = s.getCountOfElectiveSub();

	if (completed >= totalRequiredElectives) {
		return true;
	}

	size_t remaining = totalRequiredElectives - completed;

	return remaining <= maxAllowedRemaining;
}

std::string RemainingElectivesRequirement::getErrorMessage(const Student& student) const
{
	size_t completed = student.getCountOfElectiveSub();
	size_t remaining = (completed >= totalRequiredElectives) ? 0 : (totalRequiredElectives - completed);

	return "Student still has " + std::to_string(remaining) + " remaining elective courses left to pass.";
}
