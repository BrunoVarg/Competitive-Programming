int add(int a, int b, int mod) {
  return (a+b)%mod;
}

int sub(int a, int b, int mod) {
  return (a-b+mod)%mod;
}
 
int mul(int a, int b, int mod) {
  return (a*b)%mod;
}

const int mod1 = 1000015187;
const int mod2 = 1000027957;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // random number
//const int base = uniform_int_distribution<int>(356, mod1-1)(rng); // alphabet < base < mod1
const int base = 31;

// use base = 31 to query inv
struct hash_string{
    string s;
    int n;
    vector<int> h1, p1, h2, p2;
    vector<int> hi1, hi2; // inverse, just if necessary

    hash_string(){}
    hash_string(string _s): n(_s.size()), s(_s), h1(n), p1(n), h2(n), p2(n), hi1(n), hi2(n) {
        p1[0] = p2[0] = 1;
        for(int i=1; i<n; i++){
            p1[i] = mul(base, p1[i-1], mod1);
            p2[i] = mul(base, p2[i-1], mod2);
        }
        h1[0] = h2[0] = (int)s[0];
        for(int i=1; i<n; i++){
            h1[i] = add(mul(base, h1[i-1], mod1), (int)(s[i]), mod1);
            h2[i] = add(mul(base, h2[i-1], mod2), (int)(s[i]), mod2);
        }
        // inverse, just if necessary
        hi1[n-1] = hi2[n-1] = (int)s[n-1];
        for(int i=n-2; i>=0; i--){
            hi1[i] = add(mul(base, hi1[i+1], mod1), (int)(s[i]), mod1);
            hi2[i] = add(mul(base, hi2[i+1], mod2), (int)(s[i]), mod2);
        }
    }
    // return integer of 2 hashes [l, r]
    pair<int,int> query(int l, int r){
        if(l == 0) return {h1[r], h2[r]};
        int ret1 = sub(h1[r], mul(h1[l-1], p1[r-l+1], mod1), mod1);
        int ret2 = sub(h2[r], mul(h2[l-1], p2[r-l+1], mod2), mod2);
        return {ret1, ret2};
    }
    // return inverse integer of 2 hashes [l, r]
    pair<int,int> query_inv(int l, int r){
        if(r == n-1) return {hi1[l], hi2[l]};
        int ret1 = sub(hi1[l], mul(hi1[r+1], p1[r-l+1], mod1), mod1);
        int ret2 = sub(hi2[l], mul(hi2[r+1], p2[r-l+1], mod2), mod2);
        return {ret1, ret2};
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
