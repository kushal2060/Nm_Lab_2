#include<iostream>
using namespace std;
 float n,x[4],fx[4],v=0,p=1;
float dd[4],xm;
void getdata(){
	
	cout<<"Enter the number of points: ";
	cin>>n;
	cout<<"Enter interpolated value: ";
	cin>>xm;
	cout<<"Enter x and fx() ";
	for(int i=0;i<n;i++){
		cout<<"Enter x: ";
		cin>>x[i];
		cout<<"Enter f(x): ";
		cin>>fx[i];
	}
}

void first_diff(){
	for(int i=0;i<n;i++){
		dd[i]=fx[i];
	}
}

void second_diff(){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=i+1;j--){
			dd[j]=(dd[j]-dd[j-1])/(x[j]-x[j-1-i]);
		}
	}
}
void inter_value(){
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=i-1;j++){
			p=p*(xm-x[j]);
		}
		v=v+dd[i]*p;
		p=1;
	}
	cout<<"Value is "<<v;
}
int main(){
	getdata();
	first_diff();
	second_diff();
	inter_value();
	return 0;
	
}
