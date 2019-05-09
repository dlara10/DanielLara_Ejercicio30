#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    int m = 100;
    int c = 1;
    float dx = 1/m;
    float beta = 0.8;
    float u[m+1];
    float u0[m+1];
    float uf[m+1];
    float dt = 0.01;
    float Tfinal = 2.0;
    int n = Tfinal/dt;
    int i, j;
    float t = 0.0;
    double pi = asin(1.0)*2.0;
    int x;
    ofstream outfile;

  for(i=0;i<m;i++){
    x = i*dx;
    u0[i] = sin(pi*x);
    u[i] = u0[i];
    uf[i] = u0[i];
  }
  outfile.open("adveccion.dat");
  while(t < Tfinal){
    for(i=0;i<m;i++){
      outfile << u[i] << " ";
    }
    outfile << "\n";
    
    for(i=1;i<m-1;i++){
      uf[i] = (1-beta*beta)*u0[i] - (0.5*beta)*(1-beta)*u0[i+1]+(0.5*beta)*(1-beta)*u0[i-1];
    }
    for(i=1;i<m-1;i++){
      u0[i] = u[i];
      u[i] = uf[i];
    }
    t = t + dt;
  }
  outfile.close();
  return 0;
}
