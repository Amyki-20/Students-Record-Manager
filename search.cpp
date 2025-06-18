#include <iostream>
using namespace std;

void accept(string names[], int ages[], char genders[], int number);
int search(string names[], int size, string name); // search by name
int search(int ages[], int size, int age); // count by age
int search(char genders[], int size, char gender); // count by gender
int display(string names[], int ages[], char genders[], int size);

int main(void)
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    // dynamically allocates memory (to be later freed)
    string* names = new string[n];
    int* ages = new int[n];
    char* genders = new char[n];

    accept(names, ages, genders, n);
    while (display(names, ages, genders, n));

    // frees memory
    delete [] names;
    delete [] ages;
    delete [] genders;

    return 0;
}

void accept(string names[], int ages[], char genders[], int number)
{
    for (int i = 0; i < number; i++)
    {
        cout << endl << "Enter student " << i + 1 << " name: ";
        cin >> names[i];
        cout << "Enter student " << i + 1 << " age: ";
        cin >> ages[i];
        cout << "Enter student " << i + 1 << " gender (M/F): ";
        cin >> genders[i];
    }
}

int display(string names[], int ages[], char genders[], int size)
{
    int choice;
    cout << endl << "How do you want to search?\n(0 - exit, 1 - age, 2 - gender, 3 - name)" << endl << "Choice: ";
    cin >> choice;

    if (choice == 0) // program exit
        return 0;

    if (choice == 1)
    {
        int age;
        cout << "Enter age: ";
        cin >> age;
        cout << "Count of age " << age << " is " << search(ages, size, age) << endl;
    }
    else if (choice == 2)
    {
        char gender;
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Count of gender " << gender << " is " << search(genders, size, gender) << endl;
    }
    else if (choice == 3)
    {
        string name;
        cout << "Enter name: ";
        cin >> name;
        int s = search(names, size, name);
        if (s == -1)
            cout << "No entries of " << name << endl;
        else
            cout << name << " found at entry " << s + 1 << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
    }

    return 1; // for display to ask indefinitely
}

// search by name
int search(string names[], int size, string name)
{
    for (int i = 0; i < size; i++)
    {
        if (names[i] == name)   
            return i;
    }
    return -1; // not found
}

// search by age
int search(int ages[], int size, int age)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (ages[i] == age)
            c++;
    }
    return c;
}

// search by gender
int search(char genders[], int size, char gender)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (genders[i] == gender)
            c++;
    }
    return c;
}