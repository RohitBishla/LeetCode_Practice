//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high) return;
        int index = partition(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }

    int partition (int arr[], int low, int high){
        int count = 0;
        int val = arr[low];
        for(int i = low + 1; i <= high; i++){
            if(arr[i] <= val) count++;
        }
        int pivot = low + count;
        swap(arr[low], arr[pivot]);
        int i = low;
        int j = pivot + 1;
        while(i < pivot && j <= high){
            if(arr[i] <= val) i++;
            else if(arr[j] > val) j++;
            else swap(arr[i], arr[j]);
        }
        return pivot;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends