#include <iostream>
#include <queue>
#include <string>

#include "management.h" 
//allows header file to access the contents of its referenced functions 

using namespace std;

//queue declaration
queue <string> HumaneSoc; // The pets in the system
queue <string> type; // the type of pet

// Function that adds animals to the system
void add_animal(){
    string tempAnimal;
    string tempNametag;
    //string TEMP,TEMP2;
    
    Animol pet; // pet variable of type "animol" class is defined
    cout << "Will you be adding a dog or a cat?" << endl;
    cin >> tempAnimal; // animal type is stored in tempAnimal
    cout << endl;
    pet.ani = tempAnimal; // Pet's animal type is initialized
    
    cout << "What's the name of this " << tempAnimal << "?" << endl;
    cin.clear();
    cin.ignore(10000, '\n');
    getline(cin,tempNametag);
    cout << endl;
    pet.nametag = tempNametag; // Pet's name is initialized
    
    // Adding information to queues
    HumaneSoc.push(pet.nametag);
    type.push(pet.ani);
    
    // Confirmation message of being added to the system
    cout << pet.nametag << " the " << pet.ani << " has been added to the system!" << endl;
    
}

// Function that adopts an animal 
void adopt(int preference){
    if(HumaneSoc.empty()){
        cout << endl << "There are no animals to be adopted at this time." << endl;
    }
    else{
        if(preference == 3){
            cout << endl << HumaneSoc.front() << " the " << type.front() << " has been adopted!" << endl;
            HumaneSoc.pop(); // clearing the animal from the system
            type.pop(); //clearing that animal's type from the other queue
        }
        else if(preference == 1){ // If user wants a dog
            // temporary queues and variable
            queue <string> temp;
            queue <string> temp2;
            queue <string> tempCheck;
            int count = 0;
            
            tempCheck = type; // will use tempCheck to see if a dog is available
            while(count <= tempCheck.size()){
                if(type.front() == "dog"){
                    break; // breaks the search function because there is a dog available
                }
                else{
                    tempCheck.pop(); // goes through the queue searching for a dog
                    count++; // increase our counter variable
                }
            }
            if(count==type.size()){ // count indicates it went through whole queue w/o finding a dog
                cout << endl << "There are no dogs to be adopted at this time." << endl;
            }
            
            else{
                if(type.front() == "dog"){
                    cout << HumaneSoc.front() << " the " << type.front() << " has been adopted!" << endl;
                    HumaneSoc.pop(); // clearing the animal from the system
                    type.pop(); // clearing that animal's type from the other queue
                }
                else{
                    while(type.front() != "dog"){
                        temp.push(HumaneSoc.front()); // saves the previous cat names into temp q
                        temp2.push(type.front()); //saves prev. animal type into temp2 q
                        HumaneSoc.pop();
                        type.pop();
                    }
                    cout << endl << HumaneSoc.front() << " the " << type.front() << " has been adopted!" << endl;
                    HumaneSoc.pop(); // clearing the animal from the system
                    type.pop(); // clearing that animal's type from the other queue
            
                    // Add rest of the animals to the temp queues
                    while(!type.empty()){ // while the type q is not empty...
                        temp.push(HumaneSoc.front());
                        temp2.push(type.front());
                        HumaneSoc.pop();
                        type.pop(); 
                    }
                    // finalize contents of the original queues by swapping contents with the temp queues
                    HumaneSoc.swap(temp);
                    type.swap(temp2);
                }
            }
        }
        else if(preference == 2){ // if user wants a cat
            // temporary queues
            queue <string> temp;
            queue <string> temp2;
            queue <string> tempCheck;
            int count = 0;
            
            tempCheck = type; // will use tempCheck to see if a dog is available
            while(count <= tempCheck.size()){
                if(type.front() == "cat"){
                    break; // breaks the search function because there is a dog available
                }
                else{
                    tempCheck.pop(); // goes through the queue searching for a dog
                    count++; // increase our counter variable
                }
            }
            if(count==type.size()){ // count indicates it went through whole queue w/o finding a dog
                cout << endl << "There are no cats to be adopted at this time." << endl;
            }
            else{
                if(type.front() == "cat"){
                    cout << endl << HumaneSoc.front() << " the " << type.front() << " has been adopted!" << endl;
                    HumaneSoc.pop(); // clearing the animal from the system
                    type.pop(); // clearing that animal's type from the other queue
                }
                else{
                    while(type.front() != "cat"){
                        temp.push(HumaneSoc.front()); // saves the previous dog names into temp q
                        temp2.push(type.front()); //saves prev. animal type into temp2 q
                        HumaneSoc.pop();
                        type.pop();
                    }
                    cout << endl << HumaneSoc.front() << " the " << type.front() << " has been adopted!" << endl;
                    HumaneSoc.pop(); // clearing the animal from the system
                    type.pop(); // clearing that animal's type from the other queue
            
                    // Add rest of the animals to the temp queues
                    while(!type.empty()){ // while the type q is not empty...
                        temp.push(HumaneSoc.front());
                        temp2.push(type.front());
                        HumaneSoc.pop();
                        type.pop();
                    }
                    // finalize contents of the original queues by swapping contents with the temp queues
                    HumaneSoc.swap(temp);
                    type.swap(temp2);
                }
            }
        }
    }
}
