#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

bool isValidNum (int &number, int &validationError); // for validating numbers
bool isValidString (string &userInput, int &validationError); // for validating strings
int generateRollNumber (); // for generating random roll #
bool validatePhoneNumber (const string& phoneNumber); // for validating phone numbers
void displayAge (const string& dob); // for age calculation
void getStudentDetails (); // for getting neccesary student details

int main() {

    // code for generating random numbers
    srand(static_cast<unsigned>(time(0)));

    char choice;
    do {
        cout << "<------------ Student Enrollment Management System ------------>\n" << endl;
        getStudentDetails();

        cout << "\nDo you want to enroll another student? (y/n): ";
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y')
        {
            system("cls");
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\nExiting the Student Enrollment Management System , Good Bye ! :)" << endl;

    return 0;
}

bool isValidNum(int &number, int &validationError) {
    cout << "Enter an integer: ";

    // Input validation for integer
    while (!(cin >> number) || isalpha(cin.peek())) {
        // cout << "Error: Please enter a number and do not use alphabets." << endl;

        // Clear input buffer
        cin.clear();

        // Ignore remaining characters in the buffer
        cin.ignore(1000, '\n');

        // Set the error type
        validationError = 1;  // Use 1 to represent CONTAINS_ALPHA error
        return false;
    }

    // No error
    validationError = 0;  // Use 0 to represent NO_ERROR
    return true;
}

bool isValidString(string &userInput, int &validationError) {
    while (true) {
        // cout << "Enter a string: ";

        // Use getline to get the entire line of input
        getline(cin, userInput);

        // Check if the input contains any numeric characters
        bool containsDigit = false;
        for (char c : userInput) {
            if (isdigit(c)) {
                containsDigit = true;
                break;
            }
        }

        if (containsDigit) {
            validationError = 1;  // Use 1 to represent CONTAINS_DIGIT error
            return false;
        } else {
            // Input is a valid string without numbers
            validationError = 0;  // Use 0 to represent NO_ERROR
            return true;
        }
    }
}

int generateRollNumber() {
    return rand() % 9000 + 1000;
}

bool validatePhoneNumber(const string& phoneNumber) {
    if (phoneNumber.length() == 10 && isdigit(phoneNumber[0]) && phoneNumber[0] != '0') {
        return true;
    }
    cout<<"\nError: Phone Number must based on 10 Digits and not contain Alphabets , Re-Enter: ";
    return false;
}

void displayAge(const string& dob) {
    int birthDay, birthMonth, birthYear,validationResult;

    cout << "\nEnter birthdate (DD): ";

    while(!isValidNum(birthDay,validationResult))
    {
        cout<<"\nError: Enter Birth-Date in numbers only , Re-enter Again: ";
    }

    cout << "\nEnter birth month (MM): ";
    while(!isValidNum(birthMonth,validationResult))
    {
        cout<<"\nError: Enter Birth-Month in numbers only , Re-enter Again: ";
    }

    cout << "\nEnter birth year (YYYY): ";
    while(!isValidNum(birthYear,validationResult))
    {
        cout<<"\nError: Enter Birth-Year in numbers only , Re-enter Again: ";
    }

    int currentYear;
    cout << "\nEnter the current year (YYYY): ";
    while(!isValidNum(currentYear,validationResult))
    {
        cout<<"\nError: Enter Current-Year in numbers only , Re-enter Again: ";
    }

    int age = currentYear - birthYear;

    cout << "\nAge: " << age << endl;
}

// Function to get student details for enrollment
void getStudentDetails() {
    string firstName, lastName, fatherName, dob, phoneNumber, address , dd , mm , yyyy;
    int validationResult;

    cout << "Enter First Name: ";
    while (!isValidString(firstName,validationResult)){
        cout<<"\nError: Name must contains Alphabets only , Re-enter Again: ";
    }

    cout << "Enter Last Name: ";
     while (!isValidString(lastName,validationResult)){
        cout<<"\nError: Name must contains Alphabets only , Re-enter Again: ";
    }

    cout << "Enter Father's Name: ";
     while (!isValidString(fatherName,validationResult)){
        cout<<"\nError: Father Name must contains Alphabets only , Re-enter Again: ";
    }

    cout << "\nEnter Date of Birth (DD/MM/YYYY): ";
    cout << "\nDD: ";
    cin >> dd ;


    cout << "\nEnter Month (MM): ";
    cin >> mm;

    cout << "\nEnter Year (YYYY): ";
    cin >> yyyy;



    // Input validation for phone number
    do {
        cout << "\nEnter Phone Number: ";
        cin >> phoneNumber;
    } while (!validatePhoneNumber(phoneNumber));

    cout << "\nEnter Address: ";
    cin.ignore();
    getline(cin, address);

    int rollNumber = generateRollNumber();

    system("cls");
    cout << "\nEnrollment Successful!\n\nStudent Details:" << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Father's Name: " << fatherName << endl;
    cout << "Date of Birth: " << dd << '/' << mm << '/' << yyyy << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Address: " << address << endl;

    displayAge(dob);
}