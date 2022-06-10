
// quantidade de combinações possíveis sem repetição de 2 numeros
int comb(int k){
    if(k==1)return 1;
    else if(k==0)return 0;
    return (k*(k-1))/2;
}