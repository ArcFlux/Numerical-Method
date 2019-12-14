#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double func(double x){
	return pow(x,6)-pow(x,4)-pow(x,3)-1;
}
double dfun(double x){
	return 6*pow(x,5)-4*pow(x,3)-3*pow(x,2);
}

int main(){
	int i, lim;
	double x, xm, d;
	
	cout<<"Nilai x: ", cin>>x;
	cout<<"Tingkat ketelitian: ", cin>>d;
	cout<<"Iterasi maksimum: ", cin>>lim;
	
	for(i=1; fabs(func(x))>=d && i<=lim; i++){
		if(dfun(x)==0){
			cout<<"ERROR";
			return 0;
		}
		xm = x - func(x)/dfun(x);
		x = xm;
		cout<<"Iterasi ke-"<<i<<": ", printf("%.5lf",xm), cout<<endl;
	}
	if(fabs(func(xm))>d){
		cout<<endl<<"Tidak Konvergen";
	}
	else{
	cout<<endl<<"Akar persamaan akhir= ", printf("%.5lf",xm);
	}
	
	return 0;
}
