// Least Common Multiple - MMC
#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b){
    return (a/__gcd(a,b)*b);
}
