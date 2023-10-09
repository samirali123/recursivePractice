// Samir Ali
// assignment2.cpp
// CPSC 2430
// Professor Diaz

// Purpose: Multiple methods displaying usage of recursion with differtent parameters, and variable types. 
// First task find the total amount of balls in a square-pyramid stack of tennis balls using the parameter given of height. 
// The second task is to convert a given integer into binary, of type string. The third task finds the 5th root 
// using the Newton-Raphson method. The final task solves the "Ramanujan sqrt" equation, to a certain depth, and to infinity.
// main() then outputs these results in a clean, readable manner with context.

#include <iostream>
#include <cmath>
using namespace std;

// Desc: Finds the total amount of tennisballs of a square-pyramid stack, with a set rate of growth. 
// Pre: The amount of levels within the pyramid stack of tennisballs, or height.
// Post: an integer of the sum of balls within the stack.
int tennisBalls(int height, int total);

// Desc: Converts a given integer into binary of type string.
// Pre: Any integer wanting to be converted
// Post: A string holding the binary definition of the int given previously
string decToBase2(int x);

// Desc: Finds the 5th root of a given number using the Newton-Raphson method of slowly closing the gap of the intial guess.
// Pre: An int that the user wants to find the 5th root of
// Post: A variable of type double that is the 5th root of the previous number given.
double root5(int findRoot, double guess);

// Desc: Solves the "ramanujan" sqrt equation, using the depth obtained from the user.
// Pre: "depth", how far you want to go into the theory
// Post: The combined result of solving the equation, in type double.
double ramanujan(int depth, double val);

int main(int argc, char* argv[]) {

    if (argc != 5) {
        cout << "Usage: <tennis_ball_height> <binary_convert_int> <5th_root> <ramanujan>" << endl;
        return 0; 
        
    }

    int tennisHeight = atoi(argv[1]); // height of the tennisball stack
    int tennisTotal = tennisBalls(tennisHeight, 0); // total amount of balls in stack
    
    cout << "tennisBalls result at level " << tennisHeight << " is: " 
    << tennisTotal << endl;

    int preBinary = atoi(argv[2]); // number before the binary conversion
    string postBinary = decToBase2(preBinary); // number after binary conversion, in type string
    cout << "decToBase2 binary string for " << preBinary << " is: "
    << postBinary << endl;

    int findRoot5 = atoi(argv[3]); // number wanting to find the 5th root of
    double foundRoot5 = root5(findRoot5, 1.0); // result of finding the 5th root of "findRoot5"
    cout << "root5 the fifth root of " << findRoot5 << " is: " 
    << foundRoot5 << endl;

    int ramDepth = atoi(argv[4]); // depth of how far you want to go into ramanujan's theory
    double ramResult = ramanujan(ramDepth, 1); // result of ramanujan's theory
    cout << "Ramanujan result at level " << ramDepth << " is: "
    << ramResult << endl;

    ramDepth = 10000; // simulating infinity
    ramResult = ramanujan(ramDepth, 1); // result of infinity
    cout << "Ramanujan result carried to infinity is: "
    << ramResult << endl;




}

int tennisBalls(int height, int total) {
    if (height == 0) {
        total = 0;
        return total;
    }
    if (height == 1) {
        total += 1;
        return total;
    }

    return tennisBalls(height - 1, total + pow(height, 2));

}

string decToBase2(int num) {
    if (num == 0) {
        return "";
    }

    return decToBase2(num / 2) + to_string(num % 2);
}

double root5(int findRoot, double guess) {
    double errorMargin = 0.00001;
    double currentError = abs(pow(guess, 5) - findRoot);
    if (currentError <= errorMargin) {
        return guess;
    }
    return root5(findRoot, guess - (pow(guess, 5) - findRoot) / (5 * pow(guess, 4)));
}

double ramanujan(int depth, double val) {
    
    if (depth == -1) {
        return 0;
    }
    return sqrt((val + 5) + (val + 1) * ramanujan((depth - 1), (val + 1)));

}