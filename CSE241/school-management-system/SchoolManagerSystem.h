#ifndef _SCHOOLMANAGERSYSTEM_H_
#define _SCHOOLMANAGERSYSTEM_H_

#include "Student.h"
#include "Course.h"
// for <streamsize>
#include <ios>
 
// for numeric_lim
#include <limits>

namespace PA3 {


    class SchoolManagerSystem{
        /*
        two double pointer array to store references of students and courses in system management
        capacity to increase the capacity in case of exceed
        numberOf to count the objects
        
        */
        private:
            Student** students;
            int numberOfStudents;
            int capacityOfStudents;
            Course** courses;
            int numberOfCourses;
            int capacityOfCourses;
        public:
        //constructor and destructor
            SchoolManagerSystem(); //Completed
            ~SchoolManagerSystem(); //Completed

            //the whole features in pdf and menu
            void addStudent(const long ID, const string name); //Completed
            void deleteStudent(const long ID); //Completed
            void enrollStudent(const long tID); //Completed
            void unenrollStudent(const long ID); //Completed

            void addCourse(const string name, const string code); //Completed
            void deleteCourse(const string code); //Completed
            void listAllEnrolledStudents(const string code); //Completed

            void listAllStudents(); //Completed
            void listAllCourses(); //Completed

            //for menu
            void menu(int submenu, string& userInput);
            void takeStudent();
            void takeCourse();
            void takeUsersStudent(string& userInput);
            void takeUsersCourse(string& userInput);
            int checkInput(int start, int end, int submenu);
            

    }; 
}


#endif