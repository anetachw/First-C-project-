#pragma once 

#include "studentas.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <random>
#include <chrono>
#include <vector>


void generuoti_faila(std::string failoPavadinimas, int stud_kiekis, int nd_kiekis, std::mt19937 &mt);

bool failas_egzistuoja(const std::string &failoPavadinimas);

int ar_skaicius(std::string tekstas, int min, int max);

void rodyti_meniu(); 

void rodyti_konteineri();


template <typename T>
double galutinis_vid(const T &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double suma = std::accumulate(A.paz.begin(), A.paz.end(), 0.0);
    double vidurkis = suma / A.paz.size();

    return 0.4 * vidurkis + 0.6 * A.exam;
};

template <typename T>
double mediana(const T &paz) {
    if (paz.empty()) return 0.0;

    std::vector<typename T::value_type> v(paz.begin(), paz.end());
    
    std::sort(v.begin(), v.end());
    size_t n = v.size();

    if (n % 2 != 0) {
        return v[n / 2];
    } else {
        return (v[(n - 1) / 2] + v[n / 2]) / 2.0;
    }
};

template <typename T>
double galutinis_med(const T &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double med = mediana(A.paz);
    
    return 0.4 * med + 0.6 * A.exam;
};

template <typename T>
void printas(const T &A){
    std::cout << "|" << std::left << std::setw(14) << A.vardas 
              << "|" << std::left << std::setw(16) << A.pavarde << "|"
              << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_vid(A) << "|"
              << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_med(A)<<  "|\n";
};

template <typename T>
void generuoti_paz(T &A, int count, std::mt19937 &mt){
    std::uniform_int_distribution<int> dist(1, 10);

    for(int i = 1; i <= count; i++){
        int num = dist(mt);
        A.paz.push_back(num);
    }
    A.exam = dist(mt);
};

template <typename T>
void rodyti_lentele(const T &grupe){
    std::cout << '\n' << "Studentų duomenys: \n";
    std::cout << std::string(67, '-') << '\n';
    std::cout << "|" << std::left << std::setw(14) << "Vardas" 
              << "|" << std::left << std::setw(16) << "Pavarde" 
              << "|" << std::left << std::setw(16) << "Galutinis (Vid.)"
              << "|" << std::left << std::setw(16) << "Galutinis (Med.)"<< "|\n";
    std::cout << std::string(67, '-') << '\n';
    for(const auto &B : grupe) printas(B);
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
    f << std::string(67, '-') << '\n';

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

template <typename T> 
void spartos_analize(T &grupe, T &kietiakai, T &vargsiukai, const std::string failoPavadinimas, int kartojimai = 3){
    std::cout << "\nAnalizuojamas failas: " << failoPavadinimas << '\n';
    double suma_nuskaitymas = 0.0;
    double suma_rusiavimas = 0.0;
    double suma_dalijimas = 0.0;
    double suma_kietiakai = 0.0;
    double suma_vargsiukai = 0.0;
    
    for (int k = 0; k < kartojimai; k++){
        grupe.clear();
        vargsiukai.clear();
        kietiakai.clear();

        auto start = std::chrono::high_resolution_clock::now();
        nuskaityti_faila(grupe, "/Users/aneta/Documents/VU/C++/" + failoPavadinimas);
        auto end = std::chrono::high_resolution_clock::now();
        suma_nuskaitymas += std::chrono::duration<double>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        rusiavimasG(grupe);
        end = std::chrono::high_resolution_clock::now();
        suma_rusiavimas += std::chrono::duration<double>(end - start).count();
        
        start = std::chrono::high_resolution_clock::now();
        dalinti_studentus1(grupe, kietiakai, vargsiukai);
        end = std::chrono::high_resolution_clock::now();
        suma_dalijimas += std::chrono::duration<double>(end - start).count();
        
        start = std::chrono::high_resolution_clock::now();
        rasyti_i_faila(kietiakai, "kietiakai_" + (failoPavadinimas));
        end = std::chrono::high_resolution_clock::now();
        suma_kietiakai += std::chrono::duration<double>(end - start).count();
        
        start = std::chrono::high_resolution_clock::now();
        rasyti_i_faila(vargsiukai, "vargsiukai_" + (failoPavadinimas));
        end = std::chrono::high_resolution_clock::now();
        suma_vargsiukai += std::chrono::duration<double>(end - start).count();
    } 

    double vid_nuskaitymas = suma_nuskaitymas / kartojimai;
    double vid_rusiavimas = suma_rusiavimas / kartojimai;
    double vid_dalijimas = suma_dalijimas / kartojimai;
    double vid_kietiakai = suma_kietiakai / kartojimai;
    double vid_vargsiukai = suma_vargsiukai / kartojimai;
    double bendras_vid = vid_nuskaitymas + vid_rusiavimas + vid_dalijimas + vid_kietiakai + vid_vargsiukai;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Vidutinis duomenų nuskaitymas:         " << vid_nuskaitymas << "s\n";
    std::cout << "Vidutinis duomenų rūšiavimas:          " << vid_rusiavimas << "s\n";
    std::cout << "Vidutinis studentų dalijimas:          " << vid_dalijimas << "s\n";
    std::cout << "Vidutinis kietiakių įrašymas į failą:  " << vid_kietiakai << "s\n";
    std::cout << "Vidutinis vargšiukų įrašymas į failą:  " << vid_vargsiukai << "s\n";
    std::cout << "Bendras vidutinis testo laikas:        " << bendras_vid << "s\n";
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
            pasirinkimas = ar_skaicius("\nPasirinkite veiksma (0-7): ", 0, 7);

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
                    if(!kietiakai.empty()){
                        std::cout << "\nKietiakai";
                        rodyti_rezultatus(kietiakai);;
                    }
                    if(!vargsiukai.empty()){
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
                case 7: {
                    grupe.clear();
                    kietiakai.clear();
                    vargsiukai.clear();
                    std::cout << "Studentų duomenis išvalyti";
                    break;
                }   
            }
        } while(pasirinkimas != 0);
};

