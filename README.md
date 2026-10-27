# Objektinis programavimas C++

### v0.3 spartos analizė
Spartos analizė atlikta dirbant su std::vector ir std::list konteineriais naudojant iš anksto sugeneruotus testinius failus. Kiekvienas testas kartotas 5 kartus, o lentelėje pateikti gautų laiko matavimų vidurkiai sekundėmis.

**Testavimo sistemos parametrai**
- CPU: Apple M2
- RAM: 8G
- DISK: SSD

---

### Rezultatai:
#### 1. std::vector  
| **failas** | **skaitymas** | **rūšiavimas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
| --- | --- | --- | --- | --- | --- | --- |
| stud1000.txt | 0.002524s | 0.000441s | 0.000062s | 0.001192s | 0.000907s | 0.005126s |
| stud10000.txt | 0.009615s | 0.001924s | 0.000238s | 0.003938s | 0.002550s | 0.018264s |
| stud100000.txt | 0.078244s | 0.016992s | 0.002789s | 0.030469s | 0.021939s | 0.150432s |
| stud1000000.txt | 0.766029s | 0.215568s | 0.077011s | 0.299067s | 0.211799s | 1.569475s |
| stud10000000.txt | 8.022778s | 2.946046s | 1.021856s | 3.151983s | 2.265385s | 17.408047s |


#### 2. std::list
| **failas** | **skaitymas** | **rūšiavimas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
| --- | --- | --- | --- | --- | --- | --- |
| stud1000.txt | 0.002369s | 0.000417s | 0.000015s | 0.001345s | 0.000830s | 0.004976s |
| stud10000.txt | 0.009833s | 0.002544s | 0.000077s | 0.004089s | 0.002662s | 0.019205s |
| stud100000.txt | 0.079353s | 0.028916s | 0.001630s | 0.036066s | 0.026530s | 0.172494s |
| stud1000000.txt | 0.777662s | 0.622143s | 0.118022s | 0.388591s | 0.281412s | 2.187830s |
| stud10000000.txt | 8.135543s | 9.905907s | 1.168339s | 3.818835s | 2.745193s | 25.773816s |

<br>

Abiejų konteinerių atveju atlikta spartos analizė įrodo, kad optimizuota programa pasižymi linijiniu laiko sudėtingumu (O(N)): padidinus duomenų kiekį 10 kartų, apdorojimo laikas padidėja proporcingai. Didžioji dalis laiko skiriama failų skaitymo ir rašymo operacijoms bei duomenų rūšiavimui, tuo tarpu pati duomenų dalijimo operacijos atmintyje atliekamos labai greitai, net ir su 10 mln. įrašų. 

Lyginant konteinerių rezultatus std::vector duomenų rūšiavimo etape Pasirodė pastebimai greitesnis dirbant su dideliais kiekiais (pvz., prie 10 mln. įrašų atevju vektoriui prireikė ~2.95 s, o sąrašui ~9.91 s). Todėl dirbant su 10 mln. įrašų bendras std::vector vykdymo laikas (~17.41 s ) maždaug 1,5 karto trumpesnis lyginant su std::list ( ~25.77 s).

---

### v0.3.1 spartos analizė
**Pagrindinis versijos pakeitimas:** Dirbant su std::list studento struktūra pažymius irgi saugo std::list konteineryje, ne std::vector kaip tai buvo v0.3 versijos atveju. Spartos analizė atlikta analogišku būdu ir su tais pačiais sistemos parametrais kaip ir v0.3. 

### Rezultatai:

#### 1. std::vector
| **failas** | **skaitymas** | **rūšiavimas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
| --- | --- | --- | --- | --- | --- | --- |
| stud1000.txt | 0.002402s | 0.000456s | 0.000060s | 0.001110s | 0.000900s | 0.004927s |
| stud10000.txt | 0.009692s | 0.001821s | 0.000234s | 0.003685s | 0.002573s | 0.018005s |
| stud100000.txt | 0.076648s | 0.015290s | 0.002231s | 0.030013s | 0.021167s | 0.145349s |
| stud1000000.txt | 0.776421s | 0.191490s | 0.072598s | 0.312569s | 0.217503s | 1.570582s |
| stud10000000.txt | 7.964181s | 2.756484s | 1.027829s | 3.186503s | 2.285403s | 17.220399s |


#### 2. std::list
| **failas** | **skaitymas** | **rūšiavimas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
| --- | --- | --- | --- | --- | --- | --- |
| stud1000.txt | 0.002950s | 0.000460s | 0.000024s | 0.000966s | 0.000749s | 0.005150s |
| stud10000.txt | 0.012977s | 0.003238s | 0.000155s | 0.004119s | 0.002752s | 0.023241s |
| stud100000.txt | 0.111929s | 0.061884s | 0.018288s | 0.045443s | 0.032541s | 0.270085s |
| stud1000000.txt | 1.105456s | 1.045772s | 0.126726s | 0.457583s | 0.323552s | 3.059089s |
| stud10000000.txt | 11.632625s | 48.045776s | 33.027847s | 31.305997s | 23.401636s | 147.413882s |

<br>

Abiejų konteinerių atveju atlikta spartos analizė įrodo, kad programos veikimo laikas ir efektyvumas tiesiogiai priklauso nuo pasirinkto konteinerio tipo. Dirbant su std::vector, apdorojimo laikas auga nuosekliai, tuo tarpu std::list prie 10 mln. įrašų susiduria su drastišku sulėtėjimu dėl dinaminės atminties fragmentavimo ir rodyklių sekimo.

Lyginant konteinerių rezultatus duomenų rūšiavimo etape, std::vector pasirodė pastebimai greitesnis dirbant su dideliais kiekiais (prie 10 mln. įrašų vektoriui prireikė ~2.76 s, o sąrašui – ~48.05 s). Dar didesnis skirtumas išryškėja studentų dalijimo etape, kur vektorius užtruko vos ~1.03 s, tuo tarpu sąrašas sugaišo ~33.03 s. Todėl dirbant su 10 mln. įrašų bendras std::vector vykdymo laikas (~17.22 s) yra maždaug 8,5 karto trumpesnis lyginant su std::list (~147.41 s).

