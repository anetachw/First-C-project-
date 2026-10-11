#pragma once 

#include "studentas.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <random>


double galutinis_vid(const studentas &A);

double mediana(std::vector<int> paz);

double galutinis_med(const studentas &A);

int ar_skaicius(std::string tekstas, int min, int max);

void rodyti_meniu();

void printas(const studentas &A);

void generuoti_paz(studentas &A, int count, std::mt19937 &mt);

void generuoti_faila(std::string failoPavadinimas, int stud_kiekis, int nd_kiekis, std::mt19937 &mt);

bool failas_egzistuoja(const std::string &failoPavadinimas);


template <typename T>
void rodyti_lentele(const T &grupe){
    std::cout << '\n' << "Studentų duomenys: \n";
    std::cout << std::string(67, '-') << '\n';
    std::cout << "|" << std::left << std::setw(14) << "Vardas" 
              << "|" << std::left << std::setw(16) << "Pavarde" 
              << "|" << std::left << std::setw(16) << "Galutinis (Vid.)"
              << "|" << std::left << std::setw(16) << "Galutinis (Med.)"<< "|\n";
    std::cout << std::string(67, '-') << '\n';
    for(const studentas &B : grupe) printas(B);
    std::cout << std::string(67, '-') << '\n';
};

template <typename T>
void rodyti_rezultatus(const T &grupe){
    int limit = 30; 

    if (grupe.size() > limit) {
        std::cout << "\nStudentų kiekis didelis (" << grupe.size() << ")."; 
        std::cout << "Rezultatai bus išsaugoti faile.\n";
        std::string failoPavadinimas;
        std::cout << "Įveskite failo pavadinimą į kurį norite išsaugoti rezultatus: ";
        std::cin >> failoPavadinimas;
        rasyti_i_faila(grupe, failoPavadinimas);
    } else {
        rodyti_lentele(grupe);
    }
};

template <typename T>
void rasyti_i_faila(const T &grupe, std::string failoPavadinimas){
    std::ofstream f(failoPavadinimas);

    if (!f.is_open()) {
        std::cout << "Klaida! Nepavyko sukurti failo.\n";
        return;
    }

    f << std::string(67, '-') << '\n';
    f << "|" << std::left << std::setw(14) << "Vardas" 
      << "|" << std::left << std::setw(16) << "Pavardė" 
      << "|" << std::left << std::setw(16) << "Galutinis (Vid.)"
      << "|" << std::left << std::setw(16) << "Galutinis (Med.)"<< "|\n";
    f << std::string(67, '-') << '\n';

    for(const auto &s : grupe){
        f << "|" << std::left << std::setw(14) << s.vardas 
          << "|" << std::left << std::setw(16) << s.pavarde << "|"
          << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_vid(s) << "|"
          << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_med(s)<<  "|\n";
    }

    f.close();
};

template <typename T>
void rusiavimo_meniu(T &grupe){
    std::cout << "\nPasirinkite rūšiavimo būdą:\n";
    std::cout << "1. Rūšiuoti pagal Vardą/Pavardę\n";
    std::cout << "2. Rūšiuoti pagal galutinį rezultatą\n";
    int r = ar_skaicius("Jūsų pasirinkimas: ", 1, 2);
    
    if (r == 1){
        rusiavimasPV(grupe);
    } else if (r == 2){
        rusiavimasG(grupe);
    }
};