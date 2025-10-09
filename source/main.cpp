#include <iostream>
#include <locale>
#include <limits>
#include <math.h>
#include <string>
#include "scr/cpp/math.h"
#include "scr/cpp/time.h"
#include "scr/cpp/rand.h"

using namespace std;

int help() {
    cout << "You can use the following services:" << endl;
    cout << "· math >> simple calculations" << endl;
    cout << "· sum >> sum of numbers" << endl;
    cout << "· stopw >> stopwatch" << endl;
    cout << "· timer >> timer" << endl;
    cout << "· unixt >> UNIX time" << endl;
    cout << "· date >> current date" << endl;
    cout << "· randi >> random integer" << endl;
    cout << "· randf >> random float number" << endl;

    return 0;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    cout << "----------" << endl;
    cout << "Welcome to C++utility!" << endl;
    cout << "----------" << endl;
    while (true) {
        string service;
        cout << endl << "Enter the desired service (enter 'help' for info)" << endl;
        cout << "> ";
        cin >> service;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (service == "math") {
            math();
        } else if (service == "help") {
            help();
        } else if (service == "sum") {
            sum();
        } else if (service == "stopw") {
            stopw();
        } else if (service == "timer") {
            timer();
        } else if (service == "unixt") {
            unixTime();
        } else if (service == "date") {
            date();
        } else if (service == "randi") {
            irandom();
        } else if (service == "randf") {
            frandom();
        } else {
            cout << "We did not find this service(" << endl;
        }
    }
    return 0;
}
