#pragma once
#include "date.h"
#include "tgmath.h"
#include "header.h"

using namespace std;

class Order{
private:
	string title; //titulo da acao que quer vender ou comprar
	Date date; //data em que
	int amount; //quantidade de acoes a vender

public:
	Order(string title, Date date, int amount){  //Construtor Class Order
		this->title = title;
		this->date = date;
		this->amount = amount;
	};
	~Order(){};

	string gettitle(){return this->title;};
	int getamount(){return this->amount;}
	Date getdate(){return this->date;};
};



class Compra:public Order{
private:
	double maxup; // preco maximo p/ unidade
	double maxprice; //preco max a gastar
public:
	Compra(double maxup, string title, double maxprice, Date date, int amount): Order(title, date, amount){ //Construtor Class Compra: public Order
		this->maxup = maxup; //valor maximo por unidade das acções que o cliente quer comprar
		this->maxprice = maxprice; //valor máximo que o cliente está disposto a gastar pela totalidade das acções
	};
	~Compra(){};

	double getmaxupt(){return this->maxup;};

	int calculaamout(double maxup, double maxprice){  //função responsavel por saber quantas açoes de x tipo cada cliente pode comprar
		double resto;

		if(fmod(maxprice,maxup) == 0){
			return maxprice/maxup;
		}
		else{

			resto = maxprice - (floor(maxprice/maxup)*maxup);
			cout << "Foi possivel comprar " << floor(maxprice/maxup) << " restando " << resto << " euros\n";
			return floor(maxprice/maxup);
		}

	};

	double getmaxprice(){return this->maxprice;};
};



class Venda:public Order{
private:
	double minup; // preco minimo p/ unidade de venda
public:
	Venda(double minup, int amount, string title, Date date): Order(title, date, amount){ //Construtor Class Venda: public Order
		this->minup = minup;
	};
	~Venda(){};

	double getminup(){return this->minup;};
};
