#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// ================================================================
//  Task Manager & Scheduler v2.0
//  New in v2.0:
//  - Color-coded priorities (ANSI colors)
//  - Edit task (modify existing details)
//  - Search by keyword (title + description)
//  - Sort by deadline
//  - Due date alerts (overdue / due today highlighting)
//  Bug fixes from v1.0:
//  - Consistent cin.ignore() across all methods
//  - size_t comparison fixed (no more signed/unsigned warnings)
//  - Priority input validation (only H, M, L accepted)
//  - Deadline format validation (DD/MM/YYYY)
// ================================================================

// ── ANSI color codes ─────────────────────────────────────────────
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define DIM     "\033[2m"

// ── Date helpers ─────────────────────────────────────────────────

// Parse "DD/MM/YYYY" into (day, month, year). Returns false if malformed.
bool parseDate(const string& s, int& d, int& m, int& y)
{
    if (s.size() != 10) return false;
    if (s[2] != '/' || s[5] != '/') return false;
    try {
        d = stoi(s.substr(0, 2));
        m = stoi(s.substr(3, 2));
        y = stoi(s.substr(6, 4));
    } catch (...) { return false; }
    if (d < 1 || d > 31) return false;
    if (m < 1 || m > 12) return false;
    if (y < 2000 || y > 2100) return false;
    return true;
}

// Compare two "DD/MM/YYYY" strings chronologically
bool dateEarlier(const string& a, const string& b)
{
    int da, ma, ya, db, mb, yb;
    if (!parseDate(a, da, ma, ya)) return false;
    if (!parseDate(b, db, mb, yb)) return false;
    if (ya != yb) return ya < yb;
    if (ma != mb) return ma < mb;
    return da < db;
}

// Returns:  0 = future, 1 = due today, 2 = overdue, -1 = invalid date
// NOTE: Uses __DATE__ compile-time date as "today" — works cross-platform
//       without <ctime> struct tm issues on Windows/MinGW.
int deadlineStatus(const string& deadline)
{
    int dd, dm, dy;
    if (!parseDate(deadline, dd, dm, dy)) return -1;

    // Parse __DATE__ which looks like "Mar 19 2026"
    string compDate = __DATE__;
    string monthStr = compDate.substr(0, 3);
    int day   = stoi(compDate.substr(4, 2));
    int year  = stoi(compDate.substr(7, 4));

    static const string months[] = {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };
    int month = 1;
    for (int i = 0; i < 12; i++)
        if (months[i] == monthStr) { month = i + 1; break; }

    // Compare
    if (dy < year || (dy == year && dm < month) || (dy == year && dm == month && dd < day))
        return 2; // overdue
    if (dy == year && dm == month && dd == day)
        return 1; // today
    return 0;     // future
}

// ── Task class ───────────────────────────────────────────────────

class Task
{
private:
    string title;
    string description;
    string priority;   // "H", "M", or "L"
    string deadline;   // "DD/MM/YYYY"
    bool   completed;

public:
    Task(string t, string desc, string p, string d)
        : title(t), description(desc), priority(p), deadline(d), completed(false) {}

    // Getters
    string getTitle()       const { return title; }
    string getDescription() const { return description; }
    string getPriority()    const { return priority; }
    string getDeadline()    const { return deadline; }
    bool   isCompleted()    const { return completed; }

    // Setters (for edit feature)
    void setTitle(const string& t)       { title = t; }
    void setDescription(const string& d) { description = d; }
    void setPriority(const string& p)    { priority = p; }
    void setDeadline(const string& d)    { deadline = d; }

    void markComplete() { completed = true; }

    // Returns ANSI color string for this task's priority
    string priorityColor() const
    {
        if (priority == "H") return RED;
        if (priority == "M") return YELLOW;
        return GREEN;  // L
    }

    // Returns colored priority label e.g. "[H]" in red
    string coloredPriority() const
    {
        return priorityColor() + BOLD + "[" + priority + "]" + RESET;
    }

