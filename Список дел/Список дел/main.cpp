//
//  main.cpp
//  Список дел
//
//  Created by Станислав Егоров on 12.12.2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

struct Task {
    std::string title;
    std::string priority;
    std::string description;
    std::string deadline;

    Task(std::string title, std::string priority, std::string description, std::string deadline)
        : title(title), priority(priority), description(description), deadline(deadline) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask() {
        std::string title, priority, description, deadline;
        std::cout << "Enter task details:\n";
        std::cout << "Title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        std::cout << "Priority: ";
        std::getline(std::cin, priority);
        std::cout << "Description: ";
        std::getline(std::cin, description);
        std::cout << "Deadline (dd/mm/yyyy hh:mm): ";
        std::getline(std::cin, deadline);

        Task newTask(title, priority, description, deadline);
        tasks.push_back(newTask);

        std::cout << "Task added successfully!\n";
    }

    void removeTask() {
        if (tasks.empty()) {
            std::cout << "No tasks to remove.\n";
            return;
        }

        std::string title;
        std::cout << "Enter the title of the task to be removed: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        auto task = std::find_if(tasks.begin(), tasks.end(), [&](const Task& t) {
            return t.title == title;
        });

        if (task != tasks.end()) {
            tasks.erase(task);
            std::cout << "Task removed successfully!\n";
        } else {
            std::cout << "Task not found.\n";
        }
    }

    void editTask() {
        if (tasks.empty()) {
            std::cout << "No tasks to edit.\n";
            return;
        }

        std::string title;
        std::cout << "Enter the title of the task to be edited: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        auto task = std::find_if(tasks.begin(), tasks.end(), [&](const Task& t) {
            return t.title == title;
        });

        if (task != tasks.end()) {
            std::string newTitle, priority, description, deadline;
            std::cout << "Enter new task details:\n";
            std::cout << "New title: ";
            std::getline(std::cin, newTitle);
            std::cout << "Priority: ";
            std::getline(std::cin, priority);
            std::cout << "Description: ";
            std::getline(std::cin, description);
            std::cout << "Deadline (dd/mm/yyyy hh:mm): ";
            std::getline(std::cin, deadline);

            task->title = newTitle;
            task->priority = priority;
            task->description = description;
            task->deadline = deadline;

            std::cout << "Task edited successfully!\n";
        } else {
            std::cout << "Task not found.\n";
        }
    }

    void searchTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to search.\n";
            return;
        }

        std::cout << "Search tasks by:\n";
        std::cout << "1. Title\n";
        std::cout << "2. Priority\n";
        std::cout << "3. Description\n";
        std::cout << "4. Deadline\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string title;
                std::cout << "Enter the title to search: ";
                std::getline(std::cin, title);

                auto task = std::find_if(tasks.begin(), tasks.end(), [&](const Task& t) {
                    return t.title == title;
                });

                if (task != tasks.end()) {
                    displayTask(*task);
                } else {
                    std::cout << "Task not found.\n";
                }
                break;
            }
            case 2: {
                std::string priority;
                std::cout << "Enter the priority to search: ";
                std::getline(std::cin, priority);

                std::vector<Task> matchingTasks;
                for (const auto& task : tasks) {
                    if (task.priority == priority) {
                        matchingTasks.push_back(task);
                    }
                }

                if (!matchingTasks.empty()) {
                    displayTasks(matchingTasks);
                } else {
                    std::cout << "No matching tasks found.\n";
                }
                break;
            }
            case 3: {
                std::string description;
                std::cout << "Enter the description to search: ";
                std::getline(std::cin, description);

                std::vector<Task> matchingTasks;
                for (const auto& task : tasks) {
                    if (task.description == description) {
                        matchingTasks.push_back(task);
                    }
                }

                if (!matchingTasks.empty()) {
                    displayTasks(matchingTasks);
                } else {
                    std::cout << "No matching tasks found.\n";
                }
                break;
            }
            case 4: {
                std::string deadline;
                std::cout << "Enter the deadline to search (dd/mm/yyyy hh:mm): ";
                std::getline(std::cin, deadline);

                std::vector<Task> matchingTasks;
                for (const auto& task : tasks) {
                    if (task.deadline == deadline) {
                        matchingTasks.push_back(task);
                    }
                }

                if (!matchingTasks.empty()) {
                    displayTasks(matchingTasks);
                } else {
                    std::cout << "No matching tasks found.\n";
                }
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    void displayTasks(const std::vector<Task>& taskList) {
        std::cout << "--------- Tasks ---------\n";
        for (const auto& task : taskList) {
            displayTask(task);
        }
    }

    void displayTask(const Task& task) {
        std::cout << "Title: " << task.title << '\n';
        std::cout << "Priority: " << task.priority << '\n';
        std::cout << "Description: " << task.description << '\n';
        std::cout << "Deadline: " << task.deadline << '\n';
        std::cout << "-------------------------\n";
    }

    void sortTasksByPriority() {
        std::sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
            return t1.priority < t2.priority;
        });

        std::cout << "Tasks sorted by priority.\n";
    }

    void sortTasksByDeadline() {
        std::sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
            return t1.deadline < t2.deadline;
        });

        std::cout << "Tasks sorted by deadline.\n";
    }

    void showScheduledTasks(std::string period) {
        std::time_t currentTime = std::time(nullptr);

        std::cout << "Scheduled tasks for the next " << period << ":\n";
        std::cout << "------------------------------\n";
        for (const auto& task : tasks) {
            std::tm tm;
            strptime(task.deadline.c_str(), "%d/%m/%Y %H:%M", &tm);
            std::time_t taskTime = std::mktime(&tm);

            if (taskTime > currentTime) {
                if (period == "day" && taskTime - currentTime <= 86400) {
                    displayTask(task);
                } else if (period == "week" && taskTime - currentTime <= 604800) {
                    displayTask(task);
                } else if (period == "month" && taskTime - currentTime <= 2592000) {
                    displayTask(task);
                }
            }
        }

        std::cout << "------------------------------\n";
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        std::cout << "----- Todo List -----\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Edit Task\n";
        std::cout << "4. Search Tasks\n";
        std::cout << "5. Display Tasks\n";
        std::cout << "6. Sort Tasks by Priority\n";
        std::cout << "7. Sort Tasks by Deadline\n";
        std::cout << "8. Show Scheduled Tasks for Day\n";
        std::cout << "9. Show Scheduled Tasks for Week\n";
        std::cout << "10. Show Scheduled Tasks for Month\n";
        std::cout << "0. Exit\n";
        std::cout << "---------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                todoList.addTask();
                break;
            case 2:
                todoList.removeTask();
                break;
            case 3:
                todoList.editTask();
                break;
            case 4:
                todoList.searchTasks();
                break;
            case 5:
                todoList.displayTasks(todoList.getTasks());
                break;
            case 6:
                todoList.sortTasksByPriority();
                break;
            case 7:
                todoList.sortTasksByDeadline();
                break;
            case 8:
                todoList.showScheduledTasks("day");
                break;
            case 9:
                todoList.showScheduledTasks("week");
                break;
            case 10:
                todoList.showScheduledTasks("month");
                break;
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }

        std::cout << '\n';
    } while (choice != 0);

    return 0;
}
