#include<stdio.h>
#define SIZE 100
int stack[SIZE];
int top=-1;

void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
		write_into_file();
	}
}

int pop()
{
    int item;
	if(top <0)
	{
		printf("stack under flow:");
    }
	else
	{
		item = stack[top];
		printf("\t %d : DELETE\n",item);
		top = top-1;
		return(item);
	}
}
void display()
{
    if(top==-1)
    {
        printf("\tSTACK IS EMPTY\n");
    }
    int i;
    for(i=top;i>=0;i--)
    {
        printf("\t| %d |\n",stack[i]);
    }
}

void write_into_file()
{
	FILE *out_file;

    out_file = fopen("number.txt","w");

    if(out_file == NULL)
    {
        printf("error\n");
    }
    int i=0;
    for(i=top;i>=0;i--)
    {
        fprintf(out_file,"%d\n",stack[i]);
    }
    fclose(out_file);
}


void read_from_file()
{
    FILE *in_file;
    int n;

    in_file = fopen("number.txt","r");

    if(in_file == NULL)
    {
        printf("error\n");
    }
    while(fscanf(in_file,"%d",&n) != EOF)
    {
       push(n);
    }
    fclose(in_file);
}

void main()
{
    read_from_file();
    int ch,data;
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY\n");
    printf("4. EXIT\n");
    do{
        printf("Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Data : ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                write_into_file();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default :
                printf("Enter Proper Choice \n");
                break;
        }
    }while(ch!=4);
}
