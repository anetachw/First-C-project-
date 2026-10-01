// studentu valdymo programa
#include <iostream>
#include "studentas.h"
#include "funkcijos.h"
#include <array>

const int failu_kiekis = 5;
const std::array<int, failu_kiekis> failu_dydziai = {1000, 10000, 100000, 1000000, 10000000};
const std::array<std::string, failu_kiekis> failai = {"stud1000.txt", "stud10000.txt", "stud100000.txt", "stud1000000.txt", "stud10000000.txt"};
    

int main(){
    std::vector<studentas> grupe; 
    std::vector<studentas> kietiakai;
    std::vector<studentas> vargsiukai;
    std::random_device rd;
    std::mt19937 mt(rd());
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