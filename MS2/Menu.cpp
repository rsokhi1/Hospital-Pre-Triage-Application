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