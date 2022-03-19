#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <stdlib.h>
using namespace std;

template <class DstType, class SrcType> //Useful for identitfying specific classes
bool instanceof(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}


//--------------------------------------------------------People Class---------------------------------------------------------
class People
{
private:
	int  ID;
    string firstName;
    string lastName;
	People* next;

public:
	//-----------------------Constructors---------------------------------------
	People(){//Default Constructor
	}
	
	People(int ID, string firstName, string lastName){//Parametrized Constructor
		this->ID = ID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->next = NULL;
		cout << "Parametrized constructor called" << endl;
	}
	
	People(People &p){//Copy Constructor
		this->ID = p.ID;
		this->firstName = p.firstName;
		this->lastName = p.lastName;
		this->next = p.next;
		cout << "Copy constructor called" << endl;
	}
	
	People& operator=(People const &p)
	{
		this->ID = p.ID;
		setFirstName(p.firstName);
		setLastName(p.lastName);
		this->next = p.next;
		return *this;
	}
	
	virtual ~People(){
		//Destructor not needed
	}
	//-----------------------Set/Get Funtctions---------------------------------
	void setID(int ID){
		this->ID = ID;
	}
	void setFirstName(string firstName){
		this->firstName = firstName;
	} 
	void setLastName(string lastName){
		this->lastName = lastName;
	}
	void setnext(People* next){
		this->next = next;
	}
	int getID(){
		return ID;
	}
	string getFirstName(){
		return firstName;
	}
	string getLastName(){
		return lastName;
	}
	People* getnext(){
		return next;
	}
};

//--------------------------------------------------------Student Class--------------------------------------------------------
class Student: public People
{
private:
	float GPA;
	
public: 
//-----------------------Constructors---------------------------------------
	Student(){//Default Consturctor
	}
	Student(int ID, string firstName, string lastName, float GPA){//Parametrized Constructor
		setID(ID);
		setFirstName(firstName);
		setLastName(lastName);
		this->GPA = GPA;
		setnext(NULL);
	}
	Student(Student &j){//Copy Constructor
		setID(j.getID());
		setFirstName(j.getFirstName());
		setLastName(j.getLastName());
		setGPA(j.getGPA());
		setnext(j.getnext());
	}
	virtual~Student(){
		//Destructor not needed
	}
//-----------------------Set/Get Funtctions---------------------------------
	void setGPA(float GPA){
		this->GPA = GPA;
	}
	float getGPA(){
		return GPA;
	}
};

//--------------------------------------------------------Employee Class--------------------------------------------------------
class Employee: public People
{
private:
	float salary;
	
public:
//-----------------------Constructors---------------------------------------
	Employee(){//Default Consturctor
	}
	Employee(int ID, string firstName, string lastName, float salary){//Parametrized Constructor
		setID(ID);
		setFirstName(firstName);
		setLastName(lastName);
		this->salary = salary;
		setnext(NULL);
	}
	Employee(Employee &s){//Copy Constructor
		setID(s.getID());
		setFirstName(s.getFirstName());
		setLastName(s.getLastName());
		setSalary(s.getSalary());
		setnext(s.getnext());
	}
	virtual~Employee(){
		//Destructor not needed
	}
	//-----------------------Set_Get Funtctions------------------------------
	void setSalary(float salary){
		this->salary = salary;
	}
	float getSalary(){
		return salary;
	}	
};

//--------------------------------------------------------Professor Class--------------------------------------------------------
class Professor: public Employee
{
public:

enum Department {math, compsci, engineering, politicalEcology, physics}; // initializes the departments

private:
	bool tenure;
	Department department;
	
public:
//-----------------------Constructors---------------------------------------
	Professor(){//Default Consturctor
	}
	Professor(int ID, string firstName, string lastName, float salary, bool tenure, Department department){//Parametrized Constructor
		setID(ID);
		setFirstName(firstName);
		setLastName(lastName);
		setSalary(salary);
		this->tenure = tenure;
		this->department = department;
		setnext(NULL);
	}
	Professor(Professor &s){//Copy Constructor
		setID(s.getID());
		setFirstName(s.getFirstName());
		setLastName(s.getLastName());
		setSalary(s.getSalary());
		setTenure(s.getTenure());
		setDepartment(s.getDepartment());
		setnext(s.getnext());
	}
	virtual~Professor(){
		//Default destructor for non-allocated memory
	}
	//-----------------------Set_Get Funtctions------------------------------
	void setTenure(bool tenure){
		this->tenure = tenure;
	}
	void setDepartment(Department department){
		this->department = department;
	}
	bool getTenure(){
		return tenure;
	}	
	Department getDepartment(){
		return department;
	}
	
};

