#include"DynamicArray.h"
#include<vector>
template<typename T, typename Compare>
void insertionSort(DynamicArray<T>&arr,Compare comp)
{
    int n=arr.size();

    for(int i=1;i<n;i++)
    {
        T key=arr[i];
        int j=i-1;

        while(j>=0&&comp(key,arr[j]))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//2. MERGE SORT

template<typename T, typename Compare>
void merge(DynamicArray<T>&arr, T*temp,
int left, int middle, int right,
Compare comp)
{
    int i=left;
    int j=middle+1;
    int k=left;

    while(i<=middle&&j<=right)
    {
        if(comp(arr[j],arr[i]))
        {
            temp[k]=arr[j];
            j++;
        }
        else
        {
            temp[k]=arr[i];
            i++;
        }
        k++;
    }
    while(i<=middle)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=right)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int x=left;x<=right;x++)
    {
        arr[x]=temp[x];
    }
}

template<typename T, typename Compare>
void mergeSortHelper(DynamicArray,<T>&arr, T*temp,
int left, int right, Compare comp)
{
    if(left>=right)
    return;

    int middle=left+(right-left)/2;

   mergeSortHelper(arr,temp,left,middle,comp);
   
   mergeSortHelper(arr,temp,middle+1,right,comp);

   merge(arr,temp,left,middle,right,comp);
}

template<typename T,typename Compare>
void mergeSort(DynamicArray<T>&arr,Compare comp)
{
    int n=arr.size();

    if(n<=1)
    return;

    T*temp=new T[n];

    try
    {
        mergeSortHelper(arr,temp,0,n-1,comp);
    }
    catch(...)
    {
        delete[]temp;
        throw;
    }

    delete[]temp;
    
}

//ITERATIVE BINARY SEARCH

template<typename T, typename Compare>
int binarySearch(const DynamicArray<T>&arr,
    const T& target, Compare comp)
    {
        int left=0;
        int right=arr.size() -1;

        while(left<=right)
        {
            int middle=left+(right-left)/2;

            if(comp(arr[middle],target))
            {
                left=middle+1;
            }
            else if(comp(target,arr[middle]))
            {
                right=middle-1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }