const int MAX = 2e5+20;
vector<int> lazy(4*MAX, 0);
int tree[4*MAX], vet[MAX];
int n;
 
int merge(int a, int b){
    return a + b; //seg de soma
}
 
void build(int l=0, int r=n-1, int no=1){
    if(l==r){
        tree[no] = vet[l];
        lazy[no] = 0;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*no);
    build(mid+1, r, 2*no+1);
 
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
 
void update(int A, int B, int x, int l=0, int r=n-1, int no=1){
    prop(l, r, no);
    // caso 1
    if(B<l or r<A) return;
    // caso 2
    if(A<=l and r<=B){
        lazy[no] += x; //update de soma
        prop(l, r, no);
        return;
    }
    // caso 3
    int mid = (l+r)/2;
 
    update(A, B, x, l, mid, 2*no);
    update(A, B, x, mid+1, r, 2*no+1);
    
    tree[no] = merge(tree[2*no], tree[2*no+1]);
}
 
int query(int A, int B, int l=0, int r=n-1, int no=1){
    prop(l, r, no);
    // caso 1
    if(B<l or r<A) return 0;
    // caso 2
    if(A<=l and r<=B) return tree[no];
    // caso 3
    int mid = (l+r)/2;
 
    return merge(query(A, B, l, mid, 2*no),
                 query(A, B, mid+1, r, 2*no+1));
}
 
 
int32_t main(){
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin >> vet[i];
    build();
    while(q--){
        int opt; cin>>opt;
        if(opt == 1){
            int l, r, u;
            cin>>l>>r>>u;
            l--; r--;
            update(l, r, u);
        }else{
            int k; cin>>k;
            k--;
            cout<< query(k, k)<<endl;
        }
    }
    return 0;
}
