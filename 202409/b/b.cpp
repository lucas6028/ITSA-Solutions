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

	int t, limit;
	cin >> t >> limit;

    map<int, int> mp;
    int n;
	for (int i = 0; i < t; ++i) {
        cin >> n;
        mp[n]++;
	}
    for (auto &x : mp) {
        if (x.ss >= limit) {
            cout << x.ff << ',' << x.ss << '\n';
        }
    }

	return 0;
}
