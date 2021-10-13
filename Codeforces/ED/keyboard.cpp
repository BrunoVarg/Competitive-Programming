#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall keyboard.cpp -o keyboard

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

    map<char,char> m;
    string s1;
    string s2;
    cin>> s1;
    cin>> s2;
    for(int i=0; i<26; i++){
        m.insert(mp(s1[i], s2[i]));
    }
    string x;
    cin>> x;
    for(int i=0; i<x.size(); i++){
        bool upper=false;
        if(isupper(x[i])){
           upper=true; 
           x[i]+=32;
        }

        auto y = m.find(x[i]);
        if(y == m.end()){
            cout<<x[i];
        }else{
            auto elem = y->second;
            if(upper){
                elem-=32;
                cout<< elem;
            }else{
                cout<< elem;
            }

        }
    }

    return 0;
}