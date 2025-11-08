#pragma once

#include <string>
#include <iostream>
#include <iomanip> // for std::setprecision

// all the methods are static because the class is not instantiable
class ScalarConverter {
    public:
        static void convert(const std::string& input);

    private:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter&) = delete;
        ScalarConverter& operator=(const ScalarConverter&) = delete;
        ~ScalarConverter() = delete;

        // detection
        static bool isChar(const std::string& input);
        static bool isInt(const std::string& input);
        static bool isFloat(const std::string& input);
        static bool isDouble(const std::string& input);

        // display conversions
        static void displayConversions(char c);
        static void displayConversions(int i);
        static void displayConversions(float f);
        static void displayConversions(double d);
};

