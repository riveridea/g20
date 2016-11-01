/* 
Given an array and a value, 
remove all instances of that value 
in place and return the new length.

The order of elements can be changed. 
It doesn't matter what you leave 
beyond the new length.
*/


/* CPP */
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int elem) {
        int len = sizeof(Afs)/sizeof(int);

        int i = 0;

        while (i < len) {
            if (A[i] == elem) { 
                A[i] = A[--len];
            } else {
                i++;
            }
        }

        return len;
    }

};

int main() {
    int array1[5] = {1, 2, 3, 4, 5};
    Solution solution1;

    cout << "new length is: " + solution1.removeElement(array1, 3) << endl;

}