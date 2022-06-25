/* Citation and Sources...
Final Project Milestone 4 
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
2020/7/25 Created the CovidPatient module and TriagePatient module  
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <string>
#include "utils.h"
#include "TriagePatient.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket){
      m_symptoms = nullptr;
      nextTriageTicket++;
   }
   
   TriagePatient::~TriagePatient(){
      delete [] m_symptoms;
      m_symptoms = nullptr;
   }
   
   char TriagePatient::type() const{
      return 'T';
   }
   
   std::ostream& TriagePatient::csvWrite(std::ostream &ostr) const{
      Patient::csvWrite(ostr) << ',' <<m_symptoms;
      return ostr;
   }
   
   std::istream& TriagePatient::csvRead(std::istream &istr){
      char comma;
      string temp;
      if(m_symptoms){
         delete[] m_symptoms;
         m_symptoms = nullptr;
      }
      Patient::csvRead(istr);
      istr>>comma;
      getline(istr,temp,'\n');
      m_symptoms = new char[strlen(temp.c_str()) + 1];
      strcpy(m_symptoms,temp.c_str());
      nextTriageTicket = Patient::number() + 1;
      return istr;

   }
   
   std::ostream& TriagePatient::write(std::ostream &ostr) const{
      if(Patient::fileIO()){
         csvWrite(ostr);
      }
      else{
         ostr<<"TRIAGE"<<endl;
         Patient::write(ostr)<<endl;
         ostr<<"Symptoms: "<<m_symptoms<<endl;
      }
      return ostr;
   }
   
   std::istream& TriagePatient::read(std::istream &istr){
      if(Patient::fileIO()){
         csvRead(istr);
      }
      else{
         char *temp;
         if(m_symptoms){
            delete [] m_symptoms;
            m_symptoms = nullptr;
         }
         Patient::read(istr);
         temp = getcstr("Symptoms: ",istr);
         m_symptoms = new char[strlen(temp) + 1];
         strcpy(m_symptoms,temp);
         delete [] temp;
      }
      return istr;
   }


   


}