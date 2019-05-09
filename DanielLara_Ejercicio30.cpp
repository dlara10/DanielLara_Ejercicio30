#include <iostream>
#include <fstream>
#include <stdio.h>  
#include <cmath>
#include <math.h>  

using namespace std;

int main(){
    int m = 100;
    int c = 1;
    float dx = 0.01;
    float u[m+1];
    float u0[m+1];
    float uf[m+1];
    float dt = 0.01;
    float Tfinal = 2.0;
    int n = Tfinal/dt;
    int i, j;
    float t = 0.0;
    double pi = 3.1415;
    double x;
    double beta = 1/(dx/dt);
    ofstream outfile;

  for(i=0;i<m;i++){
    x = i*dx;
    u0[i] = 0.04*sin(4*pi*x/c);
    u[i] = u0[i];
    uf[i] = u0[i];
  }
  outfile.open("adveccion.dat");
  while(t < Tfinal){
    for(j=0;j<m;j++){
      outfile << u[j] << " ";
    }
    outfile << "\n";
    for(i=1;i<m-1;i++){
      uf[i] = u[i] - (beta/4)*(u0[i+1]*u0[i+1]*-u0[i-1]*u0[i-1])+((beta*beta)/8)*((u0[i+1]*u0[i])*(u0[i+1]*u0[i+1]-u0[i]*u0[i])-(u0[i]*u0[i-1])*(u0[i]*u0[i-1]-u0[i]*u0[i-1]));
     }
    for(i=1;i<m-1;i++){
      u[i] = uf[i];
      u0[i] = u[i]; 
    }
    t = t + dt;
  }
  outfile.close();
  return 0;
}
