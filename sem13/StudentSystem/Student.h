#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Subject.h"

class Student
{
	std::string fn;
	std::string name;

	std::vector<Subject> subjects;

	size_t credits;
	double avgGrade;

public:
	Student(const std::string& fn,const std::string& name, size_t credits, double avgGrade);

	void setGrade(double grade);
	const std::string& getFN() const;
	const std::string& getName() const;

	void addSubject(const Subject& s);

	size_t getTotalCredits() const;
	double getAvgGrade() const;

	size_t getElectiveCreditsCount() const;

	size_t getCountOfElectiveSub() const;
	size_t getCountOfMandatorySub() const;

	Category getSubjectCategory(const Subject& sub) const;


	size_t takenSubjectBy(const Category& category) const;
};

