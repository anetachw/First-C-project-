# Studentų valdymo sistema C++ 

### Įdiegimo instrukcija

Prieš kompiliuojant ir paleidžiant projektą įsitikinkite, kad jūsų kompiuteryje yra įdiegtas C++ kompiliatorius bei CMake (version 3.10) įrankiai. Jei neturite kompilatoriaus, teminale atlikite šiuos žingsnius:

- **Windows:**
  `winget install WinLibs.MinGW`

- **Linux:**
  `sudo apt update`
  `sudo apt install clang`

- **macOS:**
  `xcode-select --install`

Jei neturite CMake, teminale atlikite šiuos žingsnius:
- **Windows:**
  `winget install Kitware.CMake`

- **Linux:**
  `sudo apt update`
  `sudo apt install cmake`

- **macOS:**
  `brew install cmake`

Kad įsitikinti ar jūsų Cmake yra atinkamos versijos terminale įrašykite:
`cmake --version`

<br>

 Sėkmingai įdegus kompilatorių ir CMake galite pereiti prie programos paleidimo. Terminale atlikite tolimesnius žingsnius:
1. **Pereikite į atsiųsto projekto aplanką:**
```
    cd Path/To/StudentuValdymoSistema
```

2. **Sukurkite ir atidarykite laikinąją direktoriją:**
```
    mkdir build
    cd build
```

3. **Sugeneruokite projekto failus per CMake (naudojant Release režimą):**
```
    cmake -DCMAKE_BUILD_TYPE=Release ..
```

4. **Sukompiliuokite projektą:**
```
    cmake --build .
```

5. **Paleiskite sugeneruotą programą:**
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
Versijoje v0.3 pagrindinis dėmesys skirtas `std::vector` ir `std::list` konteinerių palyginimui ir spartos testavimui.
#### Pagrindiniai releaso ypatumai:
- **Konteinerio pasirinkimas:** Įdiegta galimybė pasirinkti tarp `std::vector` ir `std::list` struktūrų;
- **Funkcijų pritaikymas:** Galimos programos funkcijos pakeistos į šablonines, kitos papildomai perrašytos, kad veiktų su `std::list` struktūra.

---

### Versija v0.3.1 
**Pagrindinis versijos patobulinimas:** Dirbant su `std::list` studento struktūra pažymius irgi saugo `std::list` konteineryje, ne `std::vector` kaip tai buvo v0.3 versijos atveju. 

---

### Versija v1.0 
#### Pagrindiniai releaso ypatumai:
- **Dalijimo strategijos:**
    - **1 strategija:** Studentų konteinerio skaidymas į du naujus to paties tipo konteinerius "vargšiukės" ir "kietiakus". Tokiu būdu tas pats stundetas yra dviejuose konteineriuose: pagrindiniame ir vienam iš suskaidytų.
    - **2 strategija:** Studentų skaidymas panaudojant tik vieną naują konteinerį "vargšiukai". Perkelti į naują konteinerį studentai yra ištrinami iš pagrindinio, kuriame lieka tik "kietiakai".
    - **3 strategija:** Studentų skaidymas remiantis 2 strategija su patobulinimais. Dirbant su std::vector konteineriu naudojamas `std::stable_partition` ir `std::make_move_iterator`, o su `std::list` naudojamas `splice()`. 


#### Dalijimo strategiju palyginimo rezultatai:
**std::vector**
|Failas|Studentų skaičius|Dalijimas 1|Dalijimas 2|Dalijimas 3|
|---|---|---|---|---|
|stud1000.txt|1 000|0.000085s|0.000043s|0.000018s|
|stud10000.txt|10 000|0.000291s|0.000192s|0.000069s|
|stud100000.txt|100 000|0.002971s|0.001345s|0.000546s|
|stud1000000.txt|1 000 000|0.025115s|0.014179s|0.005826s|
|stud10000000.txt|10 000 000|0.860139s|0.515829s|0.244038s|

<img width="328" height="366" alt="image" src="https://github.com/user-attachments/assets/375465ce-c318-40d7-bd16-eeed3acd0bd3" />

