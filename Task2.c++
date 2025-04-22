#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) : type(t), amount(a) {}
};

class ATM {
private:
    string userName;
    int pin;
    double balance;
    vector<Transaction> history;

public:
    ATM(string name, int userPin) {
        userName = name;
        pin = userPin;
        balance = 1000.0;
    }

    bool verifyPin(int enteredPin) {
        return enteredPin == pin;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n===== ATM Menu =====\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. View Transaction History\n";
            cout << "5. Change PIN\n";
            cout << "6. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance(); break;
                case 2:
                    deposit(); break;
                case 3:
                    withdraw(); break;
                case 4:
                    showHistory(); break;
                case 5:
                    changePin(); break;
                case 6:
                    cout << "Thank you for using the ATM, " << userName << "!\n"; break;
                default:
                    cout << "Invalid option. Try again.\n";
            }
        } while (choice != 6);
    }

    void checkBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ₹";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            history.push_back(Transaction("Deposit", amount));
            cout << "₹" << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ₹";
        cin >> amount;

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            cout << "₹" << amount << " withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void showHistory() {
        if (history.empty()) {
            cout << "No transactions yet.\n";
            return;
        }
        cout << "\nTransaction History:\n";
        for (auto &t : history) {
            cout << " - " << t.type << ": ₹" << t.amount << endl;
        }
    }

    void changePin() {
        int oldPin, newPin;
        cout << "Enter current PIN: ";
        cin >> oldPin;
        if (oldPin == pin) {
            cout << "Enter new PIN: ";
            cin >> newPin;
            pin = newPin;
            cout << "PIN changed successfully.\n";
        } else {
            cout << "Incorrect current PIN.\n";
        }
    }
};

int main() {
    string name;
    int pin;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Set your PIN: ";
    cin >> pin;

    ATM user(name, pin);

    int attempts = 3;
    int enteredPin;
    while (attempts > 0) {
        cout << "Enter PIN to access your account: ";
        cin >> enteredPin;
        if (user.verifyPin(enteredPin)) {
            user.showMenu();
            break;
        } else {
            attempts--;
            cout << "Incorrect PIN. Attempts left: " << attempts << endl;
        }
    }

    if (attempts == 0) {
        cout << "Account locked due to multiple incorrect PIN entries.\n";
    }

    return 0;
}