People* person1 = NULL;


void addNode(People* newNode){
	People* node = person1;
    if( person1 == NULL )
    {
        person1 = newNode;
        return;
    }
	else if(person1->getnext() == NULL)
	{
		if(person1->getID() >= newNode->getID())
		{
			person1->setnext(newNode);
			return;
		}
		else
		{
			People* temp = person1;
			person1 = newNode;
			person1->setnext(temp);
			return;
		}
	}
	
	while(node->getnext() != NULL)
	{
		People* nextNode = node->getnext();
		
		if((node->getID() > newNode->getID()) && (newNode->getID() >= nextNode->getID()))
		{
			newNode->setnext(node->getnext());
			node->setnext(newNode);
			return;
		}
		else if(node->getID() <= newNode->getID())
		{
			newNode->setnext(node);
			person1 = newNode;
			return;
		}
		node = node->getnext();
	}
	node->setnext(newNode);
	newNode->setnext(NULL);
	return;
}

void reads(){
	ifstream opening;
	opening.open("ClassOfKeikis.txt");
	
	if(!opening.is_open()){
		cout << "error" << endl;
	}
	else{
		cout << "Opened Successfully" << endl;
		//---------------------------------
		string word;
		int IDw = 0;
		string firstname = "";
		string lastname = "";
		float GPAw = 0.0;
		float salary = 0.0;
		string ten;
		bool tenure;
		string departmen = "";
		Professor::Department department;
		opening >> word;
		opening >> word;
		opening >> word;
		opening >> word;
		opening >> word;
		while(opening.good()){
			if(word == "PROFESSOR"){
				opening >> word;
				opening >> word;
				opening >> IDw; // ID number 
				opening >> word;
				opening >> word;
				opening >> word;
				opening >> firstname; //Firstname
				opening >> word;
				opening >> word;
				opening >> word;
				opening >> lastname; //Lastname
				opening >> word;
				opening >> word;
				opening >> salary;//Salary
				opening >> word;
				opening >> ten;//Tenured
				if(ten == "yes"){
					tenure = 1;
				}
				else if(ten == "no"){
					tenure = 0;
				}
				opening >> word;
				opening >> departmen; //Department
				if(departmen == "Math"){
					department = Professor:: math;
				}
				else if(departmen == "Computer Science"){
					department = Professor::compsci;
				}
				else if(departmen == "Engineering"){
					department = Professor::engineering;
				}
				else if(departmen == "Political Ecology"){
					department = Professor::politicalEcology;
				}
				else if(departmen == "Physics"){
					department = Professor::physics;
				}
				People* readProfessor = new Professor(IDw, firstname, lastname, salary, tenure, department);
				addNode(readProfessor);
			}
			else if(word ==  "EMPLOYEE"){
				opening >> word;
				opening >> word;
				opening >> IDw; //ID 
				opening >> word;
				opening >> word;
				opening >> word;
				opening >> firstname; //firstname 
				opening >> word;
				opening >> word;
				opening >> word;
				opening >> lastname; //lastname
				opening >> word;
				opening >> word;
				opening >> salary;//salary
				People* readEmployee = new Employee(IDw, firstname, lastname, salary);
				addNode(readEmployee);
			}
			else if(word == "STUDENT"){
				opening >> word;
				opening >> word;
				opening >> IDw; //ID
				opening >> word;
				opening >> word;
				opening >> word;
				opening >> firstname; //firstname 
				opening >> word;
				opening >> word;
				opening >> word;
				opening >> lastname; //lastname
				opening >> word;
				opening >> word;
				opening >> GPAw; //GPA
				People* readStudent = new Student(IDw, firstname, lastname, GPAw);
				addNode(readStudent);
			}
		opening >> word;
		}
		opening.close();
		cout << "File read successfully!!!" << endl;
	}
	cout << endl;
}

