/* Citation and Sources...
Final Project Milestone 2 
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
2020/7/16  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds{
    class IOAble{
        public:
        virtual std::ostream &csvWrite(std::ostream &ostr) const = 0;
        virtual std::istream &csvRead(std::istream &istr) = 0;
        virtual std::ostream &write(std::ostream &ostr) const = 0;
        virtual std::istream &read(std::istream &istr) = 0;
        virtual ~IOAble() {};
    };

    std::ostream &operator<<(std::ostream &ostr, const IOAble &IO);
    std::istream &operator>>(std::istream &istr, IOAble &IO);
}

#endif // !SDDS_IOABLE_H_