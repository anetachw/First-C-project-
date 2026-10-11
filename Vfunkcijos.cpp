#include "basic_funkcijos.h"
#include "Vfunkcijos.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <chrono>


void rankine_ivestis(std::vector<studentas> &grupe){
    int stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 30);
    grupe.reserve(grupe.size() + stud_kiekis);

    for(int j=0; j < stud_kiekis; j++){
        studentas tempStudentas;
        tempStudentas.paz.reserve(10);

        std::cout << "Įveskite per tarpa studento vardą ir pavardę: ";
        std::cin >> tempStudentas.vardas >> tempStudentas.pavarde;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string input1;
        std::cout << "Įveskite namų darbų pažymius.\n";
        std::cout << "Palikite tuščia ir spauskite ENTER, kad tęsti.\n";
        int i = 1;

        do {
            std::cout << "Įveskite #" << i << " pažymį: ";
            std::getline(std::cin, input1);
            if (!input1.empty()){
                try {
                    int a = std::stoi(input1);
                    if (a >= 1 && a <= 10){
                        tempStudentas.paz.push_back(a);
                        i++;
                    }
                    else {
                        std::cout << "Klaida! Pažymis turi būti nuo 1 iki 10.\n";
                    }
                }
                catch (...){
                    std::cout << "Klaida! Ivedėte ne skaičių, bandykite dar karta.\n";
                }
            }     
        } while(!input1.empty());

        std::string input2;
        while (true) {
            std::cout << "Įveskite egzamino pažymį: ";
            std::getline(std::cin, input2);

            try{
                tempStudentas.exam = std::stoi(input2);
                if (tempStudentas.exam >= 1 && tempStudentas.exam <= 10){
                    break;
                }
                else {
                    std::cout << "Klaida! Pažymis turi būti nuo 1 iki 10.\n";
                }
            } catch (...) {
                std::cout << "Klaida! Ivedėte ne skaičių, bandykite dar karta.\n";
            }
        }
        std::cout << "Objekto adresas atmintyje: " << &tempStudentas << '\n'; 
        grupe.push_back(tempStudentas);
    }

};

void automatine_ivestis(std::vector<studentas> &grupe, std::mt19937 &mt){
    int stud_kiekis = ar_skaicius("Įveskite studentų kiekį: ", 1, 10000000);
    grupe.reserve(grupe.size() + stud_kiekis);

    int nd_kiekis = ar_skaicius("Įveskite kiek namų darbų pažymių norite sugeneruoti: ", 1, 10); 

    for(int j=0; j < stud_kiekis; j++){
        studentas tempStudentas;
        tempStudentas.paz.reserve(nd_kiekis);
        tempStudentas.vardas = "Vardas" + std::to_string(j + 1);
        tempStudentas.pavarde = "Pavarde" + std::to_string(j + 1);
        generuoti_paz(tempStudentas, nd_kiekis, mt);
        grupe.push_back(tempStudentas);
    }
};

void nuskaityti_faila(std::vector<studentas> &grupe, const std::string failoPavadinimas){
    std::ifstream f(failoPavadinimas, std::ios::ate);

    if(!f.is_open()){
        std::cout << "Nepavyko atidaryti failo: " << failoPavadinimas << '\n';
        return;
    };

    std::streamsize file_size = f.tellg();
    f.seekg(0, std::ios::beg); 
    size_t eil_sk = file_size / 134;
    grupe.reserve(grupe.size() + eil_sk);
    
    std::string eilute;
    std::getline (f, eilute);

    std::stringstream ss;
    while(std::getline(f, eilute)){
        if (eilute.empty()) continue;
        ss.str(eilute);
        ss.clear();

        studentas tempStudentas; 
        tempStudentas.paz.reserve(11);
        ss >> tempStudentas.vardas >> tempStudentas.pavarde;

        int skaicius;
        while (ss >> skaicius){
            tempStudentas.paz.push_back(skaicius);
        }

        if (!tempStudentas.paz.empty()){
            tempStudentas.exam = tempStudentas.paz.back();
            tempStudentas.paz.pop_back();
        }

        grupe.push_back(tempStudentas);
    }

    f.close();
};

void rusiavimasPV(std::vector<studentas> &grupe){
    std::sort(grupe.begin(), grupe.end(),
        [](const studentas &a, const studentas &b){
            if (a.pavarde != b.pavarde){
                return a.pavarde < b.pavarde;
            }
            return a.vardas < b.vardas;
    });
};

void rusiavimasG(std::vector<studentas> &grupe){
    std::sort(grupe.begin(), grupe.end(),
        [](const studentas &a, const studentas &b){
            return galutinis_vid(a) > galutinis_vid(b);
    });
};


void dalinti_studentus(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, std::vector<studentas> &vargsiukai){
    auto atrinkti = std::stable_partition(grupe.begin(), grupe.end(), [](const studentas &s) {
        return galutinis_vid(s) >= 5.0;
    });

    vargsiukai.reserve(grupe.size() / 2);
    kietiakai.reserve(grupe.size() / 2);

    kietiakai.assign(grupe.begin(), atrinkti);
    vargsiukai.assign(atrinkti, grupe.end());
};

void spartos_analize(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, 
                     std::vector<studentas> &vargsiukai, const std::string failoPavadinimas, int kartojimai){
    
    std::cout << "\nAnalizuojamas failas: " << failoPavadinimas << '\n';
    double suma_nuskaitymas = 0.0;
    double suma_dalijimas = 0.0;
    double suma_kietiakai = 0.0;
    double suma_vargsiukai = 0.0;
    
    for (int k = 0; k < kartojimai; k++){
        grupe.clear();
        vargsiukai.clear();
        kietiakai.clear();

        auto start = std::chrono::high_resolution_clock::now();
        nuskaityti_faila(grupe, "/Users/aneta/Documents/VU/C++/" + failoPavadinimas);
        rusiavimasPV(grupe);
        auto end = std::chrono::high_resolution_clock::now();
        suma_nuskaitymas += std::chrono::duration<double>(end - start).count();
        
        start = std::chrono::high_resolution_clock::now();
        dalinti_studentus(grupe, kietiakai, vargsiukai);
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
    double vid_dalijimas = suma_dalijimas / kartojimai;
    double vid_kietiakai = suma_kietiakai / kartojimai;
    double vid_vargsiukai = suma_vargsiukai / kartojimai;
    double bendras_vid = vid_nuskaitymas + vid_dalijimas + vid_kietiakai + vid_vargsiukai;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Vidutinis duomenų nuskaitymas:         " << vid_nuskaitymas << "s\n";
    std::cout << "Vidutinis studentų dalijimas:          " << vid_dalijimas << "s\n";
    std::cout << "Vidutinis kietiakių įrašymas į failą:  " << vid_kietiakai << "s\n";
    std::cout << "Vidutinis vargšiukų įrašymas į failą:  " << vid_vargsiukai << "s\n";
    std::cout << "Bendras vidutinis testo laikas:        " << bendras_vid << "s\n";
}   