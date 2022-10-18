// Code by Sean Ceria
// October 17, 2022
// CPSC 2430 Assignment 2
//---------------------------------------------------------
#include <iostream>
#include <cmath>
#include <stdlib.h> // needed to access absolute value function

using namespace std;

//------------PROBLEM 1: Big O-------------------------
// The big O of T(n)= 11n^3 + log(n) + 12*sqrt(n) is O(n)=n^3. One can prove that
// T(n) is O(f(n)) if there exists constant C (where C>0) and N (where N>=0)
// such that for all n>=N, T(n)<=C*f(n).
// Constant C = 12 since C is the integer constant that 
// would make the function the smallest upper bound of T(n). We can then find 
// where the function, 12n^3, intersects T(n) and becomes the smallest upper 
// bound function. Where they intersect is value N. After using graphing tools
// to plot 12n^3 and T(n), they intersected at approximately x=2.756,
// making N = 2.756. These values for C and N satisfy the definition, and 
// justify that T(n) is indeed O(f(n)).
//------------PROBLEM 1: Big O-------------------------

//------------PROBLEM 2: Recursive Sum-----------------
///*
int sumDigits (int number){
    int holder; // local variable which will hold different values each function call
    if (number==0){
        return 0;
    }
    else{
        holder = number%10; // stores the left most digit in holder variable
        number = number/10; // "deletes" the left most digit and aquires new number value
        return (holder + sumDigits(number)); // completes addition while calling itself
    }
}
//*/
//------------PROBLEM 2: Recursive Sum-----------------

//------------PROBLEM 3: 5th Root Recursive------------
/*
double root5(double n, long double y){
    // variables used for arithmetic
    long double YtoTheFifth = pow(y,5); // y^5 in YtoTheFifth variable
    long double yToTheFourth = pow(y,4); // y^2 in ySquared variable
    
    if (abs(YtoTheFifth - n) < 0.00001){ // if abs(y^5-n) < 0.00001...
        return ((4*y+(n/(yToTheFourth)))/5); // base case (stops the recursion)
    }
    else{
        return root5(n,y+0.1); // increments the guess, y, by 0.1
    }
    
}
*/
//------------PROBLEM 3: 5th Root Recursive------------

//------------PROBLEM 4: Egyptian Division-------------
/*
// REMEMBER, DIVISOR is "divise by" while DIVIDEND is what youre dividing

// helper function for adding
int doubleInt(int number){
    return (number = number + number);
}
//-------------------------------------------------------------------------
// helper function for subtracting
int halveInt(int number){ // base case for 2/2
    if(number-2==0){
        return 1;
    }
    else if(number==0){ // base case for dividing zero by 2
        return 0;
    }
    else if (number < 2){ // base case for 1/2; will return 0
        return 0;
    }
    else{
       return (1+halveInt(number-2)); 
    } // sums all the times it needs to call halveInt, which becomes the quotient
}

int egyptDivision(int dividend, int divisor){
    // variable definition and initialization
    int A, B, C, D;
    A = 1; 
    B = divisor;
    C = dividend;
    D = 0;
    
    while (B<=C){
        A = doubleInt(A);
        B = doubleInt(B);
    }

    while(A>=1){
        if (B<=C){
            D = D+A;
            C = C-B;
            A = halveInt(A); // halves A, becoming the new A
            B = halveInt(B); // halves B, becoming the new B
        }
        else{
            A = halveInt(A); // halves A, becoming the new A
            B = halveInt(B); // halves B, becoming the new B
        }
    }
    return D;
}
*/
//------------PROBLEM 4: Egyptian Division-------------

//------------PROBLEM 5: Ramanujan---------------------
/*
// global variable, depth and index
int maxDepth; // holds the variable of the depth specified by user
int index=-1; // will use to be depth starting from zero

long double ramanujan(int DepthDecr){ // maxDepth = DepthDecr which will decrement every function call
    index++; // increment index to be the current depth
    if(maxDepth==0){ // base case for if depth specified by user is zero
        return ((index+1)*sqrt(6+index));
    }
    else if (DepthDecr==0){ // base case for when it reaches the depth specified by user
        return ((index+1)*sqrt(6+index));
    }
    else{
        return((index+1)*sqrt(6+index+ramanujan(DepthDecr-1)));
    }
    // For a depth of infinity, the value of the expression is 4!!!!
}
*/
//------------PROBLEM 5: Ramanujan---------------------


//------------------MAIN-------------------------------
int main()
{
//------------PROBLEM 2: Recursive Sum-----------------
///*
    int number = 123456; // number taking the sum of digits of
    cout << sumDigits(number); // sumDigits function call
    //*/
//------------PROBLEM 2: Recursive Sum-----------------

//------------PROBLEM 3: 5th Root Recursive------------
/*
    double n; // Number user wants to find 5th root of
    cout << "What number should we take the 5th root of?" << endl;
    cin >> n;
    long double y = 1.0; // will be used for our guesses
    cout << root5(n,y);
    */
//------------PROBLEM 3: 5th Root Recursive------------

//------------PROBLEM 4: Egyptian Division-------------
/*
    int dividend, divisor;
    cout<<"What number do you want to divide?" << endl;
    cin >> dividend;
    cout << endl << "What number do you want to divide " << dividend << " by?" << endl;
    cin >> divisor;
    
    //cout<<egyptDivision(dividend, divisor); // calling the function
    if(divisor==0){
        cout << endl<< "DIVIDE BY ZERO ERROR!!!" << endl;
    }
    else{
    cout << egyptDivision(dividend, divisor);
    }
*/
//------------PROBLEM 4: Egyptian Division-------------

//------------PROBLEM 5: Ramanujan---------------------
/*
    int depth;
    cout << "What's the desired depth of the nested radical?" << endl;
    cin >> depth;
    maxDepth = depth;
    cout << endl << ramanujan(depth);
*/
//------------PROBLEM 5: Ramanujan---------------------

    return 0;
}
