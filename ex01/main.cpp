#include "Serializer.hpp"

int main(void) {
    Data    testData;
    testData.member = 69;
    testData.title = "Test Data Member";
    testData.description = "This is a little test data structure to check if the Serializer class works as expected.";
    
    std::cout << testData.member << std::endl;
    std::cout << testData.title << std::endl;
    std::cout << testData.description << std::endl;

    uintptr_t test = Serializer::serialize(&testData);
    Data*   deserializedData = Serializer::deserialize(test);

    std::cout << deserializedData->member << std::endl;
    std::cout << deserializedData->title << std::endl;
    std::cout << deserializedData->description << std::endl;
    return (0);
}
