#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <string>

using namespace std;

class Employee
{
private:
    int findSize(string name)
    {
        string temp;
        fstream ReadFile(name);
        int i = 0;
        while (getline(ReadFile, temp))
        {
            i++;
        }
        return i;
    }

public:
    string Emp_id;
    string Emp_name;
    vector<Employee> temp;
    int pay;
    Employee() {}
    Employee(string a, string b, int c)
    {
        this->Emp_id = a;
        this->Emp_name = b;
        this->pay = c;
    }
    void getData(string filename)
    {
        int n = findSize(filename);  // Finds the number of records in the file.
                                               // Creates a vector of objects Employees;
        string text;                           // Stores the value of each record;
        ifstream ReadFile("Employee_inp.txt"); // Reads the whole file;
        char split = ',';                      // The tokenizer that will be used to differentiate the different fields in the record;
        string out;                            // The value that will be stored for every value in a record;
        int iteration;                         // counts the which value/ word in a line it is reading
        string first, second;                  // The Parameters for the constructor for an employee.
        int third;
        for (int i = 0; i < n; i++)
        {
            iteration = 0;
            while (getline(ReadFile, text) && iteration <= 3)
            {                    // Checks if there is data in the current line
                string out = ""; // initially no word has been read;
                first = "";
                second = "";
                third = 0;
                for (int j = 0; j <= text.size(); j++)
                { // Traverses through the whole line;
                    if (text[j] != split && text[j] != '\0')
                    { // Add characters until the tokenizer is met;
                        out += text[j];
                    }
                    else
                    { // Once the tokenizer is met, the characters read till now is stored;
                        iteration++;
                        switch (iteration) // Based on the current word respective parameter is stored;
                        {
                        case 1:
                            first = out;
                            out = "";
                            break;
                        case 2:
                            second = out;
                            out = "";
                            break;
                        case 3:
                            third = stoi(out);
                            out = "";
                        default:
                            break;
                        }
                    }
                }
                this->temp.push_back(Employee(first, second, third)); // Make an object of the class and store in the vector
                break;
            }
        }
    }
    void putData(string filename)
    {   ofstream fout;
        fout.open(filename, ios ::app);
        fout << "EMPLOYEE DETAILS : " << endl;
        for (Employee &e1 : this->temp)
        {
            fout << e1.Emp_id << " " << to_string(e1.pay) << endl;
        }
        fout.close();
    }
    void listData()
    {  
        cout << "The Employee details are : " << endl;

        for (Employee &e1 : this->temp)
        {
            cout << e1.Emp_id << " " << to_string(e1.pay) << endl;
        }
    }

};
class Instructor : public Employee
{
private:
    int findSize(string name)
    {
        string temp;
        fstream ReadFile(name);
        int i = 0;
        while (getline(ReadFile, temp))
        {
            i++;
        }
        return i;
    }

public:
    vector<Instructor> temp2;
    string course;
    Instructor() {}
    Instructor(string a, string b)
    {
        this->course = a;
        this->Emp_id = b;
        for (Employee &e : this->temp)
        {
            if (a == e.Emp_id)
            {
                this->pay = e.pay;
            }
        }
    }
    void getData(string filename)
    {
        int n = findSize(filename);  // Finds the number of records in the file.
                                                 // Creates a vector of objects Employees;
        string text;                             // Stores the value of each record;
        ifstream ReadFile("Instructor_inp.txt"); // Reads the whole file;
        char split = ',';                        // The tokenizer that will be used to differentiate the different fields in the record;
        string out;                              // The value that will be stored for every value in a record;
        int iteration;                           // counts the which value/ word in a line it is reading
        string first, second;                    // The Parameters for the constructor for an employee.
        int third;
        for (int i = 0; i < n; i++)
        {
            iteration = 0;
            while (getline(ReadFile, text) && iteration <= 2)
            {                    // Checks if there is data in the current line
                string out = ""; // initially no word has been read;
                first = "";
                second = "";
                third = 0;
                for (int j = 0; j <= text.size(); j++)
                { // Traverses through the whole line;
                    if (text[j] != split && text[j] != '\0')
                    { // Add characters until the tokenizer is met;
                        out += text[j];
                    }
                    else
                    { // Once the tokenizer is met, the characters read till now is stored;
                        iteration++;
                        switch (iteration) // Based on the current word respective parameter is stored;
                        {
                        case 1:
                            first = out;
                            out = "";
                            break;
                        case 2:
                            second = out;
                            out = "";
                            break;
                        default:
                            break;
                        }
                    }
                }
                this->temp2.push_back(Instructor(second, first)); // Make an object of the class and store in the vector
                break;
            }
        }
    }
    void putData()
    {
        for (Instructor &i1 : this-> temp2)
        {
            cout << i1.Emp_id << " " <<  i1.course<< endl;
        }
    }
};
class Students
{
private:
    int findSize(string name)
    {
        string temp;
        fstream ReadFile(name);
        int i = 0;
        while (getline(ReadFile, temp))
        {
            i++;
        }
        return i;
    }

public:
    string id;
    string name;
    vector<Students> students; // Creates a vector of objects Employees;
    int fee;
    string courses[3];
    Students() {}
    Students(string a, string b, int c, string c1, string c2, string c3)
    {
        this->id = a;
        this->name = b;
        this->fee = c;
        this->courses[0] = c1;
        this->courses[1] = c2;
        this->courses[2] = c3;
    }
    void getData(string filename)
    {
        int n = findSize(filename); // Finds the number of records in the file.

        string text;                                // Stores the value of each record;
        ifstream ReadFile("Students_inp.txt");      // Reads the whole file;
        char split = ',';                           // The tokenizer that will be used to differentiate the different fields in the record;
        string out;                                 // The value that will be stored for every value in a record;
        int iteration;                              // counts the which value/ word in a line it is reading
        string first, second, fourth, fifth, sixth; // The Parameters for the constructor for an employee.
        int third;
        for (int i = 0; i < n; i++)
        {
            iteration = 0;
            while (getline(ReadFile, text) && iteration <= 6)
            {                    // Checks if there is data in the current line
                string out = ""; // initially no word has been read;
                first = "";
                second = "";
                third = 0;
                for (int j = 0; j <= text.size(); j++)
                { // Traverses through the whole line;
                    if (text[j] != split && text[j] != '\0')
                    { // Add characters until the tokenizer is met;
                        out += text[j];
                    }
                    else
                    { // Once the tokenizer is met, the characters read till now is stored;
                        iteration++;
                        switch (iteration) // Based on the current word respective parameter is stored;
                        {
                        case 1:
                            first = out;
                            out = "";
                            break;
                        case 2:
                            second = out;
                            out = "";
                            break;
                        case 3:
                            third = stoi(out);
                            out = "";
                            break;
                        case 4:
                            fourth = out;
                            out = "";
                            break;
                        case 5:
                            fifth = out;
                            out = "";
                            break;
                        case 6:
                            sixth = out;
                            out = "";
                            break;
                        default:
                            break;
                        }
                    }
                }
                this->students.push_back(Students(first, second, third, fourth, fifth, sixth)); // Make an object of the class and store in the vector
                break;
            }
        }
    }
    void putData(string filename)
    {
        ofstream fout;
        fout.open(filename , ios:: app);
        cout << "Student Details are :";
        for (Students &s1 : this-> students)
        {          
            fout << "Student Details are :" << endl;
            fout << s1.id << " " << s1.name << " " << to_string(s1.fee) << " ["
            << s1.courses[0] << ", " << s1.courses[1] << ", " << s1.courses[2] << "]" << endl;
        }
        fout.close();
    }
    void listData()
    {
        cout << "Student Details are :" << endl;
        for (Students &s1 : this-> students)
        {
            cout << s1.id << " " << s1.name << " " << to_string(s1.fee) << " ["
            << s1.courses[0] << ", " << s1.courses[1] << ", " << s1.courses[2] << "]" << endl;
        }
    }
    string toString(){
        string out = " ";
        out += this->id + this-> name ;
        return out;
    }
};
class TeachingAssistant : public Instructor, public Students
{
public:
    vector<TeachingAssistant> t1;
    TeachingAssistant()
    {
    }
    TeachingAssistant(string a, string c, int d){
        this->Emp_id = a;
        this->Emp_name = c;
        this->pay = d;
    }
    void getData(vector<Employee> emp)
    {
        string a, c;
        int d;
        for (Employee& i : emp)
        {   
            if (i.Emp_id[0] == 'S')
            {
                a = i.Emp_id;
                c = i.Emp_name;
                d = i.pay;
                this->t1.push_back(TeachingAssistant(a, c, d));
                
            }
        }
        
    }
    void listData(){
        cout << "Teaching Assistant Details" << endl;;
        for(TeachingAssistant& t : this-> t1){
            cout << t.Emp_id << " " << t.Emp_name << endl;
        }
    }
    void putData(string filename){
        ofstream fout;
        fout.open(filename, ios:: app);
        fout << "Teaching Assistant Details" << endl;
        for(TeachingAssistant& t : this-> t1){
            fout << t.Emp_id << " " << t.Emp_name << endl;
        }
        fout.close();
    }
    void StudyingOnly(vector<Students> stu){
        ofstream fout;
        fout.open("Output.txt", ios:: app);
        fout << "Students who are not instructors" << endl;
        cout << "Students who are not instructors" << endl;
        bool flag;
        for(Students& s : stu){
            for(TeachingAssistant& t : this-> t1){
                if(t.Emp_id != s.id){
                    flag = false;
                }
                else{
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << s.id << " " << s.name << endl;
                fout << s.id << " " << s.name << endl;
            }
        }
        fout.close();
    }

};

int main( int argc, char** argv){ 
    vector<string> names;
    if(argc != 5){
        cout << argc << endl;
        cout << "Incorrect number of parameters" << endl;
    }
    else{
        for(int i = 1; i < argc; ++i){
            names.push_back(argv[i]);
        }
        Employee e;
        e.getData(names.at(0));
        e.putData(names.at(3));
        e.listData();
        Instructor i;
        i.getData(names.at(1));
        // i.putData()
        Students s;
        s.getData(names.at(2));
        // s.putData();
        TeachingAssistant ta;
        ta.getData(e.temp);
        ta.putData(names.at(3));
        ta.listData();
        ta.StudyingOnly(s.students);
        s.putData(names.at(3));
        s.listData();
    }

   
    return 0;
}
