#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

//--------------------------------------------------------------------------Part B--------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Student
{
private:
	int  ID;
	string firstName;
    string lastName;
    float GPA;
	Student* next; // 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
public:
//Default Constructor 
	Student(){
		this->ID = 0;
		this->firstName = "";
		this->lastName = "";
		this->GPA = 0.0;
		this->next = NULL;
		
		cout << "Default Constructor called!" << endl;
	}
	
	//Parametrized Constructor 
	Student(int ID, string firstName, string lastName, float GPA){
		this->ID = ID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->GPA = GPA;
		this->next = NULL;
		cout << "Parametrized Constructor called!" << endl;
	}
	
	//Copy Constructor
	Student(Student &p){
		ID = p.ID;
		GPA = p.GPA;
		firstName = p.firstName;
		lastName = p.lastName;
		
		cout << "Copy Constructor called!" << endl;
	}
	
	//-------------------------------------------------------------------------------------------------------------------------------------
	//Default destructor is used by the compiler since none of the memory is being dynamically allocated! 
	//-------------------------------------------------------------------------------------------------------------------------------------

	Student& operator=(Student const &s){
		this->ID = s.ID;
		this->firstName = "";
		this->lastName = ""	;
		setFirstName(s.firstName);
		setLastName(s.lastName);
		this->GPA = s.GPA;
		return *this;
	}
	
	//-------------------------------------SET Methods-----------------------------------------
	void setID(int ID){
		this->ID = ID;
	}
	//------------------------------------------------------------------
	void setFirstName(string firstName){
		this->firstName = firstName;
	}
	//------------------------------------------------------------------
	void setLastName(string lastName){
		this->lastName = lastName;
	}
	//------------------------------------------------------------------
	void setGPA(float GPA){
		this->GPA = GPA;
	}
	//------------------------------------------------------------------
	void setNext(Student* next_object) //EXPLAINNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
	{
		next = next_object;
	}
	
	//-------------------------------------GET Methods-----------------------------------------
	int getID(){
		return ID;
	}
	string getFirstName(){
		return firstName;
	}
	string getLastName(){
		return lastName;
	}
	float getGPA(){
		return GPA;
	}
	Student* getNext(){
		return next;
	}
};

//---------------------------------------------------------------Linked Lists-------------------------------------------------------------
//Head node of the Linked List
Student* student1 = NULL; //firstStudent will act like our headNode from lab 4

// Add Node function
void addNode(Student* newNode){
    Student* currentnode = student1; // First student of the linked list
    if( student1 == NULL )
    {
        student1 = newNode;
        return;
    }
	else if(student1->getNext() == NULL) // If stuent1's next pointer is the end of the list
	{
		if(student1->getGPA() >= newNode->getGPA()) // If headnode student has a greater GPA than newNode student...
		{
			student1->setNext(newNode); // student1's next pointer will be set to newNode
			return;
		}
		else
		{
			Student* temp = student1; 
			student1 = newNode;
			student1->setNext(temp);
			return;
		}
	}
	
	// Sorts nodes of students by highest to lowest GPA
	while(currentnode->getNext() != NULL) //while the node's next pointer is not pointing to the end of the list
	{
		Student* nextNode = currentnode->getNext(); 
		
		if((newNode->getGPA() < currentnode->getGPA()) && (newNode->getGPA() >= nextNode->getGPA())) // if newnode gpa is less than current node AND greater than the next node...
		{
			newNode->setNext(currentnode->getNext()); //newNode will be linked to the node after the "node" node
			currentnode->setNext(newNode); // then current node's next pointer will be linked to the newNode
			return;
		}
		else if(newNode->getGPA() >= currentnode->getGPA()) // If newNode GPA is greater than the current node...
		{
			newNode->setNext(currentnode); // newNode's next pointer is linked to currentNode
			student1 = newNode; // newNode is now the headNode (or in this case, student1)
			return;
		}
		currentnode = currentnode->getNext(); // Moves down the list of nodes
	}
	currentnode->setNext(newNode); 
	newNode->setNext(NULL);
	return;
}

// Print Node function
void printNodes(){
	Student* currentnode = student1;
	if(currentnode == NULL){
		cout << "List is empty" << endl;
	}
	else{
		while(currentnode != NULL){ 
			cout << endl;
			cout << "Student's ID: " << currentnode->getID() << endl;
			cout << "Student's First Name: " << currentnode->getFirstName() << endl;
			cout << "Student's Last Name: " << currentnode->getLastName() << endl;
			cout << "Student's GPA: " << currentnode->getGPA() << endl;
			currentnode = currentnode->getNext(); // moves down the linked list
		}
	}
}

// Creates new student
void NewStudent(){
	string firstinput;
	string secondinput;
	int newID;
	string newfirstname;
	string newlastname;
	float newGPA;
	//USE SET AND GET FUNCTIONS
	cout << "Enter the ID: ";
	cin >> newID; // C++ version of "scanf"
	
	cout << "Enter the First Name: ";
	cin >> firstinput;
	newfirstname = firstinput; 

	cout << "Enter the Last Name: ";
	cin >> secondinput;
	newlastname = secondinput;
	
	cout << "Enter the GPA: ";
	cin >> newGPA;
	
	Student* newStud = new Student(newID, newfirstname, newlastname, newGPA);
	
	// Adds new student to the list and sorts them accordignly 
	addNode(newStud);
}

