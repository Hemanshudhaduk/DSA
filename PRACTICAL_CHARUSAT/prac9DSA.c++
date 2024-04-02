#include <iostream>

using namespace std;

const int MAX_N = 100000;
void findSeatNumbers(int N, int A[]) {
    int seats[MAX_N] = {0};
    int queueOfPeople[MAX_N];
    int front = 0, rear = -1;

    for (int i = 0; i < N; i++) {
        queueOfPeople[++rear] = i;
    }

    while (front <= rear) {
        int person = queueOfPeople[front++];
        int seat = A[person];

        if (seats[seat - 1] == 0) {
            seats[seat - 1] = person + 1;
        } else {
            seat++;
            queueOfPeople[++rear] = person;
            A[person] = seat;
        }
    }


    for (int i = 0; i < N; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << seats[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    cout<<"Enter the element"<<endl;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int A[MAX_N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        findSeatNumbers(N, A);
    }
    return 0;
}