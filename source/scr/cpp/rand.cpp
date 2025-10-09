#include <iostream>
#include <limits>
#include <time.h>

using namespace std;

void irandom () {
    srand(time(NULL));
    int a, b;

    cout << "From which number...\n>> ";
    cin >> a;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "...to which?\n>> ";
    cin >> b;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (a >= b) {
        cout << "Error: the numbers are incorrect. \n";
    } else {
        cout << "Random integer: " << (rand() % (b - a + 1) + a);
    }
}

void frandom () {
    srand(time(NULL));
    float a, b;

    cout << "From which number...\n>> ";
    cin >> a;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "...to which?\n>> ";
    cin >> b;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (a >= b) {
        cout << "Error: the numbers are incorrect.";
    } else {
        cout << "Random float number: " << a + static_cast<float>(rand()) / RAND_MAX * (b - a);
    }
}
