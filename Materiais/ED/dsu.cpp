#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;

int parent[MAX];
int sz[MAX];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void _union(int a, int b){
    a = find(a);
    b = find(b);

    if(b>a)swap(a,b);

    if (a != b){
        sz[a] += sz[b];
        parent[b] = a;
    }

}

int main(){

    return 0;
}