    // Display with full color + deadline alert
    void display(int index = -1) const
    {
        int status = deadlineStatus(deadline);

        // Deadline display string with alert color
        string deadlineDisplay;
        if (status == 2)
            deadlineDisplay = string(RED) + BOLD + deadline + " !! OVERDUE" + RESET;
        else if (status == 1)
            deadlineDisplay = string(YELLOW) + BOLD + deadline + " (Due today)" + RESET;
        else
            deadlineDisplay = deadline;

        // Status symbol
        string statusStr = completed
            ? (GREEN + string("✓ Completed") + RESET)
            : (DIM   + string("○ Pending")   + RESET);

        cout << "\n" << DIM << ". . . . . . . . . . . . . . . . . . ." << RESET << "\n";
        if (index >= 0)
            cout << BOLD << "Task #" << index << RESET << "\n";
        cout << BOLD << "Title:       " << RESET << title        << "\n";
        cout << BOLD << "Description: " << RESET << description  << "\n";
        cout << BOLD << "Priority:    " << RESET << coloredPriority() << "\n";
        cout << BOLD << "Deadline:    " << RESET << deadlineDisplay   << "\n";
        cout << BOLD << "Status:      " << RESET << statusStr         << "\n";
        cout << DIM << ". . . . . . . . . . . . . . . . . . ." << RESET << "\n";
    }

    // Compact one-line display for lists
    void displayCompact(int index) const
    {
        int status = deadlineStatus(deadline);
        string dl = deadline;
        if      (status == 2) dl = string(RED)    + BOLD + deadline + " !!" + RESET;
        else if (status == 1) dl = string(YELLOW) + BOLD + deadline + " today" + RESET;

        string check = completed ? (GREEN + string("✓") + RESET) : (DIM + string("○") + RESET);

        cout << "  " << BOLD << index << "." << RESET
             << " " << check
             << " " << coloredPriority()
             << " " << title
             << DIM << "  [" << dl << DIM << "]" << RESET << "\n";
    }
};

// ── Input helpers ────────────────────────────────────────────────

string readPriority()
{
    string p;
    while (true)
    {
        cout << "Enter priority [H / M / L]: ";
        getline(cin, p);
        if (p == "H" || p == "M" || p == "L") return p;
        cout << RED << "  Invalid! Please enter H, M, or L.\n" << RESET;
    }
}

string readDeadline()
{
    string d;
    while (true)
    {
        cout << "Enter deadline [DD/MM/YYYY]: ";
        getline(cin, d);
        int dd, dm, dy;
        if (parseDate(d, dd, dm, dy)) return d;
        cout << RED << "  Invalid format! Use DD/MM/YYYY (e.g. 25/12/2026).\n" << RESET;
    }
}

// ── TaskManager class ────────────────────────────────────────────

class TaskManager
{
private:
    vector<Task> tasks;
    string filename = "tasks.txt";

    // Validate task index from user input (1-based)
    bool validIndex(int n) const
    {
        return n >= 1 && n <= (int)tasks.size();
    }

public:
    // ── CRUD ──────────────────────────────────────────────────────

    void addTask()
    {
        cout << "\n" << BOLD << CYAN << "── Add New Task ──" << RESET << "\n";

        string title, desc, priority, deadline;
        cin.ignore();

        cout << "Enter task title: ";
        getline(cin, title);

        cout << "Enter description: ";
        getline(cin, desc);

        priority = readPriority();
        deadline = readDeadline();

        tasks.emplace_back(title, desc, priority, deadline);
        cout << GREEN << "\n✓ Task added successfully!\n" << RESET;
        saveToFile();
    }

    void viewAllTasks() const
    {
        if (tasks.empty()) { cout << "\nNo tasks found!\n"; return; }

        cout << "\n" << BOLD << CYAN << "══════════════ ALL TASKS ══════════════" << RESET << "\n";
        for (int i = 0; i < (int)tasks.size(); i++)
            tasks[i].display(i + 1);
    }

