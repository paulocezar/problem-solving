#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


#define MAXN 100000

long dist[MAXN];
vector< pair<int, long> > gr[MAXN+1];

char buffer[256];

long str_to_seconds(string &s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '-') s[i] = ' ';
	}
	istringstream in(s);
	long dias, horas, min, sec;
	in >> dias >> horas >> min >> sec;
	return ((dias*24L + horas)*60L + min)*60L + sec;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    

    int qt;
    cin >> qt;
    while (qt--) {
    	int N, M;
    	cin >> N >> M; cin.ignore();
    	string sleave, slimit;
    	getline(cin, sleave);
    	getline(cin, slimit);

 	   	struct tm tm_leave = {0}, tm_limit = {0};
		tm_leave.tm_isdst = -1; 
    	tm_limit.tm_isdst = -1; 
    	
    	strptime(sleave.c_str(), "%d/%m/%Y - %H:%M:%S", &tm_leave);
    	strptime(slimit.c_str(), "%d/%m/%Y - %H:%M:%S", &tm_limit); 
    	
    	long leave = mktime(&tm_leave);
    	long limit = mktime(&tm_limit);

    	for (int i = 0; i < N; ++i) {
    		dist[i] = -1L;
    		gr[i].clear();
		}

		int u, v;
		long c;
		string len;
		while (M--) {
			cin >> u >> v >> len;
			c = str_to_seconds(len);
			
			gr[u].push_back(make_pair(v, c));
			gr[v].push_back(make_pair(u, c));
		}

		dist[0] = 0;
		priority_queue<pair<long,int>> q;
		q.push(make_pair(0, 0));
		while (!q.empty()) {
			long cost = -q.top().first;
			u = q.top().second; q.pop();
			if (u == (N-1)) break;
			for (auto &edge : gr[u]) {
				v = edge.first;
				c = edge.second + cost;
				if ((dist[v] == -1L) || (c < dist[v])) {
					dist[v] = c;
					q.push(make_pair(-c, v));
				}
			}
		}

		if ((dist[N-1] == -1L) || ((leave+dist[N-1]) > limit)) cout << "IMPOSSIBLE\n";
		else {
			cout << "POSSIBLE\n";
			tm_leave.tm_sec += dist[N-1];
	
			mktime(&tm_leave);
			
			strftime(buffer, sizeof(buffer), "%d/%m/%Y - %H:%M:%S", &tm_leave);
			cout << buffer << "\n";
		}	

    }


	return 0;
}

















