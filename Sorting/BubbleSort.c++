#include <iostream>
using namespace std;
int main()
{
    int sizeA;
    int count = 0;
    cout << "Enter a Array Size : ";
    cin >> sizeA;
    int arr[sizeA];
    for (int i = 0; i < sizeA; i++)
    {
        cout << "Array Element A[" << i << "] : ";
        cin >> arr[i];
    }
    cout << "\tBefor Sorting Array" << endl;
    for (int i = 0; i < sizeA; i++)
    {
        cout << arr[i] << "  ";
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
                count++;
            }
        }
    }
    cout << endl;
    cout<<"\t ID : 22DCE022"<<endl;
    cout << "\tAfter Sorting Array" << endl;
    for (int i = 0; i < sizeA; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl
         << "Number of Iteration : " << count;
}