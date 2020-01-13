#include <iostream>
#define n 9
using namespace std;

bool EmptyFinder(int Sudoku[n][n], int &i, int &j);
bool Checker(int Sudoku[n][n], int i, int j, int num);

bool Solve(int Sudoku[n][n]){
	int i, j, num;
	if(!EmptyFinder(Sudoku, i, j)){
		return true;
	}
	for(num=1; num<=9; num++){
		if(Checker(Sudoku, i, j, num)){
			Sudoku[i][j] = num;
			if(Solve(Sudoku)){
				return true;
			}
			Sudoku[i][j]=0;
		}
	}
	return false;
}
bool EmptyFinder(int Sudoku[n][n], int &i, int &j){
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(Sudoku[i][j]==0){
				return true;
			}
		}
	}
	return false;
}

bool Row(int Sudoku[n][n], int i, int num){
	int j;
	for(j=0; j<n; j++){
		if(Sudoku[i][j]==num){
			return true;
		}
	}
	return false;
}
bool Column(int Sudoku[n][n], int j, int num){
	int i;
	for(i=0; i<n; i++){
		if(Sudoku[i][j]==num){
			return true;
		}
	}
	return false;
}
bool Square(int Sudoku[n][n], int is, int js, int num){
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(Sudoku[i+is][j+js]==num){
				return true;
			}
		}
	}
	return false;
}

bool Checker(int Sudoku[n][n], int i, int j, int num){
	return !Row(Sudoku, i, num) && !Column(Sudoku, j, num) && !Square(Sudoku, i-i%3, j-j%3, num);
}

int main(){
	int Sudoku[n][n], i, j;
	cout<<"=====SUDOKU SOLVER====="<<endl;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>Sudoku[i][j];
		}
	}	
	if(Solve(Sudoku)==true){
		cout<<"Solution:"<<endl;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				cout<<Sudoku[i][j]<<" ";
			}
			cout<<endl;
		}
	}else{
		cout<<"Solution not found.";
	}
	
	return 0;
}
