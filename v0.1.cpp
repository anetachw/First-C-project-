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


int main(){
    std::vector<studentas>grupe; 
    studentas A;
    int k;
    std::cout << "Iveskite studentu kieki: ";
    int n;
    std::cin >> n;

    for(int j=0; j < n; j++){
        std::cout << "Iveskite per tarpa studentu varda ir pavarde: ";
        std::cin >> A.vardas >> A.pavarde;
        std::cout << "Iveskite semestro pazymiu kieki: ";
        std::cin >> k;
        
        for (int i = 0; i < k; i++){
            //std::cin >> A.paz[i];
            std::cout << "Iveskite #" << i+1 << " pazymi: ";
            int a;
            std::cin >> a;
            A.paz.push_back(a);
        }
    
    std::cout << "Iveskite egzamino pazymi: ";
    std::cin >> A.exam;
    grupe.push_back(A);
    A.pavarde.clear();
    A.vardas.clear();
    A.paz.clear();
    }
    
    std::cout << "Studentu duomenys: \n";
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
}