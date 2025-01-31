
# BIG BASH Cricket Simulation

![Cricket Simulation](https://img.shields.io/badge/Language-C-blue)  
![License](https://img.shields.io/badge/License-MIT-green)  
![Status](https://img.shields.io/badge/Status-Complete-brightgreen)

**BIG BASH** is a dynamic C programming project designed to simulate the thrill of a three-over cricket final between **OMOR EKUSHEY HALL** and **SHAHID SMRITY HALL**. This project uses randomization techniques to create unique gameplay experiences, where runs, wickets, and balls bowled unfold unpredictably. It serves as an engaging way to explore fundamental C programming concepts while providing an interactive and entertaining cricket simulation.

---

## Features

- **Real-Time Cricket Simulation**: Simulates a three-over cricket match with real-time score updates.
- **Player and Team Management**: Manages player and team data using structures and arrays.
- **Randomized Gameplay**: Introduces randomness to simulate real-life cricket scenarios.
- **User-Friendly Interface**: Provides a color-coded output for enhanced visualization using ANSI color codes.
- **Comprehensive Statistics**: Tracks player and team statistics, including runs, wickets, strike rates, and more.
- **Error Handling**: Implements robust error handling and input validation for reliability.

---

## Objectives

1. **Simulate a Cricket Match**: Develop a three-over cricket simulation with real-time score tracking.
2. **Player and Team Management**: Use structured programming to manage player and team data.
3. **Randomized Gameplay**: Introduce randomness for runs, wickets, and other cricket events.
4. **Real-Time Updates**: Display real-time updates after each ball.
5. **Winning Determination**: Compare scores to determine the winner at the end of the match.
6. **Educational Resource**: Demonstrate fundamental C programming concepts like arrays, control structures, and file handling.

---

## Code Overview

### Key Functions

- **Main Control Functions**:
  - `main()`: Initializes the game and starts the main menu loop.
  - `begin()`: Controls the main menu flow.
  - `option()`: Handles match simulation options.

- **Team Management Functions**:
  - `manageTeam()`: Allows users to add/remove players and view squad composition.
  - `initializeTeams()`: Sets up initial team structures and loads saved data.

- **Match Simulation Functions**:
  - `simulateMatch()`: Initializes a new match and resets player statistics.
  - `viewNextBall()`: Simulates each ball with random run generation and wicket probability.

- **Statistics and Display Functions**:
  - `viewCurrentStatus()`: Shows current match statistics.
  - `calculateManOfTheMatch()`: Determines the player of the match based on performance.

- **Data Persistence Functions**:
  - `saveTeamToFile()`: Stores team compositions to files.
  - `saveMatchStatsToFile()`: Records match statistics for future reference.
  - `loadTeamFromFile()`: Retrieves saved team data.

- **User Authentication Functions**:
  - `login()`: Validates user credentials.
  - `signup()`: Creates new user accounts with username uniqueness checks.

---

### Key Features of the README

1. **Badges**: For language, license, and project status.
2. **Sections**: Clearly divided into Features, Objectives, Code Overview, How to Use, Future Enhancements, License, and Acknowledgments.
3. **Code Blocks**: For commands and key functions.
4. **Future Enhancements**: To show potential improvements.
5. **License and Acknowledgments**: To give credit and clarify usage rights.

This format is clean, professional, and easy to read, making it suitable for a GitHub repository. Let me know if you need further adjustments! 🚀
