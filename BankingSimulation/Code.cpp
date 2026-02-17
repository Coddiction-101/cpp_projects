#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// ================================================================
//  Banking System - ATM Simulator v1.0
//  Features: Account Management, Transactions, File Persistence
// ================================================================

class BankAccount
{
private:
    string accountNumber;
    string holderName;
    string pin;
    double balance;
    string accountType;
    vector<string> transactionHistory;

public:
    // Constructor
    BankAccount(string accNum, string name, string p, string type, double initialBalance = 0)
    {
        accountNumber  = accNum;
        holderName     = name;
        pin            = p;
        accountType    = type;
        balance        = initialBalance;

        string transaction = "Account created with balance: $" + to_string(initialBalance);
        transactionHistory.push_back(transaction);
    }

    // Getters
    string getAccountNumber() { return accountNumber; }
    string getHolderName()    { return holderName; }
    string getAccountType()   { return accountType; }
    double getBalance()       { return balance; }

    // PIN verification
    bool verifyPin(string enteredPin)
    {
        return pin == enteredPin;
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "\n❌ Invalid amount!\n";
            return;
        }
        balance += amount;
        string transaction = "Deposited: $" + to_string(amount) + " | New Balance: $" + to_string(balance);
        transactionHistory.push_back(transaction);
        cout << "\n✓ Successfully deposited $" << fixed << setprecision(2) << amount << endl;
    }

    // Withdraw money
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "\n❌ Invalid amount!\n";
            return false;
        }
        if (amount > balance)
        {
            cout << "\n❌ Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        string transaction = "Withdrawn: $" + to_string(amount) + " | New Balance: $" + to_string(balance);
        transactionHistory.push_back(transaction);
        cout << "\n✓ Successfully withdrawn $" << fixed << setprecision(2) << amount << endl;
        return true;
    }

    // Transfer money (for sender)
    bool transfer(double amount)
    {
        if (amount <= 0)
        {
            cout << "\n❌ Invalid amount!\n";
            return false;
        }
        if (amount > balance)
        {
            cout << "\n❌ Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    // Receive transfer (for receiver)
    void receiveTransfer(double amount, string fromAccount)
    {
        balance += amount;
        string transaction = "Received $: " + to_string(amount) + " from A/C: " + fromAccount;
        transactionHistory.push_back(transaction);
    }

    // Add transaction to history
    void addTransaction(string trans)
    {
        transactionHistory.push_back(trans);
    }

    // Display account info
    void displayAccountInfo()
    {
        cout << "\n================ ACCOUNT INFORMATION ================\n";
        cout << "Account Number:  " << accountNumber << endl;
        cout << "Holder Name:     " << holderName << endl;
        cout << "Account Type:    " << accountType << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "=====================================================\n";
    }

    // Display transaction history
    void displayTransactionHistory()
    {
        cout << "\n============== TRANSACTION HISTORY ==============\n";
        if (transactionHistory.empty())
        {
            cout << "No transactions yet.\n";
        }
        else
        {
            for (int i = 0; i < transactionHistory.size(); i++)
            {
                cout << (i + 1) << ". " << transactionHistory[i] << endl;
            }
        }
        cout << "=================================================\n";
    }

    // File saving helpers
    string getPin() { return pin; }
    vector<string> getTransactions() { return transactionHistory; }
};

// ================================================================
//  BankingSystem Class - Manages all accounts
// ================================================================
class BankingSystem
{
private:
    map<string, BankAccount> accounts;
    string filename = "accounts.txt";
    int nextAccountNumber = 1001;

    // Generate unique account number
    string generateAccountNumber()
    {
        return "ACC" + to_string(nextAccountNumber++);
    }

public:
    // Constructor - load accounts on startup
    BankingSystem()
    {
        loadFromFile();
    }

    // -----------------------------------------------
    //  Create New Account
    // -----------------------------------------------
    void createAccount()
    {
        string name, pin, type;
        double initialDeposit;

        cin.ignore();
        cout << "\n============= CREATE NEW ACCOUNT =============\n";

        cout << "Enter your full name: ";
        getline(cin, name);

        cout << "Set your 4-digit PIN: ";
        getline(cin, pin);

        cout << "Account type:\n";
        cout << "  1. Savings\n";
        cout << "  2. Current\n";
        cout << "Choose (1 or 2): ";
        int typeChoice;
        cin >> typeChoice;
        type = (typeChoice == 1) ? "Savings" : "Current";

        cout << "Initial deposit amount: $";
        cin >> initialDeposit;

        if (initialDeposit < 0)
        {
            cout << "\n❌ Invalid deposit amount!\n";
            return;
        }

        string accNum = generateAccountNumber();
        BankAccount newAccount(accNum, name, pin, type, initialDeposit);
        accounts.insert({accNum, newAccount});

        cout << "\n✓ Account created successfully!\n";
        cout << "Your Account Number: " << accNum << endl;
        cout << "Please save this number for login!\n";

        saveToFile();
    }

    // -----------------------------------------------
    //  Login to Existing Account
    // -----------------------------------------------
    BankAccount* login()
    {
        string accNum, pin;

        cout << "\n============= LOGIN =============\n";
        cout << "Enter Account Number: ";
        cin >> accNum;

        if (accounts.find(accNum) == accounts.end())
        {
            cout << "\n❌ Account not found!\n";
            return nullptr;
        }

        cout << "Enter PIN: ";
        cin >> pin;

        if (!accounts.at(accNum).verifyPin(pin))
        {
            cout << "\n❌ Incorrect PIN!\n";
            return nullptr;
        }

        cout << "\n✓ Login successful! Welcome, "
             << accounts.at(accNum).getHolderName() << "!\n";

        return &accounts.at(accNum);
    }

    // -----------------------------------------------
    //  Delete Account
    // -----------------------------------------------
    void deleteAccount()
    {
        string accNum, pin;

        cout << "\n============= DELETE ACCOUNT =============\n";
        cout << "Enter Account Number: ";
        cin >> accNum;

        if (accounts.find(accNum) == accounts.end())
        {
            cout << "\n❌ Account not found!\n";
            return;
        }

        cout << "Enter PIN to confirm: ";
        cin >> pin;

        if (!accounts.at(accNum).verifyPin(pin))
        {
            cout << "\n❌ Incorrect PIN! Deletion cancelled.\n";
            return;
        }

        string name = accounts.at(accNum).getHolderName();

        char confirm;
        cout << "\n⚠️  Are you sure you want to delete " << name << "'s account? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y')
        {
            accounts.erase(accNum);
            saveToFile();
            cout << "\n✓ Account deleted successfully!\n";
        }
        else
        {
            cout << "\n✓ Deletion cancelled.\n";
        }
    }

    // -----------------------------------------------
    //  Transfer Between Accounts
    // -----------------------------------------------
    void transferMoney(BankAccount* sender)
    {
        string targetAccNum;
        double amount;

        cout << "\n============= TRANSFER MONEY =============\n";
        cout << "Enter recipient account number: ";
        cin >> targetAccNum;

        if (accounts.find(targetAccNum) == accounts.end())
        {
            cout << "\n❌ Recipient account not found!\n";
            return;
        }

        if (targetAccNum == sender->getAccountNumber())
        {
            cout << "\n❌ Cannot transfer to your own account!\n";
            return;
        }

        cout << "Enter amount to transfer: $";
        cin >> amount;

        if (sender->transfer(amount))
        {
            accounts.at(targetAccNum).receiveTransfer(amount, sender->getAccountNumber());

            string trans = "Transferred $" + to_string(amount) + " to A/C: " + targetAccNum;
            sender->addTransaction(trans);

            cout << "\n✓ Transfer successful!\n";
            cout << "Transferred $" << fixed << setprecision(2)
                 << amount << " to " << accounts.at(targetAccNum).getHolderName() << "\n";

            saveToFile();
        }
    }

    // -----------------------------------------------
    //  Save All Accounts to File
    // -----------------------------------------------
    void saveToFile()
    {
        ofstream file(filename);

        for (auto& pair : accounts)
        {
            BankAccount& acc = pair.second;
            file << acc.getAccountNumber() << "|"
                 << acc.getHolderName()    << "|"
                 << acc.getPin()           << "|"
                 << acc.getAccountType()   << "|"
                 << acc.getBalance()       << "|";

            vector<string> trans = acc.getTransactions();
            file << trans.size() << "|";
            for (auto& t : trans)
            {
                file << t << "~";
            }
            file << endl;
        }

        file.close();
    }

    // -----------------------------------------------
    //  Load All Accounts from File
    // -----------------------------------------------
    void loadFromFile()
    {
        ifstream file(filename);
        if (!file) return;

        string line;
        while (getline(file, line))
        {
            if (line.empty()) continue;

            string accNum, name, pin, type;
            double balance;
            int transCount;

            size_t pos = 0;
            auto nextField = [&]() {
                size_t end   = line.find('|', pos);
                string field = line.substr(pos, end - pos);
                pos          = end + 1;
                return field;
            };

            accNum     = nextField();
            name       = nextField();
            pin        = nextField();
            type       = nextField();
            balance    = stod(nextField());
            transCount = stoi(nextField());

            BankAccount acc(accNum, name, pin, type, 0);

            string transData = line.substr(pos);
            size_t tPos = 0;
            for (int i = 0; i < transCount; i++)
            {
                size_t tEnd = transData.find('~', tPos);
                if (tEnd == string::npos) break;
                acc.addTransaction(transData.substr(tPos, tEnd - tPos));
                tPos = tEnd + 1;
            }

            accounts.insert({accNum, acc});
        }

        file.close();

        if (!accounts.empty())
        {
            string lastAcc    = accounts.rbegin()->first;
            nextAccountNumber = stoi(lastAcc.substr(3)) + 1;
        }
    }
};

// ================================================================
//  Account Dashboard - Menu after login
// ================================================================
void accountDashboard(BankAccount* acc, BankingSystem* bank)
{
    int choice;

    while (true)
    {
        cout << "\n========== ACCOUNT DASHBOARD ==========\n";
        cout << "Welcome, " << acc->getHolderName() << "!\n";
        cout << "Balance: $" << fixed << setprecision(2) << acc->getBalance() << "\n";
        cout << "----------------------------------------\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Transfer Money\n";
        cout << "4. Account Information\n";
        cout << "5. Transaction History\n";
        cout << "6. Logout\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            double amount;
            cout << "\nEnter deposit amount: $";
            cin >> amount;
            acc->deposit(amount);
            bank->saveToFile();
            break;
        }
        case 2:
        {
            double amount;
            cout << "\nEnter withdrawal amount: $";
            cin >> amount;
            acc->withdraw(amount);
            bank->saveToFile();
            break;
        }
        case 3:
            bank->transferMoney(acc);
            break;

        case 4:
            acc->displayAccountInfo();
            break;

        case 5:
            acc->displayTransactionHistory();
            break;

        case 6:
            cout << "\n✓ Logged out successfully!\n";
            return;

        default:
            cout << "\n❌ Invalid choice! Try again.\n";
        }
    }
}

// ================================================================
//  Main Function - Entry Point
// ================================================================
int main()
{
    BankingSystem bank;
    int choice;

    cout << "\n";
    cout << "==================================================\n";
    cout << "        WELCOME TO C++ BANKING SYSTEM\n";
    cout << "             ATM SIMULATOR v1.0\n";
    cout << "==================================================\n";

    while (true)
    {
        cout << "\n================ MAIN MENU ================\n";
        cout << "1. Create New Account\n";
        cout << "2. Login to Account\n";
        cout << "3. Delete Account\n";
        cout << "4. Exit\n";
        cout << "===========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;

        case 2:
        {
            BankAccount* acc = bank.login();
            if (acc != nullptr)
            {
                accountDashboard(acc, &bank);
            }
            break;
        }

        case 3:
            bank.deleteAccount();
            break;

        case 4:
            cout << "\n✓ Thank you for using C++ Banking System!\n";
            cout << "  Goodbye!\n";
            return 0;

        default:
            cout << "\n❌ Invalid choice! Try again.\n";
        }
    }

    return 0;
}
