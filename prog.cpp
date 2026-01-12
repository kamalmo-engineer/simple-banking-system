#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount {
private:
    string name, accountID, password, fileName = "account_data.txt";
    double balance;

public:
    BankAccount() { balance = 0.0; }

    void createAccount() {
        cout << "--- Create New Account ---\n";
        cout << "Enter Full Name (no spaces): "; cin >> name;
        cout << "Enter Account ID: "; cin >> accountID;
        cout << "Enter Password: "; cin >> password;
        balance = 0.0;
        saveData();
        cout << "\nAccount created successfully and saved to file!\n";
    }

    bool login() {
        string id, pass, fName, fID, fPass;
        double fBalance;
        cout << "--- Login System ---\n";
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Password: "; cin >> pass;

        ifstream inFile(fileName);
        if (inFile >> fName >> fID >> fPass >> fBalance) {
            if (id == fID && pass == fPass) {
                name = fName; accountID = fID; password = fPass; balance = fBalance;
                return true;
            }
        }
        return false;
    }

    void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            saveData();
            cout << "Deposit successful! Current balance: " << balance << " EGP\n";
        }
    }

    void withdraw(double amt) {
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            saveData();
            cout << "Withdrawal successful! Current balance: " << balance << " EGP\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void showInfo() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Account ID: " << accountID << endl;
        cout << "Current Balance: " << balance << " EGP" << endl;
    }

    void saveData() {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            outFile << name << " " << accountID << " " << password << " " << balance;
            outFile.close();
        }
    }
};

int main() {
    BankAccount myAccount;
    int choice;

    cout << "Welcome to My Banking System\n";
    cout << "1. Login\n2. Create New Account\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        if (!myAccount.login()) {
            cout << "\nInvalid ID or Password! Access Denied.\n";
            return 0;
        }
        cout << "\nLogin Successful! Welcome back.\n";
    } else if (choice == 2) {
        myAccount.createAccount();
    } else {
        cout << "Invalid Option.\n";
        return 0;
    }

    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Deposit Money\n2. Withdraw Money\n3. Show Account Info\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 4) break;

        double amount;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: "; cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: "; cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                myAccount.showInfo();
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    cout << "Thank you for using our system!\n";
    return 0;
}