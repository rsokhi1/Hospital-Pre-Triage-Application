/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
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
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow(){
        m_min = getTime();
        return *this;
    }
    
    Time::Time(unsigned int min){
        m_min = min;
    }
    
    std::ostream& Time::write(std::ostream& ostr) const{
        ostr.width(2);
        ostr.fill('0');
        ostr<<(m_min/60);

        ostr<<":";

        ostr.width(2);
        ostr.fill('0');
        ostr<<(m_min % 60);

        return ostr;
    }
    
    std::istream& Time::read(std::istream& istr){
        int hour = 0;
        int minute = 0;
        char delimit;
        istr >> hour;
        if(!istr){
            istr.setstate(ios::failbit);
        }
        else if(hour < 0 ){
            istr.setstate(ios::failbit);
        }
        else{
            istr>>delimit;
            if(delimit != ':'){
                istr.setstate(ios::failbit);
            }
            else{
                istr>>minute;
                if(minute < 0){
                    istr.setstate(ios::failbit);
                }
                else m_min = (hour * 60) + minute;
            }
        }
        return istr;
    }
    
    Time& Time::operator-=(const Time& D){
        if(this->m_min > D.m_min){
            this->m_min -= D.m_min;
        }
        else{
            this->m_min = this->m_min + (1440 * ( (D.m_min / 1440) + 1)) - D.m_min;
        }
        return *this;
    }
    
    Time Time::operator-(const Time& D) const{
        Time temp;
        if(this->m_min > D.m_min){
            temp.m_min -= D.m_min;
        }
        else{
            temp.m_min = this->m_min + (1440 * ( (D.m_min / 1440) + 1)) - D.m_min;
        }
        return temp;
    }
    
    Time& Time::operator+=(const Time& D){
        this->m_min += D.m_min;
        return *this;
    }

    Time Time::operator+(const Time& D) const{
        Time temp;
        temp.m_min = this->m_min + D.m_min;
        return temp;
    }
    
    Time& Time::operator=(unsigned int val){
        this->m_min = val;
        return *this;
    }
    
    
    
    Time& Time::operator *= (unsigned int val){
        this->m_min *= val;
        return *this;
    }

    Time Time::operator *(unsigned int val) const{
        Time temp;
        temp.m_min = this->m_min * val;
        return temp;
    }

    Time& Time::operator /= (unsigned int val){
        this->m_min /= val;
        return *this;
    }
    
    Time Time::operator /(unsigned int val) const{
        Time temp;
        temp.m_min = this->m_min / val;
        return temp;
    }
    
    
    Time::operator int() const{
        int temp;
        temp = this->m_min;
        return temp;
    }
    

    Time::operator unsigned int() const{
        return this->m_min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D){
        return D.write(ostr);
    }
    
    std::istream& operator>>(std::istream& istr, Time& D){
        return D.read(istr);
    }
}