#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>

#include "functions.h"
#include "Tasks.h"

using namespace std;

int main()
{
    int id;
    char choice;

    do
    {
        system("cls");                          //command for clearing the console screen each time we get to the menu
        cout << "\nMain Menu" ;
        cout << "\n\n 1. Add new Task" ;
        cout << "\n 2. Open Task list";
        cout << "\n 3. Edit the Task";
        cout << "\n 4. Mark as complete" ;
        cout << "\n 5. Close the Program";
        cout << "\n Choose the option (1-5): ";
        cin >> choice;
        system("cls");
        switch(choice)
        {
        case '1':                               // create new task and write it to a file
            writeData();
            break;
        case '2':
            displayData();                      // This function shows the list of tasks
            break;
        case '3':
            displayData();
            cout<< "\n\nWhich task ID do you want to edit?\n";
            cout << "ID: ";
            cin >>id;
            editTask(id);
            break;
        case '4':
            displayData();
            cout<< "\n\nWhich task ID do you want to complete? \nID: ";
            cin >> id;
            system("cls");
            completeTask(id);
            displayData();
            break;
        case '5':
            break;
        default :cout<<"\a";
        }
        cin.ignore();
        cin.get();
    }while(choice!='5');

    return 0;
}
