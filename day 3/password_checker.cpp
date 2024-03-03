#include <iostream>
#include <cctype>

using namespace std;

bool passValidator(const string &password);

int main (){

    // Welcome Screen To The Password Strength Checker Program

    cout << "\n------------Password Strength Checker---------------";
    

    cout << "\n\nWelcome to The Password Strength Checker Program !";

    string password;
    bool validationResult = false;

    do {
        cout << "\n\nPlease Enter Your Password: ";
        getline (cin,password);

        if ( password.length() < 8 || password.find(' ') != string::npos)
        {
            cout << "\nError: Password must contain minimum 8 characters and with no spaces.";
        }

        else if (!passValidator(password))
        {
            cout << "\nError:Password must contain 1 uppercase , lowercase and 1 number.";
        }

        else {
            validationResult = true;
            cout << "\nPassword Strength: Strong";
        }
    } while (!validationResult);
    
    return 0;
}   

bool passValidator(const string &password)
{
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;

    for (char identifer : password) 
    { 
        if (isupper(identifer)) 
        {
            hasUppercase = true;
        } 

        else if (islower(identifer))
        {
            hasLowercase = true;
        } 

        else if (isdigit(identifer)) 
        {
            hasDigit = true;
        }
    }

    return (hasUppercase && hasLowercase && hasDigit);
}