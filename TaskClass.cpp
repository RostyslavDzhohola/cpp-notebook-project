#include <iomanip>
#include <iostream>

#include "Tasks.h"

using namespace std;

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
    m_priorityLevel = priorityLevelCheck();
}

int TaskClass::priorityLevelCheck()
{
    int level{};
    cout <<"Enter Priority level from 1 to 3: ";
    cin>> level;
    while(level<1 || level>3)
    {
        system("cls");
        cout<<"Enter correct priority level: ";
        cin >> level;
    };
    return level;
}

void TaskClass::editTask()
{
    cout << "Enter the Task Note: ";
    cin.ignore();
	cin.get(m_taskNote,50);
    m_priorityLevel = priorityLevelCheck();
}

void TaskClass::displayTask()
{
    cout << "Task ID is: " << m_taskId <<endl;
    cout << "Task Note: " << m_taskNote << endl;
    cout << "Priority level is : " << m_priorityLevel << endl;
}

void TaskClass::readListOfTasks()
{
    cout<<m_taskId<<setw(15)<<" (PL:"<<m_priorityLevel<<")"<<setw(12)<<" "<<m_taskNote<<endl;
}

