#pragma once
#include <iostream>
#include "DuplicateFacultyNumberException.h"
#include "AdmissionService.h"

class StudentSystem
{
	std::vector<Student> students;
	std::shared_ptr<AdmissionService> service;

public:
	StudentSystem() = default;
	StudentSystem(std::shared_ptr<AdmissionService> service);

	void addStudent(const Student& s);
	void removeStudent(const std::string& fn);

	const Student& operator[](const std::string& fn) const;

	Result checkAdmission(const std::string& fn) const;

};

