# Objektinis programavimas C++

### v0.2 spartos analizė
Spartos analizė atlikta naudojant iš anksto sugeneruotus testinius failus (generavimo laikai išmatuoti atskirai). Kiekvienas testas kartotas 5 kartus, o lentelėje pateikti gautų laiko matavimų vidurkiai sekundėmis.

| **failas**       | **generavimas** | **skaitymas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
|------------------|-----------------|---------------|---------------|-------------------------|--------------------------|-------------|
| stud1000.txt     | 0.003594        | 0.002739      | 0.000101      | 0.001111                | 0.000898                 | 0.004850    |
| stud10000.txt    | 0.022415        | 0.010926      | 0.000427      | 0.003970                | 0.002948                 | 0.018272    |
| stud100000.txt   | 0.097393        | 0.091211      | 0.003741      | 0.033968                | 0.024201                 | 0.153122    |
| stud1000000.txt  | 0.831372        | 0.888562      | 0.038575      | 0.314916                | 0.231454                 | 1.473507    |
| stud10000000.txt | 7.98082         | 9.890693      | 0.786643      | 3.324069                | 2.467363                 | 16.468768   |

*Pastaba „Bendras laikas“ apima failo nuskaitymą, duomenų dalijimą ir abiejų rezultatų failų įrašymą (be failo generavimo laiko).*

Atlikta spartos analizė įrodo, kad optimizuota programa pasižymi linijiniu laiko sudėtingumu (O(N)): padidinus duomenų kiekį 10 kartų, apdorojimo laikas padidėja proporcingai. Pagrindinis programos laiko sąnaudų šaltinis yra nuskaitymo ir rašymo operacijos, tuo tarpu pati duomenų dalijimo operacija atmintyje atliekama labai greitai, net ir su 10 mln. įrašų.
