#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX = 1e5; // tamanho maximo do vetor
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

// End Template //

vector<ll> lazy(4*MAX, 0);
ll tree[4*MAX], vet[MAX];
int N;

ll merge(ll a, ll b){
    return a + b;
}

void build(int l=0, int r=N-1, int no=1){
    if(l==r){
        tree[no] = vet[l];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*no);
    build(mid+1, r, 2*no+1);

    tree[no] = merge(tree[2*no], tree[2*no+1]);
}

void prop(int l, int r, int no){
    if(lazy[no]!=0){
        tree[no] = (r-l+1)*lazy[no]; //acho que na verdade é += em vez de =
        if(l!=r){
            lazy[2*no] = lazy[2*no+1] = lazy[no];
        }
        lazy[no] = 0;
    }
}

void update(int A, int B, int x, int l=0, int r=N-1, int no=1){
    prop(l, r, no);
    // caso 1
    if(B<l or r<A) return;
    // caso 2
    if(A<=l and r<=B){
        lazy[no] = x;
        prop(l, r, no);
        return;
    }
    // caso 3
    int mid = (l+r)/2;

    update(A, B, x, l, mid, 2*no);
    update(A, B, x, mid+1, r, 2*no+1);
    
    tree[no] = merge(tree[2*no], tree[2*no+1]);
}

ll query(int A, int B, int l=0, int r=N-1, int no=1){
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


int32_t main()
{

    int Q, opt, a, b, l, r, k, idx;
    cin >> N >> Q;
    vector<int> vaux(N);
    for(int i=0;i<N;i++){
        cin >> vaux[i];
        vet[i] = vaux[i];
    }
    for(int i=0; i<N; i++){
        if(i==0)vet[i] = vaux[i];
        else vet[i] = vet[i-1] + vaux[i];
    }
    build();

    for(int i=0;i<Q;i++){
        cin >> opt;
        if(opt==1){ // update
            cin >> idx >> k;
            idx--;
            int soma = -vaux[idx] + k;

            vaux[idx] = k;
            update(idx, N-1, soma);
        }else{ // query
            cin >> l >> r;
            l--;r--; // indice indexado em 0
            cout << query(l, r) << endl;
        }
    }
    for(int i=0; i<N; i++){
        cout<<vet[i]<<" ";
    }
    cout<<endl;

    return 0;
}
