#include<bits/stdc++.h>
using namespace std;

int power (int m){
  int r = 10;
  while(m--){
    r *= 10;
  }
  return r;
}

int period (int m){
  if (m == 1) return 60;
  if (m == 2) return 300;
  if (m == 3) return 1500;
  return 15000;
}

int main (){
  int T;
  cin >> T;
  while(T--){
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int mod = power(m);
    int Period = period(m);
    int idx = n % period;

    if(idx == a){
      cout << (a % mod) << "\n";
      continue;
    }
    if (idx == b){
      cout << (b % mod) << "\n";
      continue;
    }
    int prev = a % mod;
    int act = b % mod;
    for(int i = 2; i <= idx; i++){
      int next = (prev + act) % mod;
      prev = act;
      act = next;
    }

    cout << act << "\n";
  }

  return 0;
}
