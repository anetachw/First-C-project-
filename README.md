# Studentų valdymo sistema C++ 

### Įdiegimo instrukcija

Prieš kompiliuojant ir paleidžiant projektą per `CMake` įsitikinkite, kad jūsų kompiuteryje yra įdiegtas C++ kompiliatorius. Jei kompilatoriaus neturite, tada teminale atlikite šiuos žingsnius:

- **Windows:**
  `winget install WinLibs.MinGW`

- **Linux:**
  `sudo apt update`
  `sudo apt install clang`

- **macOS:**
  `xcode-select --install`

 Sėkmingai įdegus kompilatorių galite pereiti prie programos paleidimo. Terminale atlikite tolimesnius žingsnius:

1. **Sukurkite ir atidarykite laikinąją direktoriją:**
```
    mkdir build
    cd build
```

2. **Sugeneruokite projekto failus per CMake:**
```
    cmake ..
```

3. **Sukompiliuokite projektą:**
```
    cmake --build .
```

4. **Paleiskite sugeneruotą programą:**
    - **Linux / macOS sistemose:** `./studentu_programa`
    - **Windows sistemoje:** `studentu_programa.exe`

---
### Naudojimosi instrukcija

Paleidus programą, terminale bus pateikiamas interaktyvus meniu. Programos eiga:

1. **Konteinerio pasirinkimas:** Programos pradžioje jūsų paprašys pasirinkti duomenų konteinerio tipą:
    - Pasirinkimas **`1`** – aktyvuoja `std::vector` paremtą studentų valdymo logiką.
    - Pasirinkimas **`2`** – aktyvuoja `std::list` paremtą studentų valdymo logiką.
    
2. **Pagrindinio meniu veiksmai:**
    - **`1`** – Įvesti studentų duomenis rankiniu būdu (įvedant vardą, pavardę, namų darbų ir egzamino pažymius).
    - **`2`** – Generuoti studentų duomenis bei pažymius atsitiktinai.
    - **`3`** – Nuskaityti studentų duomenis iš egzistuojančio tekstinio failo.
    - **`4`** – Sugeneruoti testavimo failus reikalingus spartos analizei.
    - **`5`** – Padalinti studentus į dvi kategorijas (_vargšiukus_ ir _kietiakus_).
    - **`6`** – Atlikti spartos analizę (matuojant nuskaitymo, rūšiavimo, dalijimo ir failų rašymo laiką).
    - **`7`** – Atlikti studentų dalijimo strategijų greičio analizę.
    - **`8`** – Išvalyti esamus studentų duomenis atmintyje.
    - **`0`** – Išeiti iš programos.


---
### Versija v0.1 (pradinė realizacija)
Pirmoji studentų valdymo programos versija orientuota į duomenų apdorojimą naudojant `std::vector` konteinerį.

#### Pagrindinės funkcijos:
- **Duomenų įvedimo būdai:**
    - **Rankinis įvedimas:** Galimybė įvesti studento vardą, pavardę, namų darbų pažymius bei egzamino pažymį (su įvesties validacija nuo 1 iki 10).
    - **Automatinis generavimas:** Atsitiktinis namų darbų pažymių generavimas nurodytam studentų kiekiui.
    - **Nuskaitymas iš failo:** Galimybė duomenis importuoti tiesiai iš tekstinio failo.
        
- **Skaičiavimai:**
    - Galutinio balo skaičiavimas remiantis vidurkiu (40% namų darbų vidurkis + 60% egzaminas).
    - Galutinio balo skaičiavimas remiantis mediana (40% namų darbų mediana + 60% egzaminas).
        
- **Rūšiavimas ir pateikimas:**
    - Automatinis studentų rūšiavimas abėcėlės tvarka pagal pavardę ir vardą.
    - Tvarkingas suformatuotų rezultatų atvaizdavimas terminalo lentelėje.

---

