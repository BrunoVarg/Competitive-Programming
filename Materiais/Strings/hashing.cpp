#include <bits/stdc++.h>
using namespace std;

int add(int a, int b, int mod) {
  return (a+b)%mod;
}
 
int sub(int a, int b, int mod) {
  return ((a-b)%mod + mod)%mod;
}
 
int mul(int a, int b, int mod) {
  return (a*b)%mod;
}

int fexp(int b, int e, int mod) {
  if(e == 0) return 1;
  int x = fexp(b, e/2, mod);
  x = mul(x, x, mod);
  if(e%2) x = mul(x, b, mod);

  return x;
}

const vector<int> mods = {
        1000015187, 1000027957//, 1000041323
};
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // random number
const ll base = uniform_int_distribution<int>(356, mods[0]-1)(rng); // alphabet < base < mod1
 
struct hash_string{
    string s;
    ll n;
    vector<vector<int>> hashes, power, inv;

    hash_string(): n(0){}
    hash_string(string _s)
        : n(_s.size()), s(_s), 
        hashes(mods.size(),vector<int>(n)), 
        power(mods.size(),vector<int>(n)),
        inv(mods.size(),vector<int>(n))
        {
        for(int i=0; i<mods.size(); i++){
            power[i][0] = 1, inv[i][0] = 1;
            for(int j=1; j<n; j++){
                power[i][j] = mul(power[i][j-1], base, mods[i]);
            }
            inv[i][n-1] = fexp(power[i][n-1], mods[i]-2, mods[i]);
            for(int j=n-2; j>=0; j--){
                inv[i][j] = mul(inv[i][j+1], base, mods[i]);
            }
            hashes[i][0] = s[0];
            for(int j=1; j<n; j++){
                hashes[i][j] = add(hashes[i][j-1], mul(power[i][j], (int)(s[j]), mods[i]), mods[i]);
            }
        }
    }
    // return vector of hashes [l, r]
    vector<int> query(int l, int r){
        vector<int> get_hashes;
        for(int i=0; i<mods.size(); i++){
            // hashes[r] - hashes[l-1]
            int res = hashes[i][r];
            if(l > 0) res = sub(res, hashes[i][l-1], mods[i]);
            res = mul(res, inv[i][l], mods[i]);
            get_hashes.pb(res);
        }
        return get_hashes;
    }
};

int32_t main(){ sws;
    string a, b;
    cin>>a>>b;
    hash_string hsa(a), hsb(b);
    if(hsa.query(0, a.size()-1) == hsb.query(0, b.size()-1)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}