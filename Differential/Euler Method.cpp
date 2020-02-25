#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

double f(double x, double y){
	return y-5+x;
}

int main(){
	int i, n;
	double x, y, x0, y0, h;
	//INPUT
	cout<<"x start= ", cin>>x0;
	cout<<"y start= ", cin>>y0;
	cout<<"x end= ", cin>>x;
	cout<<"n= ", cin>>n;
	//EXEC
	h = (x-x0)/n;
	cout<<"\n             RESULT\n";
	cout<<"==================================="<<endl;
	for(i=1; i<=n; i++){
		y = y0 + h * f(x0, y0);
		cout<<"x= ", printf("%.5lf", x0), cout<<"\t\t"<<"y= ", printf("%.5lf", y0), cout<<endl;
		y0 = y;
		x0 += h;
	}
	return 0;
}
