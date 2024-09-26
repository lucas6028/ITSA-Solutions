#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>

using namespace std;

constexpr int MAX_ID = 20;
constexpr int MAX_ELEMENTS = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    array<vector<string>, MAX_ID + 1> img;
    
    for (int t = 0; t < n; ++t) {
        int id, tot;
        string s;
        cin >> id >> tot >> s;

        auto& row = img[id];
        row.reserve(min(tot, MAX_ELEMENTS));

        for (int i = 0; i < min(10, tot); ++i) {
            row.emplace_back(s.substr(i * 3, 3));
        }

        for (int i = 0; i + 10 < tot && i < 10; ++i) {
            row.emplace_back(s.substr(i * 3 + 1, 3));
        }
    }

    unordered_map<int, string> cache;
    int id, col;

    while (cin >> id >> col) {
        if (id == 0 && col == 0) break;

        int key = id * 1000 + col;
        auto it = cache.find(key);

        if (it != cache.end()) {
            cout << it->second << '\n';
            continue;
        }

        string result;
        if (id > MAX_ID || img[id].empty() || col > img[id].size()) {
            result = "Not Found";
        } else {
            result = (col < 10 ? "00" : "0") + 
                     to_string(col) + "_" + img[id][col - 1] + ".jpg";
        }

        cache[key] = result;
        cout << result << '\n';
    }

    return 0;
}
