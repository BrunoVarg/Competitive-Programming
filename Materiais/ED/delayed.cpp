// adiciona elementos em um multiset, e calcula o numero de elementos menor que x no set
// O(raiz(QlogQ))

class Delayed{
    ll q;
    vector<ll> a, delayed;
    public:
    void merge(){
        for(auto x : delayed){
            a.pb(x);
        }
        sort(all(a));
        delayed = {};
    }

    void add(ll x){
        delayed.pb(x);
        if(delayed.size() * delayed.size() > q){
            merge();
        }
    }

    ll get(ll x){
        ll ans = 0;
        ll pos = lower_bound(a.begin(), a.end(), x) - a.begin();
        if(!pos){ans = 0;} else{ans = pos;}
        for(auto it: delayed){
            if(it < x){ans++;}
        }
        return ans;
    }
    
    Delayed(ll q){
        this->q = q;
    }
};
