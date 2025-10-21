#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<string>
#include<iostream>
using namespace std;


namespace PA3 {
    class Course;

    class Student{
        /*
        my private instance variable
        ID to store ID of students
        name for the name of the students
        double pointer courses to keep the reference of the courses
        numberOfCourses to count the students' courses that he enrolled
        capacity to check the capacity of courses reference array
        */
        private:
            long ID;
            string name;
            Course** courses;
            int numberOfCourses;
            int capacity;
        
        public:
            //constructors and destructors
            Student();
            Student(long ID, string name); 
            ~Student();

            //getters and setters
            long getID() const;
            void setID(long ID);

            string getName() const;
            void setName(string name);

            // adding course and removing course to enrool or unenroll the student
            void addCourse(Course* course);
            void removeCourse(Course* course);

            //display to print student to terminal
            //isStudent is an auxilary function for enroll method in SchoolManagerSystem
            bool isInStudentCourses(Course* course);
            int display() const;

    };

}


#endif