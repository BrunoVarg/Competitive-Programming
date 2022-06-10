#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -O2 -Wall b.cpp -o b

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
int primes[1000];

int main(){ sws; 

    int q;
    cin>>q;
    for(int i=2; i<100; i++){
        primes[i] = i;
        for(int j=2; j*j<=i; j++){
            if(i%j==0)primes[i]=0;
        }
    }
    while(q--){

        int k;
        cin>>k;
        vi num(k);
        set<int> s;
        vi compos = {0,1,0,0,4,0,6,0,8,9};
        string st;
        cin>>st;
        bool comp = false;
        for(int i=0; i<(int)st.size();i++){
            int x = st[i]-'0';
            num[i] = x;
            for(int j=0; j<(int)compos.size(); j++){
                if(x==compos[j]){
                    comp=true;
                    cout<<1<<endl;
                    cout<<x<<endl;
                    break;
                }
            }
            if(compos)break;
        }
        
        if(!comp){
            for(int i=0; i<k; i++){
                for(int j=i+1; j<k; j++){
                    if(primes[num[i]*10 + num[j]]>0){
                        cout<<2<<endl;
                        cout<<num[i]<<num[j]<<endl;
                    }
                }
            }
        }
    }

    return 0;
}