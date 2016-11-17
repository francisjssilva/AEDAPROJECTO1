#pragma once
#include "client.h"
#include "stock.h"
#include "order.h"
#include "header.h"
#include "algorithm.h"


using namespace std;

/*class userjaexistente{
	string username;
	userjaexistente(string nome){
		username=nome;
	}
};*/  //acabei por nao utilizar era destinada a excep�ao

class Market{
private:
	string marketname;
	vector<Client> Clients;
	vector<Stock> Stocks;
	vector<Compra> histCompra;
	vector<Venda> histVenda;

public:
	Market(string marketname){
		this->marketname = marketname;
	};
	~Market(){};

	//funcoes para fazerem pushback de determinado valor
	void pushVecClients(Client *client){this->Clients.push_back(*client);};
	void pushVecCompra(Compra *compra){this->histCompra.push_back(*compra);};
	void pushVecVenda(Venda *venda){this->histVenda.push_back(*venda);};
	void pushVecStocks(vector<Stock> sto);

	//verificacoes
	int verificausername(string username); // adicionei a funcao para aquando da cria��o do cliente verificar se esse cliente j� existe ou nao;
	bool verificapassword(string username, string password);// vai ao vetor clients e procura o cliente de username username e ve se a pass coincide;

	//funções de retorno de parametros
	string getmarketname(){return this->marketname;};
	vector<Client> getclients(){return this->Clients;};
	vector<Stock> getstocks(){return this->Stocks;};
	int findclient(string username);

	//imports
	void importvendas(string txt);
	void importposses(string txt);
	void importclientes(string txt);
	void importhistcompras(string txt);
	void importhistvendas(string txt);

	void changeStocks(string title, int amount){ //actualiza os precos que flutuam em cada acao
		vector<string> strstock;

		for(unsigned int i = 0; i < this->Stocks.size(); i++){
			strstock.push_back(this->Stocks[i].gettitle());
		}

		int posstock = sequentialSearch<string>(strstock, title);

		double precomed = 0;
		int z, a, nrvendas;
		nrvendas = 0;

		for(a = 0; a < this->Clients.size(); a++){
					for(z = 0; z < this->Clients[a].retornavendas().size(); z++){
						if(this->Clients[a].retornavendas()[z].gettitle() == title){
						precomed = precomed + this->Clients[a].retornavendas()[z].getminup();
						nrvendas++;
						}
					}
				}

		precomed = precomed / nrvendas;


		this->Stocks[posstock].actualizar(precomed, amount);
	};
};

