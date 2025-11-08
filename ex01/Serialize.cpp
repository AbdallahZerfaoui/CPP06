# include "Serialize.hpp"

/*
KEY POINTS about reinterpret_cast:
1. NO CONVERSION - just bit reinterpretation
2. Low-level, unsafe operation
3. Used for: pointer ↔ integer, pointer ↔ pointer of different types
4. Compiler doesn't check if the cast makes sense
5. Your responsibility to ensure the cast is valid
6. Mainly used in system programming, serialization, hardware interfaces
*/

uintptr_t Serialize::serialize(Data* ptr) {
    // reinterpret_cast: tells compiler "treat these bits as a different type"
    // No conversion happens - just reinterprets the memory pattern
    // Here: take pointer's address (memory location) and treat it as an integer
    // Pointer address 0x7fff12345678 becomes integer 140734035746424
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw) {
    // reinterpret_cast: reverse operation - treat integer bits as pointer
    // Takes the integer value and interprets it as a memory address
    // Integer 140734035746424 becomes pointer 0x7fff12345678
    // DANGEROUS: no safety checks - assumes the integer is a valid address
    return reinterpret_cast<Data*>(raw);
}
