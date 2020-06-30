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
    cout << "Enter Priority level from 1 to 3: ";
    cin.ignore();
    cin >> m_priorityLevel;
}

void TaskClass::editTask()
{
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
