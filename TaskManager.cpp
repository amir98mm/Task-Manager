//
// Created by User on 3/11/2023.
//

#include "TaskManager.h"
#include "fstream"
#include "sstream"
#include "iostream"
#include "iomanip"
#include "algorithm"
using std::cout;
using std::endl;
using std::setw;

void TaskManager::addTask(Task task) {
    tasks.push_back(task);
}

void TaskManager::removeTask(int index) {
    tasks.erase(tasks.begin() + index);
}

int TaskManager::getNumTasks() {
    return tasks.size();
}

Task TaskManager::getTask(int index) {
    return tasks[index];
}

static std::string TaskStatusToString(Task::Status status) {
    switch (status) {
        case Task::Status::InProgress:
            return "In Progress";
        case Task::Status::ToDo:
            return "To Do";
        case Task::Status::Done:
            return "Done";
    }
    return "Unknown";
}

void TaskManager::getAllTasks() {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << setw(5) << "Index" << setw(20) << "Name" << setw(20)
         << "Description" << setw(10) << "Priority" << setw(12)
         << "Due Date" << setw(15) << "Status" << endl;
    cout << "----------------------------------------------------------------------------------"
         << endl;

    for (unsigned int i = 0; i < tasks.size(); i++) {
        cout << setw(5) << i + 1 << setw(20) << tasks[i].getName()
             << setw(20) << tasks[i].getDescription() << setw(10)
             << tasks[i].getPriority() << setw(12) << tasks[i].getDueDate()
             << setw(15) << TaskStatusToString(tasks[i].getStatus()) << endl;
    }
}


void TaskManager::saveTasksToFile(string filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        return;
    }
    for (auto const& task : tasks) {
        outfile << "\"" << task.getName() << "\"" << "@"
                << "\"" << task.getDescription() << "\"" << "@"
                << "\"" << task.getPriority() << "\"" << "@"
                << "\"" << task.getDueDate() << "\"" << "@"
                << "\"" << TaskStatusToString(task.getStatus()) << "\"" << std::endl;
    }
    outfile.close();
}

static Task::Status TaskStatusFromString(const std::string& str) {
    if (str == "To Do") {
        return Task::Status::ToDo;
    } else if (str == "In Progress") {
        return Task::Status::InProgress;
    } else if (str == "Done") {
        return Task::Status::Done;
    }
    return Task::Status::Unkown;
}


std::vector<Task> TaskManager::loadTasksFromFile(const string& filename) {
    std::vector<Task> tasks;
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, '@')) {
            if (token.front() == '"' && token.back() == '"') {
                // Remove enclosing double-quotes
                token.erase(0, 1);
                token.erase(token.size() - 1, 1);
            }
            tokens.push_back(token);
        }

        if (tokens.size() == 5) {
            Task task(tokens[0], tokens[1], std::stoi(tokens[2]), tokens[3], TaskStatusFromString(tokens[4]));
            tasks.push_back(task);
            this->tasks.push_back(task);
        } else {
            std::cerr << "Invalid line in file \"" << filename << "\": \"" << line << "\"" << std::endl;
        }
    }

    return tasks;
}

void TaskManager::changeTaskStatus(int index, Task::Status status) {
    tasks[index].setStatus(status);
}

void TaskManager::sortTasks(const SortOption sortBy) {
    switch (sortBy) {
        case NAME:
            sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
                return a.getName() < b.getName();
            });
            break;
        case PRIORITY:
            sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
                return a.getPriority() < b.getPriority();
            });
            break;
        case DUEDATE:
            sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
                return a.getDueDate() < b.getDueDate();
            });
            break;
        case STATUS:
            sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
                return a.getStatus() < b.getStatus();
            });
            break;
        default:
            cout << "Invalid sort option." << endl;
            break;
    }
}





