# AutomataFSM

This program is a simple Finite State Machine (FSM) designed as a commuting guide for my younger sister to help her learn how to get from Lapu-Lapu to CIT. It allows the user to select various modes of transportation, and based on their choices, the FSM will either end at a "final state" (reaching the destination) or a "dead state" (invalid route).

Along the way, the program keeps track of the transportation modes used and calculates the total fare based on the choices made. At the end of the journey, it provides a summary of the chosen route and the total fare.


# Modes and States (DFA)
| STATE | a | b | c | d |
|-------|---|---|---|---|
| q0    | 1 | 4 | 4 | 4 |
| q1    | 5 | 5 | 2 | 3 |
| q2    | 5 | 5 | 1 | 3 |
| q3    | 5 | 5 | 4 | 4 |
| q4    | 4 | 4 | 4 | 4 |
| q5    | 4 | 4 | 4 | 4 |


- **Transportation Modes:** The user can choose from four modes of transportation: motor ('a'), jeep ('b'), ferry ('c'), and van ('d').
  
- **FSM States:** The program operates with six states:
  - State 0: Starting state.
  - State 1, 2, 3: states that can lead to the destination or dead state based on the transportation choice.
  - State 4: Dead state (invalid route).
  - State 5: Final state (reached the destination).
- **Fare Calculation:** Each transportation mode has a specific fare, which is added to the total as the user makes their choices.

## How It Works

### 1. User Input
The user is prompted to enter a mode of transportation:
- `a` for motor
- `b` for jeep
- `c` for ferry
- `d` for van
- `x` to exit and analyze the route

### 2. FSM Transition
Based on the input, the FSM moves to the next state using a transition table. The rows represent the current state, and the columns represent the selected transportation mode.

| Current State | Motor (a) | Jeep (b) | Ferry (c) | Van (d) |
|---------------|-----------|----------|-----------|---------|
| 0 (Start)     | 1         | 4        | 4         | 4       |
| 1             | 5         | 5        | 2         | 3       |
| 2             | 5         | 5        | 1         | 3       |
| 3             | 5         | 5        | 4         | 4       |
| 4 (Dead State)| 4         | 4        | 4         | 4       |
| 5 (Final State)| 4        | 4        | 4         | 4       |

- State 0: Starting point.
- State 4: Dead state (invalid route).
- State 5: Final state (reached destination).

### 3. Route Tracking
The program stores each mode of transportation in an array (`flow[]`) as the user makes choices. At the end, the program prints the full route taken, such as:

### 4. Fare Calculation
The program calculates the total fare based on the user's choices. Each transportation mode has a corresponding fare:
- **Motor**: P50
- **Jeep**: P13
- **Ferry**: P30
- **Van**: P55

### 5. End of Journey
- If the user exits (`x`), the program analyzes the route taken.
- The shortest valid journey must end with either:
  - **Motor followed by motor** (`aa`), or
  - **Motor followed by jeep** (`ab`).

# FSM Rules
1. The journey must start with any transportation mode.
2. The journey must end with either a motor or jeep to successfully reach the destination (final state). If the journey includes more than one occurrence of either 'a...a' (motor followed by motor) or 'a...b' (motor followed by jeep), it will go to a dead state. These patterns must only happen once, and anything beyond that will result in an invalid route.
3. Any other sequence will lead to a dead state, meaning the route taken is invalid.