### Versija v0.2
Šioje versijoje pagrindinis dėmesys skirtas sistemos spartai, efektyviam atminties valdymui ir didelių duomenų kiekių apdorojimui. Papildomai projektas išskaidytas į atskirus antraštinius (studentas.h, funkcijos.h) ir realizacijos (funkcijos.cpp, mainproject.cpp) failus.
#### Naujos funkcijos:
- **Automatinis testinių failų generavimas:** Sukurta galimybė sugeneruoti didelius studentų įrašų failus su atsitiktiniais pažymiais ir egzaminų rezultatais.
- **Automatinis rašymas į failą:** Dirbant su dideliu studentų kiekiu, operacijų rezultatai automatiškai išsaugomi faile.
- **Automatizuota spartos analizė:** Įdiegta spartos analizės funkcija, atliekanti kelių iteracijų laiko matavimus ir apskaičiuojanti tikslius nuskaitymo, dalijimo bei rašymo laiko vidurkius.
- **Studentų kategorizavimas:** Įdiegtas atskyrimas į dvi kategorijas („kietiakai“ ≥5.0 ir „vargšiukai“ <5.0) su rezultatų išsaugojimu į atskirus failus.

---

### Versija v0.3 
Versijoje v0.3 pagrindinis dėmesys skirtas std::vector ir std::list konteinerių palyginimui ir spartos testavimui.
#### Pagrindiniai releaso ypatumai:
- **Konteinerio pasirinkimas:** Įdiegta galimybė pasirinkti tarp std::vector ir std::list struktūrų;
- **Funkcijų pritaikymas:** Galimos programos funkcijos pakeistos į šablonines, kitos papildomai perrašytos, kad veiktų su std::list struktūra.

---

### Versija v0.3.1 
**Pagrindinis versijos patobulinimas:** Dirbant su std::list studento struktūra pažymius irgi saugo std::list konteineryje, ne std::vector kaip tai buvo v0.3 versijos atveju. 

---

### Versija v1.0 
#### Pagrindiniai releaso ypatumai:



---
### Spartos analizė
Spartos analizė atlikta dirbant su std::vector ir std::list konteineriais naudojant iš anksto sugeneruotus testinius failus. Kiekvienas testas kartotas 5 kartus, o lentelėje pateikti gautų laiko matavimų vidurkiai sekundėmis.

**Testavimo sistemos parametrai**
- CPU: Apple M2
- RAM: 8G
- DISK: SSD

---
### v0.2 rezultatai:
**std::vector**

| **failas**       | **generavimas** | **skaitymas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
| ---------------- | --------------- | ------------- | ------------- | ----------------------- | ------------------------ | ------------------ |
| stud1000.txt     | 0.003594        | 0.002739      | 0.000101      | 0.001111                | 0.000898                 | 0.004850           |
| stud10000.txt    | 0.022415        | 0.010926      | 0.000427      | 0.003970                | 0.002948                 | 0.018272           |
| stud100000.txt   | 0.097393        | 0.091211      | 0.003741      | 0.033968                | 0.024201                 | 0.153122           |
| stud1000000.txt  | 0.831372        | 0.888562      | 0.038575      | 0.314916                | 0.231454                 | 1.473507           |
| stud10000000.txt | 7.98082         | 9.890693      | 0.786643      | 3.324069                | 2.467363                 | 16.468768          |

*Pastaba „Bendras laikas“ apima failo nuskaitymą, duomenų dalijimą ir abiejų rezultatų failų įrašymą (be failo generavimo laiko).*

Atlikta spartos analizė įrodo, kad optimizuota programa pasižymi linijiniu laiko sudėtingumu (O(N)): padidinus duomenų kiekį 10 kartų, apdorojimo laikas padidėja proporcingai. Pagrindinis programos laiko sąnaudų šaltinis yra nuskaitymo ir rašymo operacijos, tuo tarpu pati duomenų dalijimo operacija atmintyje atliekama labai greitai, net ir su 10 mln. įrašų.

---
### v0.3 rezultatai:
#### std::vector
|**failas**|**skaitymas**|**rūšiavimas**|**dalijimas**|**rašymas (kietiakai)**|**rašymas (vargšiukai)**|**bendras laikas**|
|---|---|---|---|---|---|---|
|stud1000.txt|0.002524s|0.000441s|0.000062s|0.001192s|0.000907s|0.005126s|
|stud10000.txt|0.009615s|0.001924s|0.000238s|0.003938s|0.002550s|0.018264s|
|stud100000.txt|0.078244s|0.016992s|0.002789s|0.030469s|0.021939s|0.150432s|
|stud1000000.txt|0.766029s|0.215568s|0.077011s|0.299067s|0.211799s|1.569475s|
|stud10000000.txt|8.022778s|2.946046s|1.021856s|3.151983s|2.265385s|17.408047s|

