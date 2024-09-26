#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to calculate the sum of digits of a number
int digits(int n) {
    int sum = 0;
    while (n != 0) { // Change from for loop to while loop
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        vector<int> vc(n, 0);
        for (int i = 0; i < n; ++i) cin >> vc[i];

        // Bubble sort based on the sum of digits and value if sums are equal
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                int d1 = digits(vc[j]);
                int d2 = digits(vc[j + 1]);

                // Sort by the sum of digits
                if (d1 > d2) {
                    swap(vc[j], vc[j + 1]);
                }
                // If sums are equal, sort by the actual values
                else if (d1 == d2) {
                    if (vc[j] > vc[j + 1]) {
                        swap(vc[j], vc[j + 1]);
                    }
                }
            }
        }

        // Print the sorted vector
        for (int i : vc) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}

