#include "rezultatas.h"

// Atspausdinam studentų duomenis
void spausdinti(const vector<Studentas>& studentai, bool choice) {
    string pasirinkimas_pav;
    double pasirinkimas;

    if (choice == 0) {
        pasirinkimas_pav = "(Vid.)";
    } else {
        pasirinkimas_pav = "(Med.)";
    }

    stringstream buffer;  // naudojam stringstream

    buffer << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    buffer << left << setw(10) << "Pavardė"
           << setw(10) << "" << "Adresas"
           << setw(10) << "" << "Vardas"
           << setw(10) << "" << "Adresas" 
           << setw(10) << "" << "Galutinis "
           << pasirinkimas_pav
           << setw(10) << "" << "Adresas"
           << setw(10) << "" << "Vektoriaus adresas" << endl;
    buffer << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

    for (const auto& studentas : studentai) {
        buffer << left << setw(10) << studentas.pavarde
               << setw(10) << "" << &studentas.pavarde
               << setw(10) << "" << studentas.vardas
               << setw(10) << "" << &studentas.vardas
               << setw(15) << "" << fixed << setprecision(2) << studentas.galutinis
               << setw(20) << "" << &studentas.galutinis
               << setw(10) << "" << &studentas << endl;
    }

    cout << buffer.str() << flush;  // visk1 atspausdinam vienu metu
}
