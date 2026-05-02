#include <iostream>

// Function to return precedence of operators
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
   std::string post_str=" ";
   char stack[10];
   int top=-1;
   for(int i=0 ;i<str.length() ;i++)
   {   if(isalpha(str[i]))    // if the character is an operand, add it to output string
   {
       post_str += str[i];
   }
       else if(str[i]=='(')   // if the character is '(', push it to the stack
       {
           stack[++top]=str[i];
       }
       
       
       else if(str[i]==')') // if the character is ')', pop and output from the stack until an '(' is encountered
       {

            while(top != -1 && stack[top] != '(')  // pop and output from the stack until an '(' is encountered
            {
                post_str += stack[top];
                top--;
            }

            top--; 
       }
       else // allow operators in order of precedence
       {

            while(top != -1 &&
                  priority(stack[top]) >= priority(str[i]))
            {
                post_str += stack[top];
                top--;
            }

            stack[++top] = str[i];
       }
   }
  

 std::cout << post_str; // output the postfix expression
  while(top>-1)
   {
   std::cout<<stack[top];  // remaining operators in the stack
   top--;
   }

    return 0;
}
