#pragma once
#include "Student.h"

class Requirement
{
public:
	virtual bool isMet(const Student& student) const = 0;
	virtual std::string getErrorMessage(const Student& student) const = 0;
	virtual ~Requirement() = default;
};

//virtual size_t minimumCredits(size_t credits) const = 0; YES
//virtual size_t minCreditsElectiveSub(size_t credits) const = 0; YES
//
//virtual void takenSubject(const std::string& name) const = 0;
//virtual void takenSubject(const Category& category) const = 0; YES
//
//virtual size_t maxRemainingElectiveSub(size_t credits) const = 0;
//
//virtual double minAvgGrade(double grade) const = 0;
//virtual void takenAll() const = 0;