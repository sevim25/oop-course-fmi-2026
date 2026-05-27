#include "NoFailedMandatoryCoursesRequirement.h"

NoFailedMandatoryCoursesRequirement::NoFailedMandatoryCoursesRequirement(size_t count)
    : requiredCountOfMandatoryCourses(count) {}

bool NoFailedMandatoryCoursesRequirement::isMet(const Student& s) const
{
    return requiredCountOfMandatoryCourses <= s.getCountOfMandatorySub();
}

std::string NoFailedMandatoryCoursesRequirement::getErrorMessage(const Student& student) const
{
    return "Mandatory course not passed: ";
}
