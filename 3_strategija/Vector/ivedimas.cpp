#include "ivedimas.h"

using namespace std;

bool arTeisinga(const string& name) {
    if (name.empty() || name.length() > 10) return false;
    for (char ch : name) {
        if (!isalpha(ch)) return false; // Tik leidžiami skaičiai
    }
    return true;
}

void nuskaitymas(vector<Studentas>& studentai) {
    string  input;
    int pazymys;
    cout << "Ar norite nuskaityti duomenis is failo? (1 - Taip, 0 - Ne): ";
    int readFromFile;
    cin >> readFromFile;

    if (readFromFile == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string failo_adresas;
        while (true) {
            cout << "Iveskite failo adresa: ";
            getline(cin, failo_adresas);

            ifstream file(failo_adresas);  // Bandom atidaryti
            if (file.is_open()) {
                file.close();  // Jei atsidaro, uždarom
                skaitytiIsFailo(failo_adresas, studentai);
                break;  // Išeinam iš ciklo
            } else {
                cout << "Nepavyko atidaryti failo! Bandykite dar karta.\n";
            }
        }
    } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline from previous input
        cout << "Noredami baigti ivesti studentus, paspauskite ENTER du kartus.\n";

        while (true) {
            Studentas x;
            
            // Imame studento vardą
            cout << "\nIrasykite studento varda (ne daugiau nei 10 simboliu) arba paspauskite ENTER, kad baigtumete: ";
            getline(cin, x.vardas);
            if (x.vardas.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.vardas)) {
                cout << "Netinkamas vardas. Bandykite dar karta.\n";
                continue;
            }

            // Imame studento pavardę
            cout << "Irasykite studento pavarde (ne daugiau nei 10 simboliu): ";
            getline(cin, x.pavarde);
            if (x.pavarde.empty()) break; // Stabdom, jei enter paspaustas 2 kart
            
            if (!arTeisinga(x.pavarde)) {
                cout << "Netinkama pavarde. Bandykite dar karta.\n";
                continue;
            }

            // Klausia, kokio suvedimo norime
            int choice;
            cout << "Ar norite atsitiktinai sugeneruoti namu darbu ir egzamino pazymius?\n";
            cout << "0 - Ne, ivesiu ranka\n";
            cout << "1 - Taip, sugeneruok atsitiktinai\n";     
            
            while (true) {
                cout << "Iveskite pasirinkima (1 arba 0): ";
                if (!(cin >> choice) || (choice != 0 && choice != 1)) {
                    cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
                    cin.clear(); // Clear error state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear invalid input
                } else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline after input
                    break;
                }
            }
            
            if (choice == 1) {
                // Sugeneruojam atsitiktinus namų darbų ir egzamino rezultatus
                int nd_kiekis;
                cout << "Kiek norite sugeneruoti namu darbu pazymiu? (Ne daugiau nei 10 000): ";
                while (!(cin >> nd_kiekis) || nd_kiekis < 0 || nd_kiekis > 10000) {
                    cout << "Iveskite teisinga skaiciu: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pravalom netinkamą atsakymą
                }

                generuotiRandom(x, nd_kiekis);  // Kviečiam funkciją

                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
            } else {
                // Suvedame namų darbų rezultatus rankiniu būdu
                cout << "Irasykite namu darbu pazymius (nuo 0 iki 10). Noredami baigti ivesti pazymius, paspauskite ENTER:\n";
                
                while (true) {
                    cout << "Irasykite pazymi: ";
                    getline(cin, input);
                    if (input.empty()) break;

                    try {
                        pazymys = stoi(input);
                        if (pazymys < 0 || pazymys > 10) {
                            throw out_of_range("Pazymys turi buti tarp 0 ir 10.");
                        }
                        x.nd.push_back(pazymys);
                    } catch (invalid_argument&) {
                        cout << "Iveskite teisinga pazymi (skaiciu nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }

                // Imame egzamino rezultatą
                cout << "Irasykite egzamino pazymi: ";
                while (true) {
                    getline(cin, input);
                    try {
                        x.egz = stoi(input);
                        if (x.egz < 0 || x.egz > 10) {
                            throw out_of_range("Egzamino pazymys turi buti tarp 0 ir 10.");
                        }
                        break;
                    } catch (invalid_argument&) {
                        cout << "Iveskite teisinga egzamino pazymi (skaiciu nuo 0 iki 10).\n";
                    } catch (out_of_range& e) {
                        cout << e.what() << endl;
                    }
                }
            }

            studentai.push_back(x);  // įdedam studentą į vektorių
        }
    }
}
