#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

typedef double (*Pers) (double w, double x, double y, double z);
double f1(double w, double x, double y, double z){
	return 0.07*w+0.18*x+0.15*y+0.24*z-0.15*70;
}
double f2(double w, double x, double y, double z){
	return 0.04*w+0.24*x+0.1*y+0.65*z-0.25*70;
}
double f3(double w, double x, double y, double z){
	return 0.54*w+0.42*x+0.54*y+0.1*z-0.4*70;
}
double f4(double w, double x, double y, double z){
	return 0.35*w+0.16*x+0.21*y+0.01*z-0.2*70;
}

int main(){
	Pers functions[] = {f1, f2, f3, f4};
	int n, i, j, k, m=1, lim=1000, it;
	cout<<"Amount of Equations: ", cin>>n;
	//cout<<"Iterasi maksimum: ", cin>>lim;
	double d, e=0.00001, x[n], h=0.00001, df[n], f1[n];
	double X[n][m], XM[n][m], F[n][m], DX[n][m], JX[n][m], JI[n][n], J[2*n][2*n];
	//INPUT
	for(i=1; i<=n; i++){
		cout<<"x["<<i<<"]: ", cin>>x[i];
	}
	for(i=1; i<=n; i++){
		X[i][m]=x[i];
	}
	//cout<<"Tingkat ketelitian: ", cin>>e;
	//HITUNG -- CHANGE STOP CONDITION "pow(pow(functions[0](...),2)+pow(functions[n-1](...),2),0.5)
	for(it=1; fabs(pow(pow(functions[0](x[1],x[2],x[3],x[4]),2)+pow(functions[1](x[1],x[2],x[3],x[4]),2)+pow(functions[2](x[1],x[2],x[3],x[4]),2)+pow(functions[3](x[1],x[2],x[3],x[4]),2),0.5))>=e && it<=lim; it++){
		//MATRIX FUNGSI
		for(i=1; i<=n; i++){
			F[i][m]=functions[i-1](x[1],x[2],x[3],x[4]); //CHANGE VARIABLES
		}
		//JACOBIAN MATRIX
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				x[j]=x[j]+h;
				f1[i]=functions[i-1](x[1],x[2],x[3],x[4]); //CHANGE VARIABLES
				df[i]=(f1[i]-F[i][m])/h;
				J[i][j]=df[i];
				x[j]=X[j][m];
			}
		}
		//INVERSE
		for (i=1; i<=n; i++){
	        for (j=1; j<=2*n; j++){
	            if (j==(i+n))
	                J[i][j] = 1;
	        }
		}	
	    for (i=n; i>1; i--){
	        if (J[i-1][1]<J[i][1])
	            for (j=1; j<=n*2; j++){
	                d = J[i][j];
	                J[i][j] = J[i-1][j];
	                J[i-1][j] = d;
	            }
	    }
	    for (i=1; i<=n; i++){
	        for (j=1; j<=n*2; j++)
	            if (j!=i){
	                d = J[j][i] / J[i][i];
	                for (k=1; k<=n*2; k++)
	                    J[j][k] -= J[i][k] * d;
	            }
	    }
	    for (i=1; i<=n; i++){
	        d = J[i][i];
	        for (j=1; j<=n*2; j++)
	            J[i][j] = J[i][j] / d;
	    }
	    for(i=1; i<=n; i++){
    		for(j=1; j<=n; j++){
    			JI[i][j]=J[i][j+n];
			}
		}
		//MULTIPLICATION FOR JX
		for(i=1; i<=n; i++){
			JX[i][m]=0;
		}
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				JX[i][m]+=JI[i][j]*F[j][m];
			}
		}
		//FINAL
		for(i=1; i<=n; i++){
			XM[i][m] = X[i][m] - JX[i][m];
		}
		//NEW VALUE
		for(i=1; i<=n; i++){
				X[i][m]=XM[i][m];
				x[i]=XM[i][m];
		}
		//CLEAR MATRICES
		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				J[i][j+n]=0;
			}
		}
		for(i=1; i<=n; i++){
			JX[i][m]=0;
		}
		for(i=1; i<=n; i++){
		cout<<"x["<<i<<"]: ", printf("%.5lf",X[i][m]);
		cout<<endl;
	}
	}
	cout<<"====FINAL VALUE===="<<endl;
	for(i=1; i<=n; i++){
		cout<<"x["<<i<<"]: ", printf("%.5lf",X[i][m]);
		cout<<endl;
	}
	return 0;
}
