/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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
#include <string>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds{
    Patient::Patient(int ticket,bool flag){
        m_ticket = ticket;
        m_IOflag = flag;
        
    }
    
    Patient::~Patient(){
        if(m_name){
            delete [] m_name;
            m_name = nullptr;
        }
    }

    const bool Patient::fileIO() const{
        return m_IOflag;
    }
    
    void Patient::fileIO(bool IO_flag){
        m_IOflag = IO_flag;
    }
    
    bool Patient::operator==(const char singleChar) const{
        return this->type() == singleChar;
    }
    
    bool Patient::operator==(const Patient &P) const{
        return this->type() == P.type();
    }
    
    void Patient::setArrivalTime(){
        m_ticket.resetTime();
    }
    
    Patient::operator Time() const{
        return Time(m_ticket);
    }
    
    int Patient::number() const{
        return m_ticket.number();
    }
    
    std::ostream& Patient::csvWrite(std::ostream &ostr) const{
        ostr<<this->type() <<','<<m_name<<','<<m_ohip<<',';
        m_ticket.csvWrite(ostr);
        return ostr;
    }
    
    std::istream& Patient::csvRead(std::istream &istr){
        string temp;
        char comma;
        getline(istr,temp,',');

        if(m_name){
            delete [] m_name;
            m_name = nullptr;
        }

        m_name = new char[strlen(temp.c_str()) + 1];
        strcpy(m_name,temp.c_str());

        istr >> m_ohip >> comma;
        m_ticket.csvRead(istr);
        return istr;
    }
    
    std::ostream& Patient::write(std::ostream &ostr) const{
        ostr<<"Ticket No: "<<m_ticket.number() <<", Issued at: "<<Time(*this) << endl;
        if(strlen(m_name) > 25){
            for(int i = 0;i<25;i++){
                ostr<<m_name[i];
            }
        }
        else{
            ostr<<m_name;
        }
        ostr << ", OHIP: "<<m_ohip;
        return ostr;
    }
    
    std::istream& Patient::read(std::istream &istr){
        char *temp = getcstr("Name: ",istr);

        if(m_name){
            delete [] m_name;
            m_name = nullptr;
        }

        m_name = new char[strlen(temp) + 1];
        strcpy(m_name,temp);

        delete [] temp;

        m_ohip = getInt(100000000,999999999,"OHIP: ","Invalid OHIP Number, ");
        return istr;
    }

}