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
    cin>> n;
    while(n--){
        string s;
        cin>>s;
        map<char,int> m;
        int count1=0;
        int ans=0;
        bool maior=false;
        for(int i=0; i<s.size(); i++){
            char x = s[i];
            if(m.find(x)!=m.end()){
                m.find(x)->second++;
            }else{
                m.insert(mp(x,1));
            }
        }
        for(auto i= m.begin(); i!=m.end();i++){
            if(i->second>3){
                maior=true;
                count1++;
            }
        }
        if(!maior){
            ans= (s.size())/2;
            cout<<ans<<endl;
        }else{
            cout<<count1<<endl;
        }
    }



    return 0;
}