//Seg Tree. Considering I = 1, L = 0 and R = N-1; I is the first index in st.
class SegTree{
    private:
        ll st[4*MAX], lazy[4*MAX];

        ll merge(ll a, ll b){
            return min(a,b);
        }

        void push(int i, long long x = 0){
            st[i] += (lazy[i]+x);
            if(2*i < 4*MAX) lazy[2*i] += (lazy[i]+x);
            if(2*i+1 < 4*MAX) lazy[2*i+1] += (lazy[i]+x);
            lazy[i] = 0;
        }

    public:
        void build(int i = 1, int l = 0, int r = n-1){
            if(l == r){
                st[i] = a[l]; //leaf node.
                lazy[i] = 0;
            }
            else{
                int mid = (r+l)/2;
                lazy[i] = 0;
                build(2*i, l, mid);
                build(2*i + 1, mid+1, r);
                st[i] = merge(st[2*i], st[2*i + 1]); //parent node.
            }
            return; 
        }
 
        ll query(int l, int r, int i = 1, int auxl = 0, int auxr = n-1){
            if(l <= auxl && r >= auxr){ //total overlap.
                if(lazy[i]){
                    push(i);
                }
                return st[i];
            }
            else if(auxr < l || auxl > r){ //no overlap.
                return LLINF;
            }
            else{ //partial overlap
                int auxmid = (auxr+auxl)/2;
                push(i);
                return merge(query(l, r, 2*i, auxl, auxmid), query(l, r, 2*i + 1, auxmid+1, auxr));
            }
        }
 
        void update(int l, int r, ll x, int i = 1, int auxl = 0, int auxr = n-1){
            if(l <= auxl && auxr <= r){ //total overlap.
                push(i,x);
            }
            else if(auxr < l || auxl > r){ //no overlap.
                return;
            }
            else{ //partial overlap
                int auxmid = (auxr+auxl)/2;
                update(l, r, x, 2*i, auxl, auxmid);
                update(l, r, x, 2*i + 1, auxmid+1, auxr);
                st[i] = merge(st[2*i],st[2*i+1]);
            }
        }
};

int main(){
    int q; cin >> n >> q;
    SegTree seg;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    seg.build();
    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 1){
            int l, r, x; cin >> l >> r >> x;
            seg.update(l-1,r-1,x);
        }
        else{
            int k; cin >> k;
            cout << seg.query(k-1,k-1) << "\n";
        }
    }        
}
