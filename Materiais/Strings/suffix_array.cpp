#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sws ios::sync_with_stdio(false);cin.tie( NULL);cout.tie(NULL);
#define print(x) for (auto &it : x) cout<<it<<' ';<<cout<<endl;
#define loop(i,a,n) for(int i=a; i < n; i++) 
#define pb(x) push_back(x);
#define vi vector<int>
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define pqi priority_queue<int, vector<int>, greater<int>>
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

vector<int> suffix_array(string s) {
    s += "$";
    int n = s.size(), N = max(n, 260);
    vector<int> sa(n), ra(n);
    for (int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
 
    for (int k = 0; k < n; k ? k *= 2 : k++) {
        vector<int> nsa(sa), nra(n), cnt(N);
 
        for (int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
        for (int i = 1; i < N; i++) cnt[i] += cnt[i-1];
        for (int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];
 
        for (int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
            ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
        ra = nra;
        if (ra[sa[n-1]] == n-1) break;
    }
    return vector<int>(sa.begin()+1, sa.end());
}
 
vector<int> kasai(string s, vector<int> sa) {
    int n = s.size(), k = 0;
    vector<int> ra(n), lcp(n);
    for (int i = 0; i < n; i++) ra[sa[i]] = i;
 
    for (int i = 0; i < n; i++, k -= !!k) {
        if (ra[i] == n-1) { k = 0; continue; }
        int j = sa[ra[i]+1];
        while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
        lcp[ra[i]] = k;
    }
    return lcp;
}


int32_t main(){
    sws;
    string s;
    cin>>s;
    
    vector<int> suf = suffix_array(s);
    vector<int> lcp = kasai(s, suf);
    
    ll ans = 0;
    for(int i=0; i<s.size(); i++){
        if(islower(s[suf[i]])){
            int sz = s.size()-suf[i];
            ans += (sz - lcp[i]);
        }
    }
    cout<<ans<<endl;
}