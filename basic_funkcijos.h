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

void rodyti_konteineri();

void printas(const studentas &A);

void generuoti_paz(studentas &A, int count, std::mt19937 &mt);

void generuoti_faila(std::string failoPavadinimas, int stud_kiekis, int nd_kiekis, std::mt19937 &mt);

bool failas_egzistuoja(const std::string &failoPavadinimas);
