#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		vector<int> row;
		vector<vector<int>> vc(4, row);
		bool flag = false;
		for (int i = 0; i < 4; ++i) {
			char c;
			int tmp;
			cin >> c;
			if (c == 'A') {
				while (cin >> tmp && tmp) vc[0].push_back(tmp);
			}
			else if (c == 'B') {
				while (cin >> tmp && tmp) vc[1].push_back(tmp);
			}
			else if (c == 'C') {
				while (cin >> tmp && tmp) vc[2].push_back(tmp);
			}
			else if (c == 'D') {
				while (cin >> tmp && tmp) vc[3].push_back(tmp);
			}
		}
		cout << "ABCD\n";

		for (int p1 = 1; p1 <= 4; ++p1) {
			for (int p2 = 1; p2 <= 4; ++p2) {
				if (p1 == p2) continue;
				for (int p3 = 1; p3 <= 4; ++p3) {
					if (p1 == p3 || p2 == p3) continue;
					for (int p4 = 1; p4 <= 4; ++p4) {
						if (p1 == p4 || p2 == p4 || p3 == p4) continue;
						if (count(vc[0].begin(), vc[0].end(), p1) == 0 &&
							count(vc[1].begin(), vc[1].end(), p2) == 0 &&
							count(vc[2].begin(), vc[2].end(), p3) == 0 &&
							count(vc[3].begin(), vc[3].end(), p4) == 0) {
							cout << p1 << " " << p2 << " " << p3 << " " << p4 << "\n";
							flag = true;
						}
					}
				}
			}
		}
		if (!flag) cout << "NO\n";
	}

	return 0;
}
