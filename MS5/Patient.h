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
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"
namespace sdds{
    class Patient : public IOAble{
        char *m_name {nullptr};
        int m_ohip {0};
        Ticket m_ticket {0};
        bool m_IOflag;
    public:
        Patient(int ticket = 0,bool flag = false);
        ~Patient();
        Patient(const Patient &P) = delete;
        Patient &operator=(const Patient &P) = delete;

        virtual char type() const = 0;

        const bool fileIO() const;
        void fileIO(bool IO_flag);
        bool operator==(const char singleChar) const;
        bool operator==(const Patient &P) const;
        void setArrivalTime();
        operator Time() const;
        int number() const;

        std::ostream &csvWrite(std::ostream &ostr) const;
        std::istream &csvRead(std::istream &istr);
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
    };
}
#endif // !SDDS_PATIENT_H_