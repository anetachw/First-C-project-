#include "basic_funkcijos.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>


int ar_skaicius(std::string tekstas, int min, int max){
    int skaicius;
    while(true){
        std::cout << tekstas;
        if(std::cin >> skaicius && skaicius >= min && skaicius <= max){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return skaicius;
        }

        std::cout << "Klaida! Įveskite tinkama skaičių nuo " << min << " iki " << max << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}; 

void rodyti_meniu(){
    std::cout << "\n------------------------------------------------\n";
    std::cout << "|           STUDENTŲ VALDYMO SISTEMA           |\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "| 1. Įvesti studentų duomenis rankiniu būdu    |\n";
    std::cout << "| 2. Generuoti studentų pažymius atsitiktinai  |\n";
    std::cout << "| 3. Nuskaityti duomenis iš failo              |\n";
    std::cout << "| 4. Generuoti testavimo failus                |\n";
    std::cout << "| 5. Padalinti studentus į dvi kategorijas     |\n";
    std::cout << "| 6. Atlikti spartos analize                   |\n";
    std::cout << "| 7. Atlikti dalijimo analize                  |\n";
    std::cout << "| 8. Išvalyti studentų duomenis                |\n";
    std::cout << "| 0. Baigti darbą                              |\n";
    std::cout << "------------------------------------------------\n";
};

void rodyti_konteineri(){
    std::cout << "\n------------------------------\n";
    std::cout << "|        KONTEINERIAI        |\n";
    std::cout << "------------------------------\n";
    std::cout << "| 1. Vektorius               |\n";
    std::cout << "| 2. Sąrašas                 |\n";
    std::cout << "------------------------------\n";
};

void generuoti_faila(std::string failoPavadinimas, int stud_kiekis, int nd_kiekis, std::mt19937 &mt){
    std::ofstream f(failoPavadinimas);
    std::uniform_int_distribution<int> dist(1, 10);

    if (!f.is_open()) {
        std::cout << "Klaida! Nepavyko sukurti failo.\n";
        return;
    }

    f << std::left << std::setw(16) << "Vardas" << std::setw(16) << "Pavardė";
    for(int i = 1; i <= nd_kiekis; i++){
        f << std::left << std::setw(10) << ("ND" + std::to_string(i));
    }
    f << std::left << std::setw(10) << "Egz" << '\n';

    for(int i = 1; i <= stud_kiekis; i++){
        f << std::left << std::setw(16) << ("Vardas" + std::to_string(i))
          << std::setw(16) << ("Pavarde" + std::to_string(i));
        
        for(int j = 1; j <= nd_kiekis; j++){
            f << std::setw(10) << dist(mt);
        }
        f << std::setw(10) << dist(mt) << '\n';
    }

    f.close();
};

bool failas_egzistuoja(const std::string &failoPavadinimas){
    std::ifstream f(failoPavadinimas.data());
    return f.is_open();
};


