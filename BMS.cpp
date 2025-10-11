#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class BankAccount{
    private:
        string name;
        string address;
        string phone;
        string email;
        long int account_number;
        float balance;
    public:
        BankAccount(){
            name = "";
            address = "";
            phone = "";
            email = "";
            account_number = 0;
            balance = 0.0;
        }
        ~BankAccount(){
            
        }
        void generate_account_number(){
            ifstream in("AccountNumber.txt");
            account_number = 20501000;
            in>>account_number;
            account_number ++;
            in.close();
            ofstream out("AccountNumber.txt");
            out<<account_number;
            out.close();
        }
        void input_details(){
            ofstream in("Details.txt",ios::app);
            cout<<"Enter name: ";
            getline(cin,name);
            in<< name+"\n";
            cout<<"Enter address: ";
            getline(cin,address);
            in<<address+"\n";
            cout<<"Enter phone number: ";
            cin>>phone;
            in<<"+88"+phone+"\n";
            cout<<"Enter email: ";
            cin>>email;
            in<<email+"\n";
            generate_account_number();
            in<<"Account Number: "<<account_number<<"\n";
            cout<<"Enter initial balance: ";
            cin>>balance;
            in<<"Balance: "<<balance<<"\n";
            in.close();
        }
};

int main()
{
    BankAccount acc;
    acc.input_details();
    return 0;
}
