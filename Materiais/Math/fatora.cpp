map<int,int> fatora(int n){
    map<int,int> fact;
    for(int i = 2; i*i <= n; i++){
        while(n%i == 0){
            fact[i]++;
            n /= i;
        }
    }
    if(n > 1)
        fact[n]++;
    return fact;
}