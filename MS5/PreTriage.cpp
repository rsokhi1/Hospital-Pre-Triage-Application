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
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "PreTriage.h"
using namespace std;
namespace sdds{


    PreTriage::PreTriage(const char* dataFilename) : 
    m_averCovidWait(15),m_averTriageWait(5),m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit",2),m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage",2)
    {
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename,dataFilename);
        load();
    }
    
    PreTriage::~PreTriage(){
        ofstream out(m_dataFilename);
        if(out.is_open()){
            cout << "Saving Average Wait Times," << endl;
            cout << "   COVID Test: " << m_averCovidWait << endl;
            cout << "   Triage: " << m_averTriageWait << endl;
            cout << "Saving m_lineup..." << endl;
        
            out<<m_averCovidWait<<","<<m_averTriageWait<<endl;
            for(int i = 0;i<m_lineupSize;i++){
                m_lineup[i]->fileIO(true);
                cout<<(i+1)<<"- "<<*m_lineup[i]<<endl;
                out<<*m_lineup[i]<<endl;
            }
        }
        else{
            cout<<"Failed to SAVE File !!"<<endl;
        }

        for(int i = 0;i<m_lineupSize;i++){
            delete m_lineup[i];
            m_lineup[i] = nullptr;
        }

        delete [] m_dataFilename;
        m_dataFilename = nullptr;

        cout<<"done!"<<endl;
    }
    
    void PreTriage::run(void){
        int select;
        while(m_appMenu >> select){
            switch (select)
            {
            case 1:
                reg();
                break;
            
            case 2:
                admit();
                break;

            default:
                break;
            }
        }
    }

    void PreTriage::reg(){
        if(m_lineupSize == maxNoOfPatients){
            cout<<"Line up full!"<<endl;
        }   
        else{
            int select;
            m_pMenu >>select;
            switch (select)
            {
            case 1:
                m_lineup[m_lineupSize] = new CovidPatient();
                break;
            
            case 2:
                m_lineup[m_lineupSize] = new TriagePatient();
                break;

            default:
                break;
            }
            m_lineup[m_lineupSize]->setArrivalTime();
            cout<<"Please enter patient information: "<<endl;
            m_lineup[m_lineupSize]->fileIO(false);
            cin>>*m_lineup[m_lineupSize];
            cout<<endl;
            cout<<"******************************************"<<endl;
            cout<<*m_lineup[m_lineupSize];
            cout<<"Estimated Wait Time: "<<getWaitTime(*m_lineup[m_lineupSize])<<endl;
            cout<<"******************************************"<<endl<<endl;
            m_lineupSize++;
        }
    }

    void PreTriage::admit(){
        int select;
        int flag;
        char type = '\0';
        m_pMenu >> select;
        switch(select){
            case 1:
                type = 'C';
                break;
            
            case 2:
                type = 'T';
                break;
        
            default:
                break;
        }
        flag = indexOfFirstInLine(type);
        if(flag != -1){
            cout<<endl;
            cout<<"******************************************"<<endl;
            m_lineup[flag]->fileIO(false);
            cout<<"Calling for "<<*m_lineup[flag];
            cout<<"******************************************"<<endl<<endl;
            setAverageWaitTime(*m_lineup[flag]);
            removePatientFromLineup(flag);
        }

    }
    
    const Time PreTriage::getWaitTime(const Patient& p) const{
        unsigned int flag = 0;
        for(int i = 0;i<m_lineupSize;i++){
            if(p == *m_lineup[i]){
                flag++;
            }
        }
        return Time(p) * flag;
    }
    
    void PreTriage::setAverageWaitTime(const Patient& p){
        int temp = Time(p);
        if(p == 'C'){
            m_averCovidWait = ((getTime() - temp) + (int(m_averCovidWait) * (p.number() - 1))) / p.number(); 
        }
        else{
            m_averTriageWait = ((getTime() - temp) + (int(m_averTriageWait) * (p.number() - 1))) / p.number();
        }
    }
    
    void PreTriage::removePatientFromLineup(int index){
        removeDynamicElement<Patient>(m_lineup,index,m_lineupSize);
    }
    
    int PreTriage::indexOfFirstInLine(char type) const{
        int flag = -1;
        for (int i = 0;i<m_lineupSize && flag == -1;i++){
            if(*m_lineup[i] == type){
                flag = i;
            }
        }
        return flag;
    }
    
    void PreTriage::load(){
        int index = 0;
        char comma ='\0';
        bool flag = false;
        cout<<"Loading data..."<<endl;
        ifstream readfile(m_dataFilename);

        if(!readfile) {
            cout<<"No data or bad data file!"<<endl<<endl;
        }
        else{
            readfile >> m_averCovidWait;
            if(!readfile){
                flag = true;
            }
            readfile >> comma >> m_averTriageWait;
            readfile.ignore(32767,'\n');
            while(index < maxNoOfPatients && !readfile.eof() && !flag){
                char type = '\0';
                Patient *temp = nullptr;
                readfile >> type >>comma;

                if(type == 'C'){
                    temp = new CovidPatient();
                }
                else if(type == 'T'){
                    temp = new TriagePatient();
                }
                if(temp !=nullptr){
                    temp->fileIO(true);
                    readfile >> *temp;
                    temp->fileIO(false);
                    m_lineup[index] = temp;
                    m_lineupSize++;
                }
                index++;
            }
            if (!readfile.eof()) {
                cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
                cout << m_lineupSize << " Records imported..." << endl << endl;
            }
            else if (flag){
                cout << "No data or bad data file!" << endl << endl;
            }
            else{
                cout << m_lineupSize << " Records imported..." << endl << endl;
            }
        }
    }


    

}