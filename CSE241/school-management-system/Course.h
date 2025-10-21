#ifndef _COURSE_H_
#define _COURSE_H_

#include<string>
#include<iostream>
using namespace std;


namespace PA3 {
    class Student;

    class Course{
        private:
        /*
        my private instance variable
        code to store code of course
        name for the name of the course
        double pointer courses to keep the reference of the students
        numberOfStudents to count the students enrolled the course
        capacity to check the capacity of students reference array
        */
            string code;
            string name;
            Student** students;
            int numberOfStudents;
            int capacity;
        
        public:
        //constructors and destructors
            Course();
            Course(string code, string name);
            ~Course();
            //getters and setters
            string getCode() const;
            void setCode(string code);

            string getName() const;
            void setName(string name);

            // adding course and removing course to enrool or unenroll the student
            void addStudent(Student* student);
            void removeStudent(Student* student);

            //display to print the course to terminal
            void display() const;

    };   
}


#endif