void savelist(){
	string print = "";
	string print2 = "";
	ofstream opening;
	opening.open("ClassOfKeikis.txt");
	if(!opening.is_open()){
		cout << "Could not open file..." << endl;
	}
	else{
		People* headNode = person1; 
		int studentCount = 0; 
		while(headNode != NULL) {
			studentCount++; 
			headNode = headNode->getnext(); 
		}
		
		opening << "Number of People: " << studentCount << endl;
		
		headNode = person1; 
		while(headNode != NULL){
			if(instanceof<Student>(headNode)){
				Student* student = (Student*) headNode;
				opening << endl;
				opening << "STUDENT" << endl;
				opening << "Student ID: "<< student->getID() << endl;
				opening << "Student First Name: "<< student->getFirstName() << endl;
				opening << "Student Last Name: "<< student->getLastName() << endl;
				opening << "Student GPA: "<< student->getGPA() << endl;
			}
			else if(instanceof<Professor>(headNode)){
				Professor* professor = (Professor*) headNode;
				opening << endl;
				opening << "PROFESSOR" << endl;
				opening << "Professor ID: "<< professor->getID() << endl;
				opening << "Professor First Name: "<< professor->getFirstName() << endl;
				opening << "Professor Last Name: "<< professor->getLastName() << endl;
				opening << "Professor salary: "<< professor->getSalary() << endl;
				if(professor->getTenure() == 0){
					print = "yes";
				}
				else if(professor->getTenure() == 1){
					print = "no";
				}
				opening << "Tenured: "<< print << endl;
				if(professor->getDepartment() == 0){
					print2 = "Engineering";
				}
				else if(professor->getDepartment() == 1){
					print2 = "Math";
				}
				else if(professor->getDepartment() == 2){
					print2 = "Chemistry";
				}
				else if(professor->getDepartment() == 3){
					print2 = "Computer Science";
				}
				else if(professor->getDepartment() == 4){
					print2 = "Physics";
				}
				opening << "Department: " << print2 << endl;
			}
			
			else if(instanceof<Employee>(headNode) && !instanceof<Professor>(headNode)){
				Employee* employee = (Employee*) headNode;
				opening << endl;
				opening << "EMPLOYEE" << endl;
				opening << "Employee ID: "<< employee->getID() << endl;
				opening << "Employee First Name: "<< employee->getFirstName() << endl;
				opening << "Employee Last Name: "<< employee->getLastName() << endl;
				opening << "Employee salary: "<< employee->getSalary() << endl;
			}
		headNode = headNode->getnext();
		}
	opening.close(); 
	}
	cout << "Saved to text file" << endl;
}

void printPeople(){
	People* node = person1;
	if(node == NULL){
		cout << "List is empty" << endl;
	}
	else{
		cout << endl;
		while(node != NULL){
			if(instanceof<Student>(node)){
				Student* student = (Student*) node;
				cout << "STUDENT" << endl;
				cout << "ID: " << student->getID() << endl;
				cout << "First Name: " << student->getFirstName() << endl; 
				cout << "Last Name: " << student->getLastName() << endl;
				cout << "GPA: " << student->getGPA() << endl;
			}
			else if (instanceof<Professor>(node)){
				Professor* professor = (Professor*) node;
				cout << "PROFESSOR" << endl;
				cout << "ID: " << professor->getID() << endl;
				cout << "First Name: " << professor->getFirstName() << endl;
				cout << "Last Name: " << professor->getLastName() << endl;
				cout << "Salary: " << professor->getSalary() << endl;
				if(professor->getTenure() == 0){
					cout << "Tenured: no" << endl;
				}
				else if(professor->getTenure() == 1){
					cout << "Tenured: yes" << endl;
				}
				if(professor->getDepartment() == 0){
					cout << "Department: Math" << endl;
				}
				else if(professor->getDepartment() == 1){
					cout << "Department: Computer Science" << endl;
				}
				else if(professor->getDepartment() == 2){
					cout << "Department: Engineering" << endl;
				}
				else if(professor->getDepartment() == 3){
					cout << "Department: Political Ecology" << endl;
				}
				else if(professor->getDepartment() == 4){
					cout << "Department: Physics" << endl;
				}
			}
			else if (instanceof<Employee>(node) && !instanceof<Professor>(node)){ 
				Employee* employee = (Employee*) node;
				cout << "EMPLOYEE" << endl;
				cout << "ID: " << employee->getID() << endl;
				cout << "First Name: " << employee->getFirstName() << endl;
				cout << "Last Name: " << employee->getLastName() << endl;
				cout << "Salary: " << employee->getSalary() << endl;
			}
		cout << endl;	
		node = node->getnext();
		}
	}
}	

