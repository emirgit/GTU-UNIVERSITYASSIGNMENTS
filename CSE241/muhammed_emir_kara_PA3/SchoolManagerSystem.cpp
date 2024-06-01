#ifndef _SCHOOLMANAGERSYSTEM_
#define _SCHOOLMANAGERSYSTEM_

#include "SchoolManagerSystem.h"


namespace PA3 {

    //default constsructor sets the instances variable with default value and initiliaze the double pointers 
    SchoolManagerSystem::SchoolManagerSystem() : students(nullptr), numberOfStudents(0), capacityOfStudents(5), courses(nullptr), numberOfCourses(0), capacityOfCourses(5) {
        students = new Student*[capacityOfStudents];
        courses = new Course*[capacityOfCourses];
    }

    SchoolManagerSystem::~SchoolManagerSystem() {
        // Delete all students (my destructor worked)
        for (int i = 0; i < numberOfStudents; ++i) {
            delete students[i];
        }

        //delete the dynamic student array in SchoolManagerSystem
        delete[] students;
        students = nullptr;

        // Delete all courses (my destructor worked)
        for (int i = 0; i < numberOfCourses; ++i) {
            delete courses[i];
        }

        //delete the dynamic course array in SchoolManagerSystem
        delete[] courses;
        courses = nullptr;
    }

    // addStudent with the same logic Student.cpp and Course.cpp
    void SchoolManagerSystem::addStudent(const long ID, const string name){
        if (numberOfStudents >= capacityOfStudents) {
            
            capacityOfStudents *= 2;
            Student** temp = new Student*[capacityOfStudents];
            for (int i = 0; i < numberOfStudents; i++) {
                temp[i] = students[i];
            }
            delete[] students;
            students = temp;
        }

        // the only difference is creating new object and keep the reference of that
        //it is real to create Student
        students[numberOfStudents] = new Student(ID, name);
        numberOfStudents++;

    }


    void SchoolManagerSystem::deleteStudent(const long ID){
        int i;

        //find the student that is given Id
        for (i = 0; i < numberOfStudents; i++) {
            if (students[i]->getID() == ID) {
                //delete it
                delete students[i];
                break;
            }
        }

        // shift the rest of that
        while (i < numberOfStudents - 1){
            students[i] = students[i + 1];
            i++;
        }

        //put the nullptr instead of removed Student
        students[numberOfStudents - 1] = nullptr;
        numberOfStudents--;
    }

    void SchoolManagerSystem::enrollStudent(const long ID) {
        int i, studentI, index;

        //find the student
        for (int i = 0; i < numberOfStudents; i++) {
            if (students[i]->getID() == ID) {
                studentI = i;
                break;
            }
        }

        //printing the lecture that Students doesn't take
        index = 0;
        for (int i = 0; i < numberOfCourses; i++) {
            if(!(students[studentI]->isInStudentCourses(courses[i]))){
                cout << index + 1 << " " << courses[i]->getCode() << " " << courses[i]->getName() << endl;
                index++;
            }
        }

        // take input from user 
        int input = checkInput(0, index + 1, 0);

        //if input is not zero (that' mean not go back in menu)
        if (input != 0){
            //input supposed to array starts from 1 but it is not like that 
            // decrease by one
            input -= 1;
            index = 0;

            //find the same index in the output end add course to student simultaneously
            for (int i = 0; i < numberOfCourses; i++) {
                if(index == input){
                    students[studentI]->addCourse(courses[i]);
                    courses[i]->addStudent(students[studentI]);
                    break;
                }

                if(!(students[studentI]->isInStudentCourses(courses[i]))){
                    index++;
                }
            }
        }
    }

