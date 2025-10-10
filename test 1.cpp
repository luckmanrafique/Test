#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;
class Bank_Account{
private:
    string accout_number;
    string account_holder_name;
    string address;
    string phone_number;
    string email;
    double balance;
    string account_type;
    string password;
public:
    Bank_Account(string accNum="",string name="",string addr="",string phone="",string mail="",double initial_Deposit=0.0,string type="Savings",string pwd="1234"):accout_number(accNum),account_holder_name(name),address(addr),phone_number(phone),email(mail),balance(initial_Deposit),account_type(type),password(pwd);
    string get_account_number(){return accout_number};
    string get_account_holder_name(){return account_holder_name};
    double get_balance(){return balance};
    string get_account_type(){return account_type};
    string get_password(){return password};
    

    void register_new_account(){
        cout<<"Enter you name: ";
        cin>>account_holder_name;
        cout<<"Enter Phone number: ";
        cin>>phone_number;
        cout<<"Enter you mail address: ";
        cin>>email;
        cout<<"Enter your 4 digit pin: ";
        cin>>password;
    }
    void display(){
        cout<<"Account number: " <<accout_number<<endl;
        cout<<"Name: "<<account_holder_name<<endl;
        cout<<"Balace: "<<balance<<endl;
    }
};
void display_menu(){
    cout<<"\n===== Welcome to Bitches Menu ====="<<endl;
    cout<<"1. Creat new account"<<endl;
    cout<<"====================================="<<endl;
}
int main()
{
    Bank_Account bank;
    int choice;
    while(true)
    {
        display_menu();
        switch (choice)
        {
            case 1:
                bank.register_new_account();
                break;
            case 2:
                cout<<"Fuck you bitch "<<endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
        } 
        cin.ignore();
        cin.get();   
    }
    return 0;
}
