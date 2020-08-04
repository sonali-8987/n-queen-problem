#include<stdio.h>
#include<stdlib.h>
typedef struct{
int n;
int *col;
}queen;

void initialize (queen *a,int n)            //function to initialize
{
    a->col=(int*)malloc(sizeof(int)*(n+1)); //dynamic allocation of memory
    int i;
    for(i=1;i<=n;i++)
        a->col[i]=-1;
}

void display(queen *a,int n)  //display function to show output
{
    int j,i;
    printf("\n###################\n");
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
           if (a->col[i]==j)
            printf(" Q ");
           else
            printf(" . ");

       }
       printf("\n");
    }
    printf("\n###################\n");
}


int isSafe(queen *a,int x,int y)  //function to know if movement is safe
{
    int i;
    for(i=1;i<x;i++)
    {
        if(a->col[i]==y || (x-i)==abs(y-(a->col[i])))
            return 0;
    }
    return 1;
}

void n_queen(queen *a,int k,int n) //defining n_queen function
{
    int j;
    for(j=1;j<=n;j++)
    {

        if(isSafe(a,k,j))
        {
            a->col[k]=j;
            if(k==n){
                display(a,n);
            }
            else
                n_queen(a,k+1,n);
        }

    }
}

void main()
{
    queen *a;
    a=(queen *)malloc(sizeof(queen));//dynamic memory allocation
    printf("\nENTER VALUE OF n     -:  ");//to get the value of n from user
    scanf("%d",&(a->n));
    initialize(a,a->n);
    n_queen(a,1,a->n);
}
