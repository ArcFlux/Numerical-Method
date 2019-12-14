#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double PR(double x, double b, double a, double al, double P, double R, double T){
	return R*T/(x-b)-(a*al/(x*(x+b)+b*(x-b)))-P;
}
double dfun(double x, double h, double b, double a, double al, double P, double R, double T){
	return (PR(x+h, b, a, al, P, R, T)-PR(x, b, a, al, P, R, T))/h;
}

int main(){
	int i, lim, n, r;
	float l;
	double x, xm, d, h, xr, xx;
	double a, b, al, k, Tr;
	double R=8.314, P, T, Pc, Tc, w;
	cout<<"=====PENG ROBINSON EQUATION [Vm]====="<<endl;
	//INPUT
	cout<<"P[kPa] : ", cin>>P;
	cout<<"T[K]   : ", cin>>T;
	cout<<"Pc[kPa]: ", cin>>Pc;
	cout<<"Tc[K]  : ", cin>>Tc;
	cout<<"w      : ", cin>>w;
	cout<<"==Nilai x awal : ", cin>>x;
	cout<<"==Nilai x akhir: ", cin>>r;
	d=0.00001, h=0.00001, lim=100, l=0.1;
	//EARLY CALC
	Tr=T/Tc;
	a=0.45724*pow(R,2)*pow(Tc,2)/Pc;
	b=0.07780*R*Tc/Pc;
	k=0.37464+1.54226*w-0.26992*pow(w,2);
	al=pow(1+k*(1-pow(Tr,0.5)),2);
	cout<<"Tr= "<<Tr<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"k = "<<k<<endl;
	cout<<"al= "<<al<<endl;
	cout<<"====================================="<<endl;
	for(n=0; x<=r; n++){
		xr=x;
		for(i=1; fabs(PR(xr, b, a, al, P, R, T))>=d && i<=lim; i++){
			xm = xr - PR(xr, b, a, al, P, R, T)/dfun(xr, h, b, a, al, P, R, T);
			xr = xm;
		}
		if(n==0 && fabs(PR(xm, b, a, al, P, R, T))<=d){
			cout<<"Vm: ", printf("%.5lf",xm), cout<<" L/mol"<<endl;
			xx = xm;
		}else if(n!=0 && fabs(PR(xm, b, a, al, P, R, T))<=d && fabs(xx-xm)>0.1){
			cout<<"Vm: ", printf("%.5lf",xm), cout<<" L/mol"<<endl;
			xx = xm;
		}
		x=x+l;
	}
	return 0;
}
