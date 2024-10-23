#include <iostream>
#include <string>
using namespace std;

int main() {
    int state = 0; 
    char input;
    string flow[100];  // pang store sa used transportation
    int index = 0;     // index para sa flow array
    int totalFare = 0; // sum para sa total fare

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
            break;  
        }

        int inputColumn = -1;  //used para sa column

    
        switch (input) {
            case 'a': 
                inputColumn = 0;
                flow[index++] = "motor";  
                totalFare += 50;
                break;  
            case 'b': 
                inputColumn = 1;
                flow[index++] = "jeep";  
                totalFare += 13;
                break;  
            case 'c': 
                inputColumn = 2;
                flow[index++] = "ferry";  
                totalFare += 30;
                break;  
            case 'd': 
                inputColumn = 3;
                flow[index++] = "van"; 
                totalFare += 55;
                break;  
            default:
                cout << "Invalid input. Try again.\n";
                continue;
        }

        // Move sa next state based sa current state and input
        state = table[state][inputColumn];
    }
    
    //loop para sa used transportation
    for (int i = 0; i < index; ++i) {
        cout << flow[i];
        if (i != index - 1) {
            cout << " => ";  
        }
    }
    cout << " => done!\n";

    // Check if final or dead state
    if (state == 5) {
        cout << "You have successfully reached your destination!\n";
    } else {
        cout << "You have reached a dead state. You took an invalid route.\n";
    }
    
    cout << "Your total fare will be: P" << totalFare << ".";

    return 0;
}
