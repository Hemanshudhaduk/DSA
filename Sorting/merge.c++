#include <iostream>
using namespace std;
int Conquer(int newarr[], int si, int mid, int ei)
{
    int merge[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;
    int len = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (newarr[idx1] < newarr[idx2])
        {
            merge[x++] = newarr[idx1++];
        }
        else
        {
            merge[x++] = newarr[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        merge[x++] = newarr[idx1++];
    }
    while (idx2 <= ei)
    {
        merge[x++] = newarr[idx2++];
    }
    for (auto i : merge)
    {
        len++;
    }
    for (int i = 0, j = si; i < len; i++, j++)
    {
        newarr[j] = merge[i];
    }
}
void  Divied(int newarr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2;
    Divied(newarr, si, mid);
    Divied(newarr, mid + 1, ei);
    Conquer(newarr,si,mid,ei);
}
int main()
{
    int size1, StatIn = 0, EndIn;
    cout<<"\t ID : 22DCE022"<<endl;
    cout << "Enter a Size : ";
    cin >> size1;
    EndIn=size1-1;
    int newarr[size1];
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter' Array Element [" << i << "] : ";
        cin >> newarr[i];
    }
    Divied(newarr,StatIn,EndIn);
     for (int i = 0; i < size1; i++)
    {
        cout <<newarr[i]<<" ";
    }
}