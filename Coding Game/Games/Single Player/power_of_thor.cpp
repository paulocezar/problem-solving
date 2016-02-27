#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dx = {       0,   +1,  +1,   +1,   0,  -1,   -1,   -1};
vector<int> dy = {      -1,   -1,   0,   +1,  +1,  +1,    0,   -1};
vector<string> dir = { "N", "NE", "E", "SE", "S", "SW", "W", "NW"};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main(){

    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    
    // game loop
    while (1) {
        int remainingTurns;
        cin >> remainingTurns; cin.ignore();
        
        string res = "";
        if (initialTY > lightY) res += "N", initialTY--;
        else if (initialTY < lightY) res += "S", initialTY++;

        
        if (initialTX > lightX) res += "W", initialTX--;
        else if (initialTX < lightX) res += "E", initialTX++;

        cout << res << endl; // A single line providing the move to be made: N NE E SE S SW W or NW
    }
}
