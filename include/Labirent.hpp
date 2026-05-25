#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include <fstream>
#include <iomanip>
#include <sstream>

#include "Konum.hpp"
#include "Stack.hpp"
#define YUKSEKLIK 19
#define GENISLIK 29

class Labirent{
	public:
		char harita[YUKSEKLIK][GENISLIK];
		int x,y;
		Yon yon;
		Konum bitis;
		Stack<Konum> *yigit;
		
		Labirent(Konum, Konum);
		~Labirent();
		Konum mevcutKonum();
		bool adimAt(Konum, Konum);
		void ayarla(Konum,Yon);
		bool CikisaGeldimi();
		bool EngelVarmi(Konum);		
		string yaz();
};

#endif
