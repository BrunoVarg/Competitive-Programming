#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall a.cpp -o a

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

    int n;
    cin>> n;
    while(n--){
        int t, i=1, j=1, num=1;
        cin>>t;
        while(num<=t){
            if(num==t)break;
            if(num+2 <=t){
                i+=2;
                num+=i;
                j++;
            }else{
                i+=1;
                num+=i;
                j++;
            }
        }
        cout<< j <<endl;
    }

    return 0;
}