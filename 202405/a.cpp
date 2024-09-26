#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	vector<int> vc(4, 0);
	cin >> n;

	int coin;
	for (int fifty = 0; fifty * 50 <= n; ++fifty) {
		for (int ten = 0; ten * 10 <= n; ++ten) {
			for (int five = 0; five * 5 <= n; ++five) {
				coin = n;
				coin -= fifty * 50 + ten * 10 + five * 5;
				if (coin >= 0) {
					cout << fifty << " " << ten << " " << five << " " << coin << "\n";
				}
				else 
					break;
			}
		}
	}
	//// five dollar
	//for (int i = 1; ; ++i) {
		//coin = n;
		//coin -= 5 * i;
		//if (coin >= 0) {
			//cout << "0 0 " << i << " " << coin << "\n";
		//}
	//}
	//// five

	return 0;
}
