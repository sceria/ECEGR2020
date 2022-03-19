#include <iostream>
#include <cstring>
using namespace std;

class Student
{
//--------------------------------------------------------------------------------------------------------------------------------------------------
private: // variables declared in private can only be accessed within the class
	int ID;
	char *firstName;
	char *lastName;
	float GPA;
//--------------------------------------------------------------------------------------------------------------------------------------------------
public:
//------------------Constructor Declaration (FUNCTIONS that are called once they are intialized)----------------------------------------------------
Student (){
	// Default constructor; does nothing and is implicitly declared for classes 
	// When an object is created, this constructor is called which initializes its data members
}

// Parameterized Constructor
Student(int ID, const char *firstName, const char *lastName, float GPA){ 
	// the variables passed in the parameters are stored in their corresponding variables below
	//----------------
	this->ID = ID;
	//----------------
	unsigned int x = 0; 
	unsigned int sizeFirst;
	sizeFirst = strlen(firstName);
	this->firstName = new char[sizeFirst+1];
	
		while (x != sizeFirst){
			this->firstName[x] = firstName[x];
			x++;
		}
	//----------------
	unsigned int y = 0; 
	unsigned int sizeLast;
	sizeLast = strlen(lastName);
	this->lastName = new char[sizeLast+1]; // "new <var_type>[]" allocates memory; +1 because there's always a NULL character at the end of each string
	
		while (y != sizeLast){
			this->lastName[y] = lastName[y];
			y++;
		}
	//----------------
	this->GPA = GPA;
	cout << "Parameterized Constructor called!" << endl;
}

// Copy constructor 
Student (const Student &p){ //need & since we're dealing with pointers which point to the address of something
	//----------------
	ID = p.ID;
	//----------------
	unsigned int x = 0; 
	unsigned int sizeFirst;
	sizeFirst = strlen(p.firstName); // needs to find the strlen of p.firstName and NOT firstName since we want size of the name we are copying
	firstName = new char[sizeFirst+1];
		while (x != sizeFirst){
			firstName[x] = p.firstName[x];
			x++;
		}
	//----------------
	unsigned int y = 0; 
	unsigned int sizeLast;
	sizeLast = strlen(p.lastName);
	lastName = new char[sizeLast+1]; // "new <var_type>[]" allocates memory; +1 because there's always a NULL character at the end of each string
	
		while (y != sizeLast){
			lastName[y] = p.lastName[y]; // Copies the last name of the student into the private variable
			y++;
		}
	//----------------
	GPA = p.GPA;
	cout << "Copy Constructor called!" << endl;
}
// Destructor; Only need to define a destructor when there is memory that's allocated; compiler creates a default destructor for the memory that was not allocated
~Student()
{
	delete [] firstName;
	delete [] lastName;
	cout << "Destructor called!" << endl;
}
//------------------METHODS (FUNCTIONS IN CLASSES; called with the '.' operator)--------------------------------------------------------------------
	void setID(int ID){
		this->ID = ID; // "this" is a keyword that will refer to a private variables
	}
	void getID(){
		cout << "Student's ID: " << ID << endl; // cout is synonymous to printf and endl is "endline" and like "\n"
	}
	void setfirstName(const char *firstName){ //DONT FORGET TO ALLOCATE MEMORY
		this->firstName = (char*) malloc(strlen(firstName)+1);
		strcpy(this->firstName, firstName); // second comma placement is what's being copied and is getting put into the first comma placement
	}
	void getfirstName(){
		cout << "Student's First Name: " << firstName << endl;
	}
	void setlastName(const char *lastName){ //DONT FORGET TO ALLOCATE MEMORY
		this->lastName = (char*) malloc(strlen(lastName)+1);
		strcpy(this->lastName, lastName); 
	}
	void getlastName(){
		cout << "Student's Last Name: " << lastName << endl;
	}
	void setGPA(float GPA){
		this->GPA = GPA;
	}
	void getGPA(){
		cout << "Student's GPA: " << GPA << endl;
	}
	
};

