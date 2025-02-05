#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Define a structure for Customer
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

// Define a structure for Transaction
struct Transaction
{
    int id;
    int customerCode;
    string type; // "deposit" or "withdraw"
    int amount;
    string date;
    Transaction *next;

    Transaction(int i, int cCode, string t, int amt, string d)
    {
        id = i;
        customerCode = cCode;
        type = t;
        amount = amt;
        date = d;
        next = nullptr;
    }
};

class ManagementSystem
{
private:
    Customer *customerHead;
    Transaction *transactionHead;

public:
    ManagementSystem()
    {
        customerHead = nullptr;
        transactionHead = nullptr;
    }

    // Add a customer
    void addCustomer(int code, string dob, string name, int balance)
    {
        if (code <= 0 || dob.empty() || name.empty() || balance < 0)
        {
            cout << "Invalid customer details." << endl;
            return;
        }
        Customer *newCustomer = new Customer(code, dob, name, balance);
        newCustomer->next = customerHead;
        customerHead = newCustomer;
        cout << "Customer added successfully." << endl;
    }

    // Add a transaction
    void addTransaction(int id, int customerCode, string type, int amount, string date)
    {
        if (id <= 0 || customerCode <= 0 || (type != "deposit" && type != "withdraw") || amount <= 0 || date.empty())
        {
            cout << "Invalid transaction details." << endl;
            return;
        }
        // Check if customer exists
        Customer *customer = findCustomerByCode(customerCode);
        if (!customer)
        {
            cout << "Customer with code " << customerCode << " not found." << endl;
            return;
        }

        // Process transaction
        if (type == "withdraw" && customer->balance < amount)
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        if (type == "withdraw")
        {
            customer->balance -= amount;
        }
        else if (type == "deposit")
        {
            customer->balance += amount;
        }

        Transaction *newTransaction = new Transaction(id, customerCode, type, amount, date);
        newTransaction->next = transactionHead;
        transactionHead = newTransaction;

        cout << "Transaction added successfully." << endl;
    }

    // Find customer by code
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

    // Display customers
    void displayCustomers()
    {
        if (!customerHead)
        {
            cout << "No customers available." << endl;
            return;
        }
        Customer *temp = customerHead;
        cout << "\nCustomer Details:\n";
        while (temp)
        {
            cout << "Code: " << temp->code << endl;
            cout << "DOB: " << temp->dob << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Balance: " << temp->balance << endl;
            temp = temp->next;
        }
    }

    // Display transactions
    void displayTransactions()
    {
        if (!transactionHead)
        {
            cout << "No transactions available." << endl;
            return;
        }
        Transaction *temp = transactionHead;
        cout << "\nTransaction Details:\n";
        while (temp)
        {
            cout << "ID: " << temp->id << endl;
            cout << "Customer Code: " << temp->customerCode << endl;
            cout << "Type: " << temp->type << endl;
            cout << "Amount: " << temp->amount << endl;
            cout << "Date: " << temp->date << endl;
            temp = temp->next;
        }
    }

    // Destructor to clean up memory
    ~ManagementSystem()
    {
        Customer *tempCust = customerHead;
        while (tempCust)
        {
            Customer *toDelete = tempCust;
            tempCust = tempCust->next;
            delete toDelete;
        }

        Transaction *tempTrans = transactionHead;
        while (tempTrans)
        {
            Transaction *toDelete = tempTrans;
            tempTrans = tempTrans->next;
            delete toDelete;
        }
    }
};

// Function to validate integer input
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

// Function to validate string input
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
        cout << "\nCustomer and Transaction Management System" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Add Transaction" << endl;
        cout << "3. Display Customers" << endl;
        cout << "4. Display Transactions" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        choice = getValidInteger();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Customer Code: ";
            int code = getValidInteger();
            cout << "Enter DOB (e.g., 22/02/25): ";
            string dob = getValidString();
            cout << "Enter Name: ";
            string name = getValidString();
            cout << "Enter Balance: ";
            int balance = getValidInteger();
            system.addCustomer(code, dob, name, balance);
            break;
        }
        case 2:
        {
            cout << "Enter Transaction ID: ";
            int id = getValidInteger();
            cout << "Enter Customer Code: ";
            int customerCode = getValidInteger();
            cout << "Enter Transaction Type (deposit/withdraw): ";
            string type = getValidString();
            cout << "Enter Amount: ";
            int amount = getValidInteger();
            cout << "Enter Date (e.g., 22/02/25): ";
            string date = getValidString();
            system.addTransaction(id, customerCode, type, amount, date);
            break;
        }
        case 3:
            system.displayCustomers();
            break;
        case 4:
            system.displayTransactions();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
