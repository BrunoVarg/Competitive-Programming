// DIAMETRO ARVORE - BFS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+10;
const ll MOD = 1e9+5;

vector<int> adj(MAX);

pair<int, int> bfs(int s, int N){

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

int diameter(int N){
    auto [v, _] = bfs(1, N);
    auto [w, D] = bfs(v, N);

    return D;
}
