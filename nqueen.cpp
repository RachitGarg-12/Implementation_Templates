#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool canPlace(int x, int y, int b[][4] ){		
    // will be returning if we can place a new queen on x,y with current state of board		
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(b[i][j] ==1){
				if( x == i || y == j || x-y == i-j || x+y == i+j )	
					return false;
			}
		}		
	}
	
	return true;
}

// 0 ,1 , 2, 3, 4

int solno  = 0 ;
void solve(int b[][4],int i){
	
	if(i==4){
		solno ++;
		// Solution is found;	
		cout<<"#####"<< solno << "#####"<<endl;

		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cout<<b[i][j]<<"";
			}
			cout<<endl;
		}
		cout<<"##########"<<endl;

		return;	
	}
	
	for(int j=0;j<4;j++){
		if( canPlace( i, j ,b ) ){	
			b[i][j] = 1;
			solve(b,i+1); // try to solve for next queen 
			b[i][j] = 0;
		}
	}
	
}

int main(){
	int b[4][4];
	// 1-> Represent a queen is placed 
	// 0 -> blank
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			b[i][j] = 0;
		}
	}
	
	solve(b,0);
	
	return 0;
}
