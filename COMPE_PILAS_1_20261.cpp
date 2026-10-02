#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int LongIncreaseSequence(const string &s) {
	vector<char> tails;
	for (char c : s) {
		auto it = lower_bound(tails.begin(), tails.end(), c);
		if (it == tails.end()) {
			tails.push_back(c);
		}
		else {
			*it = c;
		}
	}

	return (int)tails.size();
}

int main() {
	string line;
	int contador = 1;
	while (cin >> line) {
		if (line == "end") break;
		if (line.empty()) continue;
		int ans = LongIncreaseSequence(line);
		cout << "Case " << contador << ": " << ans << "\n";
		contador++;
	}

	return 0;
}