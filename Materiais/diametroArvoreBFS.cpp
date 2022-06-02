#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall x.cpp -o x

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define dbg(msg, x) cout << msg << " = " << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+10;
const ll MOD = 1e9+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//

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