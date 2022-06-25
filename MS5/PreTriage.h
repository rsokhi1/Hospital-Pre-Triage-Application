/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_
#include "Time.h"
#include "Patient.h"
#include "Menu.h"
namespace sdds {
   const int maxNoOfPatients = 100;
   class PreTriage {
      Time m_averCovidWait, m_averTriageWait;
      Patient *m_lineup[maxNoOfPatients]{};
      char *m_dataFilename = nullptr;
      int m_lineupSize = 0;
      Menu m_appMenu, m_pMenu;
      void reg();
      void admit();
      const Time getWaitTime(const Patient& p)const;
      void setAverageWaitTime(const Patient& p);
      void removePatientFromLineup(int index);
      int indexOfFirstInLine(char type) const;
      void load();
   public:
      PreTriage(const char* dataFilename);
      ~PreTriage();
      void run(void);
   };

}
#endif // !SDDS_PRETRIAGE_H_