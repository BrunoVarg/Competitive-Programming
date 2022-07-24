#include <bits/stdc++.h>
using namespace std;

class SegTree{
    vector<int> seg;
    int size;
    int elem_neutro = 0;

    int merge(int a, int b){
        return a^b;
    }
    void update(int idx, int val, int stl, int str, int no){
        if(stl == idx and str==idx){
            seg[no] = val;
            return;
        }
        if(stl>idx or str<idx) return;

        int mid = (stl+str)/2;
        update(idx, val, stl, mid, 2*no);
        update(idx, val, mid+1, str, 2*no+1);

        seg[no] = merge(seg[2*no], seg[2*no+1]);
    }

    int query(int l, int r, int stl, int str, int no){
        if(str<l or stl>r) return elem_neutro;
        if(stl>=l and str<=r) return seg[no];

        int mid = (stl+str)/2;
        int x = query(l, r, stl, mid, 2*no);
        int y = query(l, r, mid+1, str, 2*no+1);
        return merge(x, y);
    }
    public:
        SegTree(int n): seg(4*n, 0){size=n;}
        int query(int l, int r){return query(l, r, 0, size-1, 1);}
        void update(int idx, int val){update(idx, val, 0, size-1, 1);}
        void out(){for(int i=0; i<size; i++){cout<<query(i, i)<<" ";cout<<endl;}}
};

int32_t main(){
    int n, q;
    cin>>n>>q;
    SegTree seg(n);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        seg.update(i,x);
    };
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;

        cout<<seg.query(a-1, b-1)<<endl;
    }
    
    return 0;
}