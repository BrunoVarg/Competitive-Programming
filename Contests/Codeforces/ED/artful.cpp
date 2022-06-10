#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall artful.cpp -o artful

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


    int n, pares=0;
    cin>> n;
    vi x(n);
    vi y(n);

    map<int,int> m;

    for(int i=0; i<n; i++){
        cin>> x[i];
        m.insert(mp(x[i], 1));
    }
    for(int i=0; i<n; i++){
        cin>> y[i];
        m.insert(mp(y[i], 1));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((m.find(x[i]^y[j])) != m.end()){
                pares++;
            }
        }
    }
    if(pares%2==0){
        cout<< "Karen"<<endl;
    }else{
        cout<< "Koyomi"<<endl;
    }


    return 0;
}