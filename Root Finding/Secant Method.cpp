#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double func(double x){
	return pow(x,6)-pow(x,4)-pow(x,3)-1;
}

int main(){
	int i;
	double x1, x2, d, xm;
	
	cout<<"Nilai x1: ", cin>>x1;
	cout<<"Nilai x2: ", cin>>x2;
	cout<<"Tingkat ketelitian: ", cin>>d;
	
	while(fabs(x2-x1)>=d && fabs(func(xm))>=d){
		xm = x2 - (x2 - x1) / (func(x2) - func(x1)) * func(x2);
		x1 = x2;
		x2 = xm;
		cout<<"Akar persamaan= ", printf("%.5lf",xm), cout<<endl;
	}
	if(fabs(func(xm))>d){
		cout<<endl<<"Tidak Konvergen";
	}
	else{
	cout<<endl<<"Akar persamaan akhir= ", printf("%.5lf",xm);
	}
	
	return 0;
}
