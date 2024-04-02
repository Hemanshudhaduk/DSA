#include <iostream>
using namespace std;
int main()
{
    int sizeA;
    int count = 0;  // 9 8 6 5 4 3 2 
    //  8 9 6 5 4 3 2
    // 6 8 9 
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
    for (int i = 1; i < sizeA; i++)
    {
            int key =arr[i];
            int j =i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
    }
    cout << endl;
    cout << "\tAfter Sorting Array" << endl;
    for (int i = 0; i < sizeA; i++)
    {
        cout << arr[i] << "  ";
    }
}