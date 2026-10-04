#include "A1.h"

// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt

GPA::GPA()
{
    id_ = " ";
    gradePoints_ = 0;
    creditHours_ = 0; 
    gpa_ = 0.0;
    letterGrade_ = ' ';
}

GPA::~GPA()
{

}

void GPA::setID(std::string id)
{
    id_ = id;
}

void GPA::setgradePoints(int gradePoints)
{
    gradePoints_ = gradePoints;
}

void GPA::setcreditHours(int creditHours)
{
    creditHours_ = creditHours;
}

void GPA::setGPA(double gpa)
{
    gpa_ = gpa;
}

void GPA::setLetterGrade(char letterGrade)
{
    letterGrade_ = letterGrade;
}


GPA::GPA(std::string id, int gradePoints, int creditHours, double gpa, char letterGrade)
{
    id_ = id;
    gradePoints_ = gradePoints;
    creditHours_ = creditHours;
    gpa_ = gpa;
    letterGrade_ = letterGrade;
}

std::string GPA::getID()
{
    return id_;
}

int GPA::getGradePoints()
{
    return gradePoints_;
}

int GPA::getCreditHours()
{
    return creditHours_;
}
double GPA::getGPA()
{
    gpa_ = (double) gradePoints_/ (double)creditHours_;
    return gpa_;
}

char GPA::getLetterGrade()
{
    if( gpa_> 3.70)
    {
        setLetterGrade('A');
    }
    else if( gpa_>= 2.7)
    {
        setLetterGrade('B');
    }
    else if( gpa_>= 1.7)
    {
        setLetterGrade('C');
    }
    else if( gpa_>= .70)
    {
        setLetterGrade('D');
    }
    else
    {
        setLetterGrade('F');
    }
    return letterGrade_;
}

void GPA::printInfo()
{
        std::cout << "ID: " << getID();
        std::cout << " Grade Points : " << getGradePoints();
        std::cout << " Credit Hours: " << getCreditHours();
        std::cout << " GPA : " << std::fixed << std::setprecision(2) << getGPA();
        std::cout << " Letter Grade: " << getLetterGrade() << std::endl;
}   