void studentTest(){
	Student Kim;
	
	Kim.setID(711);
	Kim.getID();
	Kim.setfirstName("Kim");
	Kim.getfirstName();
	Kim.setlastName("Possible");
	Kim.getlastName();
	Kim.setGPA(3.5);
	Kim.getGPA();
	//------------------------------
	cout << endl;
	Student Batman (86, "Bat", "Man", 5.2);
	Batman.getID();
	Batman.getfirstName();
	Batman.getlastName();
	Batman.getGPA();
	//------------------------------
	//Copy constructor test; when object of type Student class is equal to another object of said class, copy constructor is called
	cout << endl;
	Student Manbat = Batman;
	Manbat.getID();
	Manbat.getfirstName();
	Manbat.getlastName();
	Manbat.getGPA();
	//------------------------------
	// Destructors are called automatically
	
	// Class methods are working properly as the properties of each object of the student class are being initialized within the parameter
	// and are saved into memory. I have also included print statements that will let the user know when the constructors and destructors 
	// are called.
}
//------------------------------------------------------------EMPLOYEE----------------------------------------------------------------------------------

class Employee
{
//--------------------------------------------------------------------------------------------------------------------------------------------------
private: // variables declared in private can only be accessed within the class
	int ID;
	char *firstName;
	char *lastName;
	float Salary;
//--------------------------------------------------------------------------------------------------------------------------------------------------
public:
//------------------Constructor Declaration (FUNCTIONS that are called once they are intialized)----------------------------------------------------
Employee (){
	// Default constructor; does nothing and is implicitly declared for classes 
	// When an object is created, this constructor is called which initializes its data members
}

// Parameterized Constructor
Employee(int ID, const char *firstName, const char *lastName, float Salary){ 
	// the variables passed in the parameters are stored in their corresponding variables below
	//----------------
	this->ID = ID;
	//----------------
	unsigned int x = 0; 
	unsigned int sizeFirst;
	sizeFirst = strlen(firstName);
	this->firstName = new char[sizeFirst+1];
	
		while (x != sizeFirst){
			this->firstName[x] = firstName[x];
			x++;
		}
	//----------------
	unsigned int y = 0; 
	unsigned int sizeLast;
	sizeLast = strlen(lastName);
	this->lastName = new char[sizeLast+1]; // "new <var_type>[]" allocates memory; +1 because there's always a NULL character at the end of each string
	
		while (y != sizeLast){
			this->lastName[y] = lastName[y];
			y++;
		}
	//----------------
	this->Salary = Salary;
	cout << "Parameterized Constructor called!" << endl;
}

// Copy Constructor
Employee (const Employee &p){
	// Copies ID
	ID = p.ID;
	//----------------
	// Copies first name
	unsigned int x = 0; 
	unsigned int sizeFirst;
	sizeFirst = strlen(firstName);
	firstName = new char[sizeFirst+1];
	
		while (x != sizeFirst){
			firstName[x] = p.firstName[x];
			x++;
		}
	//----------------
	// Copies last name
	unsigned int y = 0; 
	unsigned int sizeLast;
	sizeLast = strlen(p.lastName);
	lastName = new char[sizeLast+1]; // "new <var_type>[]" allocates memory; +1 because there's always a NULL character at the end of each string
	
		while (y != sizeLast){
			lastName[y] = p.lastName[y]; // Copies the last name of the student into the private variable
			y++;
		}
		//---------------

	//----------------
	// Copies Salary
	Salary = p.Salary;
	
	cout << "Copy Constructor Called!" << endl;
}

// Employee Destructor
~Employee(){
	delete[] firstName;
	delete[] lastName;
	cout << "Destructor called!" << endl;
}
// --------------------------------------------------------------"SET" Methods--------------------------------------------------------------
void setID (int x){
	ID = x;
}
void setfirstName(const char* firstName){
	this->firstName = (char*) malloc(strlen(firstName)+1);
	strcpy(this->firstName, firstName); // second comma placement is what's being copied and is getting put into the first comma placement
}
void setlastName(const char* lastName){
	this->lastName = (char*) malloc(strlen(lastName)+1);
	strcpy(this->lastName, lastName); // second comma placement is what's being copied and is getting put into the first comma placement
}
void setSalary (float y){
	Salary = y;
}
// --------------------------------------------------------------"GET" Methods--------------------------------------------------------------
void getID(){
	cout << "Employee's ID: "<< ID <<endl;
}
void getfirstName(){
	cout << "Employee's First Name: " << firstName << endl;
}
void getlastName(){
	cout << "Employee's Last Name: " << lastName << endl;
}
void getSalary(){
	cout << "Employee's Salary: "<< Salary <<endl;
}
};

