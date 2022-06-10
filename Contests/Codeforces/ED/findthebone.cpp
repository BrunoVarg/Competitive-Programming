#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall findthebone.cpp -o findthebone

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
    int n, m, k, bone=0; 
    bool pass = false;
    cin>> n>> m>>k;
    vi holes(n, 0);
    vi cup(n, 0);
    cup[0] = 1;
    for(int i=0; i<m; i++){
        int x;
        cin>> x;
        holes[x-1] = 1;
    }
    while(k--){
        int a,b;
        cin>> a>> b;
        if(cup[0]==1 && holes[0]==1)bone=1,pass=true;
        swap(cup[a-1], cup[b-1]);
        if((holes[b-1] == 1 && cup[b-1]==1) && (!pass)){
            bone = b;
            pass=true;
        }else if((holes[a-1] == 1 && cup[a-1]==1) && (!pass)){
            bone = a;
            pass=true;
        }
    }
    if(!pass){
        for(int i=0; i<n; i++){
            if (cup[i] == 1){
                cout<< i+1<<endl;
                return 0;
            }
        }
    }else{
        cout<<bone<<endl;
    }
    return 0;
}