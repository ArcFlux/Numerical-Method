#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double func(double x){
	return 1 / (1 + pow (x, 2));
}

int main(){
	int n, i;
	float sum, h, x1, x2, y, x;
	
	cout<<"Amount of segment: ", cin>>n;
	cout<<"xmin: ", cin>>x1;
	cout<<"xmax: ", cin>>x2;
	
	h = (x2-x1)/n;
	x = x1;
	y = func(x);
	cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
	sum = y/2;
	
	for(i=1; i<n; i++){
		x = x1 + h*i;
		y = func(x);
		cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
		sum = sum + y;
	}
	x = x2;
	y = func(x);
	cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
	sum = sum + y/2;
	
	sum = sum * h;
	cout<<"SUM = ", printf("%.5lf",sum);
	
	return 0;
}
