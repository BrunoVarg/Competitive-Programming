int gcd(int a, int b) {
 if (b == 0) return a;
 return gcd(b, a % b);
}

// number of elements
long long sum_of_n_first_squares(int n) {
 return (n * (n - 1) * (2 * n - 1)) / 6;
}

// first element, last element, number of elements
long long sum_pa(int a1, int an, int n) {
 return ((a1 + an) * n) / 2;
}

// first element, number of elements, ratio
long long general_term_pa(int a1, int n, int r) {
 return a1 + (n - 1) * r;
}

// first term, numbers of elements, ratio
long long sum_pg(int a1, int n, int q) {
 return (a1 * (fexp(q, n) - 1)) / (q - 1);
}

// -1 < q < 1
// first term, ratio
long long sum_infinite_pg(int a1, double q) {
 return a1 * (1 - q);
}

// first term, number of elements, ratio
long long general_term_pg(int a1, int n, int q) {
 return a1 * fexp(q, n -1);
}

// first element of original pa, first element of derived pa, number of elements of original pa, ratio of derived pa
long long sum_second_order_pa(int a1, int b1, int n, int r) {
 return a1 * n + (b1 * n * (n - 1)) / 2 + (r * n * (n - 1) * (n - 2)) / 6
}

// log
int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}

// sum from one to n
(n * (n +1)) / 2

// gdc 
long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

// or just use __gcd(a,b)

// lcm
long long lcm(long long a, long long b){
    return (a/__gcd(a,b)*b);
}

// distancia manhattan
// https://vjudge.net/contest/539684#problem/H

// distancia euclidiana

// GEOMETRIA
// seno
a / sen(a) = b / sen(b) = c / sen(c)

//cosseno
a^2 = b^2 + c^2 - 2*b*c*cos(a)

// area losango
A = (1/2) * diagonal_maior * diagonal_menor

// volume prisma
V = B * H

//volume esfera
V = (4/3) * PI * R^3

//volume piramide
V = (1/3) * B * H

//volume cone
V = (1/3) * PI * R^2 * H

//condicao de existencia
 a - b | < c < a + b

// combinacao sem rep.
C(n  x) = n! / (x! (n-x)!)

// combinacao com rep.
C(n  m) = (m + n - 1)!/(n! (m-1)!)

// perm sem rep
 p = n!

// perm com rep
p = n!/(rep1! rep2! ... repn!)

// perm circ
 P = (n-1)!
 
