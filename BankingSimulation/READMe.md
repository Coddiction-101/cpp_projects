# Banking System - ATM Simulator

A console-based banking application built in C++ that simulates real-world ATM operations with account management, secure transactions, and persistent data storage.

## Features
- 🔐 Secure PIN-based authentication
- 🏦 Create Savings or Current accounts
- 💵 Deposit and withdraw money
- 💸 Transfer money between accounts
- 📊 Full transaction history tracking
- 👤 View detailed account information
- 🗑️ Delete account with PIN confirmation
- 💾 Persistent data storage (auto-save/load)
- ✅ Input validation & error handling throughout

## Tech Stack
- **Language:** C++ (STL)
- **Data Structures:** Map, Vector, File I/O
- **Concepts:** OOP (Classes & Objects), File Handling, Pointers, Menu-driven Interface

## Getting Started

### Prerequisites
- C++ compiler (g++, MinGW, or any C++11 compatible compiler)
- Terminal / Command Prompt

### Installation & Usage

1. **Clone or download the project**
   ```bash
   git clone <your-repo-url>
   cd banking-system
   ```

2. **Compile the program**
   ```bash
   g++ banking_system.cpp -o banking_system
   ```

3. **Run the program**
   ```bash
   ./banking_system       # Linux/Mac
   banking_system.exe     # Windows
   ```

## How to Use

### Main Menu
```
1. Create New Account  - Register a new bank account
2. Login to Account    - Access your existing account
3. Delete Account      - Permanently remove an account
4. Exit                - Save and quit the program
```

### Creating an Account
1. Select option `1` from the main menu
2. Enter your full name
3. Set a 4-digit PIN
4. Choose account type: `1` for Savings, `2` for Current
5. Enter your initial deposit amount
6. Your unique account number will be generated (e.g. ACC1001)
7. **Save your account number** - you'll need it to login!

### Logging In
1. Select option `2` from the main menu
2. Enter your account number (e.g. ACC1001)
3. Enter your PIN
4. You'll be taken to your Account Dashboard

### Account Dashboard
```
1. Deposit Money       - Add funds to your account
2. Withdraw Money      - Take out cash (balance checked)
3. Transfer Money      - Send money to another account
4. Account Information - View your account details
5. Transaction History - See all past transactions
6. Logout              - Return to main menu
```

### Deleting an Account
1. Select option `3` from the main menu
2. Enter the account number to delete
3. Enter the PIN to verify identity
4. Confirm deletion with `y` or cancel with `n`

### Data Persistence
- All accounts and transactions are automatically saved to `accounts.txt`
- Data is loaded automatically every time the program starts
- No manual saving required!

## Project Structure
```
banking-system/
│
├── banking_system.cpp    # Main source code
├── accounts.txt          # Auto-generated account storage
└── README.md             # This file
```

## Learning Outcomes
- Object-oriented design (BankAccount & BankingSystem classes)
- STL map for efficient account lookup
- Pointer usage for account references
- File I/O with custom delimiters for data parsing
- PIN-based authentication and security checks
- Multi-level menu system design
- Input validation and error handling

## Future Enhancements

### Planned Features (v2.0)
- [ ] **Interest Calculation** - Monthly interest for Savings accounts
- [ ] **Minimum Balance Rules** - Enforce minimum balance for Current accounts
- [ ] **PIN Change** - Allow users to update their PIN
- [ ] **Forgot PIN** - Security question based PIN recovery
- [ ] **Account Statement** - Generate monthly statements
- [ ] **Deposit Limits** - Set daily deposit/withdrawal limits

### Advanced Features (v3.0)
- [ ] **Admin Panel** - View and manage all accounts
- [ ] **Loan System** - Apply for and manage loans
- [ ] **Fixed Deposits** - Create FD accounts with interest
- [ ] **Mini Statement** - Last 5 transactions quick view
- [ ] **Multi-currency Support** - Handle different currencies
- [ ] **Export Statement to CSV** - Download transaction history
- [ ] **Failed Login Attempts** - Lock account after 3 wrong PINs
- [ ] **Timestamp on Transactions** - Record date/time of each transaction

### UI Improvements
- [ ] Colored output for better readability
- [ ] Progress indicators for transactions
- [ ] Cleaner receipt-style formatting
- [ ] ASCII art for the ATM interface

## Security Features
- PIN verification required for login
- PIN confirmation required before account deletion
- Double confirmation (y/n) for destructive operations
- Cannot transfer money to your own account

## Contributing
Feel free to fork this project and submit pull requests for any enhancements!

## Version History
- **v1.0** (Feb 2026) - Initial release with full core banking features

## License
This project is open source and available for educational purposes.

---

**Built as a C++ learning project covering OOP, Data Structures, File Handling, and real-world application design.**