    void viewByPriority() const
    {
        cin.ignore();
        cout << "\n" << BOLD << "Filter by priority [H / M / L]: " << RESET;
        string priority;
        getline(cin, priority);

        if (priority != "H" && priority != "M" && priority != "L")
        {
            cout << RED << "Invalid priority.\n" << RESET;
            return;
        }

        string label = (priority == "H") ? "HIGH" : (priority == "M") ? "MEDIUM" : "LOW";
        cout << "\n" << BOLD << CYAN << "══ " << label << " PRIORITY TASKS ══" << RESET << "\n";

        bool found = false;
        for (int i = 0; i < (int)tasks.size(); i++)
        {
            if (tasks[i].getPriority() == priority)
            {
                tasks[i].display(i + 1);
                found = true;
            }
        }
        if (!found) cout << "No tasks with " << label << " priority.\n";
    }

    void editTask()
    {
        if (tasks.empty()) { cout << "\nNo tasks to edit!\n"; return; }

        viewAllTasks();
        cout << "\nEnter task number to edit: ";
        int n; cin >> n; cin.ignore();
        if (!validIndex(n)) { cout << RED << "❌ Invalid task number!\n" << RESET; return; }

        Task& t = tasks[n - 1];
        cout << BOLD << CYAN << "\n── Editing Task #" << n << " (press Enter to keep current value) ──\n" << RESET;

        // Title
        cout << "Title [" << t.getTitle() << "]: ";
        string val; getline(cin, val);
        if (!val.empty()) t.setTitle(val);

        // Description
        cout << "Description [" << t.getDescription() << "]: ";
        getline(cin, val);
        if (!val.empty()) t.setDescription(val);

        // Priority
        cout << "Priority [" << t.getPriority() << "] (H/M/L, Enter to keep): ";
        getline(cin, val);
        if (val == "H" || val == "M" || val == "L") t.setPriority(val);
        else if (!val.empty()) cout << YELLOW << "  Invalid priority kept unchanged.\n" << RESET;

        // Deadline
        cout << "Deadline [" << t.getDeadline() << "] (DD/MM/YYYY, Enter to keep): ";
        getline(cin, val);
        if (!val.empty())
        {
            int dd, dm, dy;
            if (parseDate(val, dd, dm, dy)) t.setDeadline(val);
            else cout << YELLOW << "  Invalid date format, kept unchanged.\n" << RESET;
        }

        cout << GREEN << "\n✓ Task updated successfully!\n" << RESET;
        saveToFile();
    }

    void markComplete()
    {
        if (tasks.empty()) { cout << "\nNo tasks found!\n"; return; }
        viewAllTasks();

        cout << "\nEnter task number to mark complete: ";
        int n; cin >> n; cin.ignore();
        if (!validIndex(n)) { cout << RED << "❌ Invalid task number!\n" << RESET; return; }

        tasks[n - 1].markComplete();
        cout << GREEN << "\n✓ Task marked as complete!\n" << RESET;
        saveToFile();
    }

    void deleteTask()
    {
        if (tasks.empty()) { cout << "\nNo tasks found!\n"; return; }
        viewAllTasks();

        cout << "\nEnter task number to delete: ";
        int n; cin >> n; cin.ignore();
        if (!validIndex(n)) { cout << RED << "❌ Invalid task number!\n" << RESET; return; }

        cout << YELLOW << "Delete \"" << tasks[n-1].getTitle() << "\"? (y/n): " << RESET;
        char confirm; cin >> confirm; cin.ignore();
        if (confirm != 'y' && confirm != 'Y')
        { cout << "Cancelled.\n"; return; }

        tasks.erase(tasks.begin() + n - 1);
        cout << GREEN << "\n✓ Task deleted!\n" << RESET;
        saveToFile();
    }

    // ── Search ────────────────────────────────────────────────────

