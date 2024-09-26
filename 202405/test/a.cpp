#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	vector<int> vc(10, 0);
	for (int i = 1; i <= 10; ++i) vc[i - 1] = i;
	sort(vc.begin(), vc.end(), cmp);
	//sort(vc.begin(), vc.end());
	for (int i : vc) cout << i << " ";
	cout << "\n";

	return 0;
}
