#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "A1.h"

// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Honeycutt


GPA student[100];   // create the class object array

int classObjects(GPA student[100])
{
    std::ifstream file;

    std::string id = " ";
    int gradePoints = 0;
    int creditHours = 0;
    int i = 0;
    

    file.open("students.txt");  // open file

    while(!(file.eof()))    // while not at the end of file, grab ID, gradePoints, and creditHours
    {                       // then push the student info into a class object
        file >> id >> gradePoints >> creditHours;
        student[i] = GPA(id, gradePoints, creditHours, 0, ' ');

        i++;    // increment i
    } 

    file.close();   // close file

    return i;
}



void bubbleSort(GPA student[])
{
    int n = 30;
    bool swapped;

    for(int i = 0; i < n; i++)
    {
        swapped = false;
        for(int j = i+1; j < n; j++)
        {
            if(student[i].getGPA() < student[j].getGPA())
            {
                //swap(student[i].getGPA(), student[j].getGPA() );
                GPA temp = student[i];
                student[i] = student[j];
                student[j] = temp; 
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }

    }
}

int main()
{
    int i = classObjects(student);  // grab i from classObjects method

    bubbleSort(student);

    for(int var = 0; var < i; var++)    // use i to print all of student info from object array
    {    

        student[var].printInfo();
    } 



    return 0;   
} 