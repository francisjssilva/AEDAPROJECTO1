#pragma once
#include "header.h"

using namespace std;

class Stock{
private:
	string title;
	double mediumprice;
	int amount;

public:
	Stock(){};
	Stock(string title, double m, int b){this->title = title; this->mediumprice=m; this->amount=b;};
	vector<Stock> Import(string file);
	string gettitle(){return this->title;};
	double getmediumprice(){return this->mediumprice;};
	int getamount(){ return this->amount;}
	int listastock();
	void actualizar(double precomed, int amount){
		this->mediumprice = precomed;
		this->amount = this->amount + amount;
	};
};
