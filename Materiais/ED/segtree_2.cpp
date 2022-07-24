#include <bits/stdc++.h>
using namespace std;
//SEG-TREES are used when we want to apply queries in intervals(segmentes) of a vector, such as getting the min value, getting the max value or
//getting the sum of this segment, and also doing updates to these segments in a efficient O complexity.
 
//It takes O(n) to build a segment tree.
//It takes O(log n) to answer a query and to update a segment.
//Also, an important thing to notice is that we dont actually implement a tree, we do it in the form of an array.
//Queries are done in the same way despite of the seg tree type, therefore what actually changes is how we build the tree considering what we want
//such as: max, min, sum...
 
const int INF = 0x3f3f3f3f;
const int MAX = 200005;
int n;
int a[MAX];
 
// Min Seg Tree. Considering L = 1 and R = N;
class MinSegTree{
    private:
        int st[4*MAX];
    public:
        void build(int i, int l, int r){
            if(l == r){
                st[i] = a[l]; //leaf node.
            }
            else{
                int mid = (r+l)/2;
                build(2*i, l, mid);
                build(2*i + 1, mid+1, r);
                st[i] = min(st[2*i], st[2*i + 1]); //parent node.
            }
            return; 
        }
 
        int getmin(int i, int auxl, int auxr, int l, int r){
            if(l <= auxl && r >= auxr){ //total overlap.
                return st[i];
            }
            else if(auxr < l || auxl > r){ //no overlap.
                return INF;
            }
            else{ //partial overlap
                int auxmid = (auxr+auxl)/2;
                return min( getmin(2*i, auxl, auxmid, l, r), getmin(2*i+1, auxmid+1, auxr, l, r));
            }
        }
 
        void update(int i, int v, int x, int l, int r){
            if(l == r){
                st[i] = x;
            }
            else{
                int mid = (r+l)/2;
                if(v <= mid){
                    update(2*i, v, x, l, mid);
                }
                else{
                    update(2*i+1, v, x, mid+1, r);
                }
                st[i] = min(st[2*i],st[2*i + 1]);
            }
            return;
        }
};
 
int main(){
    int n, q; cin >> n >> q;
    MinSegTree seg;
    for(int i = 1; i < n+1; i++){
        cin >> a[i];
    }
    seg.build(1,1,n);
    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 1){
            int v, x; cin >> v >> x;
            seg.update(1,v,x,1,n);
        }
        else{
            int l, r; cin >> l >> r;
            cout << seg.getmin(1,1,n,l,r) << "\n";
        }
    }        
}