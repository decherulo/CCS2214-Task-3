#include <stdio.h>

#define MAX 10

int main()
{
    int matrix[MAX][MAX];
    int sparse[MAX * MAX + 1][3];   /* each row: row, column, value */
    int rows, cols, i, j, k;

    printf("Enter number of rows (max %d): ", MAX);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX);
    scanf("%d", &cols);

    if (rows < 1 || rows > MAX || cols < 1 || cols > MAX)
    {
        printf("Size not allowed\n");
        return 1;
    }

    printf("Enter the matrix values:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    /* first row of sparse stores the size and the count of non-zero values */
    k = 1;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k = k + 1;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;

    printf("\nOriginal matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    printf("\nSparse representation:\n");
    printf("Row  Col  Value\n");
    for (i = 0; i < k; i++)
        printf("%d    %d    %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);

    return 0;
}