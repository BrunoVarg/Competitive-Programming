#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall mike.cpp -o mike
 
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
 
    int conta=0;
    string s;
    cin>> s;
    int len = s.size();
    for(int i=0; i<len/2; i++){
        if(s[i]!=s[len-1-i]){
            conta++;
        }
    }
    if(conta==1 || (conta==0 && len%2!=0)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
 
    return 0;
}