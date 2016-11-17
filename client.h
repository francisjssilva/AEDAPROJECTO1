#pragma once
#include "order.h"
#include "header.h"

using namespace std;

class Posses{
private:
	string titulo;
	int quantidade;
	Date data;
public:
	Posses(){};
	Posses(string titulo, int quantidade, Date data){
		this->titulo = titulo;
		this->quantidade = quantidade;
		this->data = data;
	};
	int getquantidade(){return this->quantidade;};
	string gettitulo(){return this->titulo;};
	void subquantidade(int quantidade){this->quantidade = this->quantidade - quantidade;};
};

class Client{
private:
	string name;
	string username;
	string password;
	vector<Posses> posses; // posses (compras efectuadas com sucesso) do cliente
	vector<Venda> sells; //ordens de venda de um cliente
	vector<Compra> buys; // ordens de compra de um cliente
	long int NIF;
public:
	Client();
	Client(string name, long int NIF,string user, string password){
		this->name = name;
		this->NIF = NIF;
		this->password=password;
		username=user;
	};

	string getname(){return this->name;};
	string getusername(){return this->username;};//retorna o username
	string getpassword(){return this->password;}
	long int getNIF(){return this->NIF;};
	void pushVecPosses(Posses *cmp);
	void pushVecVenda(Venda *vnd); // nestas funcs pus com pointer para facilitar a funcao compraacao no market.cpp
	vector<Venda> retornavendas(){return this->sells;}
	int listaportfolio();
	vector<Posses> getPosses(){return this->posses;};
	void delPosses(int escolha, int quantidade){
		if(quantidade < posses[escolha].getquantidade())
			this->posses[escolha].subquantidade(quantidade);
		else
			this->posses.erase(this->posses.begin()+escolha);
	};
};

