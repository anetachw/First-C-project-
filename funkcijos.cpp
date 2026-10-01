#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <chrono>


double galutinis_vid(const studentas &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double suma = std::accumulate(A.paz.begin(), A.paz.end(), 0.0);
    double vidurkis = suma / A.paz.size();

    return 0.4 * vidurkis + 0.6 * A.exam;
};

double mediana(std::vector<int> paz){
    if (paz.empty()) return 0.0;

    std::sort(paz.begin(), paz.end());
    int n = paz.size();

    if (n % 2 != 0){
        return paz[n / 2];
    }
    else{
        return (paz[(n-1) / 2] + paz[n / 2]) / 2.0;
    }
}; 

double galutinis_med(const studentas &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double med = mediana(A.paz);
    
    return 0.4 * med + 0.6 * A.exam;
};

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
    std::cout << "| 0. Baigti darbą                              |\n";
    std::cout << "------------------------------------------------\n";
};

void printas(const studentas &A){
    std::cout << "|" << std::left << std::setw(14) << A.vardas 
              << "|" << std::left << std::setw(16) << A.pavarde << "|"
              << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_vid(A) << "|"
              << std::left << std::setw(16) << std::fixed << std::setprecision(2)<< galutinis_med(A)<<  "|\n";
};

void rodyti_lentele(const std::vector<studentas> &grupe){
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

void rodyti_rezultatus(const std::vector<studentas> &grupe) {
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
        grupe.push_back(tempStudentas);
    }

};

void generuoti_paz(studentas &A, int count, std::mt19937 &mt){
    std::uniform_int_distribution<int> dist(1, 10);

    for(int i = 1; i <= count; i++){
        int num = dist(mt);
        A.paz.push_back(num);
    }
    A.exam = dist(mt);
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

void rusiavimo_meniu(std::vector<studentas> &grupe){
    int r;
    std::cout << "Pasirinkite rūšiavimo būdą:\n";
    std::cout << "1. Rūšiuoti pagal Vardą/Pavardę\n";
    std::cout << "2. Rūšiuoti pagal galutinį rezultatą\n";
    r = ar_skaicius("Jūsų pasirinkimas: ", 1, 2);
    
    if (r == 1){
        rusiavimasPV(grupe);
    } else if (r == 2){
        rusiavimasG(grupe);
    }
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

void rasyti_i_faila(const std::vector<studentas> &grupe, std::string failoPavadinimas){
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

void dalinti_studentus(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, std::vector<studentas> &vargsiukai){
    auto atrinkti = std::stable_partition(grupe.begin(), grupe.end(), [](const studentas &s) {
        return galutinis_vid(s) > 5.0;
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