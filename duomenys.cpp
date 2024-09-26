#include "duomenys.h"
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

// Funkcija atsitiktinių rezultatų generavimui
void generuotiRandom(Studentas& x, int nd_kiekis) {
    cout << "Atsitiktinai sugeneruoti namų darbų pažymiai: ";
    for (int i = 0; i < nd_kiekis; i++) {
        int random_pazymys = (rand() % 10) + 1;  // Generuoja skaičių nuo 1 iki 10
        x.nd.push_back(random_pazymys);
        cout << random_pazymys << " "; 
    }
    x.egz = (rand() % 10) + 1;  // Generuoja skaičių nuo 1 iki 10
    cout << "\nSugeneruotas egzamino pažymys: " << x.egz << "\n";
}
// Funkcija skirta perskaityti studento duomenis iš failo
void skaitytiIsFailo(const string& failo_adresas, vector<Studentas>& studentai) {
    ifstream file(failo_adresas);
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo!\n";
        return;
    }

    string eilute;
    getline(file, eilute); // Praleidžiam pirmą eilutę

    while (getline(file, eilute)) {
        stringstream ss(eilute); // Kad lengviau nuskaityčiau duomenis
        Studentas studentas;
        ss >> studentas.vardas >> studentas.pavarde;

        int pazymys;
        vector<int> pazymiai;

        // Nuskaitom visus skaičius iki paskutinio (egzamino)
        while (ss >> pazymys) {
            pazymiai.push_back(pazymys);
        }

        if (!pazymiai.empty()) {
            studentas.egz = pazymiai.back(); // pasiimam paskutinį egzamino pažymį
            pazymiai.pop_back();             // Panaikinam jį iš namų darbų pažymių
            studentas.nd = pazymiai;         // Sudedam likusius pažymius į struktųrą
        }

        studentai.push_back(studentas);
    }

    file.close();
}