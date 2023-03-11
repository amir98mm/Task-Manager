#include <iostream>
#include "TaskManager.h"
using std::cout;
using std::endl;
using std::cin;

void printMenu() {
    cout << "Task Manager" << endl;
    cout << "============" << endl;
    cout << "1. Add task" << endl;
    cout << "2. Remove task" << endl;
    cout << "3. Print tasks" << endl;
    cout << "4. Change status" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter option number: ";
}

int main() {
    TaskManager taskManager;

    // Load tasks from file
    taskManager.loadTasksFromFile("../tasks.txt");

    // Main loop
    int option = -1;
    while (option != 0) {
        // Print menu and get user input
        printMenu();
        cin >> option;
        cin.ignore();
        // Process user input
        switch (option) {
            case 1: { // Add task
                string name, description, dueDate;
                int priority, statusInt;
                Task::Status status;

                // Get task details from user
                cout << "Enter task name: ";
                getline(cin, name);
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter task priority (1-5): ";
                cin >> priority;
                cin.ignore();
                cout << "Enter task due date (YYYY-MM-DD): ";
                getline(cin, dueDate);
                cout
                        << "Enter task status (0: To Do, 1: In Progress, 2: Done): ";
                cin >> statusInt;
                status = static_cast<Task::Status>(statusInt);

                // Create task and add to task manager
                Task task(name, description, priority, dueDate, status);
                taskManager.addTask(task);
                cout << "Task added successfully." << endl;
                break;
            }
            case 2: { // Remove task
                int taskIndex;
                string confirm;

                // Get task index from user
                taskManager.getAllTasks();
                cout << "Enter index of task to remove: ";
                cin >> taskIndex;

                // Confirm task removal
                cout << "Are you sure you want to remove task " << taskIndex
                     << "? (y/n): ";
                cin >> confirm;
                if (confirm == "y") {
                    // Remove task from task manager
                    taskManager.removeTask(taskIndex - 1);
                    cout << "Task removed successfully." << endl;
                } else {
                    cout << "Task removal cancelled." << endl;
                }
                break;
            }
            case 3: { // Print tasks
                taskManager.getAllTasks();
                break;
            }
            case 4: { // Change status
                int taskIndex, statusInt;
                Task::Status status;

                // Get task index from user
                taskManager.getAllTasks();
                cout << "Enter index of task to change status: ";
                cin >> taskIndex;
                cin.ignore();

                // Get new status from user
                cout << "Enter new task status (0: To Do, 1: In Progress, 2: Done): ";
                cin >> statusInt;
                status = static_cast<Task::Status>(statusInt);

                // Update task status
                taskManager.changeTaskStatus(taskIndex - 1, status);
                cout << "Task status changed successfully." << endl;
                break;
            }
            case 0: { // Exit
                cout << "Exiting Task Manager..." << endl;
                break;
            }
            default: {
                cout << "Invalid option." << endl;
                break;
            }
        }
        cout << endl;
    }

    // Save tasks to file before exiting
    taskManager.saveTasksToFile("../tasks.txt");

    return 0;
}