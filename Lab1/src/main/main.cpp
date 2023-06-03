#include <boost/process.hpp>
#include <fstream>
#include <iostream>

namespace bp = boost::process;
using namespace std;

void print_file(string path_to_file);

int main() {
    cout << "Enter data file name: ";
    string dataFilePath;
    cin >> dataFilePath;
    dataFilePath = ".build/data/" + dataFilePath;

    cout << "Enter amount of employees: ";
    int amountOfEmployees;
    cin >> amountOfEmployees;

    bp::child creator(".build/bin/creator", dataFilePath,
                      to_string(amountOfEmployees));
    creator.wait();

    print_file(dataFilePath);
    cout << endl;

    cout << "Enter report file name: " << endl;
    string reportFilePath;
    cin >> reportFilePath;
    reportFilePath = ".build/data/" + reportFilePath;

    cout << "Enter salary per hour: ";
    int salaryPerHour;
    cin >> salaryPerHour;

    bp::child reporter(".build/bin/reporter", dataFilePath, reportFilePath,
                       to_string(salaryPerHour));
    reporter.wait();

    print_file(reportFilePath);

    return 0;
}

void print_file(string filePath) {
    ifstream fin(filePath);
    cout << fin.rdbuf();
    fin.close();
}
