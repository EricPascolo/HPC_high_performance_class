#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <omp.h>

using namespace std;

double row_col_product(double * r,double * c, int dim);

int main(int argc, char *argv[])
{


  /*** INIT SOFTWARE ***/
  int num_threads,myid,dim,chunk;
  double *A, *B, *C,time;

  myid = 0;
  chunk = 50;
  num_threads = 1;
  dim =atoi(argv[1]);

  A = (double*) calloc(dim*dim,sizeof(double));
  B = (double*) calloc(dim*dim,sizeof(double));
  C = (double*) calloc(dim*dim,sizeof(double));

  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
      A[j+i*dim] = 2;

  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
      B[j+i*dim] = 3;

  /*** TASK PARALLELIZATION ***/
  time = omp_get_wtime();

  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
        C[j+i*dim] = row_col_product(&A[i*dim],&B[j],dim);

  time = omp_get_wtime() - time;
  cout<<"TASK TIME TO SOLUTION = "<< time<<endl;


  /*** WRITE TASK RESULTS ***/
  if (argc == 3)
  {

    ofstream fout("result_task.mxt");

    for(int i=0;i<dim;i++)
    {
      for(int j=0;j<dim;j++)
      {
        fout << C[j+i*dim]<<" ";
      }
      fout << endl;
    }
  }

  /*** THREADS PARALLELIZATION***/

  time = omp_get_wtime();
      for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            C[j+i*dim] = row_col_product(&A[i*dim],&B[j],dim);


  time = omp_get_wtime() - time;
  cout<<"THREADS TIME TO SOLUTION = "<< time<<endl;

  /*** WRITE THREADS RESULTS ***/
  if (argc == 3)
  {

    ofstream fout("result_th.mxt");

    for(int i=0;i<dim;i++)
    {
      for(int j=0;j<dim;j++)
      {
        fout << C[j+i*dim]<<" ";
      }
      fout << endl;
    }
  }

}

/*** ROW * COLUMN PRODUCT ***/
double row_col_product(double * r,double * c, int dim)
{

  double s=0;

  for(int i = 0; i < dim; i++)
  {
    s = s + r[i]*c[i*dim];
  }

  return s;
}
