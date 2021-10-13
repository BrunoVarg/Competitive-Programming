#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall a.cpp -o a

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAX = 1e5+7;
const ll MOD = 1e9+7;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//

int main(){ sws; 

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        float min;
        int aux= x;
        if(min<=15){
            cout<<0.00<<endl;
        }else if(min>15 and min<=60){
            aux -=15;
            min = aux*0.10;
            cout<<min<<endl;
        }else if(min>60 and min<=180){
            aux-=60;
            min = (aux*0.08) + 4.5;
            cout<<min<<endl;
        }else if(min>180 and min<=420){
            aux -= 180;
            min = (aux*0.06) + 9.6 + 4.5;
            cout<<min<<endl;
        }else{
            aux -= 420;
            min = (aux*0.02) + 9.6 + 4.5 + 14.4;
            cout<<min<<endl;
        }


        

    }

    return 0;
}