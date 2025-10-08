#include "math.h"
#include <iostream>
#include <locale>
#include <limits>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

void sum() {
    vector<double> nums;
    bool cont = true;
    double num;
    double sum = 0;

    while (cont) {
        cout << "Enter a number (0 to end)" << endl;
        cout << ">> ";
        cin >> num;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (num) {
            nums.push_back(num);
        } else {
            for (short i = 0; i < nums.size(); i++) {
                sum += nums[i];
            }
            cout << "Sum of numbers: " << sum << endl;
            cont = false;
        }
    }
}

void math() {
    double num1, num2;
    char math;
    cout << "Enter a mathematical operation(+,-,*,/,^): \n";
    cout << ">> ";
    cin >> math;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (math == '+' || math == '-' || math == '/' || math == '*' || math == '^') {
        cout << "Enter the number 1: \n";
        cout << ">> ";
        cin >> num1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (num1) {
            cout << "Enter the number 2: \n";
            cout << ">> ";
            cin >> num2;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } else {
        cout << "Mathematical operation error \n";
    }
    if (math && num1 && num2) {
        switch (math) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                cout << "Result: " << num1 / num2 << endl;
                break;
            case '^':
                cout << "Result: " << pow(num1, num2) << endl;
                break;
        }
    } else {
        cout << "Input error" << endl;
    }
}
