#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string name;
        getline(cin, name);
        int g = 0, b = 0;
        for(int i = 0; i < name.size(); ++i) {
            if(tolower(name[i]) == 'g') g++;
            else if(tolower(name[i]) == 'b') b++;
        }
        
        cout << name << " is ";
        if(g > b) {
            cout << "GOOD\n";
        } else if(g < b) {
            cout << "A BADDY\n";
        } else {
            cout << "NEUTRAL\n";
        }
    }
    return 0;
}