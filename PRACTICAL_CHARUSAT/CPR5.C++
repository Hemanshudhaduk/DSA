#include <iostream>
#include <algorithm>
using namespace std;
int Max_Area_Rectangle(int arr[], int size1)
{
    int a = -1;
    int b = -1;
    for (int i = 0; i < size1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            if (a == -1)
            {
                a = arr[i];
            }
            else if (b == -1)
            {
                b = arr[i];
            }
        }
    }
    if(a!=-1 && b!=-1)
    return a*b;
    return -1;
}
int main()
{
    int sizeA;
    cout << "Enter a Array SizeA : ";
    cin >> sizeA;
    int arr[sizeA];
    for (int i = 0; i < sizeA; i++)
    {
        cout << "Array Element A[" << i << "] : ";
        cin >> arr[i];
    }
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeA - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int result = Max_Area_Rectangle(arr, sizeA);
    cout << result;
}