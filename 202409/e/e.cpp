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

bool tmp(pii &a, pii &b) {
    if (a.ss != b.ss) return a.ss < b.ss;
    return a.ff < b.ff;
}

void solve(vector<pii> &vc) {
    sort(vc.begin(), vc.end(), tmp);
    int time = 0;
    for (pii &pa : vc) {
        if (time + pa.ff > pa.ss) {
            cout << "NO\n";
            return;
        }
        time += pa.ff;
    }
    cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> vc(n);
    for (int i = 0; i < n; ++i) {
        cin >> vc[i].ff >> vc[i].ss;
    }
    solve(vc);

	return 0;
}
