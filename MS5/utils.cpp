/* Citation and Sources...
Final Project Milestone 5
Module: utils
Filename: utils.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int strLen(const char* s){  
      int i,count=0;
      for(i=0;s[i]!='\0';i++){
            count++;
      }
      return count;
   }

   void strCpy(char* des, const char* src){
      int i;
      for(i=0; src[i]!= '\0';i++){
          des[i] = src[i];
      }
      des[i] = '\0';
  }
   
   int getInt(const char* prompt){
      int input;
      char buffer;
      bool flag = false;
      if (prompt){
         cout<<prompt;
      }
      do{
         cin >> input;
         if(!cin){
            cout<<"Bad integer value, try again: ";
            cin.clear();
            cin.ignore(10000,'\n');
         }
         else{
            cin.get(buffer);
            if(buffer != '\n'){
               cout << "Enter only an integer, try again: ";
               cin.clear();
               cin.ignore(10000, '\n');
            }
            else{
               flag = true;
            }
         }
      } while(!flag);
      return input;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError){
      int input;
      char buffer;
      bool flag = false;
      if (prompt){
         cout<<prompt;
      }
      do{
         cin >> input;
         if(!cin){
            cout<<"Bad integer value, try again: ";
            cin.clear();
            cin.ignore(10000,'\n');
         }
         else{
            cin.get(buffer);
            if(buffer != '\n'){
               cout << "Enter only an integer, try again: ";
               cin.clear();
               cin.ignore(10000, '\n');
            }
            else if(input < min || input > max){
               if(errorMessage){
                  cout<<errorMessage;
               }
               if(showRangeAtError){
                  cout<<"["<<min<<" <= value <= "<<max<<"]: ";
               }
            }
            else{
               flag = true;
            }
         }
      } while(!flag);
      return input;
   }
   
   char* getcstr(const char* prompt, std::istream& istr, char delimiter){
      char temp[1000];
      char* str;
      if (prompt){
         cout<<prompt;
      }
      istr.getline(temp,1000,delimiter);

      str = new char[strLen(temp) + 1];
      strCpy(str,temp);
      return str;
   }
}