// BUSCA BINÁRIA USANDO DOUBLE

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAX = 1e5+1;
const double EPS = 0.0000001;

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
