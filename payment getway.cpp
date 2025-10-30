#include <iostream>
using namespace std;

class BKashPay {
private:
    float bKashCharge;

public:
    BKashPay() {
        this->bKashCharge = 0.03;
    }

    float bkashPay(int amount, int balance) {
        float totalAmount = amount + (amount * this->bKashCharge);
        cout << "bKash charge (3%): " << totalAmount << endl;

        if (totalAmount <= balance) {
            cout << "bKash Payment successful!!!" << endl;
            return totalAmount;
        }
        else {
            cout<<"=============================="<<endl;
            cout << "bKash Payment unsuccessful!!!" << endl;
            cout << "Insufficient balance. Balance: " << balance<< "; Total charged amount: " << totalAmount << endl;
            return -1;
        }
    }
};

class NagodPay {
private:
    float nagodCharge;

public:
    NagodPay() {
        this->nagodCharge = 0.015;
    }

    float nagodPay(int amount, int balance) {
        float totalAmount = amount + (amount * this->nagodCharge);
        cout << "Nogod charge (1.5%): " << totalAmount << endl;

        if (totalAmount <= balance) {
            cout << "Nogod Payment successful!!!" << endl;
            return totalAmount;
        } else {
            cout<<"=============================="<<endl;
            cout << "Nogod Payment unsuccessful!!!" << endl;
            cout << "Insufficient balance. Balance: " << balance<< "; Total charged amount: " << totalAmount << endl;
            return -1;
        }
    }
};

class SSLCommercePay : private BKashPay, private NagodPay {
private:
    float SSLCharge;

public:
    SSLCommercePay() : BKashPay(), NagodPay() {
        this->SSLCharge = 0.005;
    }

    void sslPay(int amount, int balance, string paymentMethod) {
        float paidAmount = -1;

        if (paymentMethod == "bkash") {
            paidAmount = bkashPay(amount, balance);
        } else if (paymentMethod == "nagod") {
            paidAmount = nagodPay(amount, balance);
        } else {
            cout << "Wrong Payment Gateway..." << endl;
            return;
        }

        if (paidAmount > 0) {
            float finalAmount = paidAmount + (paidAmount * this->SSLCharge);
            cout << "SSLCommerce charge (0.5%): " << finalAmount << endl;

            if (finalAmount <= balance) {
                cout << "SSL Commerce Payment successful!!!" << endl;
            } else {
                cout << "SSL Commerce Payment unsuccessful!!!" << endl;
                cout << "Insufficient balance. Balance: " << balance << "; Total charged amount: " << finalAmount << endl;
            }
        }
    }
};

int main() {
    SSLCommercePay payment;

    int balance = 3000;
    int amount = 1000;

    cout<<"Which method you want to pay with!(Bkash / Nagod)"<<endl;
    string str;
    cin>>str;
    string pin="7577";
    cout << "=== Using "<<str<<"===" << endl;
    cout<<"Enter your "<<str<<" pin:";
    string p;
    cin>>p;
    if(pin==p) payment.sslPay(amount, balance, str);
    else cout<<"Wrong pin !!!"<<endl;
    return 0;
}
