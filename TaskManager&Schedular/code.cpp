#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Task
{
private:
    string title;
    string description;
    string priority;
    string deadline;
    bool completed;

public:
    // Constructor
    Task(string t, string desc, string p, string d)
    {
        title = t;
        description = desc;
        priority = p;
        deadline = d;
        completed = false;
    }

    // Getters
    string getTitle() { return title; }
    string getDescription() { return description; }
    string getPriority() { return priority; }
    string getDeadline() { return deadline; }
    bool isCompleted() { return completed; }

    void markComplete()
    {
        completed = true;
    }

    // Displaying Tasks
    void display()
    {
        cout << "\n------------------------------------\n";
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Priority: " << priority << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Status: " << (completed ? "✓ Completed" : "○ Pending") << endl;
        cout << "------------------------------------\n";
    }
};

class TaskManager
{
private:
    vector<Task> tasks;
    string filename = "tasks.txt";

public:
    void addTask()
    {
        string title, desc, priority, deadline;

        cin.ignore();
        cout << "\nEnter task title: ";
        getline(cin, title);

        cout << "Enter description: ";
        getline(cin, desc);

        cout << "Enter priority [H - M - L]: ";
        getline(cin, priority);

        cout << "Enter deadline [DD/MM/YYYY]: ";
        getline(cin, deadline);

        Task newTask(title, desc, priority, deadline);
        tasks.push_back(newTask);

        cout << "\n✓ Task added successfully!\n";
        saveToFile();
    }

    void viewAllTasks()
    {
        if (tasks.empty())
        {
            cout << "\nNo tasks found!\n";
            return;
        }

        cout << "\n=================== ALL TASKS ===================\n";
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << "\nTask #" << (i + 1);
            tasks[i].display();
        }
    }

    // View by Priority
    void viewByPriority()
    {
        string priority;
        cout << "\nEnter priority [H - M - L]: ";
        cin >> priority;

        bool found = false;
        cout << "\n============ " << priority << " PRIORITY TASKS ============\n";

        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].getPriority() == priority)
            {
                cout << "\nTask #" << (i + 1);
                tasks[i].display();
                found = true;
            }
        }

        if (!found)
        {
            cout << "No tasks with " << priority << " priority.\n";
        }
    }

    // Mark task as complete
    void markComplete()
    {
        viewAllTasks();

        if (tasks.empty())
            return;

        int taskNum;
        cout << "\nEnter task number to mark complete: ";
        cin >> taskNum;

        if (taskNum > 0 && taskNum <= tasks.size())
        {
            tasks[taskNum - 1].markComplete();
            cout << "\n✓ Task marked as complete!\n";
            saveToFile();
        }
        else
        {
            cout << "\n❌ Invalid task number!\n";
        }
    }

    // Delete task
    void deleteTask()
    {
        viewAllTasks();

        if (tasks.empty())
            return;

        int taskNum;
        cout << "\nEnter task number to delete: ";
        cin >> taskNum;

        if (taskNum > 0 && taskNum <= tasks.size())
        {
            tasks.erase(tasks.begin() + taskNum - 1);
            cout << "\n✓ Task deleted successfully!\n";
            saveToFile();
        }
        else
        {
            cout << "\n❌ Invalid task number!\n";
        }
    }

    void showStats()
    {
        int total = tasks.size();
        int completed = 0;

        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].isCompleted())
            {
                completed++;
            }
        }

        cout << "\n============= STATISTICS =============\n";
        cout << "Total tasks: " << total << endl;
        cout << "Completed: " << completed << endl;
        cout << "Pending: " << (total - completed) << endl;
        cout << "======================================\n";
    }

    void saveToFile()
    {
        ofstream file(filename);

        for (int i = 0; i < tasks.size(); i++)
        {
            file << tasks[i].getTitle() << "|"
                 << tasks[i].getDescription() << "|"
                 << tasks[i].getPriority() << "|"
                 << tasks[i].getDeadline() << "|"
                 << tasks[i].isCompleted() << endl;
        }

        file.close();
    }

    void loadFromFile()
    {
        ifstream file(filename);

        if (!file)
            return;

        string title, desc, priority, deadline;
        bool completed;

        while (getline(file, title, '|'))
        {
            getline(file, desc, '|');
            getline(file, priority, '|');
            getline(file, deadline, '|');
            file >> completed;
            file.ignore();

            Task newTask(title, desc, priority, deadline);
            if (completed)
            {
                newTask.markComplete();
            }
            tasks.push_back(newTask);
        }
        file.close();
    }
};

int main()
{
    TaskManager manager;
    manager.loadFromFile();

    int choice;

    cout << "\n";
    cout << "=================================================\n";
    cout << "        TASK MANAGER & SCHEDULER\n";
    cout << "=================================================\n";

    while (true)
    {
        cout << "\n================= MENU ==================\n";
        cout << "1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. View By Priority\n";
        cout << "4. Mark Task Complete\n";
        cout << "5. Delete Task\n";
        cout << "6. Statistics\n";
        cout << "7. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addTask();
            break;
        case 2:
            manager.viewAllTasks();
            break;
        case 3:
            manager.viewByPriority();
            break;
        case 4:
            manager.markComplete();
            break;
        case 5:
            manager.deleteTask();
            break;
        case 6:
            manager.showStats();
            break;
        case 7:
            cout << "\n✓ Tasks saved! Goodbye!\n";
            return 0;
        default:
            cout << "\n❌ Invalid choice! Try again.\n";
        }
    }

    return 0;
}
