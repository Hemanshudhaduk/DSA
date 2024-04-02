#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout<<"Enter the number of element : ";
    cin >> N;

    vector<int> tickets(N);
    vector<int> seats(N);
    cout << "Enter the element ";
    for (int i = 0; i < N; i++) { // 1 2 3 2 4 
        cin >> tickets[i];
    }

    vector<bool> seatOccupied(N + 1, false);

    for (int i = 0; i < N; i++) {
        int ticket = tickets[i]; // 1
        while (seatOccupied[ticket]) {
            ticket++;
        }
        seatOccupied[ticket] = true;
        seats[i] = ticket;
    }
    cout<<"\t ID : 22DCE022 "<<endl;
    for (int i = 0; i < N; i++) {
        cout<<seats[i]<<"  ";
    }

    return 0;
}