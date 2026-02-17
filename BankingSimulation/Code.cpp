#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// ================================================================
//  Banking System - ATM Simulator
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
        accountNumber = accNum;
        holderName = name;
        pin = p;
        accountType = type;
        balance = initialBalance;

        string transaction = "Account created with balance: $" + to_string(initialBalance); // ✅ Fixed typo
        transactionHistory.push_back(transaction);
    }

    // Getters
    string getAccountNumber() { return accountNumber; }
    string getHolderName()    { return holderName; }
    string getAccountType()   { return accountType; }
    double getBalance()       { return balance; }

    // PIN verification ✅ Fixed naming convention
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
        cout << "\n✓ Successfully deposited $" << amount << endl;
    }

    // Withdraw money
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "\n❌ Invalid amount!\n"; // ✅ Fixed: was showing deposit message
            return false;
        }
        if (amount > balance)
        {
            cout << "\n❌ Insufficient balance!\n";
            return false;
        }

        balance -= amount;
        string transaction = "Withdrawn: $" + to_string(amount) + " | New Balance: $" + to_string(balance); // ✅ Fixed missing ":"
        transactionHistory.push_back(transaction);
        cout << "\n✓ Successfully withdrawn $" << amount << endl;
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
        string transaction = "Received $: " + to_string(amount) + " from A/C: " + fromAccount; // ✅ Fixed spacing
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
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name:    " << holderName << endl;
        cout << "Account Type:   " << accountType << endl; // ✅ Fixed missing ":"
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl; // ✅ Fixed missing ":"
        cout << "=====================================================\n";
    }

    // Display transaction history
    void displayTransactionHistory()
    {
        cout << "\n============== TRANSACTION HISTORY ==============\n";
        if (transactionHistory.empty())
        {
            cout << "No transactions yet.\n"; // ✅ Fixed extra semicolon in string
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
    vector<string> getTransactions() { return transactionHistory; } // ✅ Fixed plural
};

// ================================================================
//  BankingSystem Class - Manages all accounts
// ================================================================
class BankingSystem
{
private:
    map<string, BankAccount> accounts; // accountNumber -> BankAccount
    string filename = "accounts.txt";
    int nextAccountNumber = 1001;      // Auto-increments for each new account

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

        // Check if account exists
        if (accounts.find(accNum) == accounts.end())
        {
            cout << "\n❌ Account not found!\n";
            return nullptr;
        }

        cout << "Enter PIN: ";
        cin >> pin;

        // Verify PIN
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
    //  Transfer Between Accounts
    // -----------------------------------------------
    void transferMoney(BankAccount* sender)
    {
        string targetAccNum;
        double amount;

        cout << "\n============= TRANSFER MONEY =============\n";
        cout << "Enter recipient account number: ";
        cin >> targetAccNum;

        // Check recipient exists
        if (accounts.find(targetAccNum) == accounts.end())
        {
            cout << "\n❌ Recipient account not found!\n";
            return;
        }

        // Can't transfer to yourself
        if (targetAccNum == sender->getAccountNumber())
        {
            cout << "\n❌ Cannot transfer to your own account!\n";
            return;
        }

        cout << "Enter amount to transfer: $";
        cin >> amount;

        // Deduct from sender
        if (sender->transfer(amount))
        {
            // Add to receiver
            accounts.at(targetAccNum).receiveTransfer(amount, sender->getAccountNumber());

            // Log in sender history
            string trans = "Transferred $" + to_string(amount) +
                           " to A/C: " + targetAccNum;
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
                 << acc.getHolderName() << "|"
                 << acc.getPin() << "|"
                 << acc.getAccountType() << "|"
                 << acc.getBalance() << "|";

            // Save transactions
            vector<string> trans = acc.getTransactions();
            file << trans.size() << "|";
            for (auto& t : trans)
            {
                file << t << "~"; // Use ~ as transaction separator
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

            // Parse each field
            string accNum, name, pin, type;
            double balance;
            int transCount;

            size_t pos = 0;
            auto nextField = [&]() {
                size_t end = line.find('|', pos);
                string field = line.substr(pos, end - pos);
                pos = end + 1;
                return field;
            };

            accNum    = nextField();
            name      = nextField();
            pin       = nextField();
            type      = nextField();
            balance   = stod(nextField());
            transCount = stoi(nextField());

            BankAccount acc(accNum, name, pin, type, 0);

            // Load transactions
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

        // Update next account number
        if (!accounts.empty())
        {
            string lastAcc = accounts.rbegin()->first;
            nextAccountNumber = stoi(lastAcc.substr(3)) + 1;
        }
    }
};
