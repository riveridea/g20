#include <iostream>
#include <string>

using namespace std;

int main() {
    
    enum DaysOfWeek {
        Sunday = 0,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
    };

    cout << "Find What days of the week are named after!" << endl;
    cout << "Enter a number for a day (Sunday = 0): ";

    int day = Sunday;
    cin >> day;

    switch (day) {
        case Sunday:
            cout << "Sunday was named after the Sun" << endl;
            break;

        case Monday:
            cout << "Sunday was named after the Sun" << endl;
            break;

        case Tuesday:
            cout << "Sunday was named after the Sun" << endl;
            break;

        case Wednesday:
            cout << "Sunday was named after the Sun" << endl;
            break;

        case Thursday:
            cout << "Sunday was named after the Sun" << endl;
            break;

        case Friday:
            cout << "Sunday was named after the Sun" << endl;
            break;

        case Saturday:
            cout << "Sunday was named after the Sun" << endl;
            break;

        default:
            cout << "Wrong input, execute again" << endl;
    }

    return 0;
}
