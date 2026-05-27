#include <iostream>
#include <memory>
#include <string>

#include "Student.h"
#include "Subject.h"
#include "StudentSystem.h"
#include "AdmissionService.h"
#include "MinimumCreditsRequirement.h"
#include "MinimumAverageGradeRequiremen.h" 
#include "MinCoursesCategoryRequirement.h"

#include "DuplicateFacultyNumberException.h"
#include "StudentNotFoundException.h"
#include "InvalidRequirementConfigurationException.h"

int main()
{
	Subject oop("OOP", 10, Category::PROGRAMMING, true);
	Subject oop_practicum("OOP-PRACTICUM", 5, Category::PROGRAMMING, false);
	Subject dstr("DSTR", 15, Category::MATHEMATICS, true);
	Subject algebra("Linear algebra", 10, Category::APPLIED_MATHEMATICS, true);

	Student s1("1MI23", "Ivan", 30, 5.25);
	Student s2("2MI22", "Maria", 45, 4.20);
	Student s3("3MI99", "Georgi", 10, 4.00);
	Student s4("3MI99", "Petar", 10, 4.00);

	s1.addSubject(oop);
	s1.addSubject(dstr);
	s2.addSubject(algebra);
	s3.addSubject(oop_practicum);

	auto admissionService = std::make_shared<AdmissionService>();

	admissionService->addRequirement(std::make_unique<MinimumCreditsRequirement>(25, 5));
	admissionService->addRequirement(std::make_unique<MinimumAverageGradeRequiremen>(4.00));
	admissionService->addRequirement(std::make_unique<MinCoursesCategoryRequirement>(Category::PROGRAMMING, 1));

	StudentSystem fmiSystem(admissionService);

	fmiSystem.addStudent(s1);
	fmiSystem.addStudent(s2);
	fmiSystem.addStudent(s3);

	Result res1 = fmiSystem.checkAdmission("1MI23");
	res1.printResult();

	Result res2 = fmiSystem.checkAdmission("2MI22");
	res2.printResult();

	Result res3 = fmiSystem.checkAdmission("3MI99");
	res3.printResult();

	try {
		fmiSystem.addStudent(s4);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		const Student& found = fmiSystem["1MI23"];
		std::cout << "Found: " << found.getName() <<'\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		const Student& s = fmiSystem["11111"];
		std::cout << "Found: " << s.getName() << '\n';
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		fmiSystem.removeStudent("2MI22");
		std::cout << "Successfully removed student!\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	try {
		fmiSystem.removeStudent("000000");
		std::cout << "Successfully removed student!\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

}
