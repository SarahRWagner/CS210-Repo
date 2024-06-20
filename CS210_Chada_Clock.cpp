#include <iostream>
#include <iomanip>
/*
* Author: Sarah Wagner
* Class: CS-210
* Date: 05/26/24
*/

// Clock class definition
class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void addHour() {
        hours = (hours + 1) % 24;
    }

    void addMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            addHour();
        }
    }

    void addSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) {
            addMinute();
        }
    }

    void displayTime24() const {
        std::cout << "*      "
                  << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds
                  << "          *" << std::endl; // Adjusted spacing to match 12-hour format
    }

    void displayTime12() const {
        int displayHour = hours % 12;
        if (displayHour == 0) displayHour = 12; // Convert '0' hour to '12' for 12-hour format
        std::string period = (hours < 12) ? "A M" : "P M";

        std::cout << "*      "
                  << std::setw(2) << std::setfill('0') << displayHour << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << " "
                  << period << "      *" << std::endl;
    }
};

void displayMenu() {
    std::cout << "**************************" << std::endl;
    std::cout << "* 1 - Add One Hour       *" << std::endl;
    std::cout << "* 2 - Add One Minute     *" << std::endl;
    std::cout << "* 3 - Add One Second     *" << std::endl;
    std::cout << "* 4 - Exit Program       *" << std::endl;
    std::cout << "**************************" << std::endl;
}

void processUserInput(Clock &clock24, Clock &clock12) {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            clock24.addHour();
            clock12.addHour();
            break;
        case 2:
            clock24.addMinute();
            clock12.addMinute();
            break;
        case 3:
            clock24.addSecond();
            clock12.addSecond();
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            exit(0); // Exit the program
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
    }
}

int main() {
    Clock clock24(0, 0, 0);
    Clock clock12(0, 0, 0);

    while (true) {
        displayMenu();
        processUserInput(clock24, clock12);
        
        std::cout << "**************************" << std::endl;
        std::cout << "*      12-Hour Clock     *" << std::endl;
        clock12.displayTime12();
        std::cout << "**************************" << std::endl;
        
        std::cout << "**************************" << std::endl;
        std::cout << "*      24-Hour Clock     *" << std::endl;
        clock24.displayTime24();
        std::cout << "**************************" << std::endl;
    }

    return 0;
}
