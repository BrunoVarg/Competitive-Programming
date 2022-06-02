bool check(int valor, int x) {
    return valor <= x;
}

int binary_search(int a, int b, int x){
    int l = a;
    int r = b;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid, x)) r = mid;
        else l = mid + 1;
    }
    return l;
}