**std::list**
|Failas|Studentų skaičius|Dalijimas 1|Dalijimas 2|Dalijimas 3|
|---|---|---|---|---|
|stud1000.txt|1 000|0.000421s|0.000263s|0.000022s|
|stud10000.txt|10 000|0.001603s|0.000978s|0.000072s|
|stud100000.txt|100 000|0.014742s|0.010635s|0.001093s|
|stud1000000.txt|1 000 000|0.151380s|0.101431s|0.010211s|
|stud10000000.txt|10 000 000|9.308188s|5.369350s|3.238489s|

<img width="328" height="366" alt="image" src="https://github.com/user-attachments/assets/e3ca7e7c-3afc-4713-bd29-3a97bf4d6122" />

Remiantis pateiktais dalijimo analizės duomenimis 3-ioji dalijimo strategija visuose testuose pasiekė geriausius rezultatus, 2-oji strategija yra vidutiniškai greita, o 1-oji strategija reikalauja daugiausiai laiko. std::vector programos veikimo laikas visuose failų dydžiuose yra pastebimai mažesnis lyginant su std::list, o didžiausiam 10 mln studentų failui apdoroti trečiai strategijai prireikė tik apie 0.24s. Tuo tarpu std::list visi trys studentų dalijimo algoritmai veikia lėčiau, 10 mln studentų failui apdoroti trečiai strategijai prireikė net 3.23s. Tai rodo, kad std::vector konteineris yra efektyvesnis atliekant dalijimą ir užtikrina geresnę spartą nei std::list.

---
### Spartos analizė
Spartos analizė atlikta dirbant su `std::vector` ir `std::list` konteineriais naudojant iš anksto sugeneruotus testinius failus. Kiekvienas testas kartotas 5 kartus, o lentelėje pateikti gautų laiko matavimų vidurkiai sekundėmis.

**Testavimo sistemos parametrai**
- CPU: Apple M2
- RAM: 8G
- DISK: SSD
- OPTIMIZATION LEVEL: -O3

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

<img width="345" height="485" alt="image" src="https://github.com/user-attachments/assets/9d448249-dfb0-476b-aab2-6b38e1acce3b" />

#### std::list
|**failas**|**skaitymas**|**rūšiavimas**|**dalijimas**|**rašymas (kietiakai)**|**rašymas (vargšiukai)**|**bendras laikas**|
|---|---|---|---|---|---|---|
|stud1000.txt|0.002369s|0.000417s|0.000015s|0.001345s|0.000830s|0.004976s|
|stud10000.txt|0.009833s|0.002544s|0.000077s|0.004089s|0.002662s|0.019205s|
|stud100000.txt|0.079353s|0.028916s|0.001630s|0.036066s|0.026530s|0.172494s|
|stud1000000.txt|0.777662s|0.622143s|0.118022s|0.388591s|0.281412s|2.187830s|
|stud10000000.txt|8.135543s|9.905907s|1.168339s|3.818835s|2.745193s|25.773816s|

<img width="345" height="485" alt="image" src="https://github.com/user-attachments/assets/1aa18eee-90e3-429b-8c68-301f04f50ef7" />

Abiejų konteinerių atveju atlikta spartos analizė įrodo, kad optimizuota programa pasižymi linijiniu laiko sudėtingumu (O(N)): padidinus duomenų kiekį 10 kartų, apdorojimo laikas padidėja proporcingai. Didžioji dalis laiko skiriama failų skaitymo ir rašymo operacijoms bei duomenų rūšiavimui, tuo tarpu pati duomenų dalijimo operacijos atmintyje atliekamos labai greitai, net ir su 10 mln. įrašų.

Lyginant konteinerių rezultatus std::vector duomenų rūšiavimo etape Pasirodė pastebimai greitesnis dirbant su dideliais kiekiais (pvz., prie 10 mln. įrašų atevju vektoriui prireikė ~2.95 s, o sąrašui ~9.91 s). Todėl dirbant su 10 mln. įrašų bendras std::vector vykdymo laikas (~17.41 s ) maždaug 1,5 karto trumpesnis lyginant su std::list ( ~25.77 s).

---
### v0.3.1 rezultatai:

