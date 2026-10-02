#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main() {
	string linea;
	while (getline(cin, linea)) {
		stringstream ss(linea);
		vector<pair<long long, long long>> pila;
		bool ok = true;
		bool existeDato = false;
		long long x;

		while (ss >> x) {
			existeDato = true;
			if (x < 0) {
				pila.push_back({ -x,0 });
			}
			else {
				if (pila.empty() || pila.back().first != x || pila.back().second >= x) {
					ok = false;
				}
				else {
					pila.pop_back();
					if (!pila.empty()) {
						pila.back().second += x;
					}
				}
			}
		}
		if (!existeDato) continue;
		if (!pila.empty()) ok = false;

		cout << (ok ? ": Matrioshka!" : "Try again.") << "\n";
	}

	return 0;
}
