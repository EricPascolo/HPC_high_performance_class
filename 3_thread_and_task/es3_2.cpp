#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <omp.h>

using namespace std;

double row_col_product(double * r,double * c, int dim);
void mm(int num1,int num2,int dim,int task_id,int wio);

int main(int argc, char *argv[])
{
      int num1,num2,dim,wio,t;
      dim =atoi(argv[1]);


            num1 = 2;
            num2 = 3;
            t=1;
            mm(num1,num2,dim,t,argc);

            num1 = 4;
            num2 = 3;
            t=2;
            mm(num1,num2,dim,t,argc);

}

void mm(int num1,int num2,int dim,int task_id,int wio)
{

  /*** INIT SOFTWARE ***/
  int num_threads,myid,chunk;
  double *A, *B, *C,time;
  string filename;

  myid = 0;
  num_threads = 1;
  chunk = 100;

  A = (double*) calloc(dim*dim,sizeof(double));
  B = (double*) calloc(dim*dim,sizeof(double));
  C = (double*) calloc(dim*dim,sizeof(double));

  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
      A[j+i*dim] = num1;

  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
      B[j+i*dim] = num2;

  /*** TASK PARALLELIZATION ***/
  time = omp_get_wtime();


  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
        C[j+i*dim] = row_col_product(&A[i*dim],&B[j],dim);

  time = omp_get_wtime() - time;

  cout<<" TASK TIME TO SOLUTION "<<task_id<<" TASK  ="<< time<<endl;


  /*** WRITE TASK RESULTS ***/
  if (wio == 3)
  {
    if(task_id==1)
      filename = "1.mxt";
    if(task_id==2)
      filename = "2.mxt";
    ofstream fout(filename.c_str());

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
