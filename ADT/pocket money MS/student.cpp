#include <iostream>
using namespace std;

struct Student
{
    int code;
    string name;
    string school;
    string level;
    int age;
    Student *next;

    Student() {}

    Student(int code, string name, string school, string level, int age)
    {
        this->code = code;
        this->name = name;
        this->school = school;
        this->level = level;
        this->age = age;
        this->next = NULL;
    }
};

void display(Student *head)
{
    while (head)
    {
        cout << head->code << " " << head->name << " " << head->school << " " << head->level << " " << head->age << endl;
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Student *stud1 = new Student();
    stud1->code = 101;
    stud1->name = "Mary";
    stud1->school = "RCA";
    stud1->level = "Y2";
    stud1->age = 15;

    Student *stud2 = new Student(102, "Peter", "RCA", "Y3", 17);
    Student *stud3 = new Student(103, "John", "RCA", "Y3", 13);
    Student *stud4 = new Student(104, "Doe", "RCA", "Y1", 14);

    stud1->next = stud2;
    stud2->next = stud3;
    stud3->next = stud4;
    stud4->next = NULL;

    display(stud1);

    return 0;
}