
#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int i = start-1;

	for(int j =start ;j<end ;j++){
		if(arr[j]<pivot){
			i++;
			int temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	i++;
	int temp = arr[i];
	arr[i] = pivot;
	arr[end] = temp;
	return i;
}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

int main()
{
    cout<<"\t ID : 22DCE022 "<<endl;
    int sizeA;
    cout << "Enter a Array SizeA : ";
    cin >> sizeA;
    int arr[sizeA];
    for (int i = 0; i < sizeA; i++)
    {
        cout << "Array Element A[" << i << "] : ";
        cin >> arr[i];
    }

	quickSort(arr, 0, sizeA - 1);

	for (int i = 0; i < sizeA; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
