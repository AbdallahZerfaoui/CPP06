# pragma once

#include <string>
#include <iostream>

struct Data {
    int         id;
    std::string strValue;
};

class Serialize {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        Serialize() = delete;
        Serialize(const Serialize&) = delete;
        Serialize& operator=(const Serialize&) = delete;
        ~Serialize() = delete;
};