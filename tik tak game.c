#include"stdio.h"
#include"stdbool.h"
int win_chack(int a[][4],int n);
void print_cell(int ar[][4],int n);
int main()
{
    int n=3;
    int a[4][4];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            a[i][j]= -1;
        }
    }
    bool p1=true;
    bool p2=false;
    while(true)
    {
        print_cell(a,n);
        if(p1==true)
        {
            int r,c;
flag:
            printf("player 1 turn (x),enter row and collum>>");
            scanf("%d %d",&r,&c);
            if(a[r][c]!=-1)
            {
                printf("enter again!!");
                goto flag;
            }
            a[r][c]=1;
            p1=false;
            p2=true;
        }
        else
        {
            int r,c;
flag2:
            printf("player 2 turn (o),enter row and collum>>");
            scanf("%d %d",&r,&c);
            if(a[r][c]!=-1)
            {
                printf("enter again!!");
                goto flag2;
            }
            a[r][c]=2;
            p2=false;
            p1=true;
        }
        if(win_chack(a,n)==1)
        {
            print_cell(a,n);
            printf("player 1 won");
            break;
        }
        else if(win_chack(a,n)==2)
        {
            print_cell(a,n);
            printf("player 2 won");
            break;
        }


    }
    return 0;
}
void print_cell(int ar[][4],int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if( ar[i][j]==-1) printf(" ");
            if( ar[i][j]==1) printf(" x ");
            if( ar[i][j]==2) printf(" o ");
            if(j<n)printf("\t|\t");
        }
        printf("\n");
        if(i<n)printf("--------------------------------------");
        printf("\n");
    }
}
int win_chack(int a[][4],int n)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]&&a[i][1]!=-1)
        {
            return a[i][1];
        }
    }
    for(int j=1; j<=n; j++)
    {
        if(a[1][j]==a[2][j]&&a[2][j]==a[3][j]&&a[1][j]!=-1)
        {
            return a[1][j];
        }
    }
    if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[1][1]!=-1)return a[1][1];
    if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&a[1][3]!=-1)return a[1][3];
    return -1;
}


