#include "Result.h"
#include <iostream>

Result::Result(const std::vector<std::string>& message)
    : messages(message) {}

bool Result::isAdmitted() const
{
    return messages.empty();
}

void Result::printResult() const
{
    if (isAdmitted()) {
        std::cout << "Student is admitted to the state exam.\n";
    }
    else {
        std::cout << "Student is not admitted to the state exam:\n";
        for (const auto& m : messages) {
            std::cout<<"- " << m << '\n';
        }
    }

}
