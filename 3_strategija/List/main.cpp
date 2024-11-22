#include <iostream>
#include <iomanip>
#include <limits> // numeric_limits
#include <vector>
#include "duomenys.h"
#include "ivedimas.h"
#include "rikiavimas.h"
#include "vertinimas.h"
#include "rezultatas.h"
#include <fstream>
#include <random>
#include <chrono>
#include <list>

using namespace std; // so that std::string can be used directly

int main(){
    list<Studentas> studentai;
    int choice;

    // Ask if we want to generate files with random data
    cout << "\nPasirinkite ar norite sugeneruoti failus su atsitiktiniais duomenimis:\n";
    cout << "0 - Sugeneruoti failus\n";
    cout << "1 - Ne\n";
    while (true) {
        cout << "Iveskite pasirinkima (0 arba 1): ";
        if (!(cin >> choice) || (choice != 0 && choice != 1)) {
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    }

    if (choice == 0) {
        // Generating 5 files with random student data
        generuotiDuomenis(1000, "studentai_1000.txt");
        generuotiDuomenis(10000, "studentai_10000.txt");
        generuotiDuomenis(100000, "studentai_100000.txt");
        generuotiDuomenis(1000000, "studentai_1000000.txt");
        generuotiDuomenis(10000000, "studentai_10000000.txt");
    }

    // Read student data
    nuskaitymas(studentai);

    cout << "\nPasirinkite, ka norite apskaiciuoti:\n";
    cout << "0 - Galutinis pazymys pagal vidurki\n";
    cout << "1 - Galutinis pazymys pagal mediana\n";

    while(true){
        cout << "Iveskite pasirinkima (1 arba 0): ";
        if(!(cin >> choice) || (choice != 0 && choice != 1)){
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else{
            break;
        }
    }

    // Calculate final grades based on average or median
    skaiciavimai(studentai, choice);

    // Separate students into "rich" and "poor" groups
    list<Studentas> vargsiukai;
    padalintiStudentus(studentai, vargsiukai);

    // Ask how to sort the students
    int sort_choice;
    cout << "\nPasirinkite, pagal ka norite surikiuoti studentus:\n";
    cout << "0 - Rikiuoti pagal pavarde\n";
    cout << "1 - Rikiuoti pagal varda\n";
    cout << "2 - Rikiuoti pagal galutini pazymi\n";

    while (true) {
        cout << "Iveskite pasirinkima (0, 1 arba 2): ";
        if (!(cin >> sort_choice) || (sort_choice < 0 || sort_choice > 2)) {
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    }

    // Sort students based on the user's choice
    rikiuotiStudentus(studentai, sort_choice);
    
    // Output the results to files
    isvestiIFailus(studentai, vargsiukai, sort_choice);

    // Ask whether to print the results or exit the program
    int final_choice;
    cout << "\nPasirinkite:\n";
    cout << "0 - Spausdinti rezultatus i terminala\n";
    cout << "1 - Iseiti is programos\n";

    while (true) {
        cout << "Iveskite pasirinkima (0 arba 1): ";
        if (!(cin >> final_choice) || (final_choice != 0 && final_choice != 1)) {
            cout << "Ivestas neteisingas simbolis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else {
            break;
        }
    }

    // Print the results to the terminal if selected
    if (final_choice == 0) {
        spausdinti(studentai, choice);
    } else {
        cout << "Programa baigta.\n";
    }

    return 0; // End the program
}
