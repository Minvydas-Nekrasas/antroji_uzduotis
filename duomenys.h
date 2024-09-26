#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <vector>
#include <string>
#include "studentas.h"

void generuotiRandom(Studentas& studentas, int nd_kiekis);
void skaitytiIsFailo(const std::string& failo_adresas, std::vector<Studentas>& studentai);

#endif