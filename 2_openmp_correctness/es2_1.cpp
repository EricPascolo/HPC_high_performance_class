#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(int, char **)
{

  int num_threads,myid,num;
  double res;
  myid = 0;
  num_threads = 1;
  num = 101;

  res = 1.0;
  for(int i=1;i<num;i++)
  {
    res = res*i;
  }

  cout<<res<<"\n";



}
