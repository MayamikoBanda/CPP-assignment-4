# CPP-assignment-4 .
C++ Practice Project — OOP, Dynamic Memory & Strings 

 Overview 

This project contains three C++ programs , each problem builds practical understanding of how memory and data structures work under the hood. 

Question 1 — Class Person & Object Swapping 

 Objective 

Implement a Person class that stores: 

Name 

Student ID 

Age 

Also implement a function to swap two Person objects. 

Key Concepts 

Classes & encapsulation 

Member functions 

Passing objects by reference 

Object swapping 

 Code Snippet 

class Person { 
private: 
   char name[50]; 
   int studentID; 
   int age; 
 
public: 
  

  void init(const char* n, int id, int a) { 
       strcpy(name, n); 
       studentID = id; 
       age = a; 
   } 
 
   void printStudentInfo() { 
       cout << "Name: " << name << endl; 
       cout << "Student ID: " << studentID << endl; 
       cout << "Age: " << age << endl; 
   } 
}; 
 
void personSwap(Person &p1, Person &p2) { 
   Person temp = p1; 
   p1 = p2; 
   p2 = temp; 
} 

Breakdown 

strcpy() copies string into the class variable. 

& (reference) allows modifying original objects. 

Swap logic uses a temporary variable (classic pattern). 

 

Question 2 — Seat Management System  

Objective 

Create a 10×10 seat system using dynamic memory: 

Initialize with memset 

Copy with memcpy 

Modify and compare arrays 

Key Concepts 

Dynamic 2D arrays (int**) 

Memory initialization (memset) 

Memory copying (memcpy) 

Manual memory cleanup 

Code Snippet 

int **seat = new int*[10]; 
for (int i = 0; i < 10; i++) { 
   seat[i] = new int[10]; 
   memset(seat[i], 0, 10 * sizeof(int)); 
} 
 
// Copy 
int **backup = new int*[10]; 
for (int i = 0; i < 10; i++) { 
   backup[i] = new int[10]; 
   memcpy(backup[i], seat[i], 10 * sizeof(int)); 
} 

Breakdown 

new int*[10] → creates array of row pointers 

Each row allocated separately → forms 2D array 

memset() → sets all values to 0 

memcpy() → copies data row-by-row 

 Important  

After copying: 

Modifying seat does NOT affect backup 

This proves they use separate memory 

 

Question 3 — Dynamic String Dictionary 

Objective 

Building a small dictionary system that: 

Stores words dynamically 

Searches, modifies and delete words 

Manages memory manually 

Key Concepts 

char** (array of strings) 

Dynamic string allocation 

String operations (strcpy, strcmp) 

Memory shifting after deletionCode Snippet 

char **list = new char*[5]; 
 
list[0] = new char[strlen("alpha") + 1]; 
strcpy(list[0], "alpha"); 

 Breakdown 

Each word gets exact memory size 

strlen(word) + 1 → includes null terminator 

strcmp() → used for searching 

Deletion requires: 

Free memory 

Shift elements left 

 Memory Cleanup Example 

for (int i = 0; i < size; i++) { 
   delete[] list[i]; 
} 
delete[] list; 
