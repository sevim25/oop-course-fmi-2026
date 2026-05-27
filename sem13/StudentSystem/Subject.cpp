#include "Subject.h"

Subject::Subject(std::string name, size_t creditsCount, Category category, bool isMandatory)
	: name(name), creditsCount(creditsCount), category(category), mandatory(isMandatory)
{
}

const std::string& Subject::getSubjectName() const
{
	return name;
}

size_t Subject::getCreditsCountPerSub() const
{
	return creditsCount;
}

Category Subject::getCategory() const
{
	return category;
}

bool Subject::isMandatory() const
{
	return mandatory;
}
