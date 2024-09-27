#include "ivedimas.h"
#include "duomenys.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>

using namespace std;

bool arTeisinga(const string& name) {
    if (name.empty() || name.length() > 10) return false;
    for (char ch : name) {
        if (!isalpha(ch)) return false; // Negalima kitko nei skaičiai
    }
    return true;
}

void nuskaitymas(vector<Studentas>& studentai){
    string  input;
    int pazymys;
    cout << "Ar norite nuskaityti duomenis iš failo? (1 - Taip, 0 - Ne): ";
    int readFromFile;
    cin >> readFromFile;

    if (readFromFile == 1) {
        cin.ignore();
        string failo_adresas;
        while (true) {
            cout << "Įveskite failo adresą: ";
            getline(cin, failo_adresas);

            ifstream file(failo_adresas);  // Bandom atidaryti
            if (file.is_open()) {
                file.close();  // Jei atsidaro, uždarom
                skaitytiIsFailo(failo_adresas, studentai);
                break;  // Išeinam iš ciklo
            } else {
                cout << "Nepavyko atidaryti failo! Bandykite dar kartą.\n";
            }
        }
    } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Norėdami baigti įvesti studentus, paspauskite ENTER du kartus.\n";
        
        while (true) {
            Studentas x;
            
            // Imame studento vardą
            cout << "\nĮrašykite studento vardą (ne daugiau nei 10 simbolių) arba paspauskite ENTER, kad baigtumėte: ";
            getline(cin, x.vardas);
            if (x.vardas.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.vardas)) {
                cout << "Netinkamas vardas. Bandykite dar kartą.\n";
                continue;
            }

            // Imame studento pavardę
            cout << "Įrašykite studento pavardę (ne daugiau nei 10 simbolių): ";
            getline(cin, x.pavarde);
            if (x.pavarde.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.pavarde)) {
                cout << "Netinkama pavardė. Bandykite dar kartą.\n";
                continue;
            }

            // Klausia, kokio suvedimo norime
            int choice;
            cout << "Ar norite atsitiktinai sugeneruoti namų darbų ir egzamino pažymius?\n";
            cout << "0 - Ne, įvesiu ranka\n";
            cout << "1 - Taip, sugeneruok atsitiktinai\n";     
            
            while (true) {
                cout << "Įveskite pasirinkimą (1 arba 0): ";
                if (!(cin >> choice) || (choice != 0 && choice != 1)) {
                    cout << "Neteisingas pasirinkimas. Bandykite dar kartą.\n";
                    cin.clear();
                    cin.ignore('\n');
                } else {
                    break;
                }
            }
            
            if (choice == 1) {
                // Sugeneruojam atsitiktinus namų darbų ir egzamino rezultatus
                int nd_kiekis;
                cout << "Kiek norite sugeneruoti namų darbų pažymių?(Ne daugiau nei 10 000): ";
                while (!(cin >> nd_kiekis) || nd_kiekis < 0 || nd_kiekis > 10000) {
                    cout << "Įveskite teisingą skaičių: ";
                    cin.clear();
                    cin.ignore('\n');
                }

                generuotiRandom(x, nd_kiekis);  // Kviečiam funkciją

                cin.clear();
                cin.ignore('\n');

            } else {
                // Suvedame namų darbų rezultatus rankiniu būdu
                cout << "Įrašykite namų darbų pažymius (nuo 0 iki 10). Norėdami baigti įvesti pažymius, paspauskite ENTER:\n";
                cin.ignore();  // išvalom \n
                while (true) {
                    cout << "Įrašykite pažymį: ";
                    getline(cin, input);
                    if (input.empty()) break;

                    try {
                        pazymys = stoi(input);
                        if (pazymys < 0 || pazymys > 10) {
                            throw out_of_range("Pažymys turi būti tarp 0 ir 10.");
                        }
                        x.nd.push_back(pazymys);
                    } catch (invalid_argument&) {
                        cout << "Įveskite teisingą pažymį (skaičių nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }

                // Imame egzamino rezultatą
                cout << "Įrašykite egzamino pažymį: ";
                while (true) {
                    getline(cin, input);
                    try {
                        x.egz = stoi(input);
                        if (x.egz < 0 || x.egz > 10) {
                            throw out_of_range("Egzamino pažymys turi būti tarp 0 ir 10.");
                        }
                        break;
                    } catch (invalid_argument&) {
                        cout << "Įveskite teisingą egzamino pažymį (skaičių nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
            }

            studentai.push_back(x);  // įdedam studentą į vektorių
        }
    }
}