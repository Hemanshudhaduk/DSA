#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hash function
int hashFunction(int x) {
    return (x % 18) + 2;
}

int main() {
    cout<<"22DCE022"<<endl;
    const int SIZE = 20;
    int arr[SIZE] = {0}; // Initialize array with all elements as 0
    int num, key, probes;

    // Generate 15 random numbers between 1,00,000 to 9,99,999
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < 15; i++) {
        num = rand() % 900000 + 100000; // Generate a random number between 100000 and 999999
        key = hashFunction(num); // Get the hash key for the number
        probes = 0; // Initialize number of probes to 0
        // Linear probing to avoid collisions
        while (arr[key] != 0 && probes < SIZE) {
            key = (key + 1) % SIZE; // Move to next index
            probes++; // Increment number of probes
        }
        if (probes == SIZE) {
            cout << "Error: Array is full" << endl;
            return 1;
        }
        arr[key] = num; // Store number in array at the calculated index
    }

    // Display the final values of the array
    for (int i = 0; i < SIZE; i++) {
    cout << "Final values of the array:" << endl;
        cout << arr[i] << " ";
    }
    cout << endl;

}

