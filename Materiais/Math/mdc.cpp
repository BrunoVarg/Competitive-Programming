// Greatest common divisor / MDC

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

// or just use __gcd(a,b)
