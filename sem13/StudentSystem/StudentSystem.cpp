#include "StudentSystem.h"
#include "StudentNotFoundException.h"
#include <iostream>

StudentSystem::StudentSystem(std::shared_ptr<AdmissionService> service)
	: service(service)
{
}

void StudentSystem::addStudent(const Student& s)
{
	for (const auto& student : students) {
		if (student.getFN() == s.getFN()) {
			throw DuplicateFacultyNumberException("Student with this faculty number already exist!");
		}
	}

	students.push_back(s);
}

void StudentSystem::removeStudent(const std::string& fn)
{
	for (auto it = students.begin(); it != students.end(); ++it) {
		if (it->getFN() == fn) {
			students.erase(it);
			return;
		}
	}
	throw StudentNotFoundException("Cannot remove: Student not found.");
}

const Student& StudentSystem::operator[](const std::string& fn) const
{
	for (const auto& student : students) {
		if (student.getFN() == fn) {
			return student;
		}
	}

	throw StudentNotFoundException("Student with the given faculty number was not found.");
}

Result StudentSystem::checkAdmission(const std::string& fn) const
{
	const Student& currentStudent = (*this)[fn]; 

	return service->meetsRequirements(currentStudent);
}

