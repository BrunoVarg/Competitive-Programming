#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall d.cpp -o d

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
class SegTree{
    vector<int> st;
    int size;

    int el_neutro = -(1e9 + 7);

    int f(int a, int b){
        return max(a,b);
    }

    int query(int sti, int stl, int str, int l, int r){
        if(str < l || r < stl) 
            return el_neutro;

        if(stl >= l and str <= r)
            return st[sti];

        int mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }

    void update(int sti, int stl, int str, int i, int amm){
        if(stl == i and str == i){
            st[sti] = amm;
            return;
        }
        if(stl > i or str < i)
            return;
        
        int mid = (stl + str)/2;

        update(sti*2+1,stl,mid,i,amm);
        update(sti*2+2,mid+1,str,i,amm);
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }
    public:
        SegTree(int n):  st(4*n,0){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update(int i, int amm){update(0,0,size-1,i,amm);}
};
bool check(vi v, int valor, int x) {
    return v[valor] <= x;
}

int binary_search(vi v, int a, int b, int x){
    int l = a;
    int r = b;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!check(v, mid, x)) r = mid;
        else l = mid + 1;
    }
    return l;
}


int main(){ sws; 

    int n, s;
    cin >> n >> s;
    vi v(n);
    vi res(n);
    SegTree st(n);
    SegTree st2(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        st.update(i, v[i]);
    }
    for(int i=0; i<n; i++){
        st2.update(i, v[n-i-1]);
    }

    for(int i=0; i<n; i++){
        int val = v[i]-s;
        int l = i+1,r = n;
        
        while(l<r){
            int mid = (l+r)/2;
            if(st.query(i+1, mid)>val) r = mid;
            else l = mid+1;
        }
        res[i] = l-i-1;

        // (n-i-1) = i inverso
        l = (n-i-1)+1;
        r = n;

        while(l<r){
            int mid = (l+r)/2;
            if(st2.query((n-i-1)+1, mid)>val) r = mid;
            else l = mid+1;
        }

        res[i] += l-(n-i-1)-1;
    }

    for(int i=0; i<n; i++){
        cout << res[i]<<" ";
    }

    return 0;
}