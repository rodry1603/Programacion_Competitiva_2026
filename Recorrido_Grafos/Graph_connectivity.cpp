#include<bits/stdc++.h>
using namespace std;

int parent [26];

int find(int x){
  while(parent[x] != x){
    parent[x] = parent[parent[x]];
    x = parent[x];
  }
  return x;
}

void unite(int a, int b){
  a = find(a);
  b = find(b);
  if(a!=b) parent[a] = b;
}

int main(){
  int t;
  string line;
  getline(cin,line);
  t = stoi(line);
  getline(cin,line);

  for(int cases = 0; cases < t; cases++){
    if(caso > 0) cout << "\n";

    getline(cin,line);
    int n = line[0] - 'A' + 1;

    for(int i = 0; i < n; i++) parent[i] = i;
    int comps = n;

    while(getline(cin,line) && !line.empty()){
      if(line.size()<2)continue;
      int a = find(line[0]-'A');
      int b = find(line[1] -'A');
      if(a != b){
        parent[a] = b;
        comps--;
      }
    }
    cout << comps << "\n";
  }
  return 0;
}
