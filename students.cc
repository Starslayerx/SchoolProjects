#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::ifstream;
using std::istringstream;
using std::setprecision;
using std::ofstream;
#include "students.h"


int main()
{
    /*
     * variables to save data
     */
    string line;
    vector <string> info;
    map <double, Student> lists;
    string file_name = "student_information.conf";

    // read file data and save data into variables
    read_file(file_name, line, info, lists);

    // initialization class operation
    Operations operation(file_name, lists);

    // menu to chose operation
    operation.menu(operation);

    return 0;
}
