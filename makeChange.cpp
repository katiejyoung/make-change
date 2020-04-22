  
// Katie Young
// CS 325, Homework Assignment #4

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <math.h>

using namespace std;

int readLines(string dataFile);
void lineToArray(vector<int> &vect, string dataString, int length);
void makeChange(int c, int k, int n);
void calcDenominations(vector<int> &denom, int c, int k);
void writeToFile(vector<int> &denom, vector<int> &quant, int c, int k, int n);

int main() {
    int removeFile = remove("change.txt"); // Delete output file in case program has already been run
    string data = "data.txt";
    int success = readLines(data); // Initiate program

    // Output message according to program success
    if (success == 1) {
        cout << "Change calculation complete." << endl;
    }
    else {
        cout << "Error: Failed to open file." << endl;
    }

    return 0;
}

// Reads file line by line and initiates sorting
// Returns 1 if sorting successful
// Returns 0 if file error
int readLines(string dataFile) {
    string fileLine;
    int len;
    int lineNum = 1;
    vector<int> valueVector;

    ifstream inputFile(dataFile.c_str()); // Open passed file

    // If open successful, read lines
    if (inputFile.is_open()) {
        while(getline(inputFile, fileLine)) { // Iterate through file lines
            valueVector.resize(3);

            // Convert line to vector containing c, k and n (respectively)
            lineToArray(valueVector, fileLine, 3);

            if ((valueVector[0] <= 1) || (valueVector[1] < 1)) {
                cout << "Error on line " << lineNum << ": c or k value not valid" << endl;
            }
            else {
                // Find quantity values for each denomination
                makeChange(valueVector[0], valueVector[1], valueVector[2]);
            }

            valueVector.clear(); // Clear vector elements
            lineNum++;
        }

        inputFile.close(); // Close ifstream
        return 1; // Return 1 if successful
    }
    else {
        return 0; // Return 0 if unsuccessful
    }  
}

// Converts a passd string to a vector by separating integers from spaces
void lineToArray(vector<int> &vect, string dataString, int length) {
    int dataItr = 0;
    int vectorItr = 0;
    int isLength = 1;
    int dataValue = 0;
    string dataItem;

    // Iterate through string
    while ((dataItr <= dataString.length()) && (vectorItr < length)) {
        // When separator identified, convert value to integer and append to vector
        if ((dataItr == dataString.length()) || (dataString[dataItr] == ' ') && (dataString[dataItr + 1] != ' ')) {
            dataValue = atoi(dataItem.c_str()); // Convert value to integer
            vect[vectorItr] = dataValue;
            vectorItr++;
            
            dataValue = 0;
            dataItem = "";
        }
        else {
            dataItem += dataString[dataItr]; // Append character to string until separator reached
        }

        dataItr++;
    }
}

// Finds quantity values for each denomination of range: c^0 to c^k
void makeChange(int c, int k, int n) {
    vector<int> denominations;
    vector<int> quantity;
    denominations.resize(k + 1);
    quantity.resize(k + 1);
    calcDenominations(denominations, c, k);
    int q;
    int remainingChange = n;
    int changeVal = k;

    while (changeVal >= 0) {
        q = 0; // Reset quantity value
        while ((remainingChange - denominations[changeVal]) >= 0) {
            remainingChange -= denominations[changeVal];
            q++;
        }

        quantity[changeVal] = q;
        changeVal--;
    }

    writeToFile(denominations, quantity, c, k, n);
}

void calcDenominations(vector<int> &denom, int c, int k) {
    for (int i = 0; i <= k; i++) {
        denom[i] = pow(c, i);
    }
}

void writeToFile(vector<int> &denom, vector<int> &quant, int c, int k, int n) {
    ofstream outputFile("change.txt", ios_base::app); // Open ofstream and enable overwriting
    outputFile << "Data input: c = " << c << ", k = " << k << ", n = " << n << endl;

    for (int i = k; i >= 0; i--) {
        if (quant[i] == 0) {
            outputFile << "Denomination: " << denom[i] << " Quantity: none" << endl;
        }
        else {
            outputFile << "Denomination: " << denom[i] << " Quantity: " << quant[i] << endl;
        }
    }
    outputFile << "--------------------------------" << endl;

    outputFile.close(); // Close ofstream
}