// Deletes new student
void deleteStudent(Student** head_ref, int ID){ 
	// Store head node
    Student *temp = *head_ref, *prev;
 
    // If head node itself holds the student to be deleted
    if (temp != NULL && temp->getID() == ID) {
        *head_ref = temp->getNext(); // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the student to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->getID() != ID) {
        prev = temp;
        temp = temp->getNext();
    }
	
    // If student was not present in linked list
    if (temp == NULL)
        return;
		
    // Unlink the node from linked list
    prev->setNext(temp->getNext());
    free(temp); // Free memory
}

void updateStudent(Student* head, int id){
	Student* current = head;
	Student* previous = current;
	char usermenuselection;
	int tempID;
	string first;
	string last;
	string firstname;
	string lastname;
	float tempGPA;
	cout << "Which would you like to update?" << endl;
	cout << "a) ID" << endl;
	cout << "b) First Name" << endl;
	cout << "c) Last Name" << endl;
	cout << "d) GPA" << endl;
	cout << "Choose from options a-d: ";
	cin >> usermenuselection;
	
	while(current != NULL){
		if(current->getID() == id){
			if(usermenuselection == 'a'){
				cout << "Enter new ID: ";
				cin >> tempID;
				current->setID(tempID);
			}
			else if(usermenuselection == 'b'){
				cout << "Enter new First Name: ";
				cin >> first;
				firstname = first;
				current->setFirstName(firstname);
			}
			else if(usermenuselection == 'c'){
				cout << "Enter new Last Name: ";
				cin >> last;
				lastname = last;
				current->setLastName(lastname);	
			}
			else if(usermenuselection == 'd'){
				cout << "Enter new GPA: ";
				cin >> tempGPA;
				current->setGPA(tempGPA);		
				if(previous == current){
					current->setNext(NULL);
					addNode(current);
				}
				else{
					previous->setNext(current->getNext());
					addNode(current);
				}
						
			}
			else{
				cout << "Invalid Input..." << endl;
			}
		}
	previous = current;
	current = current->getNext();
	}
}

void savelist(){
	ofstream opening; // output file stream; used to write info into the file
	opening.open("ClassOfKeikis.txt");
	if(!opening.is_open()){
		cout << "Error: Cannot Open File..." << endl;
	}
	else{
		cout << "Saved to text file" << endl;
		Student* top = student1; 
		int studentCount = 0; 
		while(top != NULL) {
			studentCount++; 
			top = top->getNext(); 
		}
		
		opening << "Number of students: " << studentCount << endl;
		
		top = student1; 
		while(top != NULL) 
		{
			opening << endl;
			opening << "Student ID: "<< top->getID() << endl;
			opening << "Student First Name: "<< top->getFirstName() << endl;
			opening << "Student Last Name: "<< top->getLastName() << endl;
			opening << "Student GPA: "<< top->getGPA() << endl;
			top = top->getNext();
		}
		opening.close(); 
	}
}

void reads(){
	ifstream opening; // input file stream; used to read info from file streams
	opening.open("ClassOfKeikis.txt");
	
	if(!opening.is_open()){
		cout << "Error: Cannot Open File..." << endl;
	}
	else{
		cout << "Opened Successfully!" << endl;
		//---------------------------------
		string word;
		int IDw = 0;
		string firstname = ""; // empty string!
		string lastname = "";
		float GPAw = 0.0;
		opening >> word; // manually iterating through each word in the file
		opening >> word;
		opening >> word;
		opening >> word;
		opening >> word;
		opening >> word;
		//--------------------
		while(opening.good()){
			opening >> IDw;
			
			opening >> word;
			opening >> word;
			opening >> word;
			
			opening >> word;
			firstname = word;
			
			opening >> word;
			opening >> word;
			opening >> word;

			opening >> word;
			lastname = word;
	
			opening >> word;
			opening >> word;
			opening >> GPAw;

			Student* newstud = new Student(IDw, firstname, lastname, GPAw); 
			addNode(newstud);
			
			opening >> word;
			opening >> word;
		}
		opening.close();
		cout << "File read successfully!" << endl;
	}
	cout << endl;
}

void Menu1(){
	reads();
	//------------Display Menu----------------------------
	cout << "1) List all students" << endl;
	cout << "2) Add Student" << endl;
	cout << "3) Remove Student" << endl;
	cout << "4) Update Student" << endl;
	cout << "5) Exit Program" << endl;
	
	char input;
	int IDsearch;
	int IDsearch2;
	while(1){
		cout << "Please choose an option (1-5): ";
		cin >> input;
		
		if(input == '1'){
			printNodes();
		}
		else if(input == '2'){
			NewStudent();
			cout << "Student was added to the class!" << endl;
		}
		else if(input == '3'){
			cout << "Enter the ID of the student you want to delete: ";
			cin >> IDsearch2;
			deleteStudent(&student1, IDsearch2);
			cout << "Student removed from the class!" << endl;
		}
		else if(input == '4'){
			cout << "Enter the ID of the student you want to update: ";
			cin >> IDsearch;
			updateStudent(student1, IDsearch);
			cout << "Student info successfully updated!" << endl;
		}
		else if(input == '5'){
			savelist();
			cout << "Exiting Program..." << endl;
			break;
		}
		else{
			cout << "Invalid input!" << endl;
		}
	}
}

//--------------------------------------------------------------------------Main Function-------------------------------------------------------------------------------------
int main(){
	//Part B
	Menu1();	
return 0;
}