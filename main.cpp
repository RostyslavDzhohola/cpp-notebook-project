#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>

using namespace std;

class TaskClass
{
private:
    int m_taskId;                // Assign task ID number from 1 to infinity
    char m_taskNote[50];
    int m_priorityLevel;            // This will be the level from 1-3 by urgency and importance
public:
    void addTask();
    void editTask();
    void displayTask();
    void readListOfTasks();
    void completeTask();
    int return_taskId();            // Removing task from the list of uncompleted tasks

    TaskClass() = default;
};

int TaskClass::return_taskId()
{
    return m_taskId;
}

void TaskClass::addTask()
{
    cout << "Task ID is: ";
    cin >> m_taskId;
    cout << "Enter the Task Note: ";
    cin.ignore();
	cin.get(m_taskNote,50);
    cout << "Enter Priority level from 1 to 3: ";
    cin.ignore();
    cin >> m_priorityLevel;
}

void TaskClass::editTask()
{
    //displayTask();
    cout << "Enter the Task Note: ";
    cin.ignore();
	cin.get(m_taskNote,50);
    cout << "Enter Priority level from 1 to 3: ";
    cin >> m_priorityLevel;
}

void TaskClass::displayTask()
{
    cout << "Task ID is: " << m_taskId <<endl;
    cout << "Task Note: " << m_taskNote << endl;
    cout << "Priority level is : " << m_priorityLevel << endl;
}

void TaskClass::readListOfTasks()
{
    cout<<m_taskId<<setw(15)<<" (PL:"<<m_priorityLevel<<")"<<setw(20)<<" "<<m_taskNote<<endl;
}

/******************
Functions outside of the class
******************/

void writeData()
{
    TaskClass Task;
    ofstream tasksFile;
    tasksFile.open("Tasks.dat", ios::binary|ios::app);
    Task.addTask();
    tasksFile.write(reinterpret_cast<char *> (&Task), sizeof(TaskClass));
    tasksFile.close();
}

void displayData()
{
    TaskClass Task;
    ifstream tasksFile;
    tasksFile.open("Tasks.dat", ios::binary);
    if (!tasksFile)
    {
        cerr << "Tasks.dat could not be opened for writing!" <<endl;
        return;
    }
    cout<<"\n\n\t LIST OF TASKS \n\n";
    cout<<"\n____________________________________________\n";
    cout<<"ID \tPriority Level \t\tNote ";
    cout<<"\n____________________________________________\n";
    while(tasksFile.read(reinterpret_cast<char *> (&Task), sizeof(TaskClass)))
    {
        Task.readListOfTasks();
    }
    tasksFile.close();
}

void editTask(int id)
{
    TaskClass Task;
    fstream File;
    bool found = false;
    File.open("Tasks.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"Tasks.dat could not be opened for writing!"<<endl;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&Task), sizeof(TaskClass));
        if(Task.return_taskId() == id)
        {
            cout<< "Enter new note to a task ID: " <<id<<endl;
            Task.editTask();
            int pos =(-1)*static_cast<int>(sizeof(Task));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&Task),sizeof(TaskClass));
            cout<<"\nTask updated...\n\n";
            found = true;
        }
    }
    File.close();
    if(found==false) cout<< "\nTask not found";
}

void completeTask(int id)    // This functions takes ID number as a argument and deletes that task from note list
{
    TaskClass Task;
    ifstream oldFile;
    ofstream newFile;
    oldFile.open("Tasks.dat", ios::binary);
    if(!oldFile)
    {
        cout << "Tasks.dat could not be opened for writing!"<<endl;
        return;
    }
    newFile.open("Temp.dat", ios::binary);
    oldFile.seekg(0, ios::beg);
    while(oldFile.read(reinterpret_cast<char *> (&Task), sizeof(TaskClass)))
    {
        if(Task.return_taskId()!= id)
        {
           newFile.write(reinterpret_cast<char *> (&Task), sizeof(TaskClass));
        }
    }
    oldFile.close();
    newFile.close();
    remove("Tasks.dat");
    rename("Temp.dat", "Tasks.dat");
    cout << "Task completed...\n\n";
    //displayData();
}

int main()
{
    int id;
    char choice;

    do
    {
        system("cls");      //command for clearing the console screen each time we get to the menu
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
        case '1':               // create new task and write it to a file
            writeData();
            break;
        case '2':
            displayData();      // This function shows the list of tasks
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
