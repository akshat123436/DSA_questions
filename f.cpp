// CPP CODE

// 1.debug program to get desired output:

// Info::Name
// Name: A
// Info:roll_no
// roll no: 121
// Info: Role:
// Role: student

#include <iostream>
using namespace std;
class Info
{
    char *name;
    int roll_Number;
    char name1;

public:
    Info()
    {
        name1 = 'A';
        roll_Number = 121;
        name = new char(name1);
    }
    void getInfo()
    {
        cout << "Info::Name\n";
        cout << "Name: " << *name << endl;
        getroll_no();
    }
    void getroll_no()
    {
        cout << "Info:roll_no\n";
        cout << "roll no: " << roll_Number << endl;
    }
};

class role : public Info
{
    char *name;
    string Role = "student";

public:
    void getrole()
    {
        cout << "Info: Role:\n";
        cout << "Role: " << Role << endl;
    }
};

int main()
{
    Info *P = new Info();
    role *n = new role();
    P = n;
    P->getInfo();
    n->getrole();
    return 0;
}