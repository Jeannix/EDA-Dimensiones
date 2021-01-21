#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <iomanip>
using namespace std::chrono;
using namespace std;
int n,m;
int** p;
void reservarmem(){
	p = new int*[n];
	for (int i = 0; i < n; ++i)
		p[i] = new int[m];
}
void rellenmem(){
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			int temp=rand() % 101;
			p[i][j]=temp;
		}
	}
}
void mostrarmat(){
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}
double disteuclid(){
	double res=0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){		
			res=0;
			for (int k=0;k<m;k++)
				res+=pow(((p[i][k])-(p[j][k])),2);
		res=sqrt(res);
		}
	}
	return 0;
}
void limpiarmem(){
	for (int i=0; i<n; ++i){
		delete [] p[i];
	delete [] p;
	}
}
int main(){
	cin>>n>>m;
	reservarmem();
	rellenmem();
	///mostrarmat();
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	disteuclid();
	end = std::chrono::high_resolution_clock::now();
	int64_t duration =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
		.count();
	std::cout << std::setw(10) << duration << std::setw(30);
	limpiarmem();
	return 0;
}
