#pragma once 

#include "studentas.h"
#include <string>
#include <random>

double galutinis_vid(const studentas &A);
double mediana(std::vector<int> paz);
double galutinis_med(const studentas &A);
int ar_skaicius(std::string tekstas, int min, int max);

void rodyti_meniu();
void printas(const studentas &A);
void rodyti_lentele(const std::vector<studentas> &grupe);
void rodyti_rezultatus(const std::vector<studentas> &grupe);

void rankine_ivestis(std::vector<studentas> &grupe);
void generuoti_paz(studentas &A, int count, std::mt19937 &mt);
void automatine_ivestis(std::vector<studentas> &grupe, std::mt19937 &mt);
void nuskaityti_faila(std::vector<studentas> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::vector<studentas> &grupe);
void rusiavimasG(std::vector<studentas> &grupe);
void rusiavimo_meniu(std::vector<studentas> &grupe);

void generuoti_faila(std::string failoPavadinimas, int stud_kiekis, int nd_kiekis, std::mt19937 &mt);
bool failas_egzistuoja(const std::string &failoPavadinimas);
void rasyti_i_faila(const std::vector<studentas> &grupe, std::string failoPavadinimas);
void dalinti_studentus(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, std::vector<studentas> &vargsiukai);
void spartos_analize(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, 
                     std::vector<studentas> &vargsiukai, std::string failoPavadinimas, int kartojimai = 5);
