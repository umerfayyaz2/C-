#include <iostream>
using namespace std;

int main() {

    char choice;
    do {
        cout << "<------------ Temperature Converter Program: ------------>" << endl;
        cout << "\n1. Fahrenheit to Celsius" << endl;
        cout << "2. Celsius to Fahrenheit" << endl;
        cout << "\nEnter your choice: ";
        
        int option;
        cin >> option;

        while (option != 1 && option != 2)

        {
            cin.clear();
  	        cin.ignore(1000,'\n');
  	        cout<<"\nError:Invalid Input , Choose an option (1-2) ";
  	        cin>>option;
        }

        double temperature, convertedTemperature;

        switch (option) {

            case 1:
                cout << "\nEnter temperature in Fahrenheit: ";
                cin >> temperature;

                     while(cin.fail())

                     {
                        cin.clear();
              	        cin.ignore(1000,'\n');
              	        cout<<"\nError: Invalid Input , Enter Temperature Again: ";
              	        cin>>temperature;
                    } 

                convertedTemperature = (temperature - 32) * 5 / 9;
                cout << "\nConverted temperature in Celsius: " << convertedTemperature << endl;
                break;

            case 2:
                cout << "\nEnter temperature in Celsius: ";
                cin >> temperature;

                     while(cin.fail())
                     
                     {
                        cin.clear();
              	        cin.ignore(1000,'\n');
              	        cout<<"\nError: Invalid Input , Enter Temperature Again: ";
              	        cin>>temperature;
                    }

                convertedTemperature = (temperature * 9 / 5) + 32;
                cout << "\nConverted temperature in Fahrenheit: " << convertedTemperature << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
                break;
        }

        cout << "\nDo you want to convert another temperature? (y/n): ";
        cin >> choice;

        
    } while (choice == 'y' || choice == 'Y');

    cout << "\nExiting the Temperature Converter program." << endl;

    return 0;
}