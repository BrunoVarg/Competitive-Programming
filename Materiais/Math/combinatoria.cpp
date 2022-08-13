// quantidade de combinacoes possiveis sem repeticao de 2 numeros
int comb(int k){
    if(k==1 or k==0)return 0;
    return (k*(k-1))/2;
}