#include "Student.h"
#include "Course.h"

namespace PA3{

    //default constructor
    Student::Student() : Student(-1, "") {
        /*Intentionally empty*/
    }

    //my old default constructor
    /*Student::Student() {
        string defaultString = "";

        Student(-1, defaultString);
    }*/

    // two parameter constructor that create new reference course array and set the rest of that with default
    Student::Student(long ID, string name) : name(name), ID(ID), courses(nullptr), numberOfCourses(0), capacity(5) {
        courses = new Course*[capacity];
    }

    Student::~Student() {
        // Remove the student from all courses before deleting the courses dynamic array
        for (int i = 0; i < numberOfCourses; i++) {
            courses[i]->removeStudent(this);
        }
        
        // delete the courses dynamic array
        delete[] courses;

    }


    //basically getter and setter properly
    long Student::getID() const {return ID;}

    void Student::setID(long ID) {
        this->ID = ID;
    }

    string Student::getName() const {return name;}

    void Student::setName(string name) {
        this->name = name;
    }

    void Student::addCourse(Course* course) {
        ///if the course exceed the capacity, increase that
        if (numberOfCourses >= capacity) {
            // double the capacity
            capacity *= 2;
            Course** temp = new Course*[capacity];
            //copying the old capacity to new one
            for (int i = 0; i < numberOfCourses; i++) {
                temp[i] = courses[i];
            }
            //delete the old course
            delete[] courses;
            courses = temp;
        }
        //either after increasing capacity or not, add the course to student
        courses[numberOfCourses] = course;

        numberOfCourses++;
    }

    void Student::removeCourse(Course* course) {

        int i;
        //find the course
        for (i = 0; i < numberOfCourses; i++) {
            if (courses[i] == course) {
                break;
            }
        }

        //after it found shift rest of that
        while (i < numberOfCourses - 1){
            courses[i] = courses[i + 1];

            i++;
        }

        //because we shift the rest of that, there is one excess that we should set nullptr
        courses[numberOfCourses - 1] = nullptr;
        numberOfCourses--;

    }

    //display function to display the student
    int Student::display() const {
        int i = 0;

        for (i = 0; i < numberOfCourses; i++) {
            cout << i + 1 << " " << courses[i]->getName() << " (" << courses[i]->getCode() << ")" << endl;
        }

        return i + 1;
    }

    //this functions take a reference of course and whether check thee course in student or not
    //if it is in, returns 1 otherwise returns 0
    bool Student::isInStudentCourses(Course* course){
        for(int i = 0; i < numberOfCourses; i++){
            if(courses[i] == course)
                return 1;
        }

        return 0;
    }

}