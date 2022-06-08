// DSU

#include <bits/stdc++.h>
using namespace std;


const int MAX = 1e5+10;

int parent[MAX];

void make(int v) {
    parent[v] = v;
}

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main(){

    return 0;
}
