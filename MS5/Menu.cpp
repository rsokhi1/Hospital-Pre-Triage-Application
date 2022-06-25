/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds{
    void Menu::display() const{
        cout<<m_text<<endl;
        cout<<"0- Exit"<<endl;
    }

    Menu::Menu(const char* MenuContent, int NoOfSelections){
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text,MenuContent);
        m_noOfSel = NoOfSelections;
    }
    
    Menu::~Menu(){
        delete [] m_text;
        m_text = nullptr;
    }
    
    int& Menu::operator>>(int& Selection){
        display();
        Selection = getInt(0,m_noOfSel,"> ","Invalid option ",true);
        return Selection;
    }


}