// quantidade de combinacoes possiveis sem repeticao de 2 numeros
int comb(int k){
    if(k==1 or k==0)return 0;
    return (k*(k-1))/2;
}

int fat[MAX], ifat[MAX];

void factorial(){
    fat[0] = 1;
    for(int i=0; i<MAX; i++){
        if(i > 0) fat[i] = (i * fat[i-1]) % MOD;
        ifat[i] = fast_exp(fat[i], MOD-2, MOD);
    }
}

// N escolhe K
int choose(int n, int k){
    if(k > n or k<0) return 0;
    return (((fat[n] * ifat[k]) % MOD) * ifat[n-k]) % MOD;
}