#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double VDW(double x, double P, double R, double T, double a, double b){
	return (P+(a/pow(x,2)))*(x-b)-(R*T);
}
double dfun(double x, double h, double P, double R, double T, double a, double b){
	return (VDW(x+h, P, R, T, a, b)-VDW(x, P, R, T, a, b))/h;
}

int main(){
	int i, lim, n, r;
	float l;
	double x, xm, d, h, xr, xx;
	double a, b;
	double R=8.314, P, T, Pc, Tc;
	cout<<"=====VAN DER WAALS [Vm]====="<<endl;
	//INPUT
	cout<<"P[kPa] : ", cin>>P;
	cout<<"T[K]   : ", cin>>T;
	cout<<"Pc[kPa]: ", cin>>Pc;
	cout<<"Tc[K]  : ", cin>>Tc;
	cout<<"==Nilai x awal : ", cin>>x;
	cout<<"==Nilai x akhir: ", cin>>r;
	d=0.00001, h=0.00001, lim=100, l=0.1;
	//EARLY CALC
	a=0.421875*pow(R,2)*pow(Tc,2)/Pc;
	b=0.125*R*Tc/Pc;
	cout<<"a= "<<a<<" kPa*L^2/mol^2"<<endl;
	cout<<"b= "<<b<<" L/mol"<<endl;
	cout<<"============================"<<endl;
	for(n=0; x<=r; n++){
		xr=x;
		for(i=1; fabs(VDW(xr, P, R, T, a, b))>=d && i<=lim; i++){
			xm = xr - VDW(xr, P, R, T, a, b)/dfun(xr, h, P, R, T, a, b);
			xr = xm;
		}
		if(n==0 && fabs(VDW(xm, P, R, T, a, b))<=d){
			cout<<"Vm: ", printf("%.5lf",xm), cout<<" L/mol"<<endl;
			xx = xm;
		}else if(n!=0 && fabs(VDW(xm, P, R, T, a, b))<=d && fabs(xx-xm)>0.1){
			cout<<"Vm: ", printf("%.5lf",xm), cout<<" L/mol"<<endl;
			xx = xm;
		}
		x=x+l;
	}
	return 0;
}