void employeeTest(){
	// Testing set/get methods
	Employee Employee1;
	Employee1.setID(96818);
	Employee1.setfirstName("Kamaru");
	Employee1.setlastName("Usman");
	Employee1.setSalary(25);
	Employee1.getID();
	Employee1.getfirstName();
	Employee1.getlastName();
	Employee1.getSalary();
	
	cout << endl;
	// Testing Parameterized Constructor
	Employee employee2(63, "Khing", "Vahn", 1000);
	employee2.getID();
	employee2.getfirstName();
	employee2.getlastName();
	employee2.getSalary();
	
	cout << endl;
	// Testing Copy constructor
	Employee employee3 = employee2;
	cout << "employee2's doppelganger: " << endl;
	employee3.getID();
	employee3.getfirstName();
	employee3.getlastName();
	employee3.getSalary();

// Class methods are working properly as the properties of each object of the employee class are being initialized within the parameter
// and are saved into memory. I have also included print statements that will let the user know when the constructors and destructors 
// are called. Therefore, we can identify the freeing of all the dynamically allocated memory.
}

//------------------------------------------------------------PROFESSORS----------------------------------------------------------------------------------

class professor
{
// Able to write multiple publics and privates

public:
// Initializing enumerated list:
enum Department {math, compsci, engineering, politicalEcology, physics}; // initializes the departments
// enumerated list has indentifiers that start with 0 (if initialized without values) and are intialized consecutively

//--------------------------------------------------------------------------------------------------------------------------------------------------
private: // variables declared in private can only be accessed within the class
	int ID;
	char *firstName;
	char *lastName;
	float salary;
	bool tenured;
	Department department; // department is of type Department variable 
//--------------------------------------------------------------------------------------------------------------------------------------------------

public:
//------------------Constructor Declaration (FUNCTIONS that are called once they are intialized)----------------------------------------------------
professor (){
	// Default constructor; does nothing and is implicitly declared for classes 
	// When an object is created, this constructor is called which initializes its data members
}

// Parameterized Constructor
professor(int ID, const char *firstName, const char *lastName, float salary, bool tenured, Department department){ 
	// the variables passed in the parameters are stored in their corresponding variables below
	//----------------
	this->ID = ID;
	//----------------
	unsigned int x = 0; 
	unsigned int sizeFirst;
	sizeFirst = strlen(firstName);
	this->firstName = new char[sizeFirst+1];
	
		while (x != sizeFirst){
			this->firstName[x] = firstName[x];
			x++;
		}
	//----------------
	unsigned int y = 0; 
	unsigned int sizeLast;
	sizeLast = strlen(lastName);
	this->lastName = new char[sizeLast+1]; // "new <var_type>[]" allocates memory; +1 because there's always a NULL character at the end of each string
	
		while (y != sizeLast){
			this->lastName[y] = lastName[y];
			y++;
		}
	//----------------
	this->salary = salary;
	//----------------
	this->tenured = tenured;
	//----------------
	this->department = department;

	cout << "Parameterized Constructor called!" << endl;
}

// Copy Constructor
professor (const professor &p){
	// Copies ID
	ID = p.ID;
	//----------------
	// Copies first name
	unsigned int x = 0; 
	unsigned int sizeFirst;
	sizeFirst = strlen(firstName);
	firstName = new char[sizeFirst+1];
	
		while (x != sizeFirst){
			firstName[x] = p.firstName[x];
			x++;
		}
	//----------------
	// Copies last name
	unsigned int y = 0; 
	unsigned int sizeLast;
	sizeLast = strlen(p.lastName);
	lastName = new char[sizeLast+1]; // "new <var_type>[]" allocates memory; +1 because there's always a NULL character at the end of each string
	
		while (y != sizeLast){
			lastName[y] = p.lastName[y]; // Copies the last name of the student into the private variable
			y++;
		}
		//---------------

	//----------------
	// Copies Salary
	salary = p.salary;
	
	//----------------
	// Copies tenured
	tenured = p.tenured;
	
	//----------------
	// Copies department 
	department = p.department;

	cout << "Copy Constructor Called!" << endl;
}

// Professor Destructor
~professor(){
	delete[] firstName;
	delete[] lastName;
	cout << "Destructor called!" << endl;
}
// --------------------------------------------------------------"SET" Methods--------------------------------------------------------------
void setID (int x){
	ID = x;
}
void setfirstName(const char* firstName){
	this->firstName = (char*) malloc(strlen(firstName)+1);
	strcpy(this->firstName, firstName); // second comma placement is what's being copied and is getting put into the first comma placement
}
void setlastName(const char* lastName){
	this->lastName = (char*) malloc(strlen(lastName)+1);
	strcpy(this->lastName, lastName); // second comma placement is what's being copied and is getting put into the first comma placement
}
void setSalary (float y){
	salary = y;
}
void setTenured (bool x){
	tenured = x;
}
void setDepartment (Department x){
	department = x;
}

// --------------------------------------------------------------"GET" Methods--------------------------------------------------------------
void getID(){
	cout << "Professor's ID: "<< ID <<endl;
}
void getfirstName(){
	cout << "Professor's First Name: " << firstName << endl;
}
void getlastName(){
	cout << "Professor's Last Name: " << lastName << endl;
}
void getSalary(){
	cout << "Professor's Salary: "<< salary <<endl;
}
void getTenured(){
	if (tenured == 0){
		cout << "Professor is not tenured! " <<endl;
	}
	else if (tenured == 1){
		cout << "Professor is tenured! " <<endl;
	}
}
void getDepartment(){
	if (department == 0){
		cout << "Professor's Department: Math"<< endl;
	}
	else if (department == 1){
		cout << "Professor's Department: Computer Science" <<endl;
	}
	else if (department == 2){
	cout << "Professor's Department: Engineering" <<endl;
	}
	else if (department == 3){
	cout << "Professor's Department: Political Ecology" <<endl;
	}
	else if (department == 1){
	cout << "Professor's Department: Physics" <<endl;
	}

}
};

