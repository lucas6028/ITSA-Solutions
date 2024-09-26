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

    int n;
    cin >> n;
    double ans = n * 0.9;
    if (n > 800.0 && n < 1500.0) {
        ans *= 0.9;
    }
    else if (n >= 1500.0) {
        ans *= 0.79;
    }
    printf("%.1f\n", ans);


	return 0;
}
