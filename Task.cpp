//
// Created by User on 3/11/2023.
//

#include "task.h"
#include <iostream>

Task::Task(const std::string& name, const std::string& description, int priority, const std::string& dueDate, Status status)
        : name(name), description(description), priority(priority), dueDate(dueDate), status(status) {}


const std::string& Task::getName() const{
    return this->name;
}

const std::string& Task::getDescription() const {
    return this->description;
}

int Task::getPriority() const {
    return this->priority;
}

const std::string& Task::getDueDate() const {
    return this->dueDate;
}

Task::Status Task::getStatus() const {
    return this->status;
}

void Task::setName(const std::string& name) {
    this->name = name;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

void Task::setPriority(int priority) {
    this->priority = priority;
}

void Task::setDueDate(const std::string& dueDate) {
    this->dueDate = dueDate;
}

void Task::setStatus(Status status) {
    this->status = status;
}


