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

<img width="414" height="658" alt="image" src="https://github.com/user-attachments/assets/9d448249-dfb0-476b-aab2-6b38e1acce3b" />

---

#### 2. std::list
| **failas** | **skaitymas** | **rūšiavimas** | **dalijimas** | **rašymas (kietiakai)** | **rašymas (vargšiukai)** | **bendras laikas** |
| --- | --- | --- | --- | --- | --- | --- |
| stud1000.txt | 0.002369s | 0.000417s | 0.000015s | 0.001345s | 0.000830s | 0.004976s |
| stud10000.txt | 0.009833s | 0.002544s | 0.000077s | 0.004089s | 0.002662s | 0.019205s |
| stud100000.txt | 0.079353s | 0.028916s | 0.001630s | 0.036066s | 0.026530s | 0.172494s |
| stud1000000.txt | 0.777662s | 0.622143s | 0.118022s | 0.388591s | 0.281412s | 2.187830s |
| stud10000000.txt | 8.135543s | 9.905907s | 1.168339s | 3.818835s | 2.745193s | 25.773816s |

<img width="420" height="581" alt="image" src="https://github.com/user-attachments/assets/1aa18eee-90e3-429b-8c68-301f04f50ef7" />

---

Abiejų konteinerių atveju atlikta spartos analizė įrodo, kad optimizuota programa pasižymi linijiniu laiko sudėtingumu (O(N)): padidinus duomenų kiekį 10 kartų, apdorojimo laikas padidėja proporcingai. Didžioji dalis laiko skiriama failų skaitymo ir rašymo operacijoms bei duomenų rūšiavimui, tuo tarpu pati duomenų dalijimo operacijos atmintyje atliekamos labai greitai, net ir su 10 mln. įrašų. 

Lyginant konteinerių rezultatus std::vector duomenų rūšiavimo etape Pasirodė pastebimai greitesnis dirbant su dideliais kiekiais (pvz., prie 10 mln. įrašų atevju vektoriui prireikė ~2.95 s, o sąrašui ~9.91 s). Todėl bendras std::vector vykdymo laikas gautas trumpesnis (~17.41 s ) negu std::list ( ~25.77 s).
