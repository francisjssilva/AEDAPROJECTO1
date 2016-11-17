#include "header.h"
#include "date.h"
#include "stock.h"
#include "client.h"
#include "market.h"
#include "menu.h"
#include "order.h"


using namespace std;



int main(){

	//Criacao do Mercado
	Market *CR7 = new Market("Mercado do Ronaldo");

	//Import das acções do ficheiro stocks.txt
	Stock sto;
	vector<Stock> stock = sto.Import("stocks.txt");
	CR7->pushVecStocks(stock);

	CR7->importclientes("clientes.txt");
	CR7->importposses("posses.txt");
	CR7->importvendas("vendas.txt");
	CR7->importhistvendas("histvendas.txt");
	CR7->importhistvendas("histcompras.txt");

	//cout << CR7->getclients()[1].getname() << endl;
	//cout << CR7->getclients()[1].getpassword() << endl;
	//cout << CR7->getclients()[0].getPosses()[0].gettitulo() << endl;
	cout << CR7->getclients()[1].retornavendas()[2].gettitle() << endl;
	cout << CR7->getclients()[1].retornavendas()[2].getdate().getdata() << endl;


	/*string a = CR7->getStocks()[0].gettitle();
	double b = CR7->getStocks()[0].getmediumprice();

	cout << a << "\n" << b;*/

	//Atributos das classes herdadas de Order
	//double amount = 200.0; //referente à class Venda
	//double minup = 5.0; //referente à class Venda

	//double maxup = 10.0; //referente à class Compra
	//double minprice = 5; //referente à class Compra

	//Atributos da Class Stock
	//string title = "Microsoft";
	//Date date;

	/*//Criacão do Cliente
	string name = "Francisco";
	unsigned int NIF = 506734285;
	Client owner(name, NIF);

	//Inscrição do Cliente no Mercado
	CR7->pushVecClients(owner);

	//Criação de novas ordens de compra e de venda, respectivamente de um cliente

	Compra *compra1 = new Compra(maxup, title, minprice, date);
	Venda *venda1 = new Venda(minup, amount, title, date);*/
	menu(CR7);


	return 0;
}

