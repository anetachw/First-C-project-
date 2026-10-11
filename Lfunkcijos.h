#pragma once 

#include "studentas.h"
#include <string>
#include <list>
#include <random>


void rankine_ivestis(std::list<studentas> &grupe);
void automatine_ivestis(std::list<studentas> &grupe, std::mt19937 &mt);
void nuskaityti_faila(std::list<studentas> &grupe, const std::string failoPavadinimas);

void rusiavimasPV(std::list<studentas> &grupe);
void rusiavimasG(std::list<studentas> &grupe);

void dalinti_studentus(std::list<studentas> &grupe, std::list<studentas> &kietiakai, std::list<studentas> &vargsiukai);
void spartos_analize(std::list<studentas> &grupe, std::list<studentas> &kietiakai, 
                     std::list<studentas> &vargsiukai, std::string failoPavadinimas, int kartojimai = 3);
