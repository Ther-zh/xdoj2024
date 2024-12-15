#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Employee {
    string name;
    double basicSalary;
    double floatingSalary;
    double expenditure;
};

int main() {
    int n;
    cin >> n;
    Employee employees[n];
    for (int i = 0; i < n; i++) {
        cin >> employees[i].name >> employees[i].basicSalary >> employees[i].floatingSalary >> employees[i].expenditure;
    }
    for (int i = 0; i < n; i++) {
        cout << employees[i].name << " " << fixed << setprecision(2) << (employees[i].basicSalary + employees[i].floatingSalary - employees[i].expenditure) << endl;
    }
    return 0;
}
