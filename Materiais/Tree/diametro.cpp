// Acha o caminho mais longo de uma ponta ate outra ponta de uma arvore
// Complexidade: O(N)
// Lembrar de checar N == 1, diametro = 0
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;

vector<int> adj[MAX];
/*pair<int, int> bfs(int s, int N){
    vi dist(N + 1, MAX); dist[s] = 0;
    queue<int> q; q.push(s);
    int last = s;

    while(!q.empty()){
        auto u = q.front();q.pop();
        last = u;
        for(auto v: adj[u]){
            if(dist[v]==MAX){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return {last, dist[last]};
}

int diameter_bfs(int N){
    auto [v, _] = bfs(1, N);
    auto [w, D] = bfs(v, N);

    return D;
}*/

void dfs(int u, int p, vector<int> &dist){
  for(auto v : adj[u]){
    if(v == p) continue;
    dist[v] = dist[u] + 1;
    dfs(v, u, dist);
  }
}

int diameter(int n){
  vector<int> dist(n+1);
  dfs(1, 0, dist);
  // get farthest node from root
  auto v = (int)(max_element(dist.begin(), dist.end()) - dist.begin());
  // start from farthest node
  dist[v] = 0;
  dfs(v, 0, dist);
  return *max_element(dist.begin(), dist.end());
}

int32_t main(){ sws;
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
      int a, b;
      cin>>a>>b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    if(n == 1) cout<<0<<endl;
    else cout<<diameter(n)<<endl;
    return 0;
}

