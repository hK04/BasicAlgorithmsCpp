#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define _CRT_SECURE_NO_WARNINGS

void print(int c[]);

int main(){
    int a[4] = {9, 1, 2, 3};
    int b[2] = {4, 5};

    int len_of_a = sizeof(a) / sizeof(int);
    int len_of_b = sizeof(b) / sizeof(int);
    int max_len = max(len_of_a, len_of_b);
    int new_b[max_len] = { 0 };
    int new_a[max_len] = { 0 };
    int c[max_len + 1] = { 0 };

    if (len_of_a > len_of_b){ 
        for (int i = len_of_b - 1; i >= 0; i--)
            new_b[len_of_a - len_of_b + i] = b[i];
        for (int i = len_of_a - 1; i >= 0; i--)
            new_a[i] = a[i];
    }else{
        for (int i = len_of_a - 1; i >= 0; i--)
            new_a[len_of_b - len_of_a + i] = a[i];
        for (int i = len_of_b - 1; i >= 0; i--)
            new_b[i] = b[i];
    }
    
    int div_ = 0;

    for (int i = max_len - 1; i >= 0; i--){ 
        int mod_ = (new_a[i] + new_b[i]) % 10;
        c[i+1] = div_ + mod_;
        div_ = (new_a[i] + new_b[i]) / 10;
    }
    
    if (div_ != 0){
        c[0] += div_;
    }
        
    for (int i = 0; i < max_len + 1; i++)
        printf("%d ", c[i]);

}