    void searchTasks() const
    {
        cin.ignore();
        cout << "\nSearch keyword: ";
        string keyword;
        getline(cin, keyword);

        // Case-insensitive: convert both to lowercase for comparison
        string kw = keyword;
        transform(kw.begin(), kw.end(), kw.begin(), ::tolower);

        cout << "\n" << BOLD << CYAN << "── Search results for \"" << keyword << "\" ──" << RESET << "\n";

        bool found = false;
        for (int i = 0; i < (int)tasks.size(); i++)
        {
            string title = tasks[i].getTitle();
            string desc  = tasks[i].getDescription();
            transform(title.begin(), title.end(), title.begin(), ::tolower);
            transform(desc.begin(),  desc.end(),  desc.begin(),  ::tolower);

            if (title.find(kw) != string::npos || desc.find(kw) != string::npos)
            {
                tasks[i].display(i + 1);
                found = true;
            }
        }
        if (!found) cout << "No tasks matched \"" << keyword << "\".\n";
    }

    // ── Sort by deadline ──────────────────────────────────────────

    void sortByDeadline()
    {
        if (tasks.empty()) { cout << "\nNo tasks to sort!\n"; return; }

        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return dateEarlier(a.getDeadline(), b.getDeadline());
        });

        cout << GREEN << "\n✓ Tasks sorted by deadline (earliest first).\n" << RESET;
        saveToFile();

        cout << "\n" << BOLD << CYAN << "── Tasks by Deadline ──" << RESET << "\n";
        for (int i = 0; i < (int)tasks.size(); i++)
            tasks[i].displayCompact(i + 1);
    }

    // ── Due date alerts ───────────────────────────────────────────

    void showAlerts() const
    {
        bool anyAlert = false;

        cout << "\n" << BOLD << RED << "══ OVERDUE ══" << RESET << "\n";
        for (int i = 0; i < (int)tasks.size(); i++)
        {
            if (!tasks[i].isCompleted() && deadlineStatus(tasks[i].getDeadline()) == 2)
            { tasks[i].displayCompact(i + 1); anyAlert = true; }
        }

        cout << "\n" << BOLD << YELLOW << "══ DUE TODAY ══" << RESET << "\n";
        for (int i = 0; i < (int)tasks.size(); i++)
        {
            if (!tasks[i].isCompleted() && deadlineStatus(tasks[i].getDeadline()) == 1)
            { tasks[i].displayCompact(i + 1); anyAlert = true; }
        }

        if (!anyAlert) cout << GREEN << "\n✓ No overdue or due-today tasks!\n" << RESET;
    }

    // ── Stats ─────────────────────────────────────────────────────

    void showStats() const
    {
        int total     = (int)tasks.size();
        int completed = 0, high = 0, med = 0, low = 0;
        int overdue   = 0, dueToday = 0;

        for (const Task& t : tasks)
        {
            if (t.isCompleted()) completed++;
            if (t.getPriority() == "H") high++;
            if (t.getPriority() == "M") med++;
            if (t.getPriority() == "L") low++;
            if (!t.isCompleted())
            {
                int s = deadlineStatus(t.getDeadline());
                if (s == 2) overdue++;
                if (s == 1) dueToday++;
            }
        }

        int pending = total - completed;

        cout << "\n" << BOLD << CYAN << "══════════ STATISTICS ══════════" << RESET << "\n";
        cout << BOLD << "Total tasks:   " << RESET << total     << "\n";
        cout << GREEN  << BOLD << "  Completed:  " << RESET << completed << "\n";
        cout << DIM    << BOLD << "  Pending:    " << RESET << pending   << "\n";
        cout << "\n";
        cout << BOLD << "By priority:\n" << RESET;
        cout << RED    << "  High (H):   " << RESET << high << "\n";
        cout << YELLOW << "  Medium (M): " << RESET << med  << "\n";
        cout << GREEN  << "  Low (L):    " << RESET << low  << "\n";
        if (overdue > 0 || dueToday > 0)
        {
            cout << "\n";
            if (overdue   > 0) cout << RED    << BOLD << "  !! Overdue:    " << RESET << overdue   << "\n";
            if (dueToday  > 0) cout << YELLOW << BOLD << "  !! Due today:  " << RESET << dueToday  << "\n";
        }
        cout << BOLD << CYAN << "════════════════════════════════" << RESET << "\n";
    }

    // ── File I/O ──────────────────────────────────────────────────

    void saveToFile() const
    {
        ofstream file(filename);
        for (const Task& t : tasks)
        {
            file << t.getTitle()       << "|"
                 << t.getDescription() << "|"
                 << t.getPriority()    << "|"
                 << t.getDeadline()    << "|"
                 << t.isCompleted()    << "\n";
        }
    }

    void loadFromFile()
    {
        ifstream file(filename);
        if (!file) return;

        string line;
        while (getline(file, line))
        {
            istringstream ss(line);
            string title, desc, priority, deadline, completedStr;
            if (!getline(ss, title,      '|')) continue;
            if (!getline(ss, desc,       '|')) continue;
            if (!getline(ss, priority,   '|')) continue;
            if (!getline(ss, deadline,   '|')) continue;
            if (!getline(ss, completedStr,'|') && !getline(ss, completedStr)) continue;

            Task t(title, desc, priority, deadline);
            if (completedStr == "1") t.markComplete();
            tasks.push_back(t);
        }
    }

    // Quick alert banner shown at startup
    void startupAlertBanner() const
    {
        int overdue = 0, dueToday = 0;
        for (const Task& t : tasks)
        {
            if (t.isCompleted()) continue;
            int s = deadlineStatus(t.getDeadline());
            if (s == 2) overdue++;
            if (s == 1) dueToday++;
        }
        if (overdue > 0)
            cout << RED << BOLD << "  !! " << overdue << " overdue task(s)!" << RESET << "\n";
        if (dueToday > 0)
            cout << YELLOW << BOLD << "  !! " << dueToday << " task(s) due today!" << RESET << "\n";
    }
};

