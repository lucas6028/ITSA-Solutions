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

// Function to perform modular exponentiation
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute modular inverse using Fermat's Little Theorem
ll mod_inverse(ll x, ll mod) {
    return mod_pow(x, mod - 2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t t;
    cin >> t;
    ll mod;
    string s;

    for (size_t i = 0; i < t; ++i) {
        cin >> mod >> s;
        size_t len = s.length();
        map<char, size_t> mp;
        vector<size_t> fac;
        fac.reserve(len);

        // Count frequency of each character
        for (char &c : s) {
            mp[c]++;
        }

        // Store the frequencies in a vector
        for (auto &x : mp) {
            fac.push_back(x.ss);
        }

        // Calculate factorial of len mod `mod`
        ll ans = 1;
        for (ll f = 2; f <= len; ++f) {
            ans = (ans * f) % mod;
        }

        // Divide by the factorials of the frequencies using modular inverse
        for (ll f : fac) {
            ll curr = 1;
            for (ll mul = 2; mul <= f; ++mul) {
                curr = (curr * mul) % mod;
            }
            ans = (ans * mod_inverse(curr, mod)) % mod;
        }

        // Output the result
        cout << (ans % mod) << '\n';
    }

    return 0;
}

