# Studentų Rezultatų Skaičiavimo Sistema
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

