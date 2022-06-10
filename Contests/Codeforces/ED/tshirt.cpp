#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall tshirt.cpp -o tshirt

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define ll long long
#define all(x) begin(x), end(x)
#define le(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
const int MAX = 2*1e5+7;
const int MOD = 1e9+7;


int main(){ sws; 

    int n;
    cin>> n;
    
    // [<price<color1,color2>>]
    vector<pair<long long, pair<int,int>>> tshirt(n);
    for(int i=0; i<n; i++){
        ll x;
        cin>> x;
        tshirt[i].first=x;
    }

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        tshirt[i].second.first = x;
    }
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        tshirt[i].second.second = x;
    }
    sort(tshirt.begin(),tshirt.end());

    int b;
    cin>>b;
    for(int i=0; i<b; i++){
        int x;
        cin>>x;
        bool without=true;
        for(int j=0; j<n; j++){
            if(tshirt[j].first!=0){
                if((tshirt[j].second.first==x) || (tshirt[j].second.second==x)){
                    cout<<tshirt[j].first<<" ";
                    tshirt[j].first=0;
                    without=false;
                    break;
                }
            }
        }
        if(without){
            cout<<-1<<" ";
        }
    }


    return 0;
}