#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall andryusha.cpp -o andryusha

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

    int n, maior=0;
    cin>> n;
    map<int,int> m;

    for(int i=0; i<n*2; i++){
        int x;
        cin>> x;
        if(m.find(x)!=m.end()){
            m.erase(m.find(x));
            
        }else{
            m.insert(mp(x,1));
            if(m.size()>maior){
                maior=m.size();
            }
        }
    }

    cout<<maior<<endl;

    return 0;
}