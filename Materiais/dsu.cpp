#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) begin(x), end(x)
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
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

int main(){ sws; 



    return 0;
}