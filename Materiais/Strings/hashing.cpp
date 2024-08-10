inline int add(int a, int b, int mod){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a, int b, int mod){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a, int b, int mod){return (a*b)%mod;}

const int mod1 = 1000015187;
const int mod2 = 1000027957;
// outros primos: 1000041323, 1000015553, 1000028537, 50331653
// mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // random number
// const int base = uniform_int_distribution<int>(356, mod1-1)(rng); // alphabet < base < lowest_mod
const int base = 31;
struct HS {
    int n;
    vector<int> s, t, h1, h2, hi1, hi2, p1, p2;
    template<typename T>
    HS(T x) : n(x.size()), s(x.begin(), x.end()), t(x.rbegin(), x.rend()),
               h1(n), h2(n), hi1(n), hi2(n), p1(n), p2(n) {
        for (auto& it : s) it += 1;
        for (auto& it : t) it += 1;
        p1[0] = p2[0] = 1;
        h1[0] = h2[0] = s[0];
        hi1[0] = hi2[0] = t[0];
        for (int i = 1; i < n; ++i) {
            p1[i] = mul(base, p1[i-1], mod1);
            p2[i] = mul(base, p2[i-1], mod2);
 
            h1[i] = add(mul(base, h1[i-1], mod1), s[i], mod1);
            h2[i] = add(mul(base, h2[i-1], mod2), s[i], mod2);
 
            hi1[i] = add(mul(base, hi1[i-1], mod1), t[i], mod1);
            hi2[i] = add(mul(base, hi2[i-1], mod2), t[i], mod2);
        }
    }
 
    int query(int l, int r, bool inv = false) const {
        const auto& hs1 = inv ? hi1 : h1;
        const auto& hs2 = inv ? hi2 : h2;
        int h1_val = (l == 0) ? hs1[r] : sub(hs1[r], mul(hs1[l-1], p1[r-l+1], mod1), mod1);
        int h2_val = (l == 0) ? hs2[r] : sub(hs2[r], mul(hs2[l-1], p2[r-l+1], mod2), mod2);
        return h1_val ^ (h2_val << 29);
    }
 
    int query_inv(int a, int b) const {
        return query(n - b - 1, n - a - 1, true);
    }
};
