// SEGTREE

#include <bits/stdc++.h>
using namespace std;
class SegTree{
    vector<int> st;
    int size;

    int el_neutro = -(1e9 + 7);

    int f(int a, int b){
        return max(a,b);
    }

    int query(int sti, int stl, int str, int l, int r){
    //O nodo está fora do intervalo que estamos interessados, retorne o elemento neutro que não afeta a consulta
        if(str < l || r < stl) 
            return el_neutro;

    // O nodo está completamente incluído no intervalos que estamos interessados, retorne a informação contida naquele nodo.
        if(stl >= l and str <= r)
            return st[sti];

    // Se chegarmos aqui, é porque esse Nodo está parcialmente contido no intervalo que estamos interessados. Então, continuamos procurando nos filhos.
        int mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }

    void update(int sti, int stl, int str, int i, int amm){
        // Chegamos no índice que queremos, vamos atualizar o valor
        if(stl == i and str == i){
            st[sti] = amm;
            return;
        }
        // O intervalo que estamos não contem o índice que queremos atualizar, retorne
        if(stl > i or str < i)
            return;
        
        // O intervalo contém o índice, mas temos que chegar no nodo específico, recurse para os filhos.
        int mid = (stl + str)/2;

        update(sti*2+1,stl,mid,i,amm);
        update(sti*2+2,mid+1,str,i,amm);
        // Após os filhos mais em baixo, precisamos atualizar o valor desse nodo
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }
    public:
        SegTree(int n):  st(4*n,0){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update(int i, int amm){update(0,0,size-1,i,amm);}
};

int main(){
    vector<int> v;
    SegTree st(v.size());
    for(int i = 0; i< v.size();i++){
        st.update(i,v[i]);
    }
}
