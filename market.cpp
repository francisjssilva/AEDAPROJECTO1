#include "market.h"

void Market::pushVecStocks(vector<Stock> sto){
	this->Stocks = sto;
}

int Market::verificausername(string username){
	vector<string> clie;
	for(unsigned int i=0; i < this->Clients.size(); i++){
		clie.push_back(Clients[i].getusername());
	}

	return sequentialSearch<string>(clie, username);
}

bool Market::verificapassword(string username, string password){
	vector<Client>::iterator it;
		for(it=Clients.begin();it!=Clients.end();it++)
		{
			if(it->getusername()==username)
			{
				if(it->getpassword()==password) return true;
				return false;

			}
		}
		return false; // so pus este return aqui para ele nao se quiexar de qe nao tem return a func;
}

int Market::findclient(string username){
		for(unsigned int i=0; i < Clients.size(); i++){
			if(Clients[i].getusername() == username)
				return i;
		}
		return -1;
	};

void Market::importvendas(string txt){

			ifstream a;
					char ch;
					string title, precomin, quantidade, data, username;
					double precomind;
					int quantidadei;
					int poscliente;

					a.open(txt);

					stringstream is;

					 while(getline(a,txt)){
						is.clear();
						is.str(txt);
						is >> title >> ch >> precomin >> ch >> quantidade >> ch >> data >> ch >> username;
						precomind = stod(precomin);
						quantidadei = stoi(quantidade);

						poscliente = findclient(username);

						Venda *a = new Venda(precomind, quantidadei, title, Date(data));
						Market::Clients[poscliente].Client::pushVecVenda(a);
					 }


					 a.close();

	};

void Market::importposses(string txt){

			ifstream a;
					char ch;
					string title, quantidade, data, username;
					int quantidadei;
					int poscliente;

					a.open(txt);

					stringstream is;

					 while(getline(a,txt)){
						is.clear();
						is.str(txt);
						is >> title >> ch >> quantidade >> ch >> data >> ch >> username;
						quantidadei = stoi(quantidade);

						poscliente = findclient(username);

						Posses *a = new Posses(title, quantidadei, Date(data));

						Market::Clients[poscliente].Client::pushVecPosses(a);
					 }


					 a.close();

	};

void Market::importclientes(string txt){

			ifstream a;
					char ch;
					string username, nome, NIF, password;
					long int NIFi;

					a.open(txt);

					stringstream is;

					 while(getline(a,txt)){
						is.ignore();
						is.clear();
						is.str(txt);

						is >> username >> ch;
						getline(is, nome, ';');
						is >> password >> ch >> NIF;
						NIFi = stoi(NIF);

						Client *a = new Client(nome, NIFi, username, password);
						Market::Clients.push_back(*a);
					 }


					 a.close();

	};


void Market::importhistvendas(string txt){

			ifstream a;
					char ch;
					string title, precomin, quantidade, data, username;
					double precomind;
					int quantidadei;
					int poscliente;

					a.open(txt);

					stringstream is;

					 while(getline(a,txt)){
						is.clear();
						is.str(txt);
						is >> title >> ch >> precomin >> ch >> quantidade >> ch >> data >> ch >> username;
						precomind = stod(precomin);
						quantidadei = stoi(quantidade);

						poscliente = findclient(username);

						Venda *a = new Venda(precomind, quantidadei, title, Date(data));

						this->pushVecVenda(a);
					 }


					 a.close();

	};
