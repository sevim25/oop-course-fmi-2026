#include "AdmissionService.h"

void AdmissionService::addRequirement(std::unique_ptr<Requirement> r)
{
	requirements.push_back(std::move(r));
}

Result AdmissionService::meetsRequirements(const Student& s) const
{
	std::vector<std::string> temp;

	for (const auto& r : requirements) {
		if (!r->isMet(s)) {
			temp.push_back(r->getErrorMessage(s));
		}
	}

	return Result(temp);
}
