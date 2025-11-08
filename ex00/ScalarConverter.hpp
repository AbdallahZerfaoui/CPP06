#pragma once

#include <string>
#include <iostream>
#include <limits> // INT_MAX, INT_MIN

class ScalarConverter {
    public:
        static void convert(const std::string& input);

    private:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter&) = delete;
        ScalarConverter& operator=(const ScalarConverter&) = delete;
        ~ScalarConverter() = delete;

        // detection
        bool isChar(const std::string& input);
        bool isInt(const std::string& input);
        bool isFloat(const std::string& input);
        bool isDouble(const std::string& input);

        // display conversions
        void displayConversions(char c);
        void displayConversions(int i);
        void displayConversions(float f);
        void displayConversions(double d);
};

