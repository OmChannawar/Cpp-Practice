#include<iostream>
using namespace std;

void merge(int arr[], int st, int mid, int en)
{
    int temp[en - st + 1];
    int i = st;
    int j = mid + 1;

    for(i = st; i<=mid; i++)
    {
        for(j = mid + 1; j<=en; j++)
        {
            if(arr[i] <= arr[j])
            {
                temp[i] = arr[i];
            }
            else
            {
                temp[j] = arr[j];
            }
        }
    }

    while(i<=mid)
    {
        temp[i] = arr[i];
        i++;
    }

    while(j<=en)
    {
        temp[j] = arr[j];
        j++;
    }
}

void mergeSort(int arr[], int st, int en)
{
    if(st < en)
    {
        int mid = st + (en - st) / 2;

        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, en);

        merge(arr, st, mid, en);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}