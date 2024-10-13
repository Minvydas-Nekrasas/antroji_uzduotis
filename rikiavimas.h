#ifndef RIKIAVIMAS_H
#define RIKIAVIMAS_H

#include <string>
#include <vector>
#include "studentas.h"
using namespace std;

string toLowerCase(const string& str);
void rikiuotiStudentus(vector<Studentas>& studentai, int sort_choice);

#endif