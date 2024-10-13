#include <iostream>
#include <iomanip>
#include <limits> //numeric_limits
#include <vector>
#include "duomenys.h"
#include "ivedimas.h"
#include "rikiavimas.h"
#include "vertinimas.h"
#include "rezultatas.h"
#include <fstream>
#include <random>
#include <chrono>

using namespace std; // kad nereiktų rašyt std::string

int main(){
    vector<Studentas> studentai;
    int choice;

    cout << "\nPasirinkite ar norite sugeneruoti failus su atsitiktiniais duomenimis:\n";
    cout << "0 - Sugeneruoti failus\n";
    cout << "1 - Ne\n";
    while (true) {
        cout << "Įveskite pasirinkimą (0 arba 1): ";
        if (!(cin >> choice) || (choice != 0 && choice != 1)) {
            cout << "Įvestas neteisingas simbolis. Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    }

    if (choice == 0) {
        // Generuojami 5 failai
        generuotiDuomenis(1000, "studentai_1000.txt");
        generuotiDuomenis(10000, "studentai_10000.txt");
        generuotiDuomenis(100000, "studentai_100000.txt");
        generuotiDuomenis(1000000, "studentai_1000000.txt");
        generuotiDuomenis(10000000, "studentai_10000000.txt");
    }

    nuskaitymas(studentai);

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

    skaiciavimai(studentai, choice); // Apskaičiuojami galutiniai pažymiai

    // Rūšiuojam studentus į kietiakius ir vargšiukus
    vector<Studentas> kietiakai, vargsiukai;
    padalintiStudentus(studentai, kietiakai, vargsiukai);

    // Išvedimas į failus
    isvestiIFailus(kietiakai, vargsiukai);

    int sort_choice;
    cout << "\nPasirinkite, pagal ką norite surikiuoti studentus:\n";
    cout << "0 - Rikiuoti pagal pavardę\n";
    cout << "1 - Rikiuoti pagal vardą\n";
    cout << "2 - Rikiuoti pagal galutinį pažymį\n";

    while (true) {
        cout << "Įveskite pasirinkimą (0, 1 arba 2): ";
        if (!(cin >> sort_choice) || (sort_choice < 0 || sort_choice > 2)) { // Priimam 0, 1 or 2
            cout << "Įvestas neteisingas simbolis. Bandykite dar kartą.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    }

    rikiuotiStudentus(studentai, sort_choice);

    spausdinti(studentai, choice);
    
    return 0; //uždarom programą
}
