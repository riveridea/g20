//basic array 

#include <string>
#include <iostream>

using namespace std;

int main() {

    /* 
     * Declaring and Initializing Static Arrays 
     *
     * Array declaration in C++ follows a simple syntax:
     * element-type array-name [name of elements] 
     *     = {optional initial values}
     */
    
    // declare an array of five intergs each initialized to zero
    int MyNumbers [5] = {0};
    
    // define an array of five characters
    char MyCharaters [5];

    // define the length of an array as a constant and use that
    // constant in the array definition
	const int ARRAY_LENGTH = 5;
	int MyNumbers1[ARRAY_LENGTH] = {34, 56, -21, 5002, 365};

	// or opt to leave out the number of elements in an array
	int MyNumbers2[] = {2011, 2052, -525};


	/* Accessing Date Stored in an Array */
    cout << "First element at index 0 of MyNumbers1: " 
        << MyNumbers1[0] << endl;   

    /* Modifying Data Stored in an Array*/
    cout << "Enter index of the element to be changed: ";
    int nElementIndex = 0;
    cin >> nElementIndex;

    cout << "Enter new value: ";
    cin >> MyNumbers1[nElementIndex];
    cout << endl;

	/* Display the elements in the Array */
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		cout << "array[" << i << "] = " << MyNumbers1[i] << "\n";
	}

	cout << endl;


	/* Multi-dimensional Arrays */
	int SolarPanelIDs[2][3];
	int SolarPanelIDs1p[2][3] = {{0, 1, 2}, {3, 4, 5}};

	/* C-style Strings */
	// \0 is important, compiler uses it mark the end of string
	char SayHello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	cout << SayHello << endl;

    /* C++ Strings  */
    string Greetings("Hello std::string!");
    cout << Greetings << endl;

    cout << "Enter a line of text: " << endl;
    string FirstLine;
    getline(cin, FirstLine);

    cout << "Enter another: " << endl;
    string SecLine;

    cout << "Result of concatenation: " << endl;
    string Concat = FirstLine + " " + SecLine;
    cout << Concat << endl;

    cout << "Copy of concatenated string: " << endl;
    string Copy;
    Copy = Concat;
    cout << Copy << endl;

    cout << "Length of concat string: " << Concat.length() << endl;

    return 0;
}
