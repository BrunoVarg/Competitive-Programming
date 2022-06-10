#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall b.cpp -o b
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
 
int main(){ sws; 
 
    int n;
    ll calc=0;
    cin >> n;
    vi v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(all(v));

    int media = v.size()/2;
    int mediafin;
    if(v.size()%2 != 0){
        mediafin = v[media];
    }else{
        mediafin = (v[media-1]+v[media])/2;
    }
    for(int i=0; i<n; i++){
        calc += abs(v[i]-mediafin);
    }

    cout<<calc<<endl;
    

 
    return 0;
}