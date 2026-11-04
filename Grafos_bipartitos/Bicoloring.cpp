#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, l;
  while(cin >> n && n != 0){
    cin >> l;
    vector<vector<int>> graph(n);
    int a, b;
    for(int i = 0; i < l; i++){
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    vector<int> color(n, -1);
    bool isBicoloring = true;
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while(!q.empty() && isBicoloring){
      int node = q.front();
      q.pop();
      for(int vecino : graph[node]){
        if(color[vecino] == color[node]){
          color[vecino] = 1 - color[node];
          q.push(vecino);
        }else if(color[vecino] == color[node]){
          isBicoloring = false;
          break;
        }
      }
    }
    if(isBicoloring){
      cout << "BICOLORABLE" << "\n";
    }else{
      cout << "NOT BICOLORABLE" << "\n";
    }
  }
  return 0;
}
