#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {

    // game loop
    while (1) {
        int spaceX;
        int spaceY;
        cin >> spaceX >> spaceY; cin.ignore();
        int mountainH[8];
        int mx = 0;
        for (int i = 0; i < 8; i++) {
            cin >> mountainH[i]; cin.ignore();
            if (mountainH[i] > mountainH[mx]) mx = i;
        }
        
        string cmd = "HOLD";
        if (spaceX == mx) cmd = "FIRE";

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << cmd << endl; // either:  FIRE (ship is firing its phase cannons) or HOLD (ship is not firing).
    }
}
