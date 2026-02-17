#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Bank Account Class
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
    string getHolderName() { return holderName; }
    string getAccountType() { return accountType; }
    double getBalance() { return balance; }

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
        cout << "Account Type:   " << accountType << endl;                           // ✅ Fixed missing ":"
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

