#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall d.cpp -o d

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//

int main(){ sws; 

    string s;
    cin>>s;
    int len = s.size();
    ll a=0, b=0;
    for(int i=0; i<len-4; i++){
        if(s.substr(i,5) == "heavy") a++;
        else if(s.substr(i,5)=="metal")b+=a;
    }
    //print(s.substr(0,5));
    cout<<b<<endl;

    return 0;
}