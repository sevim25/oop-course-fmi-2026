#pragma once
#include "Requirement.h"
#include "Result.h"
#include <vector>
#include <memory>


class AdmissionService
{
private:
	std::vector<std::unique_ptr<Requirement>> requirements;

public:
	void addRequirement(std::unique_ptr<Requirement> r);
	Result meetsRequirements(const Student& s) const;
};

