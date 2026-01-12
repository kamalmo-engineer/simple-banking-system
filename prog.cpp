#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Account
{
    int ID;
    string Name;
    double Balance;
};
Account Creat_Acc()
{
    Account acc;
    cout << "enter your Name : ";
    cin.ignore();
    getline(cin, acc.Name);
    cout << "enter your ID : ";
    cin >> acc.ID;
    cout << "enter your Balance : ";
    cin >> acc.Balance;
    return acc;
}
vector<Account> creat_Accounts()
{
    vector<Account>Accounts;
    int n;
    cout << "enter the number of acc you want to creat : ";
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cout << "creating acc number " << x + 1 << endl;
        Account acc = Creat_Acc();
        Accounts.push_back(acc);
    }
    return Accounts;
}
void With_draw(Account& acc)
{
    double amount;
    cout << "enter the amount of money you want to with draw : ";
    cin >> amount;
    if (amount > acc.Balance)
        cout << "your balance is under the amount you want !!" << endl;
    else
    {
        acc.Balance -= amount;
        cout << "your new balance is : " << acc.Balance << endl;
    }
}
void deposit(Account& acc)
{
    double amount;
    cout << "enter the amount of money you want to deposit : ";
    cin >> amount;
    acc.Balance += amount;
    cout << "your new balance is : " << acc.Balance << endl;
}
int main()
{
    int  y;
    vector<Account>accounts = creat_Accounts();
    cout << "All accounts created:" << endl;
    for (auto& acc : accounts)
    {
        cout << "ID: " << acc.ID << " | Name: " << acc.Name << " | Balance: " << acc.Balance << endl;
    }
    int ID;
    cout << "enter the Account ID you would like yo use : ";
    cin >> ID;
    bool found = false;
    for (auto& acc : accounts)
        if (acc.ID == ID)
        {
            found = true;
            do {
                cout << "choose the opertaion you want to make : " << endl;
                cout << "1- if you want to make a with draw" << endl;
                cout << "2- if you want to make a deposit" << endl;
                cout << "3- if you want to see your balance" << endl;
                cout << "4- if you want to create a new account" << endl;
                cout << "5- if you want to exit" << endl;
                cout << "your choise is : ";
                cin >> y;
                if (y == 1)
                {
                    With_draw(acc);
                    cout << "===============================" << endl;
                }
                else if (y == 2)
                {
                    deposit(acc);
                    cout << "===============================" << endl;
                }
                else if (y == 3)
                {
                    cout << "your balance is : " << acc.Balance << endl;
                    cout << "===============================" << endl;
                }
                else if (y == 4)
                {
                    Account nem_acc = Creat_Acc();
                    accounts.push_back(nem_acc);
                    cout << "New account created:" << endl;
                    cout << "===============================" << endl;
                }
                else if (y == 5)
                {
                    cout << "Exiting program..." << endl;
                    cout << "===============================" << endl;
                }
                else
                    cout << "Invalid choice!" << endl;
            } while (y != 5);
        }
        else if (!found)
        {
            cout << "account with ID" << ID << "is not found";
        }
    return 0;
}