void deletePerson(People** head_ref, int ID){
	People *temp = *head_ref, *prev;
		// If head node holds the student to be deleted...
		if (temp != NULL && temp->getID() == ID) {
			*head_ref = temp->getnext(); // Changed head
			delete temp; // frees memory of old headNode
			return;
		}
	 
		while (temp != NULL && temp->getID() != ID) {
			prev = temp;
			temp = temp->getnext();
		}
		
		// If student isnt present in linked list...
		if (temp == NULL)
			return;
			
		// Unlinking of the the nodes from the linked list
		prev->setnext(temp->getnext());
		delete temp; // Free memory
}

//-----------------------------------------------STUDENT FUNCTIONS------------------------------------------------------------
void updateStudent(int id){
	People* node = person1;
	People* previous = node;
	char userinput;
	int first;
	string firstname;
	string lastname;
	float las;
	cout << "What would you like to change?" << endl;
	cout << "a) ID" << endl;
	cout << "b) First Name" << endl;
	cout << "c) Last Name" << endl;
	cout << "d) GPA" << endl;
	cout << "Choose from options a-d: ";
	cin >> userinput;
	
	while(node != NULL){
		if(node->getID() == id){
			if(instanceof<Student>(node)){
				Student* student = (Student*) node;
				if(userinput == 'a'){
					cout << "Enter new ID: ";
					cin >> first;
					student->setID(first);
				}
				else if(userinput == 'b'){
					cout << "Enter new First Name: ";
					cin >> firstname;
					student->setFirstName(firstname);
				}
				else if(userinput == 'c'){
					cout << "Enter new Last Name: ";
					cin >> lastname;
					student->setLastName(lastname);				
				}
				else if(userinput == 'd'){
					cout << "Enter new GPA: ";
					cin >> las;
					student->setGPA(las);		
					if(previous == node){
						student->setnext(NULL);
						addNode(student);
					}
				else{
						previous->setnext(student->getnext());
						addNode(student);
					}
				}
				else{
					cout << "Invalid Input..." << endl;
				}
			}
		}
	previous = node;
	node = node->getnext();
	}
}

void printStudents(){
	People* node = person1;
	int count = 0;
	if(node == NULL){
		cout << "List is empty..." << endl;
	}
	else{
		while(node != NULL){
			if(instanceof<Student>(node)){
				Student* student = (Student*) node;
				cout << "ID: " << student->getID() << endl;
				cout << "First Name: " << student->getFirstName() << endl; 
				cout << "Last Name: " << student->getLastName() << endl;
				cout << "GPA: " << student->getGPA() << endl;
				count++;
			}
		cout << endl;
		node = node->getnext();
		}
		if(count == 0){
			cout << "No students in the list" << endl;
		}
	}
}

void newStudent(){
	string newfirstname;
	string newlastname;
	int newID;
	float newGPA;
	cout << "Enter the ID:";
	cin >> newID;
	
	cout << "Enter the First Name:";
	cin >> newfirstname;

	cout << "Enter the Last Name:";
	cin >> newlastname;
	
	cout << "Enter the GPA:";
	cin >> newGPA;
	
	People* newKeiki = new Student(newID, newfirstname, newlastname, newGPA);
	addNode(newKeiki);
}

