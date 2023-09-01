/*
@Author: C Wyatt Bruchhauser
@date: August 27, 2023
@Professor: David Johnson
@Class: CS3505 - Software Practice II
@Organization: University of Utah Kalhert School of Computing
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
#include <iostream>
using std::cout;
using std::cin;
using std::string;

void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSsetArray[8]);
void displayCurrentGeneration(int currentGenerationArray[], int currentGenerationArrayCount);
int convertNeighborhoodToIndex(int leftNeighbor, int current, int rightNeigbhor);
void computeNextGeneration(int currentGenerationArray[], int nextGenerationArray[], int generationArrayCount, int ruleSetArray[8]);
void clearArray(int array[], int count);
void copyArray(int originArray[], int destinationArray[], int count);
void printArray(int array[], int count);
bool isValidRuleSetNumber(string text);

int main(){

    string ruleSetInput;
    int ruleSetNumber;
    int ruleSetArray[8];

    int testGeneration [10]= {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    int nextTestGeneration [10];
    int testRuleSet [8] = {0,0,1,0,0,0,0,0};
    computeNextGeneration(testGeneration, nextTestGeneration, 10, testRuleSet);
    printArray(nextTestGeneration, 10);

    std::cout << "Welcome to Cellular Automata!" <<std::endl;
    std::cout << "Please input your ruleset as a single integer from 0-255:" <<std::endl;
    std::cin >> ruleSetInput;

    if (!isValidRuleSetNumber(ruleSetInput)) 
    {
        std::cout << "Invalid input. Exiting Program." << std::endl;
        return 0;
    }

    ruleSetNumber = stoi(ruleSetInput);

    convertRuleSetNumberToRuleSetArray(ruleSetNumber, ruleSetArray);


    int currentGeneration [64];
    int nextGeneration [64];

    // create the first generation
    clearArray(currentGeneration, 64);
    currentGeneration[32] = 1;
    displayCurrentGeneration(currentGeneration, 64);
    
    for (int i = 0; i < 49; i++){
        computeNextGeneration(currentGeneration, nextGeneration, 64, ruleSetArray);
        copyArray(nextGeneration, currentGeneration, 64);
        displayCurrentGeneration(currentGeneration, 64);
    }

    return 0;
}

/// @brief Converts a rule set number to a preexisting rule set array. The rule set array will be a conversion of the rule set number
/// in binary going from LEAST SIGNINGICANT DIGIT TO MOST SIGNIFICANT DIGIT @example ruleset 5 = [1,0,1,0,0,0,0,0]
/// @param ruleSetNumber a number between 0 and 255 that represenets the ruleset you would like to implement.
/// @param rulSsetArray an array OF LENGTH 8 that the ruleset will be mapped on to.
void convertRuleSetNumberToRuleSetArray(int ruleSetNumber, int ruleSetArray[8]){
    //Check if our rule set number is in bound.
    if (ruleSetNumber < 0 || ruleSetNumber > 255)
    {
        throw std::invalid_argument("Rule Set Number out of range!");
    }
    
    clearArray(ruleSetArray, 8);

    //Converts the ruleSetNumber into binary
    int currIndex = 0; //Keeps track of the current place we are look at in the ruleSetArray.
    while (ruleSetNumber != 0)
    {
        if(ruleSetNumber%2 == 1)
        {
            ruleSetArray[currIndex] = 1;
        }
        ruleSetNumber = ruleSetNumber/2;
        currIndex++;
    }

}

/// @brief Prints the values in an array to the console with a space for every 0 and a '#' for every 1.
/// @param currentGenerationArray The array you would like to print. MUST ONLY HAVE 1s or 0s
/// @param currentGenerationArrayCount The count of the array you would like to print.
void displayCurrentGeneration(int currentGenerationArray[], int currentGenerationArrayCount){
    for (int i = 0; i < currentGenerationArrayCount; i++)
    {
        if (currentGenerationArray[i] == 0)
        {
            std::cout << " ";
        }
        else
        {
            std::cout << "#";
        }
    }

    std::cout << "" << std::endl;
}

/// @brief Converts 3 cells from binary to decimal.
/// @param leftNeighbor The neighbor left of the cell you are currently examining (multiplied by 4)
/// @param current The cell you are currently examining (multiplied by 2)
/// @param rightNeigbhor The cell to the right of the cell you are currently examinging (multiplied by 1)
int convertNeighborhoodToIndex(int leftNeighbor, int current, int rightNeigbhor){

    return leftNeighbor*4 + current*2 + rightNeigbhor;

}

/// @brief Modifies the nextGeneration Array with the results of the currentGeneration and the given ruleset.
/// @param currentGenerationArray The current generation you would like to compute on ONLY 0s and 1s
/// @param nextGenerationArray The array the next generation will be stored in
/// @param generationArrayCount The number of elements in the currentGeneration Array
/// @param ruleSetArray The binary array describing the rules of the simulation.
void computeNextGeneration(int currentGenerationArray[], int nextGenerationArray[], int generationArrayCount, int ruleSetArray[8]){
    //First
    nextGenerationArray[0] = currentGenerationArray[0];
    
    //Middle
    int neigbhborIndex;
    for (int i = 1; i < generationArrayCount - 1; i++){
        neigbhborIndex = convertNeighborhoodToIndex(currentGenerationArray[i-1], currentGenerationArray[i], currentGenerationArray[i+1]);
        nextGenerationArray[i] = ruleSetArray[7-neigbhborIndex];
    }

    //Last
    nextGenerationArray[generationArrayCount - 1] = currentGenerationArray[generationArrayCount - 1];
}

/// @brief Helper method to convert any array into only zeroes.
/// @param array the array you want to clear
/// @param count how large the array is
void clearArray(int array[], int count){
    for (int i = 0; i < count; i++)
    {
        array[i] = 0;
    }
}

/// @brief Copies the content of one array to another
/// @param originArray The array you want to copy
/// @param destinationArray The array you want to copy to
/// @param count The size of both arrays
void copyArray(int originArray[], int destinationArray[], int count){
    for (int i = 0; i < count; i++)
    {
        destinationArray[i] = originArray[i];
    }
}

/// @brief Prints an array for testing purposes.
/// @param array the array you want to print.
/// @param count the size of the array.
void printArray(int array[], int count){
    for (int i = 0; i < count; i++)
        {
            std::cout << array[i] <<std::endl;
        }
}


/// @brief Checks if the given text is a valid rule set number meaning that it is 1) An integer and 2) between 0 and 255
/// @param text the text you want to check
/// @return true if it is valid, false if not.
bool isValidRuleSetNumber(string text)
{
    //Check that there is text
    if (text.size() == 0)
    {
        return false;
    }

    //Check that all characters in the strings are digits.
    for (int i = 0; i < text.size(); i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }

    //Check if the number is in the correct range.
    if (stoi(text) < 0 || stoi(text) > 255) 
    {
        return false;
    }

    return true;
}


