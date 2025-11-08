#include "ScalarConverter.hpp"

// Detection methods
bool ScalarConverter::isChar(const std::string& input) {
    return input.length() == 1 && isprint(input[0]) && !isdigit(input[0]);
}

bool ScalarConverter::isInt(const std::string& input) {
    if (input.empty()) return false;

    try {
        size_t pos;
        std::stoll(input, &pos);
        return pos == input.length();
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isFloat(const std::string& input) {
    if (input.empty()) return false;

    //handle -inff, +inff, nanf
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;

    try {
        size_t pos;
        std::stof(input, &pos);
        return pos == input.length() && input.back() == 'f';
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isDouble(const std::string& input) {
    return isFloat(input);
}
