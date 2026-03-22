#include <iostream>

int main()
{
    int n;
    std::cin>>n;
    int arr[n];
    int target=9;
    for(int i=0 ; i<n ; i++)
    {   
        std::cin>>arr[i];
    }
    for(int i=0 ; i<n ; i++)
    {  
        for(int j=i+1 ; j<n ; j++)
        {
        if(arr[i]+arr[j]==target)
        {
    std::cout<<i<<","<<j<<std::endl;
        }
    }
}
    return 0;
}