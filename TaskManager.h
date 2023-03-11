//
// Created by User on 3/11/2023.
//

#ifndef TODO_TASKMANAGER_H
#define TODO_TASKMANAGER_H

#include <vector>
#include "Task.h"

class TaskManager {
public:
    void addTask(Task task);
    void removeTask(int index);
    int getNumTasks();
    Task getTask(int index);
    void getAllTasks();
    void saveTasksToFile(string filename);
    std::vector<Task> loadTasksFromFile(const string& filename);
    void changeTaskStatus(int index, Task::Status status);
private:
    std::vector<Task> tasks;
};

#endif //TODO_TASKMANAGER_H
