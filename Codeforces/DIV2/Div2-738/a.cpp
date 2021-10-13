#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall a.cpp -o a

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

int main(){ sws; 

    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        vi v(n);
        int ans = -1;
        for(int i=0;i<n; i++){
            int x;
            cin>>x;
            ans&=x;
        }
        cout<<ans<<endl;
        
    }

    return 0;
}