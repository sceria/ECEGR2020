#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//--------------------------------------------------------------------------Part A--------------------------------------------------------------------------------------------

// In this lab, we are now utilizing character pointers to represent the first and last names of a student from the class "Student".
// Since we are using character pointers, the correct amount of memory needs to be allocated. For example, it's important to remember that there is a null character at the end of each string.
// Therefore, the size of the memory allocation must be the length of the string plus one (to accomodate for the terminating null character). However, when we do dynamically allocate memory, 
// it's important to free it to prevent any memory leaks

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Student
{
private:
	int  ID;
    char* firstName;
    char* lastName;
    float GPA;
	Student* next; // 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
public:
//Default Constructor 
	Student(){
		this->ID = 0;
		this->firstName = NULL;
		this->lastName = NULL;
		this->GPA = 0.0;
		this->next = NULL;
		
		cout << "Default Constructor called!" << endl;
	}
	
	//Parametrized Constructor 
	Student(int ID, char *firstName, char *lastName, float GPA){
		this->ID = ID;
		this->firstName = (char*) malloc(strlen(firstName)+1);
		strcpy(this->firstName, firstName);
		this->lastName = (char*) malloc(strlen(lastName)+1);
		strcpy(this->lastName, lastName);
		this->GPA = GPA;
		this->next = NULL;
		cout << "Parametrized Constructor called!" << endl;
	}
	
	//Copy Constructor
	Student(Student &p){
		ID = p.ID;
		GPA = p.GPA;
		firstName = NULL;
		lastName = NULL;
		if(p.firstName)
		{
			setFirstName(p.firstName);
		}
		if(p.lastName)
		{
			setLastName(p.lastName);
		}
		next = p.next;
		
		cout << "Copy Constructor called!" << endl;
	}
	
	//Deconstructor
	~Student(){
		delete [] firstName;
		delete [] lastName;
		cout << "Destructor called!" << endl;
	}
	Student& operator=(Student const &s){
		this->ID = s.ID;
		this->firstName = NULL;
		this->lastName = NULL;
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
	void setFirstName(const char *firstName){
		if(this->firstName == NULL)
		{
			this->firstName = (char*) malloc(strlen(firstName)+1);
			strcpy(this->firstName, firstName);
			return;
		}
		else
		{
			free(this->firstName);
			this->firstName = (char*) malloc(strlen(firstName)+1);
			strcpy(this->firstName, firstName);
			return;
		}
	}
	//------------------------------------------------------------------
	void setLastName(const char *lastName){
		if(this->lastName == NULL)
		{
			this->lastName = (char*) malloc(strlen(lastName)+1);
			strcpy(this->lastName, lastName);
			return;
		}
		else
		{
			free(this->lastName);
			this->lastName = (char*) malloc(strlen(lastName)+1);
			strcpy(this->lastName, lastName);
			return;
		}
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
		//cout << ID << endl;
		return ID;
	}
	char* getFirstName(){
		//cout << firstName << endl;
		return firstName;
	}
	char* getLastName(){
		//cout << lastName << endl;
		return lastName;
	}
	float getGPA(){
		//cout << GPA << endl;
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
			Student* temp = student1; // EXPLAINNNNNNNNNNNNNNNN
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
	char* newfirstname;
	char* newlastname;
	float newGPA;
	//USE SET AND GET FUNCTIONS
	cout << "Enter the ID: ";
	cin >> newID; // C++ version of "scanf"
	
	cout << "Enter the First Name: ";
	cin >> firstinput;
	newfirstname = (char*) malloc(strlen((firstinput.c_str())+1)); 
	strcpy(newfirstname, firstinput.c_str());

	cout << "Enter the Last Name: ";
	cin >> secondinput;
	newlastname = (char*) malloc(strlen((secondinput.c_str())+1));
	strcpy(newlastname, secondinput.c_str());
	
	cout << "Enter the GPA: ";
	cin >> newGPA;
	
	Student* newStud = new Student(newID, newfirstname, newlastname, newGPA);
	
	// Adds new student to the list and sorts them accordignly 
	addNode(newStud);
	free(newfirstname);
	free(newlastname);
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
	int temp1;
	string tempf;
	string templ;
	char* firstname;
	char* lastname;
	float temp2;
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
				cin >> temp1;
				current->setID(temp1);
			}
			else if(usermenuselection == 'b'){
				cout << "Enter new First Name: ";
				cin >> tempf;
				firstname = (char*) malloc(strlen((tempf.c_str())+1));
				strcpy(firstname, tempf.c_str());
				current->setFirstName(firstname);
				free(firstname);
			}
			else if(usermenuselection == 'c'){
				cout << "Enter new Last Name: ";
				cin >> templ;
				lastname = (char*) malloc(strlen((templ.c_str())+1));
				strcpy(lastname, templ.c_str());
				current->setLastName(lastname);	
				free(lastname);
			}
			else if(usermenuselection == 'd'){
				cout << "Enter new GPA: ";
				cin >> temp2;
				current->setGPA(temp2);		
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
	ofstream glasses; // output file stream; used to write info into the file
	glasses.open("ClassOfKeikis.txt");
	if(!glasses.is_open()){
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
		
		glasses << "Number of students: " << studentCount << endl;
		
		top = student1; 
		while(top != NULL) 
		{
			glasses << endl;
			glasses << "Student ID: "<< top->getID() << endl;
			glasses << "Student First Name: "<< top->getFirstName() << endl;
			glasses << "Student Last Name: "<< top->getLastName() << endl;
			glasses << "Student GPA: "<< top->getGPA() << endl;
			top = top->getNext();
		}
		glasses.close(); 
	}
}

void reads(){
	ifstream glasses; // input file stream; used to read info from file streams
	glasses.open("ClassOfKeikis.txt");
	
	if(!glasses.is_open()){
		cout << "Error: Cannot Open File..." << endl;
	}
	else{
		cout << "Opened Successfully!" << endl;
		//---------------------------------
		string word;
		int IDw = 0;
		char* firstname = NULL;
		char* lastname = NULL;
		float GPAw = 0.0;
		glasses >> word; // manually iterating through each word in the file
		glasses >> word;
		glasses >> word;
		glasses >> word;
		glasses >> word;
		glasses >> word;
		//--------------------
		/*glasses >> word;
		glasses >> word;
		glasses >> word;*/
		while(glasses.good()){
			glasses >> IDw;
			
			glasses >> word;
			glasses >> word;
			glasses >> word;

			glasses >> word;			
			firstname = (char*) malloc(strlen((word.c_str())+1));
			strcpy(firstname, word.c_str());
			
			glasses >> word;
			glasses >> word;
			glasses >> word;

			glasses >> word;
			lastname = (char*) malloc(strlen((word.c_str())+1));
			strcpy(lastname, word.c_str());
	
			glasses >> word;
			glasses >> word;
			glasses >> GPAw;

			Student* newstud = new Student(IDw, firstname, lastname, GPAw); 
			addNode(newstud);
			free(firstname);
			free(lastname);
			
			glasses >> word;
			glasses >> word;
		}
		glasses.close();
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
	//Part A
	Menu1();	
return 0;
}