# Studentų Rezultatų Skaičiavimo Sistema (v0.1)

Tai yra C++ programa, kuri apskaičiuoja studentų galutinius pažymius pagal namų darbų ir egzamino rezultatus.
Programa leidžia vartotojui įvesti studentų informaciją (vardą, pavardę, namų darbų ir egzamino pažymius) rankiniu būdu arba sugeneruoti juos atsitiktinai. Kodas gali apskaičiuoti galutinį pažymį pagal vidurkį arba medianą, atsižvelgiant į namų darbų pažymius ir egzaminą. Taip pat galima rūšiuoti studentus pagal vardą arba pavardę ir atspausdinti galutinius rezultatus lentelės formatu.
## Turinys
1. [Funkcionalumas](#funkcionalumas)
2. [Failų Struktūra](#failų-struktūra)
3. [Kompiliavimas ir Paleidimas](#kompiliavimas-ir-paleidimas)
4. [Naudojimas](#naudojimas)
## Funkcionalumas
- Įvesti studentų vardus, pavardes ir pažymius rankiniu būdu arba generuoti atsitiktinai.
- Apskaičiuoti galutinį pažymį pagal:
  - Vidurkį
  - Medianą
- Rūšiuoti studentus pagal vardą arba pavardę.
- Atspausdinti studentų duomenis ir jų galutinius pažymius lentelės formatu.
## Failų Struktūra
Projektas suskirstytas į kelis failus, kad būtų lengviau tvarkyti kodą:

- main.cpp – pagrindinis programos failas.
- studentas.h – studento struktūra.
- ivedimas.cpp ir ivedimas.h – funkcijos skirtos vartotojų įvestims.
- duomenys.cpp ir duomenys.h – unkcijos, skirtos darbui su duomenimis (duomenų nuskaitymas iš failo ir atsitiktinių duomenų generavimas).
- rikiavimas.cpp ir rikiavimas.h – funkcijos, skirtos duomenų rikiavimui pagal vardą arba pavardę.
- vertinimas.cpp ir vertinimas.h - funkcijos, skirtos duomenų susisteminimui (medianos ir vidurkio skaičiavimas).
- rezultatas.cpp ir rezultatas.h - funkcija skirta rezultato išvedimui.
## Kompiliavimas ir Paleidimas

### Naudojant kompiliatorių:
1. Nuklonuojame repozitoriją:

       git clone https://github.com/Minvydas-Nekrasas/pirmoji_uzduotis/
       cd "[direktorija]"
   
3. Sukompiliuojame kodą:

       g++ *.cpp -o vertinimas
   
5. Paleidžiame programą:

       ./vertinimas
### Naudojant cmake:
1. Terminale nurodome direktorija, kur egzistuoja projekto CMakeLists.txt failas, sukuriam build failams skirta direktorija :

       cd "[direktorija]"
       mkdir build
       cd build

2. Paleidžiame cmake, kad sugeneruoti build failus, nurodome jau minėta direktorija:
        
       cmake "[direktorija]"
   
4. Sukompiliuojame ir sukuriame .exe failą, taip pat galime pasirinkt konfigurijacija: Release arba Debug:

       cmake --build . --config [Release arba Debug]

## Naudojimas
1. Programa paklaus, ar norite įvesti duomenis iš failo, ar rankiniu būdu.
2. Rankiniu būdu įvedus duomenis, galima pasirinkti, ar sugeneruoti pažymius atsitiktinai, ar įvesti juos ranka.
3. Vartotojas gali pasirinkti, kaip apskaičiuoti galutinį pažymį – pagal vidurkį ar medianą.
4. Programa rūšiuos studentus pagal jūsų pasirinktą kriterijų (vardą arba pavardę) ir atspausdins rezultatus.

# v0.2
1. Pridėta failų sukūrimo funkcija - sukūriami 5 failai (1 000 studentų, 10 000 studentų, 100 000 studentų, 1 000 000 studentų ir 10 000 000 studentų)
2. Sukurta funkcija, dalinanti studentus į dvi kategorijas. Studentai išvedami į du naujus failus:

    - Studentai, kurių galutinis balas < 5.0 - vargšiukai

     - Studentai, kurių galutinis balas >= 5.0 - kietiakai

3. Sukurta funkcija kategorijų išvedimui į 2 atskirus failus: vargsiukai.txt, kietiakai.txt

4. Matuojama programos sparta šiems veiksmams: 
      - failų generavimui
      - duomenų nuskaitymui iš failo 
      - studentų rūšiavimui į 2 kategorijas
      - surūšiuotų studentų išvedimui į du failus

## Vidutiniai laiko spartos matavimai (vector)
| **Studentų skaičius** | **Failo genravimas (sek)** | **Rūšiavimas į 2 kategorijas (sek)** | Išvedimas į 2 failus (sek) |
|------------------|--------------------|-----------------------|----------------------|
| 1,000            | 0.003             | 0.002                 | 0.015                |
| 10,000           | 0.018              | 0.387                 | 0.381                |
| 100,000          | 0.123            | 1.858                 | 2.465                |
| 1,000,000        | 1.222             | 2.732                 | 43.907                |
| 10,000,000       | 11.796            | 11.149                | 435.121               |

## Naujos funkcijos:
- generuotiDuomenis() -  generuojami 5 studentų failai (studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt)
- skaiciavimai() - paskaičiuojamas vidurkis arba mediana kiekvienam studentui esančiam faile ir duomenys išsaugomi struktūroje
- padalintiStudentus() - padalinami studentai į 2 kategorijas
- isvestiIFailus() - išvedami studentai į du atskirus failus (kietiakai.txt, vargšiukai.txt)

# v0.3
Vietoje std::vector<Studentai> naudojame std::list<Studentai>.

## Vidutiniai laiko spartos matavimai (list)
| **Studentų skaičius** | **Failo genravimas (sek)** | **Rūšiavimas į 2 kategorijas (sek)** | Išvedimas į 2 failus (sek) |
|------------------|--------------------|-----------------------|----------------------|
| 1,000            | 0.003             | 0.002                 | 0.007                |
| 10,000           | 0.018              | 0.015                 | 0.065                |
| 100,000          | 0.098            | 0.122                 | 0.828                |
| 1,000,000        | 1.079             | 1.243                 | 15.966                |
| 10,000,000       | 9.008            | 15.039                | 235.011               |

## Testavimo sistemos parametrai
- CPU - Intel Core i5-8265U
- RAM - 12 GB
- SSD - 238 GB NVMe KINGSTON

# Studentų Rezultatų Skaičiavimo Sistema (v1.0)
## Tikslas
Šios versijos tikslas - išanalizuoti geriausius rūšiavimo algoritmus abiems studentų konteinerių tipams (Vector ir list) ir patobulinti juos.
## Failų struktūra
Šioje versijoje yra trys rūšiavimo strategijos:
- Strategija_1 - Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų".
- Strategija_2 - Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". 
- Strategija_3 (patobulinimas) - Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant greičiausiai veikiančią strategiją Vector ir List konteineriams, įtraukiant į ją partition (List) ir stable_partition (Vector) algoritmus.
## Rezultatai
Sukurti trys aplankai: Strategija_1, Strategija_2 ir Strategija_3, kuriuose yra po dar du aplankus: Vector ir List. Vector aplankas turi kodą, kur naudojamas Vector studentų konteinerio tipas, analogiškai List - List konteinerio tipas.

Atlikus pirmą ir antrą strategiją buvo pastebėta, kad pirmoji strategija tiko vektoriaus tipui, o antroji listo tipui. 3 strategijoje buvo pritaikyta pirma strategija ir stable_partition funkcija vektoriaus konteinerio tipui, o listui buvo panaudota antroji strategija ir atliktas rūšiavimo optimizavimas su partition funkcija. Laiko išmatavimai pateikti žemiau.
## Vidutiniai laiko spartos matavimai
### 1000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 0.005                        | 0.002              | 0.015                          |
| 1_strategija listai    | 0.005                        | 0.002              | 0.015                          |
| 2_strategija vektoriai | 0.005                        | 0.053              | 0.030                          |
| 2_strategija listai    | 0.005                        | 0.000              | 0.015                          |
| list su partition      | 0.005                        | 0.000              | 0.007                          |
| stable_partition vektoriai    | 0.005                        | 0.001              | 0.017                          |

### 10 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 0.160                        | 0.387              | 0.381                          |
| 1_strategija listai    | 0.161                        | 0.015              | 0.123                          |
| 2_strategija vektoriai | 0.160                        | 2.468              | 0.368                          |
| 2_strategija listai    | 0.161                        | 0.003              | 0.121                          |
| list su partition      | 0.160                        | 0.000              | 0.066                          |
| partition vektoriai    | 0.161                        | 0.011              | 0.243                          |

### 100 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 1.188                        | 1.858              | 2.465                          |
| 1_strategija listai    | 1.177                        | 0.122              | 1.301                          |
| 2_strategija vektoriai | 1.188                        | 218.594              | 3.283                          |
| 2_strategija listai    | 1.177                        | 0.039              | 1.165                          |
| list su partition      | 1.188                        | 0.012              | 0.885                          |
| partition vektoriai    | 1.177                        | 0.052              | 3.621                          |

### 1 000 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 9.692                        | 2.732              | 43.907                          |
| 1_strategija listai    | 10.064                        | 1.243              | 15.966                          |
| 2_strategija vektoriai | 9.692                        | 21 680              | 51.273                          |
| 2_strategija listai    | 10.064                        | 0.310              | 15.213                          |
| list su partition      | 9.692                        | 0.112              | 14.410                          |
| partition vektoriai    | 10.064                        | 0.562              | 37.504                          |

### 10 000 000
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 270.540                        | 11.149              | 435.121                          |
| 1_strategija listai    | 270.104                        | 15.039              | 235.011                          |
| 2_strategija vektoriai | 270.540                        | 21 859 400            | 498.332                          |
| 2_strategija listai    | 270.104                        | 4.171              | 145.376                          |
| list su partition      | 270.540                        | 1.162              | 176.744                          |
| partition vektoriai    | 270.104                        | 7.126              | 537.426                          |

# v1.1
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas
|------------------------|----------------------------------|------------------------|-----------------------------------|
| 1_strategija vektoriai | 270.540                        | 11.149              | 435.121                          |
| 1_strategija listai    | 270.104                        | 15.039              | 235.011                          |
| 2_strategija vektoriai | 270.540                        | 21 859 400            | 498.332                          |
| 2_strategija listai    | 270.104                        | 4.171              | 145.376                          |
| list su partition      | 270.540                        | 1.162              | 176.744                          |
| partition vektoriai    | 270.104                        | 7.126              | 537.426                          |

# Spartos analizė:
XXX
### 3 strategija su listais `struct` ir `class` palyginimas:
### 10 000 000:

|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|------------------------|----------------------------------|------------------------|-----------------------------------|
| struct  | 270.540 | 1.162 | 176.744 |
| class | 80.741019 | 12.709376   | 11.763234 |


### 1 000 000:
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|------------------------|----------------------------------|------------------------|-----------------------------------|
| struct    | 9.692  | 0.112 | 14.410 |
| class  | 9.087334 |  0.927201 | 0.653186 |


###  100 000:
|                        | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|------------------------|----------------------------------|------------------------|-----------------------------------|
| struct      | 1.188 | 0.012  | 0.885 |
| class  | 1.017983 |  0.054632 | 0.058039 |

### Optimizavimo strategijų (O1, O2, O3) laiko palyginimas:
### 10 000 000:
| Optimization Level | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|--------------------|----------------------------------|------------------------|-----------------------------------|
| O1                | 64.868174                        | 10.089373             | 2.419835                          |
| O2                | 47.086795                        | 9.124450             | 2.434581                         |
| O3                | 53.879896                        | 8.736600              | 2.757521                          |

### 1 000 000:
| O | Failo iš įrašų nuskaitymo laikas | Įrašų rūšiavimo laikas | Įrašų dalijimo į dvi grupes laikas |
|--------------------|----------------------------------|------------------------|-----------------------------------|
| O1                | 5.372545                        | 0.641815              | 0.197577                         |
| O2                | 6.024873                        | 0.798799              | 0.187038                         |
| O3                | 5.134171                        | 0.801610              | 0.196136                         |

### 100 000 Įrašų Laikų Palyginimas
| Optimizacijos Lygis | Failo iš įrašų nuskaitymo laikas (s) | Įrašų rūšiavimo laikas (s) | Įrašų dalijimo į dvi grupes laikas (s) |
|----------------------|--------------------------------------|----------------------------|---------------------------------------|
| O1 | 0.621154 | 0.025546 | 0.026564 |
| O2 | 0.737948 | 0.024996 | 0.037737 |
| O3 | 0.616188 | 0.026672 | 0.029621 |

