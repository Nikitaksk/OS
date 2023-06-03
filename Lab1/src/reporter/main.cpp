#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

#include "../employee.hpp"

using namespace std;

bool employeeComparator(employee &first, employee &second) {
    return first.num < second.num;
}

void printReport(ostream &out, vector<employee> &data, int revenue_per_hour) {
    out << setw(10) << "Name" << setw(10) << "Hours" << setw(10) << "Salary"
        << endl;
    for (const employee &tempEmployee : data) {
        out << "ID:" << tempEmployee.num << setw(10) << tempEmployee.name
            << setw(10) << tempEmployee.hours << setw(10)
            << tempEmployee.hours * revenue_per_hour / 100.0 << endl;
    }
}

int main(int argc, char **argv) {
    ofstream fout(argv[2]);

    string dataFileName = argv[1];
    size_t position = dataFileName.rfind('/') + 1;
    dataFileName = dataFileName.substr(position);

    vector<employee> employees;
    int num;
    char name[10];
    double hours;
    ifstream fin(argv[1]);
    fin >> num >> name >> hours;
    while (!fin.eof()) {
        employee temp;
        temp.num = num;
        memcpy(temp.name, name, strlen(name));
        temp.hours = hours;
        employees.push_back(temp);
        fin >> num >> name >> hours;
    }

    sort(employees.begin(), employees.end(), employeeComparator);

    printReport(fout, employees, atoi(argv[3]));
    return 0;
}