void studentMenu(){
	cout << "A) List students in class" << endl;
	cout << "B) Add Student" << endl;
	cout << "C) Remove Student" << endl;
	cout << "D) Update Student info" << endl;
	cout << "E) Return to Original Menu" << endl;
	
	char input;
	int IDlook;
	int IDlook2;
	while(1){
		cout << "Please choose an option (A-E): ";
		cin >> input;
		
		if(input == 'A'){
			printStudents();
		}
		else if(input == 'B'){
			newStudent();
			cout << "Student Added!!" << endl;
		}
		else if(input == 'C'){
			cout << "Enter the ID of the student you want to delete: ";
			cin >> IDlook2;
			deletePerson(&person1, IDlook2);
			cout << "Student Deleted!!" << endl;
		}
		else if(input == 'D'){
			cout << "Enter the ID of the student you want to update: ";
			cin >> IDlook;
			updateStudent(IDlook);
			cout << "Student Updated" << endl;
		}
		else if(input == 'E'){
			break;
		}
		else{
			cout << "Invalid input!" << endl;
		}
	}
}

//----------------------------------------------------------------EMPLOYEE FUNCTIONS------------------------------------------------------------
void updateEmployee(int id){
	People* node = person1;
	People* previous = node;
	char userinput;
	int tempID;
	string firstname;
	string lastname;
	float tempGPA;
	cout << "What would you like to change?" << endl;
	cout << "a) ID" << endl;
	cout << "b) First Name" << endl;
	cout << "c) Last Name" << endl;
	cout << "d) Salary" << endl;
	cout << "Choose from options a-d: ";
	cin >> userinput;
	
	while(node != NULL){
		if(node->getID() == id){
			if(instanceof<Employee>(node) && !instanceof<Professor>(node)){
				Employee* employee = (Employee*) node;
				if(userinput == 'a'){
					cout << "Enter new ID: ";
					cin >> tempID;
					employee->setID(tempID);
				}
				else if(userinput == 'b'){
					cout << "Enter new First Name: ";
					cin >> firstname;
					employee->setFirstName(firstname);
				}
				else if(userinput == 'c'){
					cout << "Enter new Last Name: ";
					cin >> lastname;
					employee->setLastName(lastname);
				}
				else if(userinput == 'd'){
					cout << "Enter new salary: ";
					cin >> tempGPA;
					employee->setSalary(tempGPA);
					if(previous == node){
						employee->setnext(NULL);
						addNode(employee);
					}
				else{
						previous->setnext(employee->getnext());
						addNode(employee);
					}
				}
				else{
					cout << "Invalid Input..." << endl;
				}
			}
		}
	previous = node;
	node = node->getnext();
	}
}

void printEmployees(){
	People* node = person1;
	int count = 0;
	if(node == NULL){
		cout << "List is empty..." << endl;
	}
	else{
		while(node != NULL){
			if (instanceof<Employee>(node) && !instanceof<Professor>(node)){
				Employee* employee = (Employee*) node;
				cout << "ID: " << employee->getID() << endl;
				cout << "First Name: " << employee->getFirstName() << endl;
				cout << "Last Name: " << employee->getLastName() << endl;
				cout << "Salary: " << employee->getSalary() << endl;
				count++;
			}
		node = node->getnext();
		}
		if(count == 0){
			cout << "No Employees in the list..." << endl;
		}
	}
}

void newEmployee(){
	string newfirstname;
	string newlastname;
	int newID;
	float salary;
	cout << "Enter the ID:";
	cin >> newID;
	
	cout << "Enter the First Name:";
	cin >> newfirstname;

	cout << "Enter the Last Name:";
	cin >> newlastname;
	
	cout << "Enter the salary:";
	cin >> salary;
	
	People* newStud = new Employee(newID, newfirstname, newlastname, salary);
	addNode(newStud);
}

