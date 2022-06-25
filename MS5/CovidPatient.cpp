/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author Rajbeer Sokhi
Student id: 124969205
Email: rsokhi1@myseneca.ca
Section: NAA
Revision 1.0
-----------------------------------------------------------
Date      Reason
2021/8/2 Created the PreTriage module.  
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket){
      nextCovidTicket++;
   }
   
   char CovidPatient::type() const{
      return 'C';
   }
   
   std::istream& CovidPatient::csvRead(std::istream &istr){
      Patient::csvRead(istr);
      nextCovidTicket = Patient::number() + 1;
      istr.ignore();
      return istr;
   }
   
   std::ostream& CovidPatient::write(std::ostream &ostr) const{
      if(Patient::fileIO()){
         Patient::csvWrite(ostr);
      }
      else{
         ostr<<"COVID TEST"<<endl;
         Patient::write(ostr)<<endl;
      }
      return ostr;
   }
   
   std::istream& CovidPatient::read(std::istream &istr){
      if(Patient::fileIO()){
         csvRead(istr);
      }
      else{
         Patient::read(istr);
      }
      return istr;
   }

}