    void SchoolManagerSystem::unenrollStudent(const long ID) {
        int studentI, index;

        //find the student
        for (int i = 0; i < numberOfStudents; ++i) {
            if (students[i]->getID() == ID) {
                studentI = i;
                break;
            }
        }

        //display the student's enrolled to course
        index = students[studentI]->display();


        //select one
        int input = checkInput(0, index , 0);

        //if it is not zero, unenroll the student from the course
        if (input != 0){
            input -= 1;
            index = 0;
            for (int i = 0; i < numberOfCourses; i++) {
                if(index == input){
                    students[studentI]->removeCourse(courses[i]);
                    courses[i]->removeStudent(students[studentI]);
                }

                if(!(students[studentI]->isInStudentCourses(courses[i]))){
                    index++;
                }
            }
        }  
    }


    //add course with the same logic addStudent
    void SchoolManagerSystem::addCourse(const string name, const string code) {
        if (numberOfCourses >= capacityOfCourses) {
            // Increase capacity by doubling it
            capacityOfCourses *= 2;
            Course** temp = new Course*[capacityOfCourses];
            for (int i = 0; i < numberOfCourses; i++) {
                temp[i] = courses[i];
            }
            delete[] courses;
            courses = temp;
        }
        courses[numberOfCourses] = new Course(code, name);

        numberOfCourses++;
    }

    //deleteCourse with the same logic with deleteStudent
    void SchoolManagerSystem::deleteCourse(const string code){
        int i;

        for (i = 0; i < numberOfCourses; i++) {
            if (courses[i]->getCode() == code) {
                delete courses[i];
                break;
            }
        }

        while (i < numberOfCourses - 1){
            courses[i] = courses[i + 1];

            i++;
        }

        courses[numberOfCourses - 1] = nullptr;
        numberOfCourses--;
    }

    // listing all enrolled students to lectur by using the method in course
    void SchoolManagerSystem::listAllEnrolledStudents(const string code){
        for (int i = 0; i < numberOfCourses; ++i) {
            if (courses[i]->getCode() == code) {
                courses[i]->display();
                break;
            }
        }
    }

    //listing all student by using getter and setters
    void SchoolManagerSystem::listAllStudents(){
        cout << "All Students in Manager System are" << endl;
        for (int i = 0; i < numberOfStudents; i++) {
            cout << i + 1 << " Name: " << students[i]->getName() << " ID: " << students[i]->getID() << endl;
        }
    }

    //listing all courses by using getter and setters
    void SchoolManagerSystem::listAllCourses(){
        cout << "All Courses in Manager System are" << endl;
        for (int i = 0; i < numberOfCourses; i++) {
            cout << i + 1 << " Name: " << courses[i]->getName() << " Code:" << courses[i]->getCode() << endl;
        }
    }

    //recursive menu that takes 2 parameter first for make the function recursive
    //second one the input from main

