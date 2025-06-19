#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <climits>
using namespace std;

// Patient structure to hold patient information
struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    Patient *next;
};

// Hospital Management System class
class HospitalSystem
{
private:
    Patient *head;
    string filename;

    // Helper function to check if patient ID already exists
    bool isIdExists(int id)
    {
        Patient *current = head;
        while (current != nullptr)
        {
            if (current->id == id)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

public:
    HospitalSystem() : head(nullptr), filename("patient_records.txt") {}

    ~HospitalSystem()
    {
        // Clean up memory when object is destroyed
        Patient *current = head;
        while (current != nullptr)
        {
            Patient *next = current->next;
            delete current;
            current = next;
        }
    }

    // Add a new patient record with validation
    void addPatient(int id, const string &name, int age, const string &disease)
    {
        if (isIdExists(id))
        {
            throw invalid_argument("Patient ID already exists!");
        }

        if (name.empty())
        {
            throw invalid_argument("Name cannot be empty!");
        }

        if (age <= 0 || age > 120)
        {
            throw invalid_argument("Age must be between 1 and 120!");
        }

        if (disease.empty())
        {
            throw invalid_argument("Disease cannot be empty!");
        }

        Patient *newPatient = new Patient{id, name, age, disease, nullptr};

        if (head == nullptr)
        {
            head = newPatient;
        }
        else
        {
            Patient *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newPatient;
        }
        cout << "Patient record added successfully!\n";
    }

    // Display all patient records
    void displayPatients()
    {
        if (head == nullptr)
        {
            cout << "No patient records found.\n";
            return;
        }

        cout << "\nPatient Records:\n";
        cout << "ID\tName\tAge\tDisease\n";
        cout << "--------------------------------\n";

        Patient *current = head;
        while (current != nullptr)
        {
            cout << current->id << "\t"
                 << current->name << "\t"
                 << current->age << "\t"
                 << current->disease << "\n";
            current = current->next;
        }
    }

    // Search for a patient by ID
    void searchPatient(int id)
    {
        if (id <= 0)
        {
            cout << "Invalid ID. Must be positive number.\n";
            return;
        }

        Patient *current = head;
        while (current != nullptr)
        {
            if (current->id == id)
            {
                cout << "\nPatient Found:\n";
                cout << "ID: " << current->id << "\n";
                cout << "Name: " << current->name << "\n";
                cout << "Age: " << current->age << "\n";
                cout << "Disease: " << current->disease << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Patient with ID " << id << " not found.\n";
    }

    // Save patient records to file
    void saveToFile()
    {
        if (head == nullptr)
        {
            cout << "No records to save.\n";
            return;
        }

        ofstream outFile(filename);
        if (!outFile)
        {
            throw runtime_error("Error opening file for writing!");
        }

        Patient *current = head;
        while (current != nullptr)
        {
            outFile << current->id << ","
                    << current->name << ","
                    << current->age << ","
                    << current->disease << "\n";
            current = current->next;
        }

        outFile.close();
        cout << "Patient records saved to file successfully!\n";
    }

    // Load patient records from file
    void loadFromFile()
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cout << "No existing patient records file found. Starting with empty records.\n";
            return;
        }

        // Clear existing records
        Patient *current = head;
        while (current != nullptr)
        {
            Patient *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;

        string line;
        int lineNumber = 0;
        while (getline(inFile, line))
        {
            lineNumber++;
            try
            {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);

                if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
                {
                    throw invalid_argument("Invalid file format at line " + to_string(lineNumber));
                }

                int id = stoi(line.substr(0, pos1));
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                string disease = line.substr(pos3 + 1);

                if (name.empty() || disease.empty())
                {
                    throw invalid_argument("Empty name or disease at line " + to_string(lineNumber));
                }

                if (age <= 0 || age > 120)
                {
                    throw invalid_argument("Invalid age at line " + to_string(lineNumber));
                }

                // Add the patient without checking for duplicate IDs from file
                Patient *newPatient = new Patient{id, name, age, disease, nullptr};
                if (head == nullptr)
                {
                    head = newPatient;
                }
                else
                {
                    Patient *temp = head;
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = newPatient;
                }
            }
            catch (const exception &e)
            {
                cerr << "Error loading record: " << e.what() << " - Skipping line.\n";
                continue;
            }
        }

        inFile.close();
        cout << "Patient records loaded from file successfully!\n";
    }
};

// Function to get validated integer input
int getValidatedInt(const string &prompt, int min = INT_MIN, int max = INT_MAX)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
        }
        else if (value < min || value > max)
        {
            cout << "Please enter a value between " << min << " and " << max << ".\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Function to get validated string input
string getValidatedString(const string &prompt, bool allowEmpty = false)
{
    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (!allowEmpty && input.empty())
        {
            cout << "Input cannot be empty. Please try again.\n";
        }
        else
        {
            return input;
        }
    }
}

// Main menu function
void displayMenu()
{
    cout << "\nHospital Management System\n";
    cout << "1. Add Patient\n";
    cout << "2. Display All Patients\n";
    cout << "3. Search Patient by ID\n";
    cout << "4. Save Records to File\n";
    cout << "5. Load Records from File\n";
    cout << "6. Exit\n";
}

int main()
{
    HospitalSystem hospital;

    // Load existing records at startup
    try
    {
        hospital.loadFromFile();
    }
    catch (const exception &e)
    {
        cerr << "Error loading records: " << e.what() << endl;
    }

    while (true)
    {
        displayMenu();
        int choice = getValidatedInt("Enter your choice (1-6): ", 1, 6);

        try
        {
            switch (choice)
            {
            case 1:
            {
                int id = getValidatedInt("Enter Patient ID: ", 1);
                string name = getValidatedString("Enter Patient Name: ");
                int age = getValidatedInt("Enter Patient Age (1-120): ", 1, 120);
                string disease = getValidatedString("Enter Patient Disease: ");

                hospital.addPatient(id, name, age, disease);
                break;
            }
            case 2:
                hospital.displayPatients();
                break;
            case 3:
            {
                int id = getValidatedInt("Enter Patient ID to search: ", 1);
                hospital.searchPatient(id);
                break;
            }
            case 4:
                hospital.saveToFile();
                break;
            case 5:
                hospital.loadFromFile();
                break;
            case 6:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}