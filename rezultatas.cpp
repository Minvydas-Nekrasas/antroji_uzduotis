#include "rezultatas.h"
#include <iostream>
#include <iomanip>

// Atspausdinam studentų duomenis
void spausdinti(const vector<Studentas>& studentai, bool choice){
    string pasirinkimas_pav;
    double pasirinkimas;

    if (choice == 0){
        pasirinkimas_pav = "(Vid.)";
    }
    else{
        pasirinkimas_pav = "(Med.)";
    }
    
    cout << "\n----------------------------------------------\n";
    cout << left << setw(15) << "Pavardė" //su setw nustatom tarpus
         << setw(15) << "Vardas" 
         << "Galutinis " 
         << pasirinkimas_pav << endl;
    cout << "----------------------------------------------\n";

    for (const auto& studentas : studentai) {
        if (choice == 0){
            pasirinkimas = vidurkis(studentas.nd, studentas.egz);
        }
        else{
            pasirinkimas = mediana(studentas.nd, studentas.egz);
        }
        cout << left << setw(15) << studentas.pavarde
             << setw(15) << studentas.vardas
             << setw(20) << fixed << setprecision(2) << pasirinkimas // setprecision(2) => du skaičiai po kablelio
             << endl;
    }
}