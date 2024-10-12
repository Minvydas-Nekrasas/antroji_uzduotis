#include <iostream>
#include <iomanip>
#include <limits> //numeric_limits
#include <vector>
#include "ivedimas.h"
#include "rikiavimas.h"
#include "vertinimas.h"
#include "rezultatas.h"
#include <fstream>
#include <random>
#include <chrono>

using namespace std; // kad nereiktų rašyt std::string
using namespace std::chrono;

void generuotiDuomenis(int studentuSk, const string &failoPavadinimas) {

    auto start = high_resolution_clock::now(); // fiksuojam laiką (pradžia)
    ofstream file(failoPavadinimas);
    file << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas\n"; // Pirma failo eilutė

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);  // Generuojam pažymius nuo 1 iki 10

    for (int i = 0; i < studentuSk; ++i) {
        string pavarde = "Pavarde" + to_string(i + 1);
        string vardas = "Vardas" + to_string(i + 1);

        // Generuojam 5 namų darbų pažymius
        int nd1 = dist(gen);
        int nd2 = dist(gen);
        int nd3 = dist(gen);
        int nd4 = dist(gen);
        int nd5 = dist(gen);

        // Generuojam egzamino pažymį
        int egzaminas = dist(gen);

        // Įrašom duomenis į failą
        file << pavarde << " " << vardas << " "
             << nd1 << " " << nd2 << " " << nd3 << " " << nd4 << " " << nd5 << " "
             << egzaminas << "\n";
    }

    file.close();

    // fiksuojam laiką (pabaiga)
    auto end = high_resolution_clock::now();
    
    // Paskaičiuojam trukmę
    auto duration_ms = duration_cast<milliseconds>(end - start);

    // Milisekundes paverčiam į sekundes
    double duration_sec = duration_ms.count() / 1000.0;


    cout << "Sugeneruotas failas: " << failoPavadinimas << " su " << studentuSk << " studentais.\n";
    cout << "Sugeneravimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundės\n";
}
void skaiciavimai(vector<Studentas>& studentai, int choice) {
    for (auto& studentas : studentai) {
        if (choice == 0) {
            studentas.galutinis = vidurkis(studentas.nd, studentas.egz); // Galutinis pagal vidurkį
        } else {
            studentas.galutinis = mediana(studentas.nd, studentas.egz); // Galutinis pagal medianą
        }
    }
}
void padalintiStudentus(const vector<Studentas>& studentai, vector<Studentas>& kietiakiai, vector<Studentas>& vargsiukai) {
    auto start = high_resolution_clock::now();
    for (const auto& studentas : studentai) {
        if (studentas.galutinis >= 5.0) {
            kietiakiai.push_back(studentas);
        } else {
            vargsiukai.push_back(studentas);
        }
    }
    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    double duration_sec = duration_ms.count() / 1000.0;
    cout << "Padalinimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundės\n";
}
void isvestiIFailus(const vector<Studentas>& kietiakai, const vector<Studentas>& vargsiukai) {
    auto start = high_resolution_clock::now();
    ofstream kietiakiaiFile("kietiakai.txt");
    ofstream vargsiukaiFile("vargsiukai.txt");

    kietiakiaiFile << "Pavarde Vardas Galutinis Balas\n";
    for (const auto& studentas : kietiakai) {
        kietiakiaiFile << studentas.pavarde << " " << studentas.vardas << " " << studentas.galutinis << "\n";
    }

    vargsiukaiFile << "Pavarde Vardas Galutinis Balas\n";
    for (const auto& studentas : vargsiukai) {
        vargsiukaiFile << studentas.pavarde << " " << studentas.vardas << " " << studentas.galutinis << "\n";
    }

    kietiakiaiFile.close();
    vargsiukaiFile.close();

    auto end = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end - start);
    double duration_sec = duration_ms.count() / 1000.0;
    cout << "Failų išvedimo laikas: " << fixed << setprecision(3) << duration_sec << " sekundės\n";
}

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
