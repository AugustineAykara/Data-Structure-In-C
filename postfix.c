#include<stdio.h>
#include<ctype.h>
#include<string.h>


int top=-1, stack[15];


void push(char x)
{
    stack[++top] = x;
}


char pop()
{ 
	return stack[top--];
}


int precedence(char c)
{  
	if(c == '(')
   		return 0;
    else if(c == '+' || c == '-')
    	return 1;
    else if(c == '*' || c == '/')
    	return 2;
    else if(c == '^') 
    	return 3;
}


int infixtopostfix(char infix[],char postfix[])
{
    char item, x;
    int i=0, j=0;

    while(infix[i] != '\0')
    {
       item = infix[i];

       if(isalnum(item))
        {
   		    postfix[j++] = item;
        }

        else if(item=='(')
        {
     		push(item);
        }

        else if(item==')')
        {
         	while((x=pop()) != '(')
         	{
          		postfix[j++]=x;
           	}
        }

        else
        {  
      	 	while(precedence(stack[top]) >= precedence(item))
            {
            	postfix[j++] = pop();
            }
            push(item);
        }
        i++;
    }

    while(top!= -1)
    {
   		postfix[j++] = pop();
    }
    postfix[j] = '\0';
}


void main()
{
    char infix[15],postfix[15];
    printf("\n Enter the infix expression  : ");
    scanf("%s", infix);

    infixtopostfix(infix, postfix);
    printf("\n The postfix expression is   : %s",postfix);
    printf("\n");
}


