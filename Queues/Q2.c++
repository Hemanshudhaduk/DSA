#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector <int> vssum(vector<int> &arr ,int k){
        deque<int> dq;
        vector<int>res;
        for(int i=0;i<k;i++){
            while(not dq.empty() and arr[dq.back()] < arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(arr[dq.front()]);
        for(int i=k;i<arr.size();i++){
            int curr = arr[i];
            if(dq.front() == (i-k))
            dq.pop_front();
            while(not dq.empty() and arr[dq.back()]<arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res;
    }
int main(){
    vector<int> v(8);
    for(int i=0;i<v.size();i++){
        cout<<"Enter a element : ";
        cin>>v[i];
    }
    vector<int>res = vssum(v,3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"   ";
    }
}
