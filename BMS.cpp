#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class BankAccount {
private:
    string name;
    string address;
    string phone;
    string email;
    long int account_number;
    float balance;
    int pin;

public:
    BankAccount(){
        this->name=" ";
        this->address=" ";
        this->phone=" ";
        this->email=" ";
        this->account_number=0;
        this->balance=0.0;
        this->pin=0;
    }
    ~BankAccount(){}
    void generate_account_number() {
        ifstream in("AccountNumber.txt");
        if (!in || !(in >> account_number)) {
            account_number = 20501000;
        }
        in.close();
        account_number++;
        ofstream out("AccountNumber.txt");
        out << account_number;
        out.close();
    }

    void input_details() {
        ofstream out("Details.txt", ios::app);

        cout << "Enter name: ";
        getline(cin, name);
        out << "Name: " << name << endl;

        cout << "Enter address: ";
        getline(cin, address);
        out << "Address: " << address << endl;

        cout << "Enter phone number: ";
        cin >> phone;
        out << "Phone: +88" << phone << endl;

        cout << "Enter email: ";
        cin >> email;
        out << "Email: " << email << endl;

        generate_account_number();
        out << "Account Number: " << account_number << endl;

        cout << "Enter initial balance: ";
        cin >> balance;
        out << "Balance: " << balance << endl;

        cout << "Enter your 4 digit PIN: ";
        cin >> pin;
        out << "PIN: " << pin << endl;

        out << "-----------------------------" << endl;
        out.close();

        cout << "\nYour account has been successfully created.\n";
        cout << "Your account number is: " << account_number << endl;
    }
};

void display_menu() {
    cout << "1. Register new account." << endl;
}

int main() {
    BankAccount acc;
    display_menu();
    acc.input_details();
    //cout<<"Please enter a number between 1 and 8."<<endl;
    // int choice;
    // cin >> choice;
    // if (choice == 1) {
    //     cin.ignore();
    //     acc.input_details();
    // }
    return 0;
}
