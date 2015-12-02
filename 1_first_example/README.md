Esercizio 1 : basi di OpenMP
==============================

Creare partendo da es1.cpp altri due software che sfruttano la libreria OpenMP:

  - es1_omp.cpp : versione multithreads di es1.cpp, ogni processore deve scrivere correttamente il suo id e il numero totale di threads generati. Se serve utilizzare i costrutti atomici di OpenMP.

  - main_omp_sec.cpp : cambiare es1_omp.cpp in modo tale che non scriva più "Hello word" ma che scriva:
      - "Hello France"
      - "Hello Italy"
      - "Hello Germany"
      - "Hello Norway"

    seguito sempre dal numero del thread e dal numero di threads totali. Non si possono usare i costrutti atomici di OpenMP.

Per compilare il codice utilizzare il Makefile in modo opportuno.
