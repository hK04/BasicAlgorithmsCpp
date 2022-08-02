#include <stdio.h>

int gcd(int a, int b); //greatest common divisor

int lcm(int a, int b); //least common multiple

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("GCD(%d, %d) = %d", a, b, gcd(a, b));
    printf("%c", '\n');
    printf("LCM(%d, %d) = %d", a, b, lcm(a, b));
    return 0;
}

int gcd(int a, int b){
    if (a == 0)
        return b;
    else 
        return gcd(b % a, a);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}