#### std::list
|**failas**|**skaitymas**|**rūšiavimas**|**dalijimas**|**rašymas (kietiakai)**|**rašymas (vargšiukai)**|**bendras laikas**|
|---|---|---|---|---|---|---|
|stud1000.txt|0.002369s|0.000417s|0.000015s|0.001345s|0.000830s|0.004976s|
|stud10000.txt|0.009833s|0.002544s|0.000077s|0.004089s|0.002662s|0.019205s|
|stud100000.txt|0.079353s|0.028916s|0.001630s|0.036066s|0.026530s|0.172494s|
|stud1000000.txt|0.777662s|0.622143s|0.118022s|0.388591s|0.281412s|2.187830s|
|stud10000000.txt|8.135543s|9.905907s|1.168339s|3.818835s|2.745193s|25.773816s|

Abiejų konteinerių atveju atlikta spartos analizė įrodo, kad optimizuota programa pasižymi linijiniu laiko sudėtingumu (O(N)): padidinus duomenų kiekį 10 kartų, apdorojimo laikas padidėja proporcingai. Didžioji dalis laiko skiriama failų skaitymo ir rašymo operacijoms bei duomenų rūšiavimui, tuo tarpu pati duomenų dalijimo operacijos atmintyje atliekamos labai greitai, net ir su 10 mln. įrašų.

Lyginant konteinerių rezultatus std::vector duomenų rūšiavimo etape Pasirodė pastebimai greitesnis dirbant su dideliais kiekiais (pvz., prie 10 mln. įrašų atevju vektoriui prireikė ~2.95 s, o sąrašui ~9.91 s). Todėl dirbant su 10 mln. įrašų bendras std::vector vykdymo laikas (~17.41 s ) maždaug 1,5 karto trumpesnis lyginant su std::list ( ~25.77 s).

---
### v0.3.1 rezultatai:
#### std::vector
|**failas**|**skaitymas**|**rūšiavimas**|**dalijimas**|**rašymas (kietiakai)**|**rašymas (vargšiukai)**|**bendras laikas**|
|---|---|---|---|---|---|---|
|stud1000.txt|0.002402s|0.000456s|0.000060s|0.001110s|0.000900s|0.004927s|
|stud10000.txt|0.009692s|0.001821s|0.000234s|0.003685s|0.002573s|0.018005s|
|stud100000.txt|0.076648s|0.015290s|0.002231s|0.030013s|0.021167s|0.145349s|
|stud1000000.txt|0.776421s|0.191490s|0.072598s|0.312569s|0.217503s|1.570582s|
|stud10000000.txt|7.964181s|2.756484s|1.027829s|3.186503s|2.285403s|17.220399s|

#### std::list
|**failas**|**skaitymas**|**rūšiavimas**|**dalijimas**|**rašymas (kietiakai)**|**rašymas (vargšiukai)**|**bendras laikas**|
|---|---|---|---|---|---|---|
|stud1000.txt|0.002950s|0.000460s|0.000024s|0.000966s|0.000749s|0.005150s|
|stud10000.txt|0.012977s|0.003238s|0.000155s|0.004119s|0.002752s|0.023241s|
|stud100000.txt|0.111929s|0.061884s|0.018288s|0.045443s|0.032541s|0.270085s|
|stud1000000.txt|1.105456s|1.045772s|0.126726s|0.457583s|0.323552s|3.059089s|
|stud10000000.txt|11.632625s|48.045776s|33.027847s|31.305997s|23.401636s|147.413882s|

Atlikta spartos analizė įrodo, kad programos veikimo laikas ir efektyvumas tiesiogiai priklauso nuo pasirinkto konteinerio tipo. Dirbant su std::vector, apdorojimo laikas auga nuosekliai, tuo tarpu std::list prie 10 mln. įrašų susiduria su drastišku sulėtėjimu dėl dinaminės atminties fragmentavimo ir rodyklių sekimo.

Lyginant konteinerių rezultatus duomenų rūšiavimo etape, std::vector pasirodė pastebimai greitesnis dirbant su dideliais kiekiais (prie 10 mln. įrašų vektoriui prireikė ~2.76 s, o sąrašui – ~48.05 s). Dar didesnis skirtumas išryškėja studentų dalijimo etape, kur vektorius užtruko vos ~1.03 s, tuo tarpu sąrašas sugaišo ~33.03 s. Todėl dirbant su 10 mln. įrašų bendras std::vector vykdymo laikas (~17.22 s) yra maždaug 8,5 karto trumpesnis lyginant su std::list (~147.41 s).

---
### v1.0 rezultatai:
#### std::vector

#### std::list
