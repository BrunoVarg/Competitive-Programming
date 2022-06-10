#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall run.cpp -o run

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main(){ sws; 

    int kir, n;
    cin>> kir >> n;
    vector<pii> vp;
    for(int i=0; i<n; i++){
        int str, bon;
        cin>> str>> bon;
        vp.pb(mp(str, bon));
    }
    sort(all(vp));
    for(int i=0;i<vp.size(); i++){
        if(kir<=vp[i].first){
            cout<<"NO"<<endl;
            return 0;
        }
        kir+=vp[i].second;
    }
    cout << "YES"<<endl;

    return 0;
}