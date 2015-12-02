Esercizio 2 : usare la testa!
===============================

Creare una versione parallela di es2_1.cpp, verificando la correttezza dei risultati.

  - Parallelizzare il software es2_1_omp.cpp utilizzando il costrutto OMP FOR.
  - Inserire un timer sul ciclo con stdlib:

    ```
    clock_t cpuTime = clock();
      doSomeOperation();
    cpuTime = clock() - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    ```
    e con il costrutto OpenMP :

    ```
    double startTime = omp_get_wtime();
      doSomeOperation();
    double endTime = omp_get_wtime() - startTime;
    ```
    Ci sono differenze ?
  - Verificare le performance e la correttezza dei risultati ottenuti con il programma parallelo. Il valore che deve restituire è:
  ```
  RESULT = 9.33262e+157

  ```
