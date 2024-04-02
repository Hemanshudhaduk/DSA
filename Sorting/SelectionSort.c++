#include <iostream>
using namespace std;
int main()
{
    cout<<"\t ID: 22DCE022"<<endl;
    int countin = 0;
    int countou = 0;
    int sizeA;
    cout << "Enter a Array SizeA : ";
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
        int min = i;
        for (int j = i; j < sizeA ; j++)
        {
            if (arr[min] > arr[j])
            {
                countin++;
                min = j;
            }
        }
        countou++;
        int temp;
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    cout << endl;
    cout << "\tAfter Sorting Array" << endl;
    for (int i = 0; i < sizeA; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl
         << "Number of Iteration in inner loop : " << countin<<endl;
    cout << "Number of Iteration in inner loop : " << countou;
}