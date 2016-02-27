#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int laps;
    cin >> laps;

    int checkpointCount;
    cin >> checkpointCount;

    vector<int> checkpointX(checkpointCount), checkpointY(checkpointCount);
    for (int i = 0; i < checkpointCount; i++) {
        cin >> checkpointX[i] >> checkpointY[i]; cin.ignore();
    }

    while (1) {
        int target[2];
        for (int i = 0; i < 2; i++) {
            int x;
            int y;
            int vx;
            int vy;
            int angle;
            int nextCheckPointId;
            cin >> x >> y >> vx >> vy >> angle >> nextCheckPointId; cin.ignore();
            target[i] = nextCheckPointId;
        }
        for (int i = 0; i < 2; i++) {
            int x;
            int y;
            int vx;
            int vy;
            int angle;
            int nextCheckPointId;
            cin >> x >> y >> vx >> vy >> angle >> nextCheckPointId; cin.ignore();
        }

        for (int i = 0; i < 2; ++i) {
            cout << checkpointX[target[i]] << " " << checkpointY[target[i]] << " " << (rand()%200) << endl;
        }
    }

    return 0;
}
