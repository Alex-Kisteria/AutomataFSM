#include <iostream>
using namespace std;

int main() {
    int state = 0; 
    char input;

    // Transition table
    int table[6][4] = {
        {1, 4, 4, 4},  // state 0 
        {5, 5, 2, 3},  // state 1
        {5, 5, 1, 3},  // state 2
        {5, 5, 4, 4},  // state 3
        {4, 4, 4, 4},  // state 4 (dead state)
        {4, 4, 4, 4}   // state 5 (final state)
    };

    cout << "Hello Cheska! Please choose your first mode of transportation.\n";

    while (true) {  
        cout << "Enter your mode of transportation (a = motor, b = jeep, c = ferry, d = van, x = exit): ";
        cin >> input;
        
        cout << "\n";

        if (input == 'x') {
            cout << "Analyzing your route...\n";
            break;  // Exit the loop
        }

        int inputColumn = -1;  //used for the column

        // Determine input column based on input
        switch (input) {
            case 'a': 
                inputColumn = 0; break;  // column 0 para sa motor
            case 'b': 
                inputColumn = 1; break;  // column 1 para sa jeep
            case 'c': 
                inputColumn = 2; break;  // column 2 para sa ferry
            case 'd': 
                inputColumn = 3; break;  // column 3 para sa van
            default:
                cout << "Invalid input. Try again.\n";
                continue;
        }

        // Move sa next state based sa current state and input
        state = table[state][inputColumn];

    }
    
    // Check final or dead state
        if (state == 5) {
            cout << "You have successfully reached your destination!\n";
        } else {
            cout << "You have reached a dead state. You took an invalid route.\n";
        }

    return 0;
}
