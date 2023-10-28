#include <stdio.h>

void add(int m, int n, int a[m][n], int b[m][n], int c[m][n])
{
    printf("Addition of matrices : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            // *(*(c+i)+j)= *(*(a+i)+j)+*(*(b+i)+j);
        }
    }
}
void sub(int m, int n, int a[m][n], int b[m][n], int c[m][n])
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void mul(int m, int n, int p, int q, int a[m][n], int b[p][q], int c[m][q])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

void display(int m, int n, int a[m][n])
{
    
    for (int i = 0; i < m; i++)
    {
        printf("[");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(a + i) + j));
        }
        printf("]\n");
    }
}

void input(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter for [%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void transpose(int m,int a[][m])
{   int temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
        
        
    }
    
}

void replace(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   if(i!=j){
            if(i<=j){
                a[i][j]=0;
            }
            else{
                a[i][j]=1;
            }
        }
            
        }
    }
}

int main()
{
    int m, n, p, q;
    printf("Enter number of rows for MATRIX A : ");
    scanf("%d", &m);
    printf("Enter number of column for MATRIX A : ");
    scanf("%d", &n);
    printf("Enter number of rows for MATRIX B : ");
    scanf("%d", &p);
    printf("Enter number of column for MATRIX B : ");
    scanf("%d", &q);
    int a[m][n], b[p][q];

    // INPUT AND display

    printf("Enter Elements for Matrix A :\n");
    input(m, n, a);
    printf("Matrix A : \n");
    display(m, n, a);
    printf("Enter Elements for Matrix B :\n");
    input(p, q, b);
    printf("Matrix B : \n");
    display(p, q, b);

    int choice;
    printf("Enter 1 to add \nEnter 2 to subtract\nEnter 3 to multiply\nEnter 4 to transpose \nEnter 5 to replace with [0,1]\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        if (m == p && n == q)
        {
            int c[m][n];
            add(m, n, a, b, c);
            display(m, n, c);
        }
        else
        {
            printf("Dimentions not matched");
        }
    }
    else if (choice == 2)
    {
        if (m == p && n == q)
        {
            int c[m][n];
            sub(m, n, a, b, c);
            display(m, n, c);
        }
        else
        {
            printf("Dimentions not matched");
        }
    }
    else if (choice == 3)
    {
        if (n == p)
        {
            int c[m][q];
            mul(m,n,p,q,a,b,c);

            display(m, q, c);
        }
        else
        {
            printf("Dimentions not matched");
        }
    }
    else if(choice==4){
        printf("Transpose of A : ");
        transpose(m,a);
        display(m,n,a);
    }
    else if(choice==5){
        replace(m,n,a);
        display(m,n,a);
    }
    return 0;
}