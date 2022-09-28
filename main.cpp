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
	for(int i = 0; i<power; i++){ //for loop creates the rows of Pascal's triangle
		for(int j = 0; j<=i+1; j++){ // j var for number of entries per row (one more entry than prev. row)
			if(j == 0||j==i+1){
				next.push_back(1);
			}
			else{
				int sum; // will hold sum of two entries from previous row
				sum = (start.at(i) + start.at(i+1)); 
				next.push_back(sum); // inserts sum into new vector which would again be worked off of to create next row
			}
		for 
		start = next; //
		}
	}
	//---------------Displays Rows of the vectors-----------------------------------------------------------------------------------
	// For loop to display the vector
	for (int s=0; s<next.size(); s++){
		cout<<next[s]<<" ";
	}
    cout << endl;
	//-------------------------------------------------------------------------------------------------
}

int main()
{
    int power;
    int index;
    
    cout<<"Input the degree of the binomial: "; cin >> power;
    cout << endl;
    cout << "Input the the index of the coefficient: "; cin >> index;
    cout << endl;
	
	bico(power, index);

    return 0;
}
