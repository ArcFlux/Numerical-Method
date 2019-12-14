#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double func(double x){
	return pow(x,3)-4*x+1;
}
double dfun(double x, double h){
	return (func(x+h)-func(x))/h;
}

int main(){
	int i, lim, n, r;
	float l;
	double x, xm, d, h, xr, xx;
	
	cout<<"Nilai x awal: ", cin>>x;
	cout<<"Nilai x akhir: ", cin>>r;
	//cout<<"Tingkat ketelitian: ", cin>>d;
	//cout<<"Interval: ", cin>>l;
	d=0.00001, h=0.00001, lim=100, l=0.5;
	
	for(n=0; x<=r; n++){
		xr=x;
		for(i=1; fabs(func(xr))>=d && i<=lim; i++){
			if(dfun(xr, h)==0){
				cout<<"ERROR";
				return 0;
			}
			xm = xr - func(xr)/dfun(xr, h);
			xr = xm;
		}
		if(n==0 && fabs(func(xm))<=d){
			cout<<"Akar: ", printf("%.5lf",xm), cout<<endl;
			xx = xm;
		}else if(n!=0 && fabs(func(xm))<=d && fabs(xx-xm)>d){
			cout<<"Akar: ", printf("%.5lf",xm), cout<<endl;
			xx = xm;
		}
		x=x+l;
	}
	
	return 0;
}
