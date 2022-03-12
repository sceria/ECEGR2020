#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FULL 10

typedef struct Student
{
	int ID;
	char firstName[30];
	char lastName[30];
	float GPA;
	// next pointer is used for the linked list
	struct Student *next;
}Student;
//--------------------------------------------------------------------------
Student* headNode = NULL; //start of the linked list. Linked lists have a head and a tail that are both NULL.
//--------------------------------------------------------------------------
//Function that Creates Nodes
Student* createNode(int tempID, char tempFirst[30], char tempLast[30], float tempGPA){
	Student*   newNode = NULL;
	//  Create new node
	newNode = (Student *) malloc(sizeof(Student));
	if( newNode != NULL ) // If new node is not empty...
	{
		newNode->ID = tempID;
		strcpy(newNode -> firstName, tempFirst); // strcopy (AKA string copy) goes into newNode and copies the string of variable "firstName" and puts it into variable "tempFirst"
		strcpy(newNode -> lastName, tempLast);
		newNode->GPA = tempGPA;
		
		newNode->next = NULL;
	
	}
	return newNode;
}
//--------------------------------------------------------------------------
//  Adds a Node to the end of the list
void addNode(Student* newStudentInfo)
{
    Student* currentNode = headNode;
	Student* afterNode;
    //  Check for empty list
    if( headNode == NULL ) // If headNode is pointing at NULL...
    {
        headNode = newStudentInfo;
        return;
    }
	
	while( currentNode->next != NULL )
        currentNode = currentNode->next;
    //  Add new node to end
    currentNode->next = newStudentInfo;
}
//--------------------------------------------------------------------------
// Inserts student node 
void topAdd(Student* newStudentInfo)
{
	Student* currentNode = headNode;
	Student* afterNode;
	//  Check for empty list
	if( headNode == NULL ) // If headNode is pointing at NULL...
	{
		headNode = newStudentInfo;
		return;
	}
	 //  Organizes Linked List by highest to lowest GPA
    while( currentNode->next != NULL ){
		afterNode = currentNode->next;
		if ((currentNode->GPA > newStudentInfo->GPA) && (newStudentInfo->GPA > afterNode->GPA)) 
		{
			//newStudentInfo->next = afterNode->next;
			currentNode->next = newStudentInfo;
			newStudentInfo->next = afterNode;
			return;
		}
		// Else if adds node to the top of the linked list
		else if (newStudentInfo->GPA > currentNode->GPA)
		{
			newStudentInfo->next = currentNode;
			headNode = newStudentInfo;
			return;
		}
		else
		{
			currentNode = currentNode->next;
			afterNode = afterNode->next;
		}
	}
	
    //  Add new node to end; IDK IF THESE BEING IMPLEMENTED CORRECTLY 
    currentNode->next = newStudentInfo;
	newStudentInfo->next = NULL;
	return;
	
}
//--------------------------------------------------------------------------
// Deletes node from the linked list
void nodeDeleter(Student* deleteNode) // deleteNode is the node that's going to be deleted
{
	Student* currentNode = headNode;
	Student* prevNode;
	
	// Deletion for nodes at the beginning of the list
	if (deleteNode==headNode)
	{
		headNode=headNode->next;
		free(deleteNode);
		return;
	}
	
	// Gets prevNode to point at node before deleteNode
	while(currentNode!= NULL && currentNode!=deleteNode){
		prevNode=currentNode;
		currentNode=currentNode->next;
	}
	// Unlinks the node to be deleted and links previous node to the node after it
	prevNode->next = currentNode->next;
    
	// Frees and deletes node
	free(currentNode);
}
//--------------------------------------------------------------------------
// Menu option 1: Lists all students
void ListingStudents()
{

	Student* currNode = headNode;
	int position = 0;
	while(currNode != NULL)
	{
		//printf("List Position: %d\n", position++); // line used for visualization of moving along the linked list
		printf("\nStudent ID: %d\n", currNode->ID);
		printf("Student's First Name: %s\n", currNode->firstName);
		printf("Student's Last Name: %s\n", currNode->lastName);
		printf("Student's GPA: %f\n", currNode->GPA);
		printf("\n");
		currNode = currNode->next;
		
	}
}
//--------------------------------------------------------------------------
// Menu option 2: Add Student
void AddStudent()
{
	// Collects new information of the student 
	Student* student = (Student*)malloc(sizeof(Student));
	char firstName[30];
	char lastName[30];
	printf("\nWhat's the student's ID?\n");
	scanf("%d", &(student -> ID));
	printf("What's the student's first name?\n");
	scanf("%s", &firstName);
	printf("What's the student's last name?\n");
	scanf("%s", &lastName);
	printf("What's the student's GPA?\n");
	scanf("%f", &(student -> GPA));
	
	strcpy(student -> firstName, firstName);
	strcpy(student -> lastName, lastName);
	
	// Creates a new node for the student 
	Student* newStudentInfo = createNode(student->ID, firstName, lastName, student->GPA);
	topAdd(newStudentInfo); // FOR NEW ADDSTUDENT FUNCTION!
	printf("\nStudent successfully added to the class!");
}
//--------------------------------------------------------------------------
// Menu option 3: Delete Student
void deleteStudent(Student** deleteNode)
{
	int deleteID;
	Student *currentNode = *deleteNode,  *prevNode;
	printf("What's the ID of the student you would like to remove?\n");
	scanf("%d", &deleteID);
	
	// Checks if the desired node to be deleted is the headnode (AKA beginning of the list)
	if (currentNode != NULL && currentNode->ID == deleteID)
	{
		*deleteNode = currentNode->next;
		free(currentNode);
		// Message indicating process was successful
		printf("Student successfully removed from the class!");
		return;
	}
	// Finds the desired node to be deleted
	while(currentNode != NULL && currentNode->ID != deleteID){
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	
	// Unlinks the node to be deleted and links previous node to the node after it
	if (currentNode == NULL)
	{
		return;
	}
	// Frees and deletes node
	prevNode->next = currentNode->next;
	free(currentNode);
	
	// Message indicating process was successful
	printf("Student successfully removed from the class!");
} 
//--------------------------------------------------------------------------
// Menu option 4: Updating Student Information
void updateStudent()
{
	int updateID, userInput;
	Student* Updater = headNode;
	printf("\nWhat's the ID of the student whose profile you would like to update?\n");
	scanf("%d", &updateID);
	
	// Find the student/node that wants to be updated
	while(Updater->ID != updateID){
		Updater = Updater->next;
	}
	printf("\nWould you like to update their\n1)ID,\n2)first name,\n3)last name, or \n4)GPA?\n");
	printf("Please enter an option (1-4): ");
	scanf("%d", &userInput);
	if (userInput == 1)
	{
		// Updates ID
		printf("\nWhat's this student's new ID?\n");
		scanf("%d", &(Updater->ID));
		printf("ID has been successfully updated!");
	}
	else if (userInput == 2)
	{
		char newFirst[30];
		// Collects new First name
		printf("\nWhat's this student's first name?\n");
		scanf("%s", &newFirst);
		// Updates the first name
		strcpy(Updater -> firstName, newFirst);
		printf("First name has been successfully updated!");
	}
	else if (userInput == 3)
	{
		char newLast[30];
		// Collects new Last name
		printf("\nWhat's this student's last name?\n");
		scanf("%s", &(newLast));
		// Updates the last name
		strcpy(Updater -> lastName, newLast);
		printf("Last name has been successfully updated!\n");
	}
	else if (userInput == 4)
	{
		// Updates GPA
		printf("\nWhat's this student's new GPA?\n");
		scanf("%f", &(Updater->GPA));
		//-----------------------------------------------------------
		// Re-sorts linked list by highest to lowest GPA
		Student* prevNode;
		Student* currentNode = headNode;
		Student* afterNode;
		Student* lastNode = headNode;
		
		// Loops to end of the list
		while(lastNode->next != NULL){
			lastNode = lastNode->next;
		}
		
		// Finds where the node is, unlinks it appropriately, and then adds it to the proper spot in the list
		while(1){
			if (Updater->ID == currentNode->ID) // If the updated student is the same student at the top of the list
			{
				// Unlinks node from the list
				currentNode = currentNode->next;
				// reinserts node in correct spot
				topAdd(currentNode);
				break;
			}
			else if (Updater->ID == lastNode->ID) // If the updated student is the last student of the list
			{
				// Loops to end of the list
				while(currentNode->next != NULL){
					prevNode = currentNode;
					currentNode = currentNode->next;
				}
			// Unlinks last node
			prevNode->next = NULL;
			// Reinserts student node in the right place
			topAdd(currentNode);
			break;
			}
			else
			{
				// Finds where the updated student is in the list
				while(Updater->ID != currentNode->ID){
					prevNode = currentNode;
					currentNode = currentNode->next;
				}
			afterNode = currentNode->next;
			// Unlinks the updated student node
			prevNode->next = afterNode;
			// Reinserts student in the right place
			topAdd(currentNode);
			break;
			}
		}
		printf("GPA has been successfully updated!");
	}
	else
	{
		printf("That is an invalid input!\nPlease enter an option (1-4): ");
	}
}
//--------------------------------------------------------------------------
// Writes to the file created
void writeClassroom()
{
	Student* roleCall = headNode;
	int studentCount = 0;
	// Student Class counter
	while(roleCall != NULL) {
		studentCount++;
		roleCall = roleCall->next;
	}
	// While loop counted the amount of students in the class which is stored in the variable studentCount
	// Now, we will write into the file, overriding it.
	FILE *pencil = fopen("C:/C++/ECEGR2020/ClassOfKeikis.txt", "w");
	fprintf(pencil, "Number of Keikis in the class: %d\n", studentCount);
	fprintf(pencil, "\n");
	for(int i = 0; i < studentCount; i++) {
		fprintf(pencil, "ID Number: %d\n", headNode -> ID);
		fprintf(pencil, "First Name: %s\n", headNode -> firstName);
		fprintf(pencil, "Last Name: %s\n", headNode -> lastName);
		fprintf(pencil, "GPA: %f\n", headNode -> GPA);
		fprintf(pencil, "\n");
		headNode = headNode->next;
	} 
	fclose(pencil);
}
//--------------------------------------------------------------------------
// Reads file created
void readStudentInfo()
{
	
	// Temporary variables to hold the contents of each struct
	int tempID, tempclass_size;
	char tempFirst[30];
	char tempLast[30];
	float tempGPA, temp;

	FILE *glasses;
	glasses = fopen("C:/C++/ECEGR2020/ClassOfKeikis.txt", "r");
	fscanf(glasses, "Number of Keikis in the class: %d\n", &tempclass_size); //tried to use this to set parameters for my node creating for loop
	
	for (int i = 0; i < tempclass_size; i++){
		// scans file for the needed information and puts them in temporary variables
		fscanf(glasses, "ID Number: %d\n", &tempID);
		fscanf(glasses, "First Name: %s\n", &tempFirst);
		fscanf(glasses, "Last Name: %s\n", &tempLast);
		fscanf(glasses, "GPA: %f\n", &tempGPA);
		//create node and puts the info into the node
		//if(tempGPA != temp){
			Student* LLStudentInfo = createNode(tempID, tempFirst, tempLast, tempGPA);
			// puts node into the list
			addNode(LLStudentInfo);
		//}
	}
	fclose(glasses);
	
	//--------------------------------------------------------------------------
	// Part B: Menu of options that incoporates the Linked List of Students
	//--------------------------------------------------------------------------
	// Displays Menu
	printf("1) List all Students\n2) Add Student\n3) Remove Student\n");
	printf("4) Update Student\n5) Quit\n");
	
	while(1)
	{
		printf("\nPlease enter an option: ");
		int userInput;
		scanf("%d", &userInput);
		if (userInput == 1)
		{
			ListingStudents();
		}
		else if (userInput==2)
		{
			AddStudent();
		}
		else if (userInput==3)
		{
			deleteStudent(&headNode);
		}
		else if (userInput==4)
		{
			updateStudent();
		}
		else if (userInput == 5)
		{
			writeClassroom();
			printf("\nExiting Student List Operations... Goodbye :)\n");
			break;
		}
		else
		{
			printf("Invalid input!\n");
		}
	}

}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// Part C of lab4: Updating StackArray.cpp
// Data structure to represent a stack
typedef struct Stack
{
    int data;
	struct Stack* next;
} Stack;
 
 Stack* headnode;
 
// Utility function to initialize the linked list
void newStack(){
	headnode = NULL;
}

// Utility function to return the size of the stack
int size(Stack* top) {
    int count = 0; // intialize the count
	Stack* current = top; 
	while (current != NULL){
		count++;
		current = current->next;
	}
	return count;
}
 
// Utility function to check if the stack is empty or not
int isEmpty() {
	if (headnode==NULL)
	{
		printf("Stack is empty!");
	}
	else
	{
		printf("Stack is not empty!");
	}
}

// Utility function to add an element `x` to the stack
void push(int x)
{
    Stack* tempX;
	tempX = malloc(sizeof(Stack));
	tempX->data = x;
	tempX->next = headnode; // adds tempX onto stack
	headnode = tempX; // tempX is the new headNode
}
 
// Utility function to pop a top element from the stack
int pop()
{
    Stack* tempX;
	int s;
	tempX = headnode;
	s = tempX->data;
	headnode = headnode->next; // Unlinks top element from list
	free(tempX);
	return s;
}
 
// Utility function to peek at top element from the stack
int peek()
{
    return headnode->data;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// Part D Lab4: QueueArray.cpp
// Data structure to represent a queue
struct node{
	int data;
	struct node *next;
};

typedef struct node node;

struct Queue
{
	int count;
    node* front;
    node* rear;
};
 
 typedef struct Queue Queue;
 
// Utility function to initialize the queue
void newQueue(Queue *q)
{
    q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}
 
// Utility function to check if the queue is empty or not
int isempty(Queue *q) {
	if (q->rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
// Utility function to add an element `x` to the queue
void insert(Queue *q, int x)
{
    // check if the queue is already full
    if (q->count < FULL)
    {
        node *temp;
		temp = malloc(sizeof(node));
		temp->data = x;
		temp->next=NULL;
		if(!isempty(q))
		{
			q->rear->next = temp;
			q->rear = temp;
		}
		else
		{
			q->front = q->rear = temp;
		}
		q->count++;
    }
	else
	{
		printf("List is full\n");
	}
 
}
 
// Utility function to remove an element from the queue
int Remove(Queue *q)
{
    node *temp;
	int n = q->front->data;
	temp = q->front;
	q->front = q->front->next;
	q->count--;
	free(temp);
	return(n);
}
 
// Utility function to peek at first element from the queue
void Peek(node *head)
{
   if (head == NULL)
   {
	   printf("NULL\n");
   }
   else
   {
	   printf("%d\n", head -> data);
   }
}

int sizes(Queue* q)
{
	printf("%d\n", q->count);
	return 0;
}
//--------------------------------------------------------------------------
int main()
{
//--------------------------------------------------------------------------
	// For the Student menu operations
	readStudentInfo();
//--------------------------------------------------------------------------
	// For part C:
	// create a stack of capacity 5
    /*newStack();
 
    push(3);
    push(2);
    push(1);
 
    printf("\nThe stack size is %d\n", size(headnode));
    printf("Top val on stack is %d\n", peek());
	
    pop();
    pop();
    pop();
	
	isEmpty();*/
//--------------------------------------------------------------------------
	// For part D:
	// create a queue of capacity 5
    /*Queue *qt;
    qt = malloc(sizeof(Queue));
	newQueue(qt);
 
    insert(qt, 10);
    insert(qt, 20);
    insert(qt, 30);
 
	printf("The queue size is: ");
	sizes(qt);
 
    printf("Top value on queue is: ");
    Peek(qt->front);
	
    Remove(qt);
    Remove(qt);
    Remove(qt);
 
    if (isempty(qt)) {
        printf("The queue is empty");
    }
    else {
        printf("The queue is not empty");
    }*/
	return 0;
}
