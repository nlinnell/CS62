// Main program for simulating a Network

#include <iostream>
#include "network.h"
#include "user.h"
#include <set>

// pre: user has entered a full name
// post: reads a full name from cin (user input)
std::string getFullName();

// pre: none
// post: prints the menu options
void printMenu();

// pre: (optional) pass in a file name to read initial users
// post: starts the interactive menu
// which allows for adding people, friend connections etc.
int main(int argc, char *argv[]) {
    Network myNetwork;

    if (argc > 1) {
        // attempt to read the users from the given file if filename entered
        int result = //Fill in code
        if (result == -1) { // file read error
            std::cout << "Error reading from file.";
            return 1;
        }
    }
    bool exit = false;
    while (!exit){
        printMenu();
        int action;
        std::cin >> action;

        if (action == 1){
            // Add user option: read user info use it to 
            // create a user and then add it to the network
            std::string name = getFullName();

            int year, zip;
            std::cin >> year;
            std::cin >> zip;

            //Fill in this code

            std::cout << "User added!\n";
        } else if (action == 2){
            // Add friend connection between the 2 full names given
            std::string name1 = getFullName();
            std::string name2 = getFullName();
            int result = //Fill in this code
            if (result == 0) std::cout<< "Connection Added!\n";
            else std::cout << "Error: one of the users is invalid.\n";
        } else if (action == 3){
            // Remove friend connection between the 2 full names given
            std::string name1 = getFullName();
            std::string name2 = getFullName();
            int result = //Fill in this code
            if (result == 0) std::cout<< "Connection Removed!\n";
            else std::cout << "Error: one of the users is invalid.\n";
        } else if (action == 4){
            // Write the user data to the given file name
            std::string fileName;
            std::cin >> fileName;
            int result = //Fill in this code
            if (result == 0) {
                std::cout<< "Written to file!\n";
            } else std::cout << "Error writing to file.\n";

        } else {
            exit = true;
        }

        std::cout << "\n";
    }
}

void printMenu(){
    std::cout << "-- Menu --\n";
    std::cout << "Add User: 1 FullName BirthYear ZipCode\n";
    std::cout << "Add Friend Connection: 2 FullName1 FullName2\n";
    std::cout << "Remove Friend Connection: 3 FullName1 FullName2\n";
    std::cout << "Write to file: 4 filename.txt\n";
    std::cout << "Exit program: 5+\n";
    std::cout << "Enter Action:\n";
}

std::string getFullName() {
    std::string fname, lname;
    std::cin >> fname;
    std::cin >> lname;
    return fname + " " + lname;
}