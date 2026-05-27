#include "MinimumAverageGradeRequiremen.h"
#include "InvalidRequirementConfigurationException.h"

MinimumAverageGradeRequiremen::MinimumAverageGradeRequiremen(double grade)
{
	if (grade < 2.0 || grade > 6.0) {
		throw InvalidRequirementConfigurationException("Invalid requirement configuration: minimum average grade must be between 2.00 and 6.00.");
	}
	minRequiredGrade = grade;
}

bool MinimumAverageGradeRequiremen::isMet(const Student& s) const
{
	return minRequiredGrade <= s.getAvgGrade();
}

std::string MinimumAverageGradeRequiremen::getErrorMessage(const Student& student) const
{
	return "Student average grade is " + std::to_string(student.getAvgGrade()) + ", but at least " + std::to_string(minRequiredGrade )+ "is required.\n";
}


