#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double karim, rahim, both, none;
int karim_likes[64], rahim_likes[64];

double cache[101][101][101];
int last_cached[101][101][101], cached;

double solve(int days, int karim_chosen, int rahim_chosen) {
    
    if (days == 0) {
        return ((rahim_chosen == 2*karim_chosen) ? 1.0 : 0.0);
    }
    
    double &ret = cache[days][karim_chosen][rahim_chosen];
    if (last_cached[days][karim_chosen][rahim_chosen] != cached) {
        ret = 0.0;
        ret += karim * solve(days - 1, karim_chosen + 1, rahim_chosen);
        ret += rahim * solve(days - 1, karim_chosen, rahim_chosen + 1);
        ret += both * solve(days - 1, karim_chosen + 1, rahim_chosen + 1);
        ret += none * solve(days - 1, karim_chosen , rahim_chosen);
        last_cached[days][karim_chosen][rahim_chosen] = cached;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    
    int n, tc = 1;
    while (cin >> n && n) {
        
        for (int i = 1; i <= n; ++i) karim_likes[i] = rahim_likes[i] = 0;
        
        int likes;
        cin >> likes;
        for (int i = 0; i < likes; ++i) {
            int dish;
            cin >> dish;
            karim_likes[dish] = 1;
        }
        
        cin >> likes;
        for (int i = 0; i < likes; ++i) {
            int dish;
            cin >> dish;
            rahim_likes[dish] = 1;
        }
        
        int d;
        cin >> d;
        
        karim = rahim = both = none = 0.0;
        
        for (int i = 1; i <= n; ++i) {
            if (karim_likes[i] && rahim_likes[i]) both += 1.0;
            else if (karim_likes[i]) karim += 1.0;
            else if (rahim_likes[i]) rahim += 1.0;
            else none += 1.0;
        }
        
        karim /= n;
        rahim /= n;
        both /= n;
        none /= n;
        
        cached++;   
        cout << "Case " << tc++ << ": " << solve(d,0,0) << "\n";
    }
    return 0;
}

/* ITERATIVE

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double karim, rahim, both, none;
int karim_likes[64], rahim_likes[64];

double prob[101][101][101];

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    
    int n, tc = 1;
    while (cin >> n && n) {
        
        for (int i = 1; i <= n; ++i) karim_likes[i] = rahim_likes[i] = 0;
        
        int likes;
        cin >> likes;
        for (int i = 0; i < likes; ++i) {
            int dish;
            cin >> dish;
            karim_likes[dish] = 1;
        }
        
        cin >> likes;
        for (int i = 0; i < likes; ++i) {
            int dish;
            cin >> dish;
            rahim_likes[dish] = 1;
        }
        
        int D;
        cin >> D;
        
        karim = rahim = both = none = 0.0;
        
        for (int i = 1; i <= n; ++i) {
            if (karim_likes[i] && rahim_likes[i]) both += 1.0;
            else if (karim_likes[i]) karim += 1.0;
            else if (rahim_likes[i]) rahim += 1.0;
            else none += 1.0;
        }
        
        karim /= n;
        rahim /= n;
        both /= n;
        none /= n;
        
        for (int i = 0; i <= D; ++i) 
            for (int j = 0; j <= D; ++j)
                for (int k = 0; k <= D; ++k)
                    prob[i][j][k] = 0.0;
        
        prob[0][0][0] = 1.0;
        
        for (int day = 0; day < D; ++day) {
            for (int karim_chosen = 0; karim_chosen <= day; ++karim_chosen) {
                for (int rahim_chosen = 0; rahim_chosen <= day; ++rahim_chosen) {
                    prob[day+1][karim_chosen+1][rahim_chosen] += karim * prob[day][karim_chosen][rahim_chosen];
                    prob[day+1][karim_chosen][rahim_chosen+1] += rahim * prob[day][karim_chosen][rahim_chosen];
                    prob[day+1][karim_chosen+1][rahim_chosen+1] += both * prob[day][karim_chosen][rahim_chosen];
                    prob[day+1][karim_chosen][rahim_chosen] += none * prob[day][karim_chosen][rahim_chosen];
                }
            }
        }
        
        double res = 0.0;
        for (int karim_chosen = 0; 2*karim_chosen <= D; ++karim_chosen) {
            res += prob[D][karim_chosen][2*karim_chosen];
        }
        cout << "Case " << tc++ << ": " << res << "\n";
    }
    return 0;
}
*/