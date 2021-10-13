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
const int MAX = 1e5+7;
const ll MOD = 1e9+7;

int main(){ sws; 

    int n;
    cin>> n;
    while(n--){
        ll num;
        cin>> num;
        int num1= num/3;
        int num2;
        if(num%3==0){
            num2 = num1;
        }else{
            num2 = (num/3)+1;
        }

        if((num1 + (num2*2))== num){
            cout<<num1<<" "<<num2<<endl;
        }else if((num2 + (num1*2))==num){
            cout<<num2<<" "<<num1<<endl;
        }

    }

    return 0;
}