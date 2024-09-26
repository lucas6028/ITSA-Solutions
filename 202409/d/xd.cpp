#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

        vector<string> row(min(tot, 20));  // Resize to either tot or 20 elements (to avoid unnecessary space)

        // Fill the first 10 elements (if they exist)
        for (int i = 0; i < min(10, tot); ++i) {
            row[i] = s.substr(i * 3, 3);
        }

        // Fill the remaining elements starting from index 10 (if they exist)
        for (int i = 0; i + 10 < tot && i < 10; ++i) {
            row[i + 10] = s.substr(i * 3 + 1, 3);
        }

        img[id] = move(row);  // Use move semantics to avoid copying
    }

    int id, col;
    while (cin >> id >> col) {
        if (id == 0 && col == 0) break;

        // Check for invalid id or column
        if (img[id].empty() || col - 1 >= img[id].size()) {
            cout << "Not Found\n";
        } else {
            // Print the result with leading zeros for id
            if (id > 9) {
                cout << "0";
            } else {
                cout << "00";
            }
            cout << col << "_" << img[id][col - 1] << ".jpg\n";
        }
    }

    return 0;
}

