#include "time.h"
#include <iostream>
#include <locale>
#include <limits>
#include <math.h>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <sys/select.h>
#include <ctime>

using namespace std;

void stopw() {
    short sec = 0;
    short min = 0;
    long hour = 0;
    bool cont = true;
    bool pause = false;

    cout << "Stopwatch started (0 - stop, 1 - pause)" << endl;

    atomic<bool> running{true};
    thread input_thread([&] {
        string line;
        while (running && getline(cin, line)) {
            if (line == "0") {
                cout << "Stopwatch off";
                cont = false;
                running = false;
                break;
            } else if (line == "1") {
                if (pause == false) {
                    cout << "Stopwatch paused" << endl;
                } else {
                    cout << "Stopwatch restored" << endl;
                }
                pause = !pause;
            }
            if (pause) {
                cout << ">> " << flush;
            }
        }
    });

    while (cont) {
        this_thread::sleep_for(chrono::seconds(1));
        if (!cont) {
            break;
        }
        if (pause) {
            continue;
        }
        sec++;
        if (sec == 60) {
            min++;
            sec = 0;
            if (min == 60) {
                hour++;
                min = 0;
            }
        }
        cout << "\rhours: " << hour << ", minutes: " << min << ", seconds: " << sec << " | >> " << flush;
    }
    if (input_thread.joinable()) input_thread.join();
    cout << endl;
}

void timer() {
    short sec = 10;
    short min = 0;
    long hour = 0;
    bool cont = true;
    bool pause = false;

    cout << "Enter hours\n" << ">> " << flush;
    cin >> hour;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter minutes\n" << ">> " << flush;
    cin >> min;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter seconds\n" << ">> " << flush;
    cin >> sec;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if ((sec < 0 || min < 0 || hour < 0) || (sec == 0 && min == 0 && hour == 0)) {
        cout << "Input error\n";
        return;
    }

    cout << "Timer started (0 - stop, 1 - pause)\n";

    atomic<bool> running{true};

    thread input_thread([&]() {
        while (running) {
            fd_set readfds;
            FD_ZERO(&readfds);
            FD_SET(STDIN_FILENO, &readfds);
            struct timeval tv;
            tv.tv_sec = 0;
            tv.tv_usec = 200000;

            int ret = select(STDIN_FILENO + 1, &readfds, nullptr, nullptr, &tv);
            if (ret > 0 && FD_ISSET(STDIN_FILENO, &readfds)) {
                string line;
                if (!getline(cin, line)) {
                    running = false;
                    break;
                }
                if (line == "0") {
                    cout << "Timer off";
                    cont = false;
                    running = false;
                    break;
                }
                else if (line == "1") {
                    pause = !pause;
                    if (pause) cout << "Timer paused";
                    else cout << "Timer resumed";
                }
                cout << "\n>> " << flush;
            }
        }
    });

    while (cont) {
        this_thread::sleep_for(chrono::seconds(1));
        if (!cont) break;
        if (pause) {
            continue;
        }
        sec--;
        if (sec < 0) {
            sec = 59;
            min--;
            if (min < 0) {
                min = 59;
                hour--;
            }
        }
        cout << "\rhours: " << hour
        << ", minutes: " << min
        << ", seconds: " << sec
        << " | >> " << flush;

        if (hour == 0 && min == 0 && sec == 0) {
            cout << "\nTimer end!";
            cont = false;
            running = false;
            system("python3 ../source/scr/py/timerWindow.py");
            break;
        }
    }

    if (input_thread.joinable()) {
        input_thread.join();
    }
    cout << endl;
}

void unixTime () {
    auto now = chrono::system_clock::now();
    auto timestamp = chrono::system_clock::to_time_t(now);

    cout << "UNIX time: " << timestamp << endl;
}

void date () {
    auto now = chrono::system_clock::now();
    time_t time_now = chrono::system_clock::to_time_t(now);

    cout << "Current date: " << ctime(&time_now);
}
