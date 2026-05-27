#pragma once
#include "Requirement.h"

class MinimumAverageGradeRequiremen : public Requirement
{
private:
	double minRequiredGrade;

public:
	MinimumAverageGradeRequiremen(double grade);

	bool isMet(const Student& s) const override;
	std::string getErrorMessage(const Student& student) const override;

};

