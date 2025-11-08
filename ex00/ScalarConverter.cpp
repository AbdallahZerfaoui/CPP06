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

// Display conversion methods
void ScalarConverter::displayConversions(char c) {
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::displayConversions(int i) {
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << i << "\n";
    std::cout << "float: " << static_cast<float>(i) << "f\n";
    std::cout << "double: " << static_cast<double>(i) << "\n";
}

void ScalarConverter::displayConversions(float f) {
    if (f >= 32 && f <= 126 && static_cast<int>(f) == f)
        std::cout << "char: '" << static_cast<char>(f) << "'\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << static_cast<int>(f) << "\n";
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << static_cast<double>(f) << "\n";
}

void ScalarConverter::displayConversions(double d) {
    if (d >= 32 && d <= 126 && static_cast<int>(d) == d)
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    else
        std::cout << "char: Non displayable\n";

    std::cout << "int: " << static_cast<int>(d) << "\n";
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << "\n";
}
