/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.h
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
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds {
    class CovidPatient :public Patient{
    public:
        CovidPatient();
        char type() const;
        std::istream &csvRead(std::istream &istr);
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
    };

}
#endif // !SDDS_COVIDPATIENT_H_