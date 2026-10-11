#pragma once 

#include "studentas.h"
#include "basic_funkcijos.h"
#include "Vfunkcijos.h"
#include "Lfunkcijos.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <random>
#include <chrono>

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


const int failu_kiekis = 5;
const std::array<int, failu_kiekis> failu_dydziai = {1000, 10000, 100000, 1000000, 10000000};
const std::array<std::string, failu_kiekis> failai = {"stud1000.txt", "stud10000.txt", "stud100000.txt", "stud1000000.txt", "stud10000000.txt"};

template <typename T> 
void paleisti_programa(std::mt19937 &mt){
     T grupe;
     T kietiakai;
     T vargsiukai;
    
    int pasirinkimas;
        do{
            rodyti_meniu();
            pasirinkimas = ar_skaicius("\nPasirinkite veiksma (0-6): ", 0, 6);

            switch(pasirinkimas){
                case 0: 
                    std::cout << "Darbas baigtas\n";
                    break;
                case 1:
                    rankine_ivestis(grupe);
                    rusiavimo_meniu(grupe);
                    rodyti_lentele(grupe);
                    break;
                case 2:
                    automatine_ivestis(grupe, mt);
                    rusiavimo_meniu(grupe);
                    rodyti_rezultatus(grupe);
                    break;
                case 3: {
                    std::cout << "Įveskite failo pavadinimą: ";
                    std::string failas;
                    std::cin >> failas; 
                    nuskaityti_faila(grupe, failas);
                    rusiavimo_meniu(grupe);
                    if(!grupe.empty()){
                        rodyti_rezultatus(grupe);
                    }
                    break;
                    }
                case 4:
                    char input;
                    std::cout << "Ar norite sugeneruoti testinius failus? (t/n): ";
                    std:: cin >> input;
                    if(input == 't'){
                        for (int i = 0; i < failu_kiekis; i++){
                            if(!failas_egzistuoja(failai[i])){
                                auto start = std::chrono::high_resolution_clock::now();
                                generuoti_faila(failai[i], failu_dydziai[i], 10, mt);
                                auto end = std::chrono::high_resolution_clock::now();
                                std::chrono::duration<double> f_sukurimas = end - start;
                                std::cout << "Failo " << failai[i] << " generavimo laikas: " << f_sukurimas.count() << "s.\n";
                            } else{
                                std::cout << "Failas " << failai[i] << " jau egzistuoja.\n";
                            }
                        }
                    } 
                    break;
                case 5:
                    dalinti_studentus(grupe, kietiakai, vargsiukai);
                    if(!grupe.empty()){
                        std::cout << "\nKietiakai";
                        rodyti_rezultatus(kietiakai);;
                    }
                    if(!grupe.empty()){
                        std::cout << "\nVargšiukai";
                        rodyti_rezultatus(vargsiukai);
                    }
                    break;
                case 6:
                    std::cout << "\nSpartos analizė:";
                    for (int i = 0; i < failu_kiekis; i++){
                        spartos_analize(grupe, kietiakai, vargsiukai, failai[i]);
                    }
                    break; 
            }
        } while(pasirinkimas != 0);
};
