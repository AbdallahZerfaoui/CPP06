#include "Serialize.hpp"

int main() {
    Data data;
    data.id = 41;
    data.strValue = "Abdallah";

    // Serialize
    uintptr_t raw = Serialize::serialize(&data);
    std::cout << "Original Data address: " << &data << "\n";
    std::cout << "Serialized Data pointer to integer: " << raw << "\n";

    // Deserialize
    Data* deserializedData = Serialize::deserialize(raw);

    if (deserializedData == &data) {
        std::cout << "Deserialization successful: pointers match.\n";
    } else {
        std::cout << "Deserialization failed: pointers do not match.\n";
        return 1;
    }
    std::cout << "Deserialized Data address: " << deserializedData << "\n";
    std::cout << "Deserialized Data id: " << deserializedData->id << "\n";
    std::cout << "Deserialized Data strValue: " << deserializedData->strValue << "\n";

    return 0;
}