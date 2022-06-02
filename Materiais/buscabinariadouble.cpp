#include <bits/stdc++.h>
using namespace std;
//g++ -std=c++17 -O2 -Wall run.cpp -o run
 
#define endl "\n"
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define input(x) for (auto &it : x) cin >> it
#define print(x) for (auto &it : x) cout << it << ' '; cout<<endl;
#define dbg(msg, x) cout << msg << " = " << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define TETO(a, b) ((a) + (b-1))/(b)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const float PI = 3.1415;
const ll MOD = 32768;
const int MAX = 1e5+1;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 0.0000001;
//----------------------------------//
//         Fé que o AC vem          //
//----------------------------------//
vector<int> v(100001);
int n;
ll check(double x){
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += (v[i]/x);
    }
    return sum;
}

int main(){ sws;
    
    int k;
    cin>>n>>k;
	
    for(int i=0; i<n; i++)cin>>v[i];

    double l=0.0000000, r=10000000.0000000;
    double mid;
    while(r-l>EPS){
        mid = (double)((l + r)/2);
        if (check(mid)>=k){
            l=mid;
        }
        else{
            r = mid;
        }
            
    }

    cout<<fixed<<setprecision(7)<<mid<<endl;

    
    return 0;
}