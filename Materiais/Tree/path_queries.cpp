#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define sws ios::sync_with_stdio(false);cin.tie( NULL);cout.tie(NULL);
#define loop(i,a,n) for(int i=a; i < n; i++) 
#define pb(x) push_back(x);
#define vi vector<int>
#define mp(x,y) make_pair(x,y)
#define print(x,y) loop(i,0,y){cout << x[i] << " ";} cout << "\n";
#define pii pair<int,int>
 
const int N = 2e5+10;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 2e5+10;
 
ll n, T = 0, a[MAX], path[MAX], valor[MAX], in[MAX], out[MAX], preorder[MAX];
 
vector<ll> tree[MAX];
 
class SegTree{
    private:
        ll st[4*MAX], lazy[4*MAX];
 
        ll merge(ll a, ll b){
            return max(a,b);
        }
 
        void push(int i, long long x = 0){
            st[i] += (lazy[i]+x);
            if(2*i < 4*MAX) lazy[2*i] += (lazy[i]+x);
            if(2*i+1 < 4*MAX) lazy[2*i+1] += (lazy[i]+x);
            lazy[i] = 0;
        }
 
    public:
        void build(int i = 1, int l = 0, int r = n-1){
            if(l == r){
                st[i] = a[l]; //leaf node.
                lazy[i] = 0;
            }
            else{
                int mid = (r+l)/2;
                lazy[i] = 0;
                build(2*i, l, mid);
                build(2*i + 1, mid+1, r);
                st[i] = merge(st[2*i], st[2*i + 1]); //parent node.
            }
            return; 
        }
 
        ll query(int l, int r, int i = 1, int auxl = 0, int auxr = n-1){
            if(l <= auxl && r >= auxr){ //total overlap.
                if(lazy[i]){
                    push(i);
                }
                return st[i];
            }
            else if(auxr < l || auxl > r){ //no overlap.
                return 0;
            }
            else{ //partial overlap
                int auxmid = (auxr+auxl)/2;
                push(i);
                return merge(query(l, r, 2*i, auxl, auxmid), query(l, r, 2*i + 1, auxmid+1, auxr));
            }
        }
 
        void update(int l, int r, ll x, int i = 1, int auxl = 0, int auxr = n-1){
            if(l <= auxl && auxr <= r){ //total overlap.
                push(i,x);
            }
            else if(auxr < l || auxl > r){ //no overlap.
                return;
            }
            else{ //partial overlap
                int auxmid = (auxr+auxl)/2;
                update(l, r, x, 2*i, auxl, auxmid);
                update(l, r, x, 2*i + 1, auxmid+1, auxr);
                st[i] = merge(st[2*i],st[2*i+1]);
            }
        }
};
 
void dfs(int u, int p){
    path[u] += (path[p] + valor[u]);
    preorder[++T] = u; //preorder
    a[T-1] = path[u];
    in[u] = T;
    for(auto v: tree[u]){
        if(v != p){
            dfs(v,u);
        }
    }
    out[u] = T;
}
 
int main(){
    sws;
    int q; cin >> n >> q;
    SegTree seg;
    loop(i,1,n+1){
        int a; cin >> a;
        valor[i] = a;
    }
    loop(i,0,n-1){
        int u, v; cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1,0);
    seg.build();
    while(q--){
        int op; cin >> op;
        if(op == 1){
            ll u, x; cin >> u >> x;
            seg.update(in[u]-1,out[u]-1,x-valor[u]);
            valor[u] = x;
        }
        else{
            int u; cin >> u;
            cout << seg.query(in[u]-1,in[u]-1) << "\n";
        }
    }
}