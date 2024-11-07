#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <vector>
#include <string>
#include "studentas.h"
#include "vertinimas.h"
#include "rikiavimas.h"
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <chrono>

void generuotiRandom(Studentas& studentas, int nd_kiekis);
void skaitytiIsFailo(const std::string& failo_adresas, std::vector<Studentas>& studentai);
void generuotiDuomenis(int studentuSk, const string &failoPavadinimas);
void skaiciavimai(vector<Studentas>& studentai, int choice);
void padalintiStudentus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai);
void isvestiIFailus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, int sort_choice);

#endif