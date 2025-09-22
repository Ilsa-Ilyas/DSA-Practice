#include <iostream>
using namespace std;

class Student {
public:
    int id;
    double gpa;
    string name;
    int age;

    // default constructor
    Student() : id(0), gpa(0.0), name(""), age(0) {}

    // parameterized constructor
    Student(int _id, double _gpa, const string& _name, int _age)
        : id(_id), gpa(_gpa), name(_name), age(_age) {}
};

// Bubble sort: sorts students by GPA in ascending order
void sort(Student arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].gpa > arr[j + 1].gpa) {
                // swap students if out of order
                Student tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// Binary search: find students with given GPA and print their IDs
void selection(Student arr[], int n, double target) {
    int low = 0, high = n - 1, mid, found = -1;

    // Standard binary search loop
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid].gpa == target) {
            found = mid; // GPA found
            break;
        } else if (arr[mid].gpa < target) {
            low = mid + 1; // search right half
        } else {
            high = mid - 1; // search left half
        }
    }

    cout << "Students with GPA " << target << " (IDs): ";

    // If GPA not found at all
    if (found == -1) {
        cout << "None\n";
        return;
    }

    // Move left to find the first occurrence of target GPA
    int i = found;
    while (i >= 0 && arr[i].gpa == target) i--;
    int start = i + 1; // first index where target GPA starts

    // Print all matching students from left to right
    int idx = start;
    while (idx < n && arr[idx].gpa == target) {
        if (idx != start) cout << ", "; // print commas between IDs
        cout << arr[idx].id;
        ++idx;
    }
    cout << "\n";
}

int main() {
    // Sample data
    Student arr[] = {
        Student(101, 3.2, "Ali", 20),
        Student(102, 3.5, "Sara", 21),
        Student(103, 3.5, "Bilal", 19),
        Student(104, 2.9, "Aisha", 22),
        Student(105, 3.7, "Tom", 20)
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Step 1: Sort by GPA
    sort(arr, n);

    // Step 2: Search by GPA and print IDs
    selection(arr, n, 3.5); // expects: 102, 103
    selection(arr, n, 3.9); // expects: None
    selection(arr, n, 3.2); // expects: 101

    return 0;
}
