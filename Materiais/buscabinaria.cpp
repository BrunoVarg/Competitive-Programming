// BUSCA BINÁRIA

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

// Valor mínimo
int bb_menor(int a, int b){
    int l = a;
    int r = b;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    // a resposta fica em l
    return l
}
// lower_bound(vetor.begin(), vetor.end(), x) - vetor.begin(); 

// Valor máximo
int bb_maior(int a, int b){
    int l = a;
    int r = b;
    while (l < r) {
        int mid = (l + r) / 2;
        if (!check(mid)) r = mid; // check vira !check
        else l = mid + 1;
    }
    // a resposta fica em l-1
}
// upper_bound(vetor.begin(), vetor.end(), x) - vetor.begin(); 

