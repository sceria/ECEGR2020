#include <iostream>
#include <string>
#include "management.h" //references the header file

using namespace std;

int main ()
{
    int decision;
    cout << "Welcome to the Animal Shelter!" << endl << endl;
    while(1){ // produces a menu/user interface that takes in integers for corresponding actions
        cout << endl << "What would you like to do?" << endl; 
        cout << "1) Add animal to system" << endl;
        cout << "2) Adopt animal" << endl;
        cout << "3) Quit system" << endl;
        cin >> decision;
        if(decision ==  1){
            add_animal();
        }
        else if(decision == 2){
            
            int preference;
            cout << "What type of animal would you like to adopt?" << endl;
            cout << "1) Dog" << endl << "2) Cat" << endl << "3) Surprise me" << endl;
            cin >> preference;
            adopt(preference); // call the adopt function
        }
        else if(decision == 3){
            cout << "Thank you for visiting the animal shelter!";
            break;
        }
        else{
            cout << "That is not a valid input :(" << endl;
        }
    }
  

  return 0;
}
