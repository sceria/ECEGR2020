#include <iostream>
#include <string>
using namespace std;

//-----------------------GRADE CONVERTER CODE-----------------------------
char GradeConverter(int grade){
    if(grade >=0 && grade <=59){ // [0, 59] is grade range for F grade
        cout << "This is a F letter grade.";
    }
    else if(grade>=60 && grade<=69){ // [60, 69] is grade range for D grade
        cout << "This is a D letter grade.";
    }
    else if(grade>=70 && grade<=79){ // [70, 79] is grade range for C grade
        cout << "This is a C letter grade.";
    }
    else if(grade>=80 && grade<=89){ // [80, 89] is grade range for B grade
        cout << "This is a B letter grade.";
    }
    else if (grade>=90 && grade<=100){ // [90, 100] is grade range for A grade
        cout << "This is an A letter grade.";
    }
    return 0;
}
//-----------------------GRADE CONVERTER CODE-----------------------------
//-----------------------BOX CLASS CODE-----------------------------------
/*
class Box
{
    public:
    
    // Class elements
    double length;
    double width;
    double height;
    
    
    // Methods
    void print(){ // will be used to return the box's dimensions
        cout << "Box length: " << length << endl;
        cout << "Box width: " << width << endl;
        cout << "Box height: " << height << endl;
        
    }
    
};

Box AddBox(Box box1, Box box2){
    Box Box3; // creation of Box3 object as it utilizes the dimensions of box1 and box2
    Box3.height = box1.height + box2.height;
        if(box1.length <= box2.length){
            Box3.length = box2.length;
        }
        else if(box1.length>=box2.length){
            Box3.length = box1.length;
        }
        
        if(box1.width <= box2.width){
            Box3.width = box2.width;
        }
        else if(box1.width >= box2.width){
            Box3.width = box1.width;
        }
    
    return Box3;
}
*/
//-----------------------BOX CLASS CODE-----------------------------------
//------------------------PALINDROME CODE---------------------------------
/*
int PalinTest(string word){
    int flag; // indicator for whether word is a palindrome or not
    int s = word.size(); // setting limit for the foor loop
    
    // Following for loop converts word to all lowercase
    for(int c = 0; c<s; c++){ // following range is the capital letters via ASCII
        if (word[c]>=65 && word[c]<=90){
            word[c]=word[c] + 32; // add 32 gives the letter its corresponding lowercase
        }
        else{
            word[c]=word[c];
        }
    }
    
    int start = 0; // first index of word
    int last = s-1; // last index of word
    while(start<s){
        if(word[start]==word[last]){
            start++; // increments one character of string to the right
            last--; // decrements one character of string to the left
            flag = 1; // palindrome indicator
        }
        else{
            flag = 0;
            break;
        }
    }
    
    if(flag==1){
        return 1;
    }
    else if (flag==0){
        return 0;
    }

}
*/
//------------------------PALINDROME CODE---------------------------------



int main()
{
//-----------------------GRADE CONVERTER CODE-----------------------------
    // */
    int grade;
    cout<< "Please enter a grade: ";
    cin>> grade;
    cout<< endl;
    while(1){
        if (grade<0 || grade >100){
            cout<< "That is an invalid grade. Please try again: ";
            cin>> grade;
        }
        else{
            GradeConverter(grade);
            break;
        }
    }
    return 0;
    // */
//-----------------------GRADE CONVERTER CODE-----------------------------
//------------------------PALINDROME---------------------------------
/*
    string word;
    cout<<"What word would you like to test to be a palindrome?" << endl;
    cin >> word;
    cout << endl;
    //cout << word.size(); // used to test function that obtains string length
    cout << PalinTest(word);
    return 0;
 */   
//------------------------PALINDROME---------------------------------
//-----------------------BOX CLASS CODE-----------------------------------
  /*
  Box box1;
    Box box2;
    double bleng1, bleng2, bwid1, bwid2, bhei1, bhei2;
    
    // User input for box1 dimensions
    cout << "Length of the first box: " << endl;
    cin >> bleng1;
    cout << "Width of the first box: " << endl;
    cin >> bwid1;
    cout << "Height of the first box: " << endl;
    cin >> bhei1;
    
    // setting dimensions for box1
    box1.length=bleng1;
    box1.width=bwid1;
    box1.height=bhei1;
    
    // User input for b0x2 dimensions
    cout << "Length of the second box: " << endl;
    cin >> bleng2;
    cout << "Width of the second box: " << endl;
    cin >> bwid2;
    cout << "Height of the second box: " << endl;
    cin >> bhei2;
    
    // setting dimensions for box2
    box2.length=bleng2;
    box2.width=bwid2;
    box2.height=bhei2;
    
    AddBox(box1, box2).print(); // accesses the methods since its type box 
    
    return 0;
    */
  //-----------------------BOX CLASS CODE-----------------------------------
}
