#ifndef _COURSE_
#define _COURSE_

#include "Course.h"
#include "Student.h"

//putting all methods in namespace
namespace PA3 {

    //default constructer that call the 2 parameter constructoor
    Course::Course() : Course("CODE101", "") {
        /*Intentionally empty*/
    }

    // two parameter constructor that create new reference student array and set the rest of that with default
    Course::Course(string code, const string name) : code(code), name(name), students(nullptr), numberOfStudents(0), capacity(5) {
        students = new Student*[capacity];
    }

    Course::~Course() {
        // Remove the course from all students' courses before deleting the students dynamic array
        for (int i = 0; i < numberOfStudents; i++) {
            students[i]->removeCourse(this);
        }

        // Now, delete the students array
        delete[] students;
    }

    //basically getter and setters
    string Course::getCode() const{return code;}
    void Course::setCode(string code){
        this->code = code;
    }

    string Course::getName() const{return name;}
    void Course::setName(string name){
        this->name = name;
    }


    void Course::addStudent(Student* student) {
        //if the student exceed the capacity 
        if (numberOfStudents >= capacity) {
            cout << numberOfStudents << " " << capacity;
            // double the capacity
            capacity *= 2;
            Student** temp = new Student*[capacity];
            //copying the old capacity to new one
            for (int i = 0; i < numberOfStudents; i++) {
                temp[i] = students[i];
            }
            //delete the old students array
            delete[] students;
            students = temp;
        }
        //either after increasing capacity or not, add the student to course
        students[numberOfStudents] = student;

        numberOfStudents++;
    }

    void Course::removeStudent(Student* student) {
        
        int i;
        //finding the student
        for (i = 0; i < numberOfStudents; i++) {
            if (students[i] == student)
                break;
        }

        //shifting the rest of that
        while (i < numberOfStudents - 1){
            students[i] = students[i + 1];

            i++;
        }

        // because of removing the student, put nullptr 
        students[numberOfStudents - 1] = nullptr;
        numberOfStudents--;
    }

    //display print the course and enrolled students student by student
    void Course::display() const{
        cout << "Name: " << name << ", Code: " << code << endl;
        cout << "Enrolled Students:" << endl;
        for (int i = 0; i < numberOfStudents; i++) {
            cout << i + 1 << " " << students[i]->getName() << " " << students[i]->getID() << endl;
        }
    }

}


#endif