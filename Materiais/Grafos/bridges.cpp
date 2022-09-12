#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
const int MAX = 1e5+5;

vector<int> adj[MAX];
int timer=0;
int low[MAX], tin[MAX];
bool bridge=false;
bool visited[MAX];

void dfs(int u, int p=-1){
    visited[u] = true;
    low[u] = tin[u] = timer++;
    for(auto v: adj[u]){
        if(v != p){
            if(!visited[v]){
                dfs(v, u);
                if(low[v] > tin[u]) bridge=true; // bridge between v and u
            }
            low[u] = min(low[v], low[u]);
        }
    }
}


int32_t main(){ sws; 
	int n, m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
	    int a, b;
	    cin>>a>>b;
	    
	    adj[a].pb(b);
	    adj[b].pb(a);
	}
	for(int i=1; i<=n; i++){
	    if(!visited[i]) dfs(i);
	}
	if(bridge)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

    return 0;
}
