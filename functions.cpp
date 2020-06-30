#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "functions.h"
#include "Tasks.h"

using namespace std;

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
