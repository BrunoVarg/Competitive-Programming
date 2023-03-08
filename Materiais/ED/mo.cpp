int block;
bool comp(tuple<int,int,int> a, tuple<int,int,int> b){
    int l, r, idx, ll, rr, idx2;
    tie(l, r, idx) = a;
    tie(ll, rr, idx2) = b;

    if(l/block != ll/block){
        return l/block < ll/block;
    }
    return (l/block & 1) ? r < rr : r > rr;
}

class MO{
    public:
    vector<int> a;
    int ans = 0;
    vector<int> cnt(1e6+5);
    vector<tuple<int,int,int>> queries;
    
    void add(int x){
        ans -= (cnt[x]*cnt[x])*x;
        cnt[x]++;
        ans += (cnt[x]*cnt[x])*x;
    }

    void del(int x){
        ans -= (cnt[x]*cnt[x])*x;
        cnt[x]--;
        ans += (cnt[x]*cnt[x])*x;
    }
    vector<int> get(){
        vector<int> qans(queries.size());
        sort(all(queries), comp);
        int l=0, r=-1;
        for(auto q: queries){
            int ll, rr, idx;
            tie(ll, rr, idx) = q;
            while(r < rr) add(a[++r]);
            while(l > ll) add(a[--l]);
            while(r > rr) del(a[r--]);
            while(l < ll) del(a[l++]);
            qans[idx] = ans;
        }
        return qans;
    }
    MO(vector<int> a, vector<tuple<int,int,int>> queries){
        this->a = a;
        this->queries = queries;
        block = sqrt((int)a.size());
    }
};

int32_t main(){ sws; 
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<tuple<int,int,int>> queries;
    for(int i=0; i<m; i++){
        int l, r;
        cin>>l>>r;
        queries.push_back({l-1, r-1, i});
    }
    MO mo(a, queries);
    vector<int> ans = mo.get();
    for(int i=0; i<m; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}