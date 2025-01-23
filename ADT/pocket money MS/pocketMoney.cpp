#include <iostream>
#include <string>
#include <limits>
#include <regex>

using namespace std;

// customer linked list
struct Customer
{
    int code;
    string dob;
    string name;
    int balance;
    Customer *next;

    Customer(int c, string d, string n, int b)
    {
        code = c;
        dob = d;
        name = n;
        balance = b;
        next = nullptr;
    }
};

class ManagementSystem
{
private:
    Customer *customerHead;

    // validate date of birth
    bool isValidDOB(const string &dob)
    {
        regex dobPattern("\\d{1,2}/\\d{1,2}/\\d{4}");
        if (!regex_match(dob, dobPattern))
        {
            return false;
        }

        int day, month, year;
        sscanf(dob.c_str(), "%d/%d/%d", &day, &month, &year);

        if (year > 2025 || (year == 2025 && month > 1) || (year == 2025 && month == 1 && day > 23))
        {
            return false;
        }

        if (month < 1 || month > 12 || day < 1 || day > 31)
        {
            return false;
        }

        return true;
    }

public:
    ManagementSystem()
    {
        customerHead = nullptr;
    }

    // 1. add a customer
    void addCustomer(int code, string dob, string name, int balance)
    {
        if (code <= 0 || name.empty() || balance < 0 || !isValidDOB(dob))
        {
            cout << "Invalid customer details. Make sure the DOB is in DD/MM/YYYY format and before 23/01/2025." << endl;
            return;
        }

        Customer *newCustomer = new Customer(code, dob, name, balance);
        newCustomer->next = customerHead;
        customerHead = newCustomer;
        cout << "Customer added successfully." << endl;
    }

    // 2. view customer
    Customer *findCustomerByCode(int code)
    {
        Customer *temp = customerHead;
        while (temp)
        {
            if (temp->code == code)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // view customer details
    void viewCustomer(int code)
    {
        Customer *customer = findCustomerByCode(code);
        if (!customer)
        {
            cout << "Customer with code " << code << " not found." << endl;
            return;
        }

        cout << "\nCustomer Details:" << endl;
        cout << "Code: " << customer->code << endl;
        cout << "DOB: " << customer->dob << endl;
        cout << "Name: " << customer->name << endl;
        cout << "Balance: " << customer->balance << endl;
    }

    // 3. deposit
    void deposit(int code, int amount)
    {
        Customer *customer = findCustomerByCode(code);
        if (!customer)
        {
            cout << "Customer with code " << code << " not found." << endl;
            return;
        }
        if (amount <= 0)
        {
            cout << "Invalid deposit amount." << endl;
            return;
        }

        customer->balance += amount;
        cout << "Amount deposited successfully. New balance: " << customer->balance << endl;
    }

    // 5.withdraw
    void withdraw(int code, int amount)
    {
        Customer *customer = findCustomerByCode(code);
        if (!customer)
        {
            cout << "Customer with code " << code << " not found." << endl;
            return;
        }
        if (amount <= 0 || amount > customer->balance)
        {
            cout << "Invalid or insufficient funds for withdrawal." << endl;
            return;
        }

        customer->balance -= amount;
        cout << "Amount withdrawn successfully. New balance: " << customer->balance << endl;
    }

    // 6.check balance
    void checkBalance(int code)
    {
        Customer *customer = findCustomerByCode(code);
        if (!customer)
        {
            cout << "Customer with code " << code << " not found." << endl;
            return;
        }

        cout << "Current balance: " << customer->balance << endl;
    }

    // clean memory
    ~ManagementSystem()
    {
        Customer *temp = customerHead;
        while (temp)
        {
            Customer *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
};

// validate int input
int getValidInteger()
{
    int value;
    while (true)
    {
        cin >> value;
        if (cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// validate string input
string getValidDOB()
{
    string dob;
    while (true)
    {
        getline(cin, dob);
        regex dobPattern("\\d{1,2}/\\d{1,2}/\\d{4}");
        if (!regex_match(dob, dobPattern))
        {
            cout << "Invalid DOB format. Please enter in DD/MM/YYYY format: ";
            continue;
        }

        int day, month, year;
        sscanf(dob.c_str(), "%d/%d/%d", &day, &month, &year);
        if (year > 2025 || (year == 2025 && month > 1) || (year == 2025 && month == 1 && day > 23))
        {
            cout << "DOB must be before 23/01/2025. Please try again: ";
            continue;
        }

        return dob;
    }
}

string getValidString()
{
    string value;
    while (true)
    {
        getline(cin, value);
        if (value.empty())
        {
            cout << "Invalid input. Please enter a valid string: ";
        }
        else
        {
            return value;
        }
    }
}

int main()
{
    ManagementSystem system;
    int choice;

    do
    {
        cout << "\nCustomer Management System" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. View Customer" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        choice = getValidInteger();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Customer Code: ";
            int code = getValidInteger();
            cout << "Enter DOB (e.g., 22/3/2007): ";
            string dob = getValidDOB();
            cout << "Enter Name: ";
            string name = getValidString();
            cout << "Enter Balance: ";
            int balance = getValidInteger();
            system.addCustomer(code, dob, name, balance);
            break;
        }
        case 2:
        {
            cout << "Enter Customer Code: ";
            int code = getValidInteger();
            system.viewCustomer(code);
            break;
        }
        case 3:
        {
            cout << "Enter Customer Code: ";
            int code = getValidInteger();
            cout << "Enter Deposit Amount: ";
            int amount = getValidInteger();
            system.deposit(code, amount);
            break;
        }
        case 4:
        {
            cout << "Enter Customer Code: ";
            int code = getValidInteger();
            cout << "Enter Withdrawal Amount: ";
            int amount = getValidInteger();
            system.withdraw(code, amount);
            break;
        }
        case 5:
        {
            cout << "Enter Customer Code: ";
            int code = getValidInteger();
            system.checkBalance(code);
            break;
        }
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
