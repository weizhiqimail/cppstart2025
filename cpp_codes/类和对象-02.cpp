#include <iostream>
#include <string.h>

using namespace std;

class CEmployee {
private:
    char userName[50];

public:
    int salary;

    void printUserInfo();

    void setUserName(char *name);

    static void calcSalaryAvg(CEmployee e1, CEmployee e2);

    CEmployee(char *name, int salary);

};

void CEmployee::setUserName(char *name) {
    strcpy(userName, name);
    this->printUserInfo();
}

void CEmployee::printUserInfo() {
    cout << "CEmployee::userName = " << this->userName << endl;
    cout << "CEmployee::salary = " << this->salary << endl;
}

void CEmployee::calcSalaryAvg(CEmployee e1, CEmployee e2) {
    cout << "CEmployee::avgSalary() = " << (e1.salary + e2.salary) / 2 << endl;
}

CEmployee::CEmployee(char *name, int salary_) {
    this->salary = salary_;
    setUserName(name);
}

void testCEmployee() {
    CEmployee e1("tom", 10000);
    e1.printUserInfo();
    e1.setUserName("jack");
    e1.printUserInfo();

    CEmployee e2("sherry", 20000);
    e2.printUserInfo();
}


int main() {
    testCEmployee();
    return 0;
}
