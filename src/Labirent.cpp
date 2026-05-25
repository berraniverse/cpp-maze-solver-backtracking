#include "Labirent.hpp"
#include <stdexcept>
#include <chrono>
#include <thread>

Labirent::Labirent(Konum baslangic, Konum bitis){
	x = baslangic.x;
	y = baslangic.y;
	this->bitis = bitis;
	yon = ASAGI;

	yigit = new Stack<Konum>();
	yigit->push(Konum(-1, -1, yon));

	for(int satir = 0; satir < YUKSEKLIK; satir++){
		for(int sutun = 0; sutun < GENISLIK; sutun++){
			harita[satir][sutun] = '#';
		}
	}

	ifstream dosya("Harita.txt");

	if(!dosya.is_open()){
		throw std::runtime_error("Harita.txt dosyasi acilamadi.");
	}

	string satirMetni;
	int satir = 0;

	while(satir < YUKSEKLIK && getline(dosya, satirMetni)){
		for(int sutun = 0; sutun < GENISLIK && sutun < static_cast<int>(satirMetni.length()); sutun++){
			harita[satir][sutun] = satirMetni[sutun];
		}
		satir++;
	}
}
Labirent::~Labirent(){
	delete yigit;
}
Konum Labirent::mevcutKonum(){
	return Konum(x,y,yon);
}
bool Labirent::adimAt(Konum mevcut, Konum ileri){
	if(!EngelVarmi(ileri)){
		yigit->push(mevcut);
		ayarla(ileri,ileri.yon);
		return true;
	}
	return false;
}
void Labirent::ayarla(Konum konum, Yon yon){
	std::cout << "\033[2J\033[H";
	this->x = konum.x;
	this->y = konum.y;
	this->yon = yon;
	harita[konum.x][konum.y] = '-';
	std::cout << yaz();
	std::this_thread::sleep_for(std::chrono::milliseconds(30));
}
bool Labirent::CikisaGeldimi(){
	return x == bitis.x && y == bitis.y;
}
bool Labirent::EngelVarmi(Konum konum){			
	if(konum.x >= YUKSEKLIK || konum.x < 0 || konum.y >= GENISLIK || konum.y < 0) return true;
	return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';
}
	
string Labirent::yaz(){
	char YonChr[] = {3,17,6,16};
	stringstream ss;
	for(int satir=0;satir<YUKSEKLIK;satir++){
		ss<<setw(10);
		for(int sutun=0;sutun<GENISLIK;sutun++){
			if(satir == x && sutun == y){
				ss<<YonChr[yon];
			}
			else{
				 if(harita[satir][sutun] == '-') ss<<' ';
				 else ss<<harita[satir][sutun];
			}
		}	
		ss<<endl;				
	}
	return ss.str();
}
