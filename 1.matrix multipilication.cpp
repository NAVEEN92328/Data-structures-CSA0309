#include <stdio.h>

int main()
 {
    int m, n, p, q, i, j, k;
    
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &p, &q);
    
    if (n != p) {
        printf("Multiplication not possible\n");
        return 0;
    }

    int a[m][n], b[p][q], c[m][q];

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    printf("Resultant matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    
    return 0;
}
