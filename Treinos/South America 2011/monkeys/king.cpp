#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int v[3], ans[3];
	
	cin >> v[0] >> v[1] >> v[2];
	while (v[0] || v[1] || v[2]) {
		
		sort(v, v + 3);
		
		if (v[0] == v[1]) {
			if (v[1] == v[2]) {
				//set
				
				if (v[0] < 13) {
					int a = v[0] + 1;
					cout << a << ' ' << a << ' ' << a << '\n';
				}
				else {
					cout << "*\n";
				}	
			}
			else {
				// pair
				if (v[2] < 13) {
					ans[0] = ans[1] = v[0];
					ans[2] = v[2] + 1;
					
					if (ans[2] == ans[0]) {
						ans[2]++;
						
						if (ans[2] <= 13) {
							sort(ans, ans + 3);
							cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
						}
						else {
							cout << "1 1 1\n";
						}
					}
					else {
					
						sort(ans, ans + 3);
						cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
					}
				}
				else if (v[0] < 13) {
					cout << 1 << ' ' << v[0] + 1 << ' ' << v[0] + 1 << '\n';
				}
				else {
					cout << "*\n";
				}
			}
		}
		else if (v[1] == v[2]) {
			// pair
			if (v[0] < 13) {
				ans[0] = ans[1] = v[1];
				ans[2] = v[0] + 1;
				
				if (ans[2] == ans[0]) {
					ans[2]++;
					if (ans[2] <= 13) {
						sort(ans, ans + 3);
						cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
					}
					else {
						cout << "1 1 1\n";
					}
				}
				else {
					sort(ans, ans + 3);
					cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
				}
			}
			else if (v[1] < 13) {
				cout << 1 << ' ' << v[1] + 1 << ' ' << v[1] + 1 << '\n';
			}
			else {
				cout << "*\n";
			}
		}
		else {
			cout << "1 1 2\n";
		}
	
		cin >> v[0] >> v[1] >> v[2];
	}
	
	return 0;
}

