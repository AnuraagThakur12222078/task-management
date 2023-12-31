#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;  // Maximum number of tasks, adjust as needed

struct Task {
    string description;
    bool completed;
};

class TaskManager {
private:
    Task tasks[MAX_TASKS];
    int numTasks = 0;

public:
    void addTask(const string& description) {
        if (numTasks < MAX_TASKS) {
            tasks[numTasks++] = {description, false};
            cout << "Task added: " << description << endl;
        } else {
            cout << "Cannot add more tasks. Task limit reached." << endl;
        }
    }

    void displayTasks() const {
        if (numTasks == 0) {
            cout << "No tasks available." << endl;
        } else {
            cout << "Tasks:\n";
            for (int i = 0; i < numTasks; ++i) {
                cout << "- " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
            }
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Ignore newline character left in the buffer
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                taskManager.addTask(description);
                break;
            case 2:
                taskManager.displayTasks();
                break;
            case 3:
                cout << "Exiting Task Manager.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

