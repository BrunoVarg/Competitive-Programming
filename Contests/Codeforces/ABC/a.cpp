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
#define ff first
#define ss second
#define pii pair<int,int>
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

int main(){ sws; 

    int s, t;
    cin>>s >> t;
    int counts=0, countt=0;

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            for(int k=0; k<s; k++){
                if(i+j+k<=s){
                    counts++;
                }
                if(i*j*k<=t){
                    countt++;
                }
            }
        }
    }

    

    return 0;
}