void employeeMenu(){
	cout << "A) List all Employees" << endl;
	cout << "B) Add Employee" << endl;
	cout << "C) Remove Employee" << endl;
	cout << "D) Update Employee" << endl;
	cout << "E) Go Back to Original Menu" << endl;
	
	char input;
	int IDsearch;
	int IDsearch2;
	while(1){
		cout << "Please choose an option (A-E): ";
		cin >> input;
		
		if(input == 'A'){
			printEmployees();
		}
		else if(input == 'B'){
			newEmployee();
			cout << "Employee successfully added!!" << endl;
		}
		else if(input == 'C'){
			cout << "Enter the ID of the employee you want to delete: ";
			cin >> IDsearch2;
			deletePerson(&person1, IDsearch2);
			cout << "Employee successfully deleted!!" << endl;
		}
		else if(input == 'D'){
			cout << "Enter the ID of the employee you want to update: ";
			cin >> IDsearch;
			updateEmployee(IDsearch);
			cout << "Employee successfully updated!" << endl;
		}
		else if(input == 'E'){
			break;
		}
		else{
			cout << "Invalid input..." << endl;
		}
	}
}

//------------------------------------------------------------------PROFESSOR FUNCTIONS-----------------------------------------------------
void updateProfessor(int id){
	People* node = person1;
	char userinput;
	int first;
	string firstname;
	string lastname;
	float last;
	cout << "What needs to be updated?" << endl;
	cout << "a) ID" << endl;
	cout << "b) First Name" << endl;
	cout << "c) Last Name" << endl;
	cout << "d) Salary" << endl;
	cout << "e) Tenure" << endl;
	cout << "f) Department" << endl;
	cout << "Choose between options a-d: ";
	cin >> userinput;
	string tenure = " ";
	string Depart = " ";
	
	while(node != NULL){
		if(node->getID() == id){
			if(instanceof<Professor>(node)){
				Professor* professor = (Professor*) node;
				if(userinput == 'a'){
					cout << "Enter new ID: ";
					cin >> first;
					professor->setID(first);
				}
				else if(userinput == 'b'){
					cout << "Enter new First Name: ";
					cin >> firstname;
					professor->setFirstName(firstname);
				}
				else if(userinput == 'c'){
					cout << "Enter new Last Name: ";
					cin >> lastname;
					professor->setLastName(lastname);
				}
				else if(userinput == 'd'){
					cout << "Enter new salary: ";
					cin >> last;
					professor->setSalary(last);
				}
				else if(userinput == 'e'){
					cout << "Enter new tenure status (yes or no): " << endl;
					cin >> tenure;
					if(tenure == "yes"){
						professor->setTenure(true);
					}
					else if(tenure == "no"){
						professor->setTenure(false);
					}
				}
				else if(userinput == 'f'){
					cout << "Enter new Department" << endl;
					cin >> Depart;
					while(1){
						if(Depart == "Math"){
							professor->setDepartment(Professor::math);
							break;
						}
						else if(Depart == "Computer Science"){
							professor->setDepartment(Professor::compsci);
							break;
						}
						else if(Depart == "Engineering"){
							professor->setDepartment(Professor::engineering);
							break;
						}
						else if(Depart == "Political Ecology"){
							professor->setDepartment(Professor::politicalEcology);
							break;
						}
						else if(Depart == "Physics"){
							professor->setDepartment(Professor::physics);
							break;
						}
						else{
							cout << "Invalid Input..." << endl;
						}
					}
				}
				else{
					cout << "Invalid Input..." << endl;
				}
			}
		}
	node = node->getnext();
	}
}

void printProfessors(){
	People* node = person1;
	int count = 0;
	if(node == NULL){
		cout << "List is empty..." << endl;
	}
	else{
		while(node != NULL){
			if (instanceof<Professor>(node)){
				Professor* professor = (Professor*) node;
				cout << "ID: " << professor->getID() << endl;
				cout << "First Name: " << professor->getFirstName() << endl;
				cout << "Last Name: " << professor->getLastName() << endl;
				cout << "Salary: " << professor->getSalary() << endl;
				if(professor->getTenure() == 0){
					cout << "Tenured: no" << endl;
				}
				else if(professor->getTenure() == 1){
					cout << "Tenured: yes" << endl;
				}
				if(professor->getDepartment() == 0){
					cout << "Department: Math";
				}
				else if(professor->getDepartment() == 1){
					cout << "Department: Computer Science";
				}
				else if(professor->getDepartment() == 2){
					cout << "Department: Engineering";
				}
				else if(professor->getDepartment() == 3){
					cout << "Department: Political Ecology";
				}
				else if(professor->getDepartment() == 4){
					cout << "Department: Physics";
				}
				count++;
			}
		node = node->getnext();
		}
		if(count == 0){
			cout << "No professors in the list..." << endl;
		}
	}
	cout << endl;
}

