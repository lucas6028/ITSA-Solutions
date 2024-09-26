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

void solve() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    vector<vector<char>> vc(8, vector<char>(8));
    vector<pii> res;
    vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> vc[i][j];
        }
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (pii dir : dirs) {
                int nx = dir.ff + i;
                int ny = dir.ss + j;
                if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
                if (vc[i][j] == vc[nx][ny]) {
                    res.push_back({i, j});
                    break;
                }
            }
        }
    }

    for (pii pa : res) {
        cout << "(" << pa.ff << ',' << pa.ss << ")\n";
    }
	return 0;
}
