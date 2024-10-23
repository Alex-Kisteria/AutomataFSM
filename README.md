# AutomataFSM

This program is a simple Finite State Machine (FSM) designed as a commuting guide for my younger sister to help her learn how to get from Lapu-Lapu to CIT. It allows the user to select various modes of transportation, and based on their choices, the FSM will either end at a "final state" (reaching the destination) or a "dead state" (invalid route).

Along the way, the program keeps track of the transportation modes used and calculates the total fare based on the choices made. At the end of the journey, it provides a summary of the chosen route and the total fare.


# Modes and States
| STATE | a | b | c | d |
| q0 | 1 | 4 | 4 | 4 |
| q1 | 5 | 5 | 2 | 3 |
| q2 | 5 | 5 | 1 | 3 |
| q3 | 5 | 5 | 4 | 4 |
| q4 | 4 | 4 | 4 | 4 |
| q5 | 4 | 4 | 4 | 4 |

- Transportation Modes: The user can choose from four modes of transportation: motor ('a'), jeep ('b'), ferry ('c'), and van ('d').
-FSM States: The program operates with six states:
State 0: Starting state.
State 1, 2, 3: states that can lead to the destination or dead state based on the transportation choice.
State 4: Dead state (invalid route).
State 5: Final state (reached the destination).
-Fare Calculation: Each transportation mode has a specific fare, which is added to the total as the user makes their choices.


# FSM Rules
1. The journey must start with any transportation mode.
2. The journey must end with either a motor or jeep to successfully reach the destination (final state).
3. Any other sequence will lead to a dead state, meaning the route taken is invalid.
