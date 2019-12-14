#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, i;
	float sum, h, x1, x2, y, a, b;
	
	cout<<"Amount of segment: ", cin>>n;
	cout<<"xmin: ", cin>>x1;
	cout<<"xmax: ", cin>>x2;
	cout<<"y0: ", cin>>a;
	cout<<"y"<<n<<": ", cin>>b;
	
	h = (x2-x1)/n;
	sum = (a + b)/2;
	
	for(i=1; i<n; i++){
		cout<<"y"<<i<<": ", cin>>y;
		sum = sum + y;
	}
	
	sum = sum * h;
	cout<<endl<<"SUM = "<<sum;
	
	return 0;
}