void professorTest(){
	// Testing set/get methods
	professor prof1;
	prof1.setID(99);
	prof1.setfirstName("Lee");
	prof1.setlastName("Annrob");
	prof1.setSalary(50);
	prof1.setTenured(1);
	prof1.setDepartment(professor :: math);
	prof1.getID();
	prof1.getfirstName();
	prof1.getlastName();
	prof1.getSalary();
	prof1.getTenured();
	prof1.getDepartment();
	
	cout << endl;
	// Testing Parameterized Constructor
	professor prof2(63, "Tah", "Poha", 200, 0, professor :: politicalEcology);
	prof2.getID();
	prof2.getfirstName();
	prof2.getlastName();
	prof2.getSalary();
	prof2.getTenured();
	prof2.getDepartment();
	
	cout << endl;
	// Testing Copy constructor
	professor prof3 = prof2;
	cout << "professor2's doppelganger: " << endl;
	prof3.getID();
	prof3.getfirstName();
	prof3.getlastName();
	prof3.getSalary();
	prof2.getTenured();
	prof2.getDepartment();
	
// Class methods are working properly as the properties of each object of the professor class are being initialized within the parameter
// and are saved into memory. Print statements are created so that it will notify the user when the constructors and destructors 
// are called. 
}

int main()
{

	//studentTest();
	//employeeTest();
	professorTest();
}
