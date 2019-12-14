#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, i;
	float sum, h, x1, x2, y, a, b;
	
	cout<<"Amount of segment: ", cin>>n;
	cout<<"xmin: ", cin>>x1;
	cout<<"xmax: ", cin>>x2;
	cout<<"Nilai y0: ", cin>>a;
	cout<<"Nilai y"<<n<<": ", cin>>b;

	
	h = (x2-x1)/n;
	sum = a + b;
	
	for(i=1; i<n; i++){
		cout<<"Nilai y"<<i<<": ", cin>>y;
		if(i%2==0){
			sum = sum + 2*y;
		}
		else{
			sum = sum + 4*y;
		}
	}
	
	sum = h * sum / 3;
	cout<<endl<<"SUM = "<<sum;
	
	return 0;
}
