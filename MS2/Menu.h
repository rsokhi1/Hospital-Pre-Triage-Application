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
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
namespace sdds{
    class Menu{
      char* m_text; 
      int m_noOfSel;
      void display()const;
    public:
      Menu(const char* MenuContent, int NoOfSelections);
      virtual ~Menu();
      int& operator>>(int& Selection);
      // add safe copying logic
   };

}
#endif // !SDDS_MENU_H_