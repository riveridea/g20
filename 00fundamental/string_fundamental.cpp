#include <string>
#include <iostream>

using namespace std;
/*
 * When talking about String, always come up with these following areas:
 * 1. Copying
 * 2. Concatenating
 * 3. Finding characters and substrings
 * 4. Truncating
 * 5. String reversal and case conversions
 */

class StringExercise {
public:
    void InitializeString() {
    // initialize a constant character string literal to a regular STL
    // std::string object
    const char* constCStyleString = "Hello String!";

    // assign a constant character string literal to a regular STL
    // std::string object
    string strFromConst(constCCtyleString);
    }

    void CopyString() {

    }

    void CopyCStyleString() {

    }

};

int main() {


    return 0;
}
