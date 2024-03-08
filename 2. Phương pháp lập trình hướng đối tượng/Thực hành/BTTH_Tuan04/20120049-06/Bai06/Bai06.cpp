#include <iostream>
#include "Student.h"
int main()
{
    ArrayStudent arrStd("Student.csv");
    arrStd.SortByLName();
    arrStd.writeXML("Student.xml");
    return 0;
}