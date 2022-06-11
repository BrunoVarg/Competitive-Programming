#include <bits/stdc++.h>
using namespace std;

bool check(int valor, int x) {
    return valor <= x;
}

int bb(int a, int b, int x){
    int l = a;
    int r = b;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid, x)) r = mid;
        else l = mid + 1;
    }
    return l;
}

bool check(int valor) {
    return valor <= 10;
}

int bb_menor(int a, int b){
    int l = a;
    int r = b;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    return l;
}


int bb_maior(int a, int b){
    int l = a;
    int r = b;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!check(mid)) r = mid;
        else l = mid + 1;
    }

}
