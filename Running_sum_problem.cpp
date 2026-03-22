
#include <iostream>

int main()
{
    int n;
    std::cin>>n;
    int arr[n];
    int sum=0 ;
    for(int i=0 ; i<n ; i++)
    {   std::cin>>arr[i];
        sum = sum+ arr[i];
        arr[i]=sum;
    }
    
    
    for(int i=0 ; i<n ; i++)
    {
    std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}