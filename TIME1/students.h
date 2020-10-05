#ifndef FRACTOIN_H
#define FRACTOIN_H

/*
 * class Studnet :
 * include student's: name, id, chinese score, math_score, english_score, average_score
 */
class Student
{
    public:
        string name, id;
        double chinese, english, math, average_score;
        
        /*
         * initalization and calculate average_score
         */
        Student(string a, string b, double c, double d, double e) : id{a}, name{b}, chinese{c}, math{d}, english{e} 
        {
            average_score = (chinese + english + math) / 3.0;
        }
         
        /*
         * output a studwnt's information
         */
        void show_data()
        {
            cout << id << "\t" 
                 << name << "\t"
                 // output only 2 fraction part
                 << setprecision(2) << std::fixed << chinese << "\t"
                 << setprecision(2) << std::fixed << math << "\t"
                 << setprecision(2) << std::fixed << english << endl;
        }

        /* 
         * if necessay, reset student's information
         * but i didn't use this function
         */
        void set_data(string a, string b, double c, double d, double e)
        {
            id = a;
            name = b;
            chinese = c;
            math = d;
            english= e;
            average_score = (chinese + english + math) / 3;
        }                   
};

class Operations
{
    public:

        //public vatiables
        string filename;
        map <double, Student> lists;
        Operations(string a, map <double, Student> b) : filename{a}, lists{b} {}
          
        void menu(Operations operation)
        {
            // funnny output :)
            /*
            cout << ""
            << "\\ \\      / /__| | ___ ___  _ __ ___  \n"
            << " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ \n"
            << "  \\ V  V /  __/ | (_| (_) | | | | | |\n"
            << "   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\n" << endl << endl;
            */

            cout << "Enter operation numbers to select what to do: " << endl;
            cout << "1.Show student's informations (sorted)" << endl;
            cout << "2.Look up a student's information by id" << endl;
            cout << "3.Add a new student's information" << endl;

            int number;
            cin >> number;
            // chose a operation
            switch(number)
            {
                case 1:
                    operation.cout_sorted_score(lists);
                    break;
                case 2:
                    check_by_id(lists);
                    break;
                case 3:
                    add_student_info(filename);
                    break;
                default:
                    cout << "Not this operation number!" << endl;
            }

        }

        /*
         * output sorted student informations by average score
         */
        void cout_sorted_score(map <double, Student> lists)
        {
            cout << "Average_Score\tId\t\tName\tChinese\tMath\tEnglish" << endl;
            for (auto &[k, v] : lists)
            {
                cout << k << "\t\t";
                v.show_data();
            }
        }

        /*
         * output sudent's score and find student by id
         */
        void check_by_id(map <double, Student> lists)
        {
            string id;
            cout << "Enter id: ";
            cin >> id;

            int i = 1;
            for (auto &[k, v] : lists)
            { if (id == v.id) {
                    cout << v.name << "'s score :" << endl
                         << "\tchinese: " << v.chinese << endl
                         << "\tmath: " << v.math << endl
                         << "\tenglish: " << v.english << endl;
                    return;
                }
                ++i;
            }
            cout << "Didn't find this student, you can insert new data" << endl;
        }

        /* 
         * add a student's infotmation into config file
         */
        void add_student_info(string filename)
        {
            string name, id;
            double chinese, english, math, average_score;

            cout << "Enter new student's id: ";
            cin >> id;

            cout << "Enter new student's name: ";
            cin >> name;

            cout << "Enter new student's chinese score: ";
            cin >> chinese;

            cout << "Enter new student's math score: ";
            cin >> math;

            cout << "Enter new student's english score: ";
            cin >> english;

            // append insteand of overwrite
            ofstream file(filename, std::ios_base::app);

            file << id << " " << name << " " << chinese << " " << math << " " << english << endl;
            file.close();
            cout << "New studnent information added!";
        }

};

/* * split string into to words by blankspace
 */
vector <string> split_string(string test)
{
    vector <string> t;
    string world("");

    for (auto x : test)
    {
        if (x == ' ')
        {
            t.push_back(world);
            world = "";
        }
        else
        {
            world += x;
        }
    }
    if (test[-1] != ' ')
    {
        t.push_back(world);
    }

    return t;
}

/*
 * read file and save data
 */
void read_file(string file_name, string &line, vector <string> &info, map <double, Student> &lists)
{
    ifstream file(file_name);
    // open student information config file
    if(file.is_open())
    {
        while(getline(file, line))
        {
            info = split_string(line);
            Student list(info[0], info[1], stod(info[2]), stod(info[3]), stod(info[4]));
            lists.insert({list.average_score, list});
        }
        file.close();
    }
}

#endif
