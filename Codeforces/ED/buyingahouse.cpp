#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall buyingahouse.cpp -o buyingahouse

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

    int n, m, k, menor=101;
    cin >> n >> m >> k;
    vi houses(n,0);
    for(int i=0; i<n; i++){
        int a;
        cin>> a;
        houses[i] = a;
    }

    for(int i=0;i<n; i++){
        if(k >= houses[i] && houses[i]!=0){
            if(abs(i-m+1)<menor){
                menor = abs(i-m+1);
            }
        }
    }

    menor*=10;
    cout<<menor<<endl;

    return 0;
}