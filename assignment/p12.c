#include<stdio.h>
#include<string.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
char str[20];
void push(char c)
{
    if(top > SIZE)
        printf("Stack is OverFlow \n");
    else
    {
        top++;
        stack[top]=c;
    }
}
char pop()
{
    if(top == -1)
        printf("Stack is Underflow \n");
    else
    {
        char x=stack[top];
        top--;
        return x;
    }
}

void read_from_file()
{
    FILE *in_file;
    int n;

    in_file = fopen("string.txt","r");

    if(in_file == NULL)
    {
        printf("error\n");
    }
    int i=0;
    printf("Given String is :\n");
    while(fscanf(in_file,"%c",&n) != EOF)
    {
       printf("%c",n);
       str[i]=n;
       push(n);
       i++;
    }
    fclose(in_file);
}
int palindrom()
{
    char pal[20];
    int j=0;
    while(top != -1)
    {
        pal[j]=pop();
        j++;
    }
    if(strcmp(str,pal) == 0)
        return 1;
    else
        return 0;
}
void main()
{
    read_from_file();
    printf("\n");
    int res;
    res = palindrom();
    if(res == 1)
        printf("String is Palindrom \n");
    else
        printf("String is Not Palindrom \n");
}
