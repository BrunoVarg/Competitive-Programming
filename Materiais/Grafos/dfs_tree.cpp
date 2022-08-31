#include <bits/stdc++.h>
using namespace std;


#define int long long
#define endl "\n"
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '; cout<<endl;
#define dbg(msg, x) cout << msg << " = " << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define TETO(a, b) ((a) + (b-1))/(b)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll MOD = 1e9+7;
const int MAX = 2e5+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
vector<int> scores;
vector<int> adj[MAX];
bool visited[MAX];
bool backedge[MAX];
int ans1=0, ans2=0;

bool path_backs(int u, int p){
    // sum all backedges
    visited[u] = true;
    
    bool cycle = false;
    for(auto v: adj[u]){
        if(!visited[v]) cycle |= path_backs(v, u);
        else if(v != p and visited[v]) cycle = true;
    }
    if(cycle) ans1 += scores[u];
    return backedge[u] = cycle;
}

int path_no_backs(int u){
    // max sum no-backedges
    if(visited[u]) return 0;
    visited[u] = true;
    
    int ans = 0;
    for(auto v: adj[u]){
        if(!visited[v]){
            int aux = path_no_backs(v);
            ans = max(ans, aux);
        }
    }
    if(!backedge[u]) ans += scores[u];
    return ans;
}

int32_t main(){ sws;
    
    int n, m;
    cin>>n>>m;
    
    scores.pb(0);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        scores.pb(x);
    }
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int city;
    cin>>city;
    
    path_backs(city, 0);
    memset(visited, 0, sizeof(visited));
    int ans2 = path_no_backs(city);

    cout<<ans1+ans2<<endl;


}