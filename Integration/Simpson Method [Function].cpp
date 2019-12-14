#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double func(double x){
	return pow(x, 2);
}

int main(){
	int n, i;
	float sum, h, x1, x2, y, x;
	
	cout<<"Amount of segment: ", cin>>n;
	if(n%2>0){
		cout<<"Amount of segment must be even.";
		return 0;
	}
	else{
	cout<<"xmin: ", cin>>x1;
	cout<<"xmax: ", cin>>x2;
	
	h = (x2-x1)/n;
	x = x1;
	y = func(x);
	cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
	sum = y;
	
	for(i=1; i<n; i++){
		x = x1 + h*i;
		y = func(x);
		cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
		if(i%2==0){
			sum = sum + 2*y;
		}
		else{
			sum = sum + 4*y;
		}
	}
	
	x = x2;
	y = func(x);
	cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<endl;
	sum = sum + y;
	
	sum = h * sum / 3;
	cout<<endl<<"SUM = ", printf("%.5lf",sum);
	}
	return 0;
}