#### std::list
|**failas**|**skaitymas**|**rūšiavimas**|**dalijimas**|**rašymas (kietiakai)**|**rašymas (vargšiukai)**|**bendras laikas**|
|---|---|---|---|---|---|---|
|stud1000.txt|0.002950s|0.000460s|0.000024s|0.000966s|0.000749s|0.005150s|
|stud10000.txt|0.012977s|0.003238s|0.000155s|0.004119s|0.002752s|0.023241s|
|stud100000.txt|0.111929s|0.061884s|0.018288s|0.045443s|0.032541s|0.270085s|
|stud1000000.txt|1.105456s|1.045772s|0.126726s|0.457583s|0.323552s|3.059089s|
|stud10000000.txt|11.632625s|48.045776s|33.027847s|31.305997s|23.401636s|147.413882s|

<img width="345" height="485" alt="image" src="https://github.com/user-attachments/assets/df29c62e-db89-4573-b35c-fd2a0858a6b5" />

Palyginus v0.3 ir v0.3.1 std::list realizacijas paaiškėjo, kad konteinerio vidinė sandara turi kritinę įtaką programos greičiui. Kai studentai saugomi sąraše, tačiau jų vidiniai pažymiai yra vektoriaus tipo (v0.3 std::list lentelė), programa veikia pastebimai sparčiau. Kai ir patys studentai, ir jų pažymiai yra saugomi kaip std::list (v0.3.1 std::list lentelė), dirbant su dideliais duomenų kiekiais sistema susiduria su milžinišku sulėtėjimu.

Palyginus v0.3 std::vector ir v0.3.1 std::list rezultatus matome, kad dirbant su std::vector, apdorojimo laikas auga nuosekliai. Tuo tarpu std::list prie 10 mln. įrašų susiduria su drastišku sulėtėjimu dėl dinaminės atminties fragmentavimo ir rodyklių sekimo. Todėl 10 mln. įrašų atveju bendras std::vector vykdymo laikas (~17.22 s) yra maždaug 8,5 karto trumpesnis lyginant su std::list (~147.41 s).

---
### v1.0 rezultatai:
#### std::vector 
| **failas** | **skaitymas** | **rūšiavimas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
|---|---|---|---|---|---|---|
|stud1000.txt|0.001437s|0.000371s|0.000005s|0.000421s|0.000323s|0.002558s|
|stud10000.txt|0.007686s|0.001591s|0.000054s|0.003950s|0.002142s|0.015423s|
|stud100000.txt|0.079053s|0.015520s|0.000759s|0.030696s|0.021396s|0.147424s|
|stud1000000.txt|0.762898s|0.189387s|0.020536s|0.352839s|0.252865s|1.578525s|
|stud10000000.txt|7.960285s|2.699411s|0.260887s|3.644756s|2.707295s|17.272633s|

<img width="345" height="485" alt="image" src="https://github.com/user-attachments/assets/042c2ec8-b24a-4e8a-b402-97b725bd1cca" />


#### std::list
| **failas** | **skaitymas** | **rūšiavimas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
|---|---|---|---|---|---|---|
|stud1000.txt|0.011973s|0.000184s|0.000010s|0.000526s|0.000344s|0.013038s|
|stud10000.txt|0.012852s|0.002650s|0.000136s|0.003298s|0.002483s|0.021419s|
|stud100000.txt|0.116893s|0.054418s|0.009600s|0.044759s|0.035320s|0.260990s|
|stud1000000.txt|1.164097s|0.994149s|0.125354s|0.460706s|0.320855s|3.065162s|
|stud10000000.txt|11.736854s|21.281563s|5.730201s|12.261700s|13.396715s|64.407032s|

<img width="345" height="485" alt="image" src="https://github.com/user-attachments/assets/269d5002-4515-4183-acad-8cbc307b15a8" />

Remiantis atlikta spartos analize, akivaizdu, kad duomenų konteinerio pasirinkimas turi milžinišką įtaką programos veikimo greičiui, analogiškai kaip ir v0.3 versijoje. Pritaikytos 3 strategijos dalijimo funkcijos studentų skaidymą atlieką greičiau tiek std::list, tiek std::vector atveju. 
