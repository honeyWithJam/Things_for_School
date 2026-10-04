#include <iostream>
#include <iomanip>
#include <string>

// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

class GPA
{
    public:
        GPA(); //Default Constructor

        GPA(std::string id, int gradePoints, int creditHours, double gpa, char letterGrade); //Non-Default Constructor

        ~GPA(); // Destructor
                // there will never be more or less Deconstructors!!!!
                // the Deconstructor will never have any perameters!!!!

        void setID(std::string id); // setters
        void setgradePoints(int gradePoints);
        void setcreditHours(int creditHours);
        void setGPA(double gpa);
        void setLetterGrade(char letterGrade);

        std::string getID();    // accessor
        int getGradePoints();   // accessor
        int getCreditHours();   // accessor
        double getGPA();
        char getLetterGrade();

        void printInfo();   //to string method

    private:
        std::string id_; 
        int gradePoints_, creditHours_;
        double gpa_;
        char letterGrade_;
};