void newProfessor(){
	string newfirstname;
	string newlastname;
	int newID;
	float salary;
	bool tenured;
	Professor::Department department;
	string input;
	string yn;
	cout << "Enter the ID: ";
	cin >> newID;
	
	cout << "Enter the First Name: ";
	cin >> newfirstname;

	cout << "Enter the Last Name: ";
	cin >> newlastname;
	
	cout << "Enter the salary: ";
	cin >> salary;
	
	while(2000){
		cout << "Tenured? Enter yes or no: ";
		cin >> yn;
		if(yn == "yes"){
			tenured = true;
			break;
		}
		else if(yn == "no"){
			tenured = false;
			break;
		}
		else{
			cout << "Invalid Input..." << endl;
		}
	}
	
	while(1){
		cout << "Department: ";
		cin >> input;
		if(input == "Math"){
			department = Professor::math;
			break;
		}
		else if(input == "Computer Science"){
			department = Professor::compsci;
			break;
		}
		else if(input == "Engineering"){
			department = Professor::engineering;
			break;
		}
		else if(input == "Political Ecology"){
			department = Professor::politicalEcology;
			break;
		}
		else if(input == "Physics"){
			department = Professor::physics;
			break;
		}
		else{
			cout << "Invalid Department" << endl;
		}
	}	
	People* newStud = new Professor(newID, newfirstname, newlastname, salary, tenured, department);
	addNode(newStud);
}

void professorMenu(){
	cout << "A) List all Professors" << endl;
	cout << "B) Add Professors" << endl;
	cout << "C) Remove Professors" << endl;
	cout << "D) Update Professors" << endl;
	cout << "E) Go Back to Original Menu" << endl;
	
	char input;
	int IDsearch;
	int IDsearch2;
	while(1){
		cout << "Please choose an option (A-E): ";
		cin >> input;
		
		if(input == 'A'){
			printProfessors();
		}
		else if(input == 'B'){
			newProfessor();
			cout << "Professor successfully added!" << endl;
		}
		else if(input == 'C'){
			cout << "Enter the ID of the professor you want to delete: ";
			cin >> IDsearch2;
			deletePerson(&person1, IDsearch2);
			cout << "Professor successfully deleted!" << endl;
		}
		else if(input == 'D'){
			cout << "Enter the ID of the professor you want to update: ";
			cin >> IDsearch;
			updateProfessor(IDsearch);
			cout << "Professor successfully updated!" << endl;
		}
		else if(input == 'E'){
			break;
		}
		else{
			cout << "Invalid input..." << endl;
		}
	}
}

//-------------------------------------------------------Main-----------------------------------------------------------
int main(){
	reads();
	char option;
	
	while(100000){
		cout << "----------------------------Main Menu------------------------------" << endl;
		cout << "1) Manage Student " << endl;
		cout << "2) Manage Employee " << endl;
		cout << "3) Manage Professor " << endl;
		cout << "4) View all Faculty, Staff and Students " << endl;
		cout << "5) Quit Program " << endl;
		cout << "Please choose an option (1-5): ";
		cin >> option;
		if(option == '1'){
			cout << "----------------------------Student Menu------------------------------" << endl;
			studentMenu();
		}
		else if(option == '2'){
			cout << "----------------------------Employee Menu------------------------------" << endl;
			employeeMenu();
		}
		else if(option == '3'){
			cout << "----------------------------Professor Menu------------------------------" << endl;
			professorMenu();
		}
		else if(option == '4'){
			printPeople();
		}
		else if(option == '5'){
			savelist();
			cout << "Exiting Program... Goodbye!" << endl;
			break;
		}
		else{
			cout << "Invalid Input..." << endl;
		}
	}
return 0;
}
