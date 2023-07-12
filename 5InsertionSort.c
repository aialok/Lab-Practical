#include <stdio.h>


int* selection(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr=arr[i];
        int j=i-1;
        while(arr[j]>curr && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=curr;
    }

    return arr;
    
}

int main()
{
    int arr[5]={5,4,3,2,1};

    selection(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    

}