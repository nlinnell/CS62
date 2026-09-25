
#include "network.h"
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>

int Network::readUsers(const char* fname) {
    std::string myline;
    std::ifstream myfile(fname);

    if (!myfile.is_open()) return -1; // File failed to open

    std::getline(myfile, myline);// First line is number of users
 
    // Variables needed for user
    int id, year, zip;
    std::string name;

    while (myfile>>id){
        std::getline(myfile, myline);//Consume leftover newline character
        std::getline(myfile, myline);
        name = myline.substr(1); // substr(1) gets the text after the tab
 
        myfile>>year;
        myfile>>zip;
        std::getline(myfile, myline);//Consume leftover newline character
        std::getline(myfile, myline);
        std::stringstream friendStream(myline.substr(1));

        // Read each friend id from the friend line
        int friendId;
        std::set<int> friends;
        while (friendStream >> friendId) {
            //Fill in this Code
        }

        //Fill in this Code
    }

    return 0; // Success
}