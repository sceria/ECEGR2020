// The following code creates pascal's triangle according to how many rows the user requests
// and returns the coefficient the user wants to obtain from the specified row.

// Code by Sean Ceria (9/26/2022)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bico(int power, int index){
    vector<int> start; // old vector/row from P's triangle to work from
	vector<int> next; // next row 
	start.push_back(1);
	start.push_back(1);
    //for loop creates the rows of Pascal's triangle
	for(int i = 0; i<power-1; i++){ 
	    next.clear();//clears next vector, so new next vector can be constructed
	    next.push_back(1); // creates first 1 of the row
		for(int j=0; j<=i+1; j++){ // j var for number of entries per row 
			if (j==i+1){ // will push back a 1 once it's at the end of the vector
			    next.push_back(1);  
			}
			else{ // takes the sum of entries from the previous row and uses it in next vector
			    next.push_back(start.at(j) + start.at(j+1));  
			    }
		}
		start.clear(); // clears the start vector 
		start = next; // makes start vector equal to the newly built vector to 
		               // to work off of it in the next iteration
		}
	//---------------Displays Rows of the vectors-------------------------------
	// For loop to display the vector
	//for (int s=0; s<next.size(); s++){
	//	cout<<next[s]<<" ";
	//}
    //cout << endl;
	//--------------------------------------------------------------------------
	//next.at(index);
	
	// Following if statement covers the indices with a zero coefficient
	int output;
	if((index>power)||(index<0)){
	    output=0;
	}
	else{
	    output=next.at(index);
	}
	return output; // all functions need a return statement
}

int main()
{
    int power;
    int index;
    
    cout<<"Input the degree of the binomial: "; cin >> power;
    cout << endl;
    cout << "Input the the index of the coefficient: "; cin >> index;
    cout << endl;
	
	cout<<bico(power, index); 

    return 0;
}
