int fast_exp(int base, int e){
    if(e == 0) return 1;
    if(e % 2) return base * fast_exp(base * base,e/2);
    else return fast_exp(base * base, e/2);
}