    /*
    the recursive algorithm

    
    1   -> 11   -> 111
                -> 112
        
        -> 12
    
    when the digits added, it means it is submenus of the previous menus
    112 means
    main -> 1. submenu -> 2. submenu of 1. submenu

    it uses checkInput function
    that implements the logic


    stol() functions is a function to convert string to long 
    I use long to find the students in SchoolManagerSstem

    if user selects a student or course
    it needs to fill the reference of main to trasmit the data to other submenus

    */
    void SchoolManagerSystem::menu(int submenu, string& userInput){
        if (submenu == 0){
            return;
        }

        switch (submenu)
        {
        // Main menu
        case 1:
            cout << "Main_menu\n0 exit\n1 student\n2 course\n3 list_all_students\n4 list_all_courses";

            submenu = checkInput(0, 4, submenu);

            break;
        // Student
        case 11:
            cout 
            << "    0 up\n"
            << "    1 add_student\n"
            << "    2 select_student ";
            submenu = checkInput(0, 2, submenu);

            if (submenu == 112)
                takeUsersStudent(userInput);

                
            break;
        
        // Course
        case 12:
            cout 
            << "    0 up\n"
            << "    1 add_course\n"
            << "    2 select_course";
            submenu = checkInput(0, 2, submenu);

            if (submenu == 122)
                takeUsersCourse(userInput);

            break;

        //list all student
        case 13:
            listAllStudents();
            submenu = 1;

        break;
        //list all course
        case 14:
            listAllCourses();
            submenu = 1;
            break;
        
        
        case 111:
            submenu = 11;
            takeStudent();
            //add just student
            break;

        //Menu Select student
        case 112:
            cout 
            << "        0 up\n"
            << "        1 delete_student\n"
            << "        2 add_selected_student_to_a_course\n"
            << "        3 drop_selected_student_from_a_course";
            submenu = checkInput(0, 3, submenu);
            break;

        // add course
        case 121:
            submenu = 12;
            takeCourse();
            break;

        // Menu Select Course
        case 122:
            cout 
            << "        0 up\n"
            << "        1 delete_course\n"
            << "        2 list_students_registered_to_selected_course";
            submenu = checkInput(0, 2, submenu);
            break;

        case 1121:
            submenu = 11;
            //delete student
            deleteStudent(stol(userInput));
            break;
        case 1122:
            //add_selected_student_to_a_course
            cout << "0 up\n";
            enrollStudent(stol(userInput));
            submenu = 112;
            break;
        case 1123:
            //drop_selected_student_from_a_course
            cout << "0 up\n";
            unenrollStudent(stol(userInput));

            submenu = 112;

            break;
        case 1221:
            submenu = 12;
            //delete course
            deleteCourse(userInput);
            break;
        case 1222:
            submenu = 122;
            //list students registered to selected course
            listAllEnrolledStudents(userInput);
            break;

        default:
            submenu = 0;
            break;
        }

        menu(submenu, userInput);
    }

    int SchoolManagerSystem::checkInput(int start, int end, int submenu){
        int input = 0;
        bool flag;
        // if input is not in the range, force user to input correct one
        do {
            cout << "\n>> ";
            cin >> input;
            flag = (input < start || input > end);
            if (flag){
                cout << "Please input correcty by the menu \n";
            }
        } while(flag);

        //if input is 0, go back by dividing itself by 10 
        //if it is 11, it will return the main menu that is 1
        //else multiply that by 1 and add input to decide submenus
        if (input == 0)
            submenu = submenu / 10;
        else
            submenu = submenu * 10 + input;

        return submenu;
    }

    //the rest functions use same logic by the input according to pdf
    void SchoolManagerSystem::takeUsersStudent(string& userInput){
        //User will input name and ID respectivelly
        //clear the buffer becuase getline() takes the datas from terminal until see new line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ">> ";
        getline(cin, userInput);

        // the last is ID so find last space character
        size_t lastOccur = userInput.find_last_of(' ');

        //put ID to reference to trasmit it to submenus
        userInput = userInput.substr(lastOccur + 1);


    }

    //it uses the same logic 
    void SchoolManagerSystem::takeUsersCourse(string& userInput){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ">> ";
        getline(cin, userInput);

        size_t lastOccur = userInput.find_first_of(' ');

        userInput = userInput.substr(0, lastOccur);

    }

    //it uses same logic, but It will used to find name and ID
    //so pass this argument directly addStudent() instead of transmitting
    void SchoolManagerSystem::takeStudent(){
        string userInput;
    

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ">> ";
        getline(cin, userInput);

        size_t lastOccur = userInput.find_last_of(' ');

        string name = userInput.substr(0, lastOccur);
        string ID = userInput.substr(lastOccur + 1);

        addStudent(stol(ID), name);
    }

    //it uses same logic, but It will used to find name and code
    //so pass this argument directly addStudent() instead of transmitting
    void SchoolManagerSystem::takeCourse(){
        string userInput;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ">> ";
        getline(cin, userInput);

        size_t lastOccur = userInput.find_first_of(' ');

        string code = userInput.substr(0, lastOccur);
        string name = userInput.substr(lastOccur + 1);

        addCourse(name, code);
    }    

}

#endif