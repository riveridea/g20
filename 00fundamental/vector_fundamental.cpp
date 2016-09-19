#include <vector>
#include <iostream>
using namespace std;
// c++ 

void DisplayVector(const vector<int>& vecInput) {
    for (auto iElement = vecInput.cbegin();
            iElement != vecInput.cend();
            ++ iElement) {
        cout << *iElement << ", " ;
    }

    cout << endl;
}


int main() {
    vector<int> v = {2, 3, 4, 5};
    DisplayVector(v);

    v.insert(v.begin(), 1);
    DisplayVector(v);

    return 0;
}

