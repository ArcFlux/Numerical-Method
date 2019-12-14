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
	
	if(func(x1)*func(x2)>=0){
		cout<<"ERROR";
		return 0;
	}
	else{
	while(x2-x1>=d && fabs(func(xm))>=d){
		xm = x1 + (func(x1)/(func(x1)-func(x2)))*(x2-x1);
		if(func(xm)*func(x1)<0)
			x2 = xm;
		else
			x1 = xm;
		cout<<"Akar persamaan = ", printf("%.5lf",xm), cout<<endl;
	}
	}
	if(fabs(func(xm))>d){
		cout<<endl<<"Tidak Konvergen";
	}
	else{
	cout<<endl<<"Akar persamaan akhir= ", printf("%.5lf",xm);
	}
	
	return 0;
}
