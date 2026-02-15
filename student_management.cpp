#include <iostream>
#include <string>
using namespace std;

// Structure to store student information
struct Student {
    int rollNo;
    string name;
    string department;
};

// Function to add student records
void addStudents(Student s[], int &n) {
    cout << "\n========================================\n";
    cout << "  STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "\nEnter number of students: ";
    cin >> n;
    
    for (int i = 0; i < n; i++)
 {
        cout << "\n--- Student " << i + 1 << " ---\n";
        cout << "Roll No: ";
        cin >> s[i].rollNo;
        cin.ignore(); // Clear input buffer
        cout << "Name: ";
        getline(cin, s[i].name);
        cout << "Department: ";
        getline(cin, s[i].department);
    }
    cout << "\n✓ " << n << " student(s) added successfully!\n";
}

// Function to display all student records
void displayStudents(Student s[], int n)
 {
    cout << "\n========================================\n";
    cout << "       STUDENT RECORDS (Sorted)\n";
    cout << "========================================\n";
    cout << "\nRoll No\t\tName\t\t\tDepartment\n";
    cout << "----------------------------------------\n";
    
    for (int i = 0; i < n; i++)
 {
        cout << s[i].rollNo << "\t\t"
             << s[i].name << "\t\t\t"
             << s[i].department << endl;
    }
    cout << "========================================\n";
}

// Bubble Sort algorithm to sort students by roll number
void bubbleSort(Student s[], int n)
 {
    for (int i = 0; i < n - 1; i++)

 {
        for (int j = 0; j < n - i - 1; j++)

 {
            if (s[j].rollNo > s[j + 1].rollNo)
 {
                // Swap students
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    cout << "\n✓ Records sorted successfully using Bubble Sort!\n";
}

// Binary Search algorithm to search student by roll number
int binarySearch(Student s[], int n, int key)
 {
    int low = 0;
    int high = n - 1;
    
    while (low <= high)
 {
        int mid = (low + high) / 2;
        
        if (s[mid].rollNo == key)
 {
            return mid;  // Student found
        }
        else if (s[mid].rollNo < key)
 {
            low = mid + 1;  // Search in right half
        }
        else {
            high = mid - 1;  // Search in left half
        }
    }
    
    return -1;  // Student not found
}

// Main function
int main()
 {
    Student s[50];  
    int n = 0;      
    int choice;     
    int key;        
    int result;     
    
    // Add students at the start
    addStudents(s, n);
    
    // Sort the records
    bubbleSort(s, n);
    
    // Menu-driven system
    do {
        cout << "\n========================================\n";
        cout << "              MAIN MENU\n";
        cout << "========================================\n";
        cout << "1. Display All Records\n";
        cout << "2. Search Student by Roll Number\n";
        cout << "3. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                // Display all student records
                displayStudents(s, n);
                break;
                
            case 2:
                // Search for a student
                cout << "\nEnter Roll No to search: ";
                cin >> key;
                result = binarySearch(s, n, key);
                
                if (result != -1) {
                    cout << "\n✓ Student Found!\n";
                    cout << "----------------------------------------\n";
                    cout << "Roll No: " << s[result].rollNo << endl;
                    cout << "Name: " << s[result].name << endl;
                    cout << "Department: " << s[result].department << endl;
                    cout << "----------------------------------------\n";
                }
                else {
                    cout << "\n✗ Student not found!\n";
                    cout << "No record exists with Roll No: " << key << endl;
                }
                break;
                
            case 3:
                // Exit the program
                cout << "\n========================================\n";
                cout << "  Thank you for using the system!\n";
                cout << "========================================\n";
                break;
                
            default:
                cout << "\n✗ Invalid choice! Please try again.\n";
        }
        
    } while (choice != 3);
    
    return 0;
}
