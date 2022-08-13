#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall run.cpp -o run

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
#define loop(i,a,n) for(int i=a; i < n; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll MOD = 1e9+7;
const int MAX = 1e4+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
int n;
bool visited[MAX];
bool visited2[MAX];
int entrada[MAX];
vector<int> adj[MAX];
vector<int> adj2[MAX];
stack<int> st;
vector<int> v;
int conta=0;
void dfs(int x){
    if(visited[x]) return;
    conta++;
    //cout<<x<<", d = "<<conta<<endl;
    visited[x] = true;
    for(auto v : adj[x]){
        dfs(v);
    }
    conta++;
    //cout<<x<<", f = "<<conta<<endl;
    st.push(x);
    v.pb(x);
}

void dfs2(int x){
    if(visited2[x]) return;
    //cout<<x<<", d = "<<conta<<endl;
    visited2[x] = true;
    for(auto v : adj2[x]){
        dfs2(v);
    }
    //cout<<x<<", f = "<<conta<<endl;
    v.pb(x);
}
int main(){ sws; 
    int m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        entrada[b]++;
        adj[a].pb(b);
        adj2[b].pb(a);
    }

    for(int i=1; i<=n; i++){
        dfs(i);
    }
    cout<<"stack"<<endl;
    print(v);
    vector<vector<int>> ans;
    while(!st.empty()){
        int vertice = st.top();
        dfs2(vertice);
        print(v);
        ans.pb(v);
        v = {};
        st.pop();
    }

    for(auto lista : ans){
        print(lista);
    }

    return 0;
}