#include <iostream>
using namespace std;

int main() {
    int state = 0; 
    char input;

    // FSM table
    int table[6][4] = {
        {1, 4, 4, 4},  // state 0 (start with motor)
        {5, 5, 2, 3},  // state 1
        {5, 5, 1, 3},  // state 2
        {5, 5, 4, 4},  // state 3
        {4, 4, 4, 4},  // state 4 (dead state)
        {4, 4, 4, 4}   // state 5 (final state)
    };

    cout << "Hello Cheska! Please choose your first mode of transportation.\n";

    while (true) {  // Infinite loop until 'x' is entered
        cout << "Enter your mode of transportation (a = motor, b = jeep, c = ferry, d = van, x = exit): ";
        cin >> input;
        
        cout << "\n";

        if (input == 'x') {
            cout << "Analyzing your route...\n";
            break;  // Exit the loop
        }

        int inputColumn = -1;  // to store which column to use

        // Determine input column based on input
        switch (input) {
            case 'a': 
                inputColumn = 0; break;  // motor
            case 'b': 
                inputColumn = 1; break;  // jeep
            case 'c': 
                inputColumn = 2; break;  // ferry
            case 'd': 
                inputColumn = 3; break;  // van
            default:
                cout << "Invalid input. Try again.\n";
                continue;
        }

        // Move to the next state based on the current state and input

        state = table[state][inputColumn];

    }
    
    // Check final and dead states
        if (state == 5) {
            cout << "You have successfully reached your destination!\n";
        } else {
            cout << "You have reached a dead state. You took an invalid route.\n";
        }

    return 0;
}
