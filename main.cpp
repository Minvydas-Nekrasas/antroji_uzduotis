#include <iostream>
#include <iomanip>
#include <limits> //numeric_limits
#include <vector>
#include "ivedimas.h"
#include "rikiavimas.h"
#include "vertinimas.h"

using namespace std; // kad nereiktų rašyt std::string

int main(){
    vector<Studentas> studentai;
    nuskaitymas(studentai);
    int choice;
    cout << "\nPasirinkite, ką norite apskaičiuoti:\n";
    cout << "0 - Galutinis pažymys pagal vidurkį\n";
    cout << "1 - Galutinis pažymys pagal medianą\n";

    while(true){
        cout << "Įveskite pasirinkimą (1 arba 0): ";
        if(!(cin >> choice)||(choice != 0 && choice != 1)){
            cout << "Įvestas neteisingas simbolis. Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else{
            break;
        }
    }

    string pasirinkimas_pav;
    double pasirinkimas;

    if (choice == 0){
        pasirinkimas_pav = "(Vid.)";
    }
    else{
        pasirinkimas_pav = "(Med.)";
    }

// Rikiavimo pasirinkimas
    int sort_choice;
    cout << "\nPasirinkite, pagal ką norite surikiuoti studentus:\n";
    cout << "0 - Rikiuoti pagal pavardę\n";
    cout << "1 - Rikiuoti pagal vardą\n";

    while(true){
        cout << "Įveskite pasirinkimą (0 arba 1): ";
        if(!(cin >> sort_choice)||(sort_choice != 0 && sort_choice != 1)){
            cout << "Įvestas neteisingas simbolis. Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else{
            break;
        }
    }

    // Rikiuojam studentus pagal pasirinkimą
    rikiuotiStudentus(studentai, sort_choice == 1);

    // Atspausdinam studentų duomenis
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
    return 0; //uždarom programą
}
