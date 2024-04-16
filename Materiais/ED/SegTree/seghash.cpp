const int mod1 = 1000015187;
const int mod2 = 1000027957;

struct Node{
    int m1, m2;
    Node(int val1=-1, int val2=-1){
        if(val1 != -1){
            val1 %= mod1;
            val2 %= mod2;
        }
        this->m1 = val1;
        this->m2 = val2;
    }
    Node operator+(const Node &o) const{ return {(m1+o.m1)%mod1, (m2+o.m2)%mod2};}
    Node operator*(const Node &o) const{ return {(m1*o.m1)%mod1, (m2*o.m2)%mod2};}
    bool operator==(const Node &o) const{return m1==o.m1 and m2==o.m2;}
};

struct SegTreeHash{
    int n;
    vector<int> v;
    vector<Node> tree, pw;

    // p = 31, 53, 59
    int p = 31;

    SegTreeHash(string &s){
        this->n=s.size();
        v.assign(n, 0);
        for(int i=0; i<n; i++) v[i] = (int)s[i];
        tree.assign(4*n, Node());
        pw.assign(4*n, Node());
        pw[0] = Node(1, 1);
        for(int i=1; i<pw.size(); i++) pw[i] = pw[i-1] * Node(p, p);
        build(0, n-1, 1);
    }

    Node merge(Node a, Node b, int sz){
        if(a == Node()) return b;
        if(b == Node()) return a;
        return (a + b * pw[sz]);
    }

    void build(int l, int r, int no){
        if(l==r){
            tree[no] = Node(v[l], v[l]);
            return;
        }
        int mid = l + (r-l)/2;
        build(l, mid, 2*no);
        build(mid+1, r, 2*no+1);
    
        tree[no] = merge(tree[2*no], tree[2*no+1], mid-l+1);
    }

    void update(int idx, int x, int l, int r, int no){
        if(l == r){
            tree[no] = Node(x, x);
            return;
        }
        int mid = l + (r-l)/2;
    
        if(idx <= mid) update(idx, x, l, mid, 2*no);
        else update(idx, x, mid+1, r, 2*no+1);
        tree[no] = merge(tree[2*no], tree[2*no+1], mid-l+1);
    }

    Node query(int A, int B, int l, int r, int no){
        if(B<l or r<A) return Node();
        if(A<=l and r<=B) return tree[no];
        int mid = l + (r-l)/2;
        return merge(query(A, B, l, mid, 2*no), query(A, B, mid+1, r, 2*no+1), mid - max(A, l) + 1);
    }
        
    Node query(int l, int r){return query(l, r, 0, n-1, 1);}
    void update(int idx, char val){update(idx, (int)val, 0, n-1, 1);}
};