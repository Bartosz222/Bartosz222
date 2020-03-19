#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class palindrom{
	public:
		ifstream wejscie;
		ofstream wyjscie;
		string napis;
		string napis2;
		string napisbezspacji;
		string znak;
		palindrom();
		~palindrom();
		
	void sprawdzanie();
	void wczytaj();
	void zamiana();
	bool sprawdzCzyPalindrom(string ss);
	void zapis();
	
};
palindrom::palindrom(){
	wejscie.open("wejœcie.txt");
	wyjscie.open("wyjscie.txt");
	wyjscie<<"[\n";
}
palindrom::~palindrom(){
	wyjscie<<"]";
	wejscie.close();
	wyjscie.close();
	
}
void palindrom::sprawdzanie(){
	if(wejscie.good()&&wyjscie.good()){
		wczytaj();
	}
	else{
		cout<<"blad";
	}
}
void palindrom::wczytaj(){
	while(!wejscie.eof()){
		getline(wejscie,napis);
		zamiana();
	}
}
void palindrom::zamiana(){
	stringstream s(napis);
	while(s >> napis2){
		napisbezspacji += napis2;
	}
	napis = napisbezspacji;
	for(int i=0;i<napis.length();i++){
		napis[i] = tolower(napis[i]);
	}
	napis2 = "";
	napisbezspacji = "";
	cout<<napis<<" ";
	sprawdzCzyPalindrom(napis);
	napis = "";
}
bool palindrom::sprawdzCzyPalindrom(string ss){
	int last = ss.length()-1;
	bool palindrom = true;
	for(int i = 0;i<ss.length()/2&&palindrom;i++){
		if(ss[i] !=ss[last--]){
			palindrom = false;
		}
	}
	cout<<palindrom<<endl;
	if(palindrom == true){
		znak = "TAK";
	}
	else{
		znak = "NIE";
	}
	zapis();
}
void palindrom::zapis(){
	wyjscie<<"{string:"+napis+",palindrom:"+znak+"},"<<endl;
}
int main() {
	palindrom p1;
	p1.sprawdzanie();
	return 0;
}
