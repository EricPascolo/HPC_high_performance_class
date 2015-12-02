Esercizio 3.1 : verso il futuro
==============================

Utilizzare il software contenuto in es3_1.cpp per creare un benchmark di confronto tra l'approcio a threads e a tasks. Il codice contiene due matrix multiplication, le matrici in input sono A e B mentre il risultato viene scritto in C. E' già presente il timing e la possibilità di scrittura dei risultati su file. Il programma prende da command line due parametri, il primo è la dimensione della matrice, mentre il secondo (opzionale) è il segnale di output su file. Per creare il benchmark:

  - Parallelizzare la prima MM con i task e la seconda con i threads
  - Testare la correttezza della parallelizzazione impostando la dimensione della matrice a 2 e attivando l'output su file
  - Se il test è andato a buon fine, disabilitare la scrittura su file e  cambiando le dimensioni e il numero di processori trovare la configurazione che da il maggior speedup.

  ------
Esercizio 3.2 : andare al massimo
====================================
Creare dal software contenuto in es3.2 .cpp un programma a più livelli di parallelismo.

  - Parallelizzare con i task la matrix multiplication contenuta nel file es3.2.cpp.
  - Testare la correttezza dei risultati con la stessa metodologia dell'esercizio 3.1
  - Aggiungere un altro livello di parallelismo
