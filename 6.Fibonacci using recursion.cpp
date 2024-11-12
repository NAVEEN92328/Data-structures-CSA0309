#include <stdio.h>

void fibonacci(int n, int a, int b) {
    if (n == 0)
        return;  
    printf("%d ", a);
    fibonacci(n - 1, b, a + b);  
}

int main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci series: ");
        fibonacci(num, 0, 1);  
    }
    
    return 0;
}

