#include <fstream>
#include <iostream>

#include "../employee.hpp"

using namespace std;

int main(int argc, char **argv) {
    int amountOfEmplayees = atoi(argv[2]);
    ofstream fout(argv[1]);

    employee tempEmployee;
    for (int i = 0; i < amountOfEmplayees; ++i) {
        cout << "Employee №" << i + 1 << endl;
        cout << "Enter ID: ";
        cin >> tempEmployee.num;

        cout << "Enter name:";
        cin >> tempEmployee.name;

        cout << "Enter amount of hours:";
        cin >> tempEmployee.hours;

        fout << tempEmployee.num << ' ' << tempEmployee.name << ' '
             << tempEmployee.hours << ' ';
    }

    fout.close();

    return 0;
}
