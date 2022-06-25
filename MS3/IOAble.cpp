/* Citation and Sources...
Final Project Milestone 3 
Module: Utils
Filename: Utils.cpp
Version 1.0
Author Rajbeer Sokhi
Student id: 124969205
Email: rsokhi1@myseneca.ca
Section: NAA
Revision 1.0
-----------------------------------------------------------
Date      Reason
2020/7/23 Created the patient module  
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include<iostream>
#include"IOAble.h"
namespace sdds{
    std::ostream& operator<<(std::ostream &ostr, const IOAble &IO){
        return IO.write(ostr);
    }
    
    std::istream& operator>>(std::istream &istr, IOAble &IO) 
    {
        return IO.read(istr);
    }

} // namespace sdds
