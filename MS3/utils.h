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
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   extern bool debug; // making sdds::debug variable global to all the files
                      // which include: "utils.h"
   

   int getTime(); // returns the time of day in minutes

   int strLen(const char* s);

   void strCpy(char* des, const char* src);

   int getInt(const char* prompt = nullptr);

   int getInt(int min, int max, const char* prompt = nullptr,
          const char* errorMessage = nullptr, bool showRangeAtError = true);

   char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');


}
#endif // !SDDS_UTILS_H_

