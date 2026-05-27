#include "Student.h"
#include "InvalidRequirementConfigurationException.h"

Student::Student(const std::string& fn, const std::string& name, size_t credits, double avgGrade)
	: name(name), fn(fn), credits(credits) 
{
	setGrade(avgGrade);
}

void Student::setGrade(double grade)
{
	if (grade < 2 || grade > 6) {
		throw InvalidRequirementConfigurationException("Invalid requirement configuration: minimum average grade must be between 2.00 and 6.00");
	}

	this->avgGrade = grade;
}

const std::string& Student::getFN() const
{
	return fn;
}

const std::string& Student::getName() const
{
	return name;
}

void Student::addSubject(const Subject& s)
{
	subjects.push_back(s);
}

size_t Student::getTotalCredits() const
{
	return credits;
}

double Student::getAvgGrade() const
{
	return avgGrade;
}

size_t Student::getElectiveCreditsCount() const
{
	size_t count = 0;
	for (const auto& s : subjects) {
		if (!s.isMandatory()) {
			
			count += s.getCreditsCountPerSub();
		}
	}

	return count;
}

size_t Student::getCountOfElectiveSub() const
{
	size_t count = 0;
	for (const auto& s : subjects) {
		if (!s.isMandatory()) {
			count++;
		}
	}

	return count;
}

size_t Student::getCountOfMandatorySub() const
{
	return subjects.size() - getCountOfElectiveSub();
}

Category Student::getSubjectCategory(const Subject& sub) const
{
	return sub.getCategory();
}

size_t Student::takenSubjectBy(const Category& category) const
{
	size_t count = 0;
	for (const auto& s : subjects) {
		if (s.getCategory() == category) {
			count++;
		}
	}

	return count;
}
