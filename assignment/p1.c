#include<stdio.h>
#include<string.h>
void swap(int *x1,int *x2)
{
    int temp;
    temp=*x1;
    *x1=*x2;
    *x2=temp;
}
void palindrom(int x1)
{
    int n1=x1;
    int d=0;
    printf("value of N1 : %d\n",x1);
    while(x1 != 0)
    {
        d = d * 10;
        d = d + x1%10;
        x1= x1/10;
    }
    if(n1 == d)
    {
        printf(" %d is Palindrom \n",n1);
    }
    else
    {
        printf(" %d is not palindrom \n",n1);
    }
}
void read_from_file()
{
    FILE *in_file;
    int n,no[2];

    in_file = fopen("swap.txt","r");
    if(in_file == NULL)
    {
        printf("error\n");
    }

    int i=0;
    while(fscanf(in_file,"%d",&n) != EOF)
    {
       no[i]=n;
       i++;
    }
    fclose(in_file);
}

int main()
{
    int n1,n2,no[2];
    read_from_file();
    n1=no[0];
    n2=no[1];
    void (*p)(int,int)=&swap;
    (*p)(&n1,&n2);
    printf("\n");
    printf("Check Two numbers are palindrom or not :\n");
    printf("Number  1 : \n");
    palindrom(n1);
    printf("\n");
    printf("Number  2 : \n");
    palindrom(n2);
}
