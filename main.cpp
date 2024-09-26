#include <iostream>
#include <iomanip>
#include <limits> //numeric_limits
#include <vector>
#include "ivedimas.h"
#include "rikiavimas.h"
#include "vertinimas.h"
#include "rezultatas.h"

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

    spausdinti(studentai, choice);
    
    return 0; //uždarom programą
}
