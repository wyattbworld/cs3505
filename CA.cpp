/*
Cellular Automata: This program runs a one dimensions Cellular Automata Simulation similar to "Conway's Game of Life".
It will ask the user to input a number from 0 to 255 that coorelates with a binary translation that describes the rules of the game.
The binary array maps to the rules as follows, if a 0 is in the spot the rule inhabits the cell will die when that rule applies to it, if it is one it will be alive.
index 0: [1,1,1]
index 1: [1,1,0]
index 2: [1,0,1]
index 3: [1,0,0]
index 4: [0,1,1]
index 5: [0,1,0]
index 6: [0,0,1]
index 7: [0,0,0]
It will then run the simulation for 49 consecutive generations on 64 value long array with the 32nd index starting as alive.

*/
void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSsetArray[8]);
void displayCurrentGeneration(int currentGenerationArray[], int currentGenerationArrayCount);
void convertNeighborhoodToIndex(int leftNeighbor, int current, int rightNeigbhor);
void computeNextGeneration(int currentGenerationArray[], int nextGenerationArray[], int generationArrayCount, int ruleSetArray[8]);

int main(){
    return 0;
}

/// @brief Converts a rule set number to a preexisting rule set array. The rule set array will be a conversion of the rule set number
/// in binary going from LEFT TO RIGHT @example ruleset 5 = [1,0,1,0,0,0,0,0]
/// @param ruleSetNumber a number between 0 and 255 that represenets the ruleset you would like to implement.
/// @param rulSsetArray an array OF LENGTH 8 that the ruleset will be mapped on to.
void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSsetArray[8]){

}

/// @brief Prints the values in an array to the console with a space for every 0 and a '#' for every 1.
/// @param currentGenerationArray The array you would like to print. MUST ONLY HAVE 1s or 0s
/// @param currentGenerationArrayCount The count of the array you would like to print.
void displayCurrentGeneration(int currentGenerationArray[], int currentGenerationArrayCount){

}

/// @brief Converts 3 cells from binary to decimal.
/// @param leftNeighbor The neighbor left of the cell you are currently examining (multiplied by 4)
/// @param current The cell you are currently examining (multiplied by 2)
/// @param rightNeigbhor The cell to the right of the cell you are currently examinging (multiplied by 1)
void convertNeighborhoodToIndex(int leftNeighbor, int current, int rightNeigbhor){

}
/// @brief Modifies the nextGeneration Array with the results of the currentGeneration and the given ruleset.
/// @param currentGenerationArray The current generation you would like to compute on ONLY 0s and 1s
/// @param nextGenerationArray The array the next generation will be stored in
/// @param generationArrayCount The number of elements in the currentGeneration Array
/// @param ruleSetArray The binary array describing the rules of the simulation.
void computeNextGeneration(int currentGenerationArray[], int nextGenerationArray[], int generationArrayCount, int ruleSetArray[8]){

}


