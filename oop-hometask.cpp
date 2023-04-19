//task implementation using concepts of aggregation, assosiation and inheritence
#include <iostream>
using namespace std;

class Account;

class Bank {
    string code, address;

    public:
    void manages() {
        cout << "Bank manages accounts" << endl;
    }

    void maintains() {
        cout << "Bank maintains accounts" << endl;
    }
};

class Customer {
    string name, address, pin, dob, card_number;
    Bank* b;
    Account* a;

    public:
    Customer(Bank* b, Account* a) {
        this->b = b;
        this->a = new Account;
        *this->a = *a;
    }

    void verifyPassword() {
        cout << "Customer verifies password" << endl;
    }
};

class ATM {
    string location, managedby;
    Bank* b;
    Customer* c;

    public:
    ATM() {
        this->b = nullptr;
        this->c = nullptr;
    }

    ATM(Bank* b, Customer* c) {
        this->b = b;
        this->c = c;
    }

    void identifies() {

    }
    
    void transaction() {

    }
};

class Account {
    private:
    ATM* a;

    public:
    int number;
    double balance;

    // public:
    Account() {
        this->a = new ATM;
        *this->a = *a;
    }

    Account(ATM* a) {
        this->a = new ATM;
        *this->a = *a;
    }
    void deposit() {

    }

    void withdraw() {

    }

    void createTransaction() {

    }
};

class CurrentAccout: public Account {
    SavingsAccount s;
    public:
    CurrentAccout(SavingsAccount s) {
        // this->s = new SavingsAccount;
        this->s = s;
    }

    void withdraw() {

    }

    void savingChecking() {
        cout << "Saving: " << s.balance;
    }
};

class SavingsAccount: public Account {
    
};

int main() {



    return 0;
}