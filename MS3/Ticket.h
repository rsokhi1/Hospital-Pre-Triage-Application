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
#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
namespace sdds {
   class Ticket:public IOAble{
      Time m_time;
      int m_number;
   public:
      Ticket(int number);
      operator Time()const;
      int number()const;
      void resetTime();
      std::ostream& csvWrite(std::ostream& ostr)const;
      std::istream& csvRead(std::istream& istr);
      std::ostream& write(std::ostream& ostr )const;
      std::istream& read(std::istream& istr);
   };
}
#endif // !SDDS_TICKET_H_
