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

>Sukompiliuoti programą galite su šia komanda:
>
>```bash
>g++ main.cpp ivedimas.cpp duomenys.cpp vertinimas.cpp rikiavimas.cpp rezultatas.cpp -o studentu_rezultatai
>```
>
>Paleisti programą galite su šia komanda:
>
>```bash
>./studentu_rezultatai
>```
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

## Vidutiniai laiko spartos matavimai
| **Studentų skaičius** | **Failo genravimas (sek)** | **Rūšiavimas į 2 kategorijas (sek)** | Išvedimas į 2 failus (sek) |
|------------------|--------------------|-----------------------|----------------------|
| 1,000            | 0.0028             | 0.004                 | 0.010                |
| 10,000           | 0.0294              | 0.811                 | 0.499                |
| 100,000          | 0.2462            | 2.825                 | 0.176                |
| 1,000,000        | 1.7686             | 3.529                 | 2.327                |
| 10,000,000       | 12.1972            | 11.268                | 39.660               |

## Naujos funkcijos:
- generuotiDuomenis() -  generuojami 5 studentų failai (studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt)
- skaiciavimai() - paskaičiuojamas vidurkis arba mediana kiekvienam studentui esančiam faile ir duomenys išsaugomi struktūroje
- padalintiStudentus() - padalinami studentai į 2 kategorijas
- isvestiIFailus() - išvedami studentai į du atskirus failus (kietiakai.txt, vargšiukai.txt)

# v0.3
Vietoje std::vector<Studentai> naudojame std::list<Studentai>.

## Vidutiniai laiko spartos matavimai
| **Studentų skaičius** | **Failo genravimas (sek)** | **Rūšiavimas į 2 kategorijas (sek)** | Išvedimas į 2 failus (sek) |
|------------------|--------------------|-----------------------|----------------------|
| 1,000            | 0.003             | 0.002                 | 0.007                |
| 10,000           | 0.018              | 0.015                 | 0.065                |
| 100,000          | 0.098            | 0.122                 | 0.828                |
| 1,000,000        | 1.079             | 1.243                 | 3.727                |
| 10,000,000       | 9.008            | 15.039                | 235.011               |
