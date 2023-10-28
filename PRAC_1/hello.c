//1.upper diagonal elements 0,lower diagonal elements 0
//2.Multiplication,addition , substraction,

#include <stdio.h>
void add(int m,int n, int a[m][n], int b[m][n], int c[m][n])
{

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // c[i][j]=a[i][j]+b[i][j];
                *(*(c+i)+j)= *(*(a+i)+j)+*(*(b+i)+j);
            }
            
        }
    }
     

    
void display(int m,int n,int a[m][n]){
    for (int i = 0; i < m; i++)
    {
        printf("[");
        for (int j = 0; j < n; j++)
        {
            printf("%d ",*(*(a+i)+j ));
        }
        printf("]\n");
    }
    
}

void input( int m, int n,int a[m][n]){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter for A[%d][%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }
}

int main(){
    int m,n,p,q;
    printf("Enter number of rows for MATRIX A : ");
    scanf("%d",&m);
    printf("Enter number of column for MATRIX A : ");
    scanf("%d",&n);
    printf("Enter number of rows for MATRIX B : ");
    scanf("%d",&p);
    printf("Enter number of column for MATRIX B : ");
    scanf("%d",&q);
    int a[m][n],b[p][q];

    // INPUT AND display

    printf("Enter Elements for Matrix A :\n");
    input(m,n,a);
    printf("Matrix A : \n");
    display(m,n,&a);
    printf("Enter Elements for Matrix B :\n");
    input(p,q,b);
    printf("Matrix B : \n");
    display(p,q,b);

    int c[m][n];
    add(m,n,a,b,c);
    display(m,n,c);

    return 0;
}