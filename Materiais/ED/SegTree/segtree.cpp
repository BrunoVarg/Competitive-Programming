// Build: O(N)
// Queries: O(log N)
// Update: O(log N)

// indexada em 0

class SegTree{
    int n, elem_neutro = 0;
    vector<int> tree, lazy, v;

    int merge(int a, int b){
        return a+b; //seg de soma
    }

    void build(int l, int r, int no){
        if(l==r){
            tree[no] = v[l];
            return;
        }
        int mid = (l+r)/2;
        build(l, mid, 2*no);
        build(mid+1, r, 2*no+1);
    
        tree[no] = merge(tree[2*no], tree[2*no+1]);
    }

    void update(int A, int B, int x, int l, int r, int no){
        prop(l, r, no);
        if(B<l or r<A) return;
        if(A<=l and r<=B){
            lazy[no] += x; //update de soma
            prop(l, r, no);
            return;
        }
        int mid = (l+r)/2;
    
        update(A, B, x, l, mid, 2*no);
        update(A, B, x, mid+1, r, 2*no+1);
        
        tree[no] = merge(tree[2*no], tree[2*no+1]);
    }

    void prop(int l, int r, int no){
        if(lazy[no]!=0){
            tree[no] += (r-l+1)*lazy[no]; //update de soma
            if(l!=r){
                lazy[2*no] += lazy[no]; //update de soma
                lazy[2*no+1] += lazy[no]; //update de soma
            }
            lazy[no] = 0;
        }
    }

    int query(int A, int B, int l, int r, int no){
        prop(l, r, no);
        if(B<l or r<A) return elem_neutro;
        if(A<=l and r<=B) return tree[no];
        int mid = (l+r)/2;
    
        return merge(query(A, B, l, mid, 2*no),
                    query(A, B, mid+1, r, 2*no+1));
    }

    public:
        SegTree(vector<int> &v){
                this->n=v.size();
                this->v=v;
                tree.assign(4*n, 0);
                lazy.assign(4*n, 0);
                build(0, n-1, 1);
            }
        int query(int l, int r){return query(l, r, 0, n-1, 1);}
        void update(int l, int r, int val){update(l, r, val, 0, n-1, 1);}
        void out(){for(int i=0; i<n; i++){cout<<query(i, i)<<" ";cout<<endl;}}
};

int32_t main(){ 
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    SegTree seg(v);
    while(q--){
        int op; cin>>op;
        if(op == 1){
            int l, r, val;
            cin>>l>>r>>val;
            l--; r--;
            seg.update(l, r, val);
        }else{
            int idx;
            cin>>idx;
            idx--;
            cout<<seg.query(idx, idx)<<endl;
        }
    }
    return 0;
}