// ================================================================
//  main
// ================================================================

int main()
{
    TaskManager manager;
    manager.loadFromFile();

    cout << "\n" << BOLD << CYAN;
    cout << "=================================================\n";
    cout << "         TASK MANAGER & SCHEDULER v2.0\n";
    cout << "=================================================" << RESET << "\n";
    manager.startupAlertBanner();

    while (true)
    {
        cout << "\n" << BOLD << CYAN << "══════════════ MENU ══════════════" << RESET << "\n";
        cout << "  1. Add Task\n";
        cout << "  2. View All Tasks\n";
        cout << "  3. View by Priority\n";
        cout << "  4. Edit Task\n";
        cout << "  5. Mark Task Complete\n";
        cout << "  6. Delete Task\n";
        cout << "  7. Search Tasks\n";
        cout << "  8. Sort by Deadline\n";
        cout << "  9. Due Date Alerts\n";
        cout << " 10. Statistics\n";
        cout << "  0. Exit\n";
        cout << BOLD << CYAN << "══════════════════════════════════" << RESET << "\n";
        cout << "Enter choice: ";

        int choice; cin >> choice;

        switch (choice)
        {
            case 1:  manager.addTask();        break;
            case 2:  manager.viewAllTasks();   break;
            case 3:  manager.viewByPriority(); break;
            case 4:  manager.editTask();       break;
            case 5:  manager.markComplete();   break;
            case 6:  manager.deleteTask();     break;
            case 7:  manager.searchTasks();    break;
            case 8:  manager.sortByDeadline(); break;
            case 9:  manager.showAlerts();     break;
            case 10: manager.showStats();      break;
            case 0:
                cout << GREEN << "\n✓ Tasks saved! Goodbye!\n" << RESET;
                return 0;
            default:
                cout << RED << "\n❌ Invalid choice!\n" << RESET;
        }
    }
    return 0;
}
