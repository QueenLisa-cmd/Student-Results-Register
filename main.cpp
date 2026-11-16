#include<iostream>
#include"Student.h"
#include"DynamicArray.h"

int main()
{
    DynamicArray<Student>students;

    Student student1 = {
        "VU2026001",
        "John Mukaasa",
        "Computer Science",
        85
    };

    Student student2 ={
        "VU2026002",
        "Sarah Namuli",
        78
    };

    Student student3 ={
     "VU2026003",
     "Peter Okello",
     "Business Administration",
     92   
    };

    students.add(student1);
    students.add(student2);
    students.add(student3);

    std::cout<"\nNumber of students:"
    <<students.size()<<'\n';

    std::cout<<"Array capacity:"
    <<sudents.capacity()<<'\n';

    int position = students.findIndex(student2);

    if(position !=-1)
    {
        std::cout<<"\nStudent found at position:"
        <<position<<'\n';

    }

    else
    {
        std::cout<<"\nStudent not found.\n";

    }
    students.removeAt(1);

    std::cout<<"\n---AFTER REMOVING A STUDENT ---\n";
    students.display();

    if(students.saveToFile("students.txt"))
    {
        std::cout<<"\nRecords saved successfully.\n";

    }
    else
    {
        std::cout<<"\nFailed to save records.\n";

    }
    return 0;

}