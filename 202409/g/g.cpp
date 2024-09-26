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
#define INF 1e18

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t;
	cin >> t;
    size_t mod;
    string s;
	for (size_t i = 0; i < t; ++i) {
        cin >> mod >> s;
        size_t len = s.length();
        map<char, size_t> mp;
        vector<size_t> fac;
        fac.reserve(len);

        for (char &c : s) {
            mp[c]++;
        }
        for (auto &x : mp) {
            fac.push_back(x.ss);
        }
        size_t ans = 1;
        for (size_t f = 2; f <= len; ++f) {
            ans *= f;
            ans %= (size_t)INF;
        }
        for (size_t f : fac) {
            int curr = 1;
            for (size_t mul = 2; mul <= f; ++mul) {
                curr *= mul;
                curr %= (size_t)INF;
            }
            ans /= curr;
        }
        cout << (ans % mod) << '\n';
	}


	return 0;
}
