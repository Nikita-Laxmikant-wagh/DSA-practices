#include <iostream>
using namespace std;

int main() {
    string str = "{}{{[]()}}";
    char stack[10];
    int top = -1;

    for (int i = 0; i < str.length(); i++) { 

        //check current operator is opening 
        // if yes then push it to stack
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        }
        // if current operator is closing then check top of stack
        else 
        {   
            // close operator is found but stack is empty 
            //means no opening bracket is available
            // "([])}" this is example of such case
            if (top == -1)
            {
                cout << "Not Valid";
                return 0;
            }

            // close operator is found then check top of stack
            // if yes then pop the top of stack and continue
            // if no then return not valid
            if ((str[i] == ')' && stack[top] == '(') ||
                (str[i] == '}' && stack[top] == '{') ||
                (str[i] == ']' && stack[top] == '[')) {
                
                top--; 
            } 
            else 
            {
                cout << "Not Valid";
                return 0;
            }
        }
    }
   
   // if stack is empty then all brackets are balanced
   // if stack is not empty means some opening brackets are not closed
   if(top == -1)
   {
        cout << " Valid";
   }
   else
   {
       cout<<"Not Valid";
   }

    return 0;
}