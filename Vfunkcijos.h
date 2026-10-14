#pragma once 

#include "studentas.h"
#include <string>
#include <random>


void rankine_ivestis(std::vector<studentas> &grupe);
void automatine_ivestis(std::vector<studentas> &grupe, std::mt19937 &mt);
void nuskaityti_faila(std::vector<studentas> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::vector<studentas> &grupe);
void rusiavimasG(std::vector<studentas> &grupe);

void dalinti_studentus(std::vector<studentas> &grupe, std::vector<studentas> &kietiakai, std::vector<studentas> &vargsiukai);
