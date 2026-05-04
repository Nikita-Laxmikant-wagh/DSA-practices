//reverse the infix expression and swap '(' with ')' and vice versa
//convert the modified infix expression to postfix
//reverse the postfix expression to get the prefix expression
#include <iostream>

int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;

    if(ch == '*' || ch == '/' || ch == '%')
        return 2;

    if(ch == '^')
        return 3;

    return 0;
}

int main()
{
   std::string str="(c*(b+a)/b)";
   std::string rev_str="";
    for(int  i=str.length()-1; i>=0;i--)
    {

   if(str[i] == '(')
        {
            rev_str += ')';
        }

        else if(str[i] == ')')
        {
            rev_str += '(';
        }

        else
        {
            rev_str += str[i];
        }

    }
   std::string post_str=" ";
   std::string pre_str=" ";
   char stack[10];
   int top=-1;
   for(int i=0 ;i<rev_str.length() ;i++)
   {   if(isalpha(rev_str[i]))
   {
       post_str += rev_str[i];
   }
       else if(rev_str[i]=='(')
       {
           stack[++top]=rev_str[i];
       }
       
       
       else if(rev_str[i]==')')
       {

            while(top != -1 && stack[top] != '(')
            {
                post_str += stack[top];
                top--;
            }

            top--; 
       }
       else
       {

            while(top != -1 &&
                  priority(stack[top]) >= priority(rev_str[i]))
            {
                post_str += stack[top];
                top--;
            }

            stack[++top] = rev_str[i];
       }
   }
  
 
 
  while(top>-1)
   {   post_str += stack[top];
       top--;
   }
   for(int  i = post_str.length()-1; i>=0;i--)
    {
       pre_str+=post_str[i];
   }
  std::cout<<pre_str;
    return 0;
}