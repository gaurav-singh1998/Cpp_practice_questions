#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string firstname;
    string lastname;
    int roll_no;
    Student(string f, string l, int no): firstname(f), lastname(l), roll_no(no)
    {}

    bool operator ==(const Student &s) const
    {
        return this->roll_no == s.roll_no?true: false;
    }
};

class HashFn
{
    public:
    size_t operator()(const Student &s) const
    {
        return s.firstname.length() + s.firstname.length();
    }
};


int main()
{
    unordered_map<Student, int, HashFn> student_map;
    Student s1("prateek", "narang", 10);
    Student s2("rahul", "kumar", 23);
    Student s3("prateek", "narang", 30);
    Student s4("rahul", "kumar", 120);

    student_map[s1]=13;
    student_map[s2]=15;
    student_map[s3]=20;
    student_map[s4]=24;

    for(auto s: student_map)
    {
        cout << s.first.firstname << "-->" << s.first.roll_no << " Marks " << s.second << endl;
    }

}