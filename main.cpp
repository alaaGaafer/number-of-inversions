#include <bits/stdc++.h>
using namespace std;
//prototypes
int mergeSort1(int arr[], int temp[], int left, int right);
int mergee(int arr[], int temp[], int left, int mid,int right);


int mergeSort1(int arr[], int temp[], int left, int right)
{
    int mid, inversion_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inversion_count += mergeSort1(arr, temp, left, mid);
        inversion_count += mergeSort1(arr, temp, mid + 1, right);
        inversion_count += mergee(arr, temp, left, mid + 1, right);
    }
    return inversion_count;
}
int mergeSort(int arr[], int n)
{
    int temp[n];
    return mergeSort1(arr, temp, 0, n - 1);
}


int mergee(int arr[], int temp[], int left, int mid,int right)
{
    int i, j, k;
    int inversion_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversion_count = inversion_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inversion_count;
}
int main()
{
    int continuee=0,n;
    do
    {
        cout<<"enter the size of the array"<<endl;
        cin>>n;
        while(n<0)
        {
            cout<<"size must be above zero, please enter a suitable size "<<endl;
            cin>>n;
        }
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cout<<"enter element number "<<i+1<<endl;
            cin>>arr[i];
        }
        cout <<"number of inversions = "<< mergeSort(arr, n) << endl;
        cout<<"if you wish to continue press 1 ,if not press 0"<<endl;
        cin>>continuee;
        while(continuee!= 1&&continuee!= 0)
        {
            cout<<"wrong input, please enter 1 or 0"<<endl;
            cin>>continuee;
        }
    }
    while(continuee==1);
    return 0;
}
