// student managment program
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>

struct studentas{
    std::string vardas, pavarde;
    std::vector<int> paz;
    int exam;
    };
    
void printas(studentas &A);
double galutinis_vid(studentas &A);
double mediana(std::vector<int> paz);
double galutinis_med(studentas &A);
std::vector<int> generuoti_paz(studentas &A, int count);


int main(){
    std::vector<studentas>grupe; 
    studentas A;
    int k;
    std::cout << "Iveskite studentu kieki: ";
    int n;
    std::cin >> n;

    for(int j=0; j < n; j++){
        std::cout << "Iveskite per tarpa studento varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Iveskite kiek namu darbu pazymiu norite sugeneruoti: ";
        int kiekis;
        std::cin >> kiekis;

        generuoti_paz(A, kiekis);
        std::cout << "Pazymiai: ";
        for ( int p: A.paz) {
            std::cout << p << " ";
        }
        std::cout << '\n';

        A.exam = (rand() % 10) + 1;
        grupe.push_back(A);
        std::cout << "Egzamino rezultatas: " << A.exam << '\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


/*
        std::string input1;
        std::cout << "Iveskite namu darbu pazymius.\n";
        std::cout << "Palikite tusia ir spauskite ENTER, kad bagti.\n";
        int i = 1;

        do {
            std::cout << "Iveskite #" << i << " pazymi: ";
            std::getline(std::cin, input1);
            if (!input1.empty()){
                try {
                    int a = std::stoi(input1);
                    if (a >= 1 && a <= 10){
                        A.paz.push_back(a);
                        i++;
                    }
                    else {
                        std::cout << "Klaida! Pazymis turi buti nuo 1 iki 10. Bandykite dar karta.";
                    }
                }
                catch (...){
                    std::cout << "Klaida! Ivedete ne skaiciu, bandykite dar karta. \n";
                }
            }     
        } while(!input1.empty());

    std::string input2;
    while (true) {
        std::cout << "Iveskite egzamino pazymi: ";
        std::getline(std::cin, input2);

        try{
            A.exam = std::stoi(input2);
            if (A.exam >= 1 && A.exam <= 10){
                grupe.push_back(A);
                break;
            }
            else {
                std::cout << "Klaida! Pazymis turi buti nuo 1 iki 10.\n";
            }
        } catch (...) {
            std::cout << "Klaida! Ivedete ne skaiciu, bandykite dar karta. \n";
        }
    }
*/
    A.pavarde.clear();
    A.vardas.clear();
    A.paz.clear();
    }
    
    std::cout << '\n' << "Studentu duomenys: \n";
    std::cout << std::string(57, '-') << '\n';
    std::cout << "|" << std::left << std::setw(10) << "Vardas" 
              << "|" << std::left << std::setw(10) << "Pavarde" 
              << "|" << std::left << std::setw(16) << "Galutinis (Vid.)"
              << "|" << std::left << std::setw(16) << "Galutinis (Med.)"<< "|\n";
    std::cout << std::string(57, '-') << '\n';
    for(studentas &B:grupe) printas(B);
    std::cout << std::string(57, '-') << '\n';
}

void printas(studentas &A){
    std::cout << "|" << std::left << std::setw(10) << A.vardas 
              << "|" << std::left << std::setw(10) << A.pavarde << "|"
              << std::left << std::setw(16) << std::setprecision(2)<< galutinis_vid(A) << "|"
              << std::left << std::setw(16) << std::setprecision(2)<< galutinis_med(A)<<  "|\n";
};

double galutinis_vid(studentas &A){
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

double galutinis_med(studentas &A){
    if (A.paz.empty()){
        return 0.6 * A.exam;
    }
    double med = mediana(A.paz);
    
    return 0.4 * med + 0.6 * A.exam;
};

std::vector<int> generuoti_paz(studentas &A, int count){
    srand(time(NULL));

    for(int i = 1; i <= count; i++){
        int num = (rand() % 10) + 1;
        A.paz.push_back(num);
    }

    return A.paz;
}