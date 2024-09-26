#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<string>> img(21);

    for (int t = 0; t < n; ++t) {
        int id, tot;
        string s;
        cin >> id >> tot >> s;
        vector<string> row(tot);
        for (int i = 0; i < 10 && i < tot; ++i) {
            row[i] = s.substr(i * 3, 3);
        }
        for (int i = 0; i + 10 < tot; ++i) {
            row[i + 10] = s.substr(i * 3 + 1, 3);
        }
        img[id] = row;
    }
    int id, col;
    while (cin >> id >> col) {
        if (!id && !col) break;
        if (img[id].size() == 0) {
            cout << "Not Found\n";
        }
        else if (col - 1 >= img[id].size()) {
            cout << "Not Found\n";
        }
        else {
            if (id > 9) {
                cout << "0";
            }
            else {
                cout << "00";
            }
            cout << col << "_" << img[id][col - 1] << ".jpg\n";
        }
    }

	return 0;
}
