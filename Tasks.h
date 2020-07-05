#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED

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
    int priorityLevelCheck(); //Checking if pritority level is the right number


    TaskClass() = default;
};

#endif // TASKS_H_INCLUDED
