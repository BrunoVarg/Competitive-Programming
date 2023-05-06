// utiliza-se convexhull tricky geralmente para dp O(n²), onde para cada elemento, percorre os elementos anteriores à ele.
// o objetivo é iterar pelo j e transformar o i em constante para criar retas e assim, encontrar o max. ou min.
// convex foi feito para achar o max, caso queira o min. troque o sinal de todos os j's
// reta ax + b, onde x é em função de i. Transforma em um for só, onde os i's já são atribuidas em dp[i] e soma-se à ela o cht.eval(x da reta)
// logo depois, faz cht.insert_line(a da reta, b da reta)

// algoritmo
const ll is_query = -(1LL<<62);
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line> { // will maintain upper hull for maximum
    const ll inf = LLONG_MAX;
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

		/* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m) v1 = x->b > y->b ? inf : -inf;
        else v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m) v2 = y->b > z->b ? inf : -inf;
        else v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((line) { x, is_query });
        return l.m * x + l.b;
    }
};


// antes do convex
    vll dp(n+1, LLINF);
    for(int i=1; i<=n; i++){
        ll x, a, b; tie(x, a, b) = v[i];
        ll ans = LLINF; dp[i] = x*b + a;
        for(int j=i-1; j>=1; j--){
            ll x_bef, a_bef, b_bef; tie(x_bef, a_bef, b_bef) = v[j];
            ll val = -x_bef * b;
            ans = min(ans, val + dp[j]);
        }
        dp[i] = min(dp[i], ans + x*b + a);
    } 
 
    return 0;
}


// depois do convex
    cht.insert_line(0, 0); // primeiro valor (no caso dessa questao exemplo eh 0, 0)

    for(int i=1; i<=n; i++){
        ll x, a, b; tie(x, a, b) = v[i];
        dp[i] = x * b + a - cht.eval(b);
        cht.insert_line(x, -dp[i]);
    }
