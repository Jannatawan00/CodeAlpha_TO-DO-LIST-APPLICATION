#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\n--- To-Do List Menu ---\n";
    cout << "1. Add Task\n";
    cout << "2. Mark Task as Completed\n";
    cout << "3. View Tasks\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added successfully!\n";
}

void markTaskCompleted(vector<Task>& tasks) {
    int taskIndex;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskIndex;

    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n--- Current Tasks ---\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " [Completed]";
            }
            cout << "\n";
        }
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                markTaskCompleted(tasks);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                cout << "Exiting the application.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
