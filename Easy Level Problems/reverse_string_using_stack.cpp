#include <iostream>

int main() {
    
    std::string str="cat";
    char stack[5];
    int top =-1;
    for(int i=0 ; i<str.length(); i++)
    {
        stack[++top]=str[i];
    }
    for(int i=0 ; i<str.length(); i++)
    {
        
        std::cout << stack[top]<<" ";
        stack[top--];
    }
    
    

    return 0;
}