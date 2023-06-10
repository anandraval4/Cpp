#include<iostream>
using namespace std;
void merge(int *arr,int s,int e)
{
    int mid = s+(e-s)/2;
    int len1 = mid -s +1;
    int len2 = e-mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k=s;
    for(int i =0;i<len1;i++)
    {
    left[i] = arr[k++];
    }

    k = mid+1;
    for(int i =0;i<len2;i++)
    {
        right[i]=arr[k++];
    }

    int leftIndex = 0;
    int rightIndex =0;
    int mainArrayIndex = s;

    while(leftIndex<len1 && rightIndex<len2)
    {
        if(left[leftIndex]>right[rightIndex])
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
    }
    while(leftIndex<len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }
    while(rightIndex<len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}
void mergsort(int* arr,int s,int e)
{
    if(s>=e)
    {
        return ;
    }
    int mid = s+(e-s)/2;
    mergsort(arr,s,mid);
    mergsort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{
    int arr[] = {5,3,2,1,4};
    int n = 5;
    int s = 0;
    int e = n-1;
    mergsort(arr,s,e);
    for(int i =0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;
}