#include "stock.h"
#include "market.h"



vector<Stock> Stock::Import(string file){
		ifstream a;
		char ch;
		string title, m, b;
		double d;
		int i;

		a.open(file);

		stringstream is;
		vector<Stock> sto;

		 while(getline(a,file)){
			is.clear();
			is.str(file);
			is >> title >> ch >> m >> ch >> b;
			d = stod(m);
			i = stoi(b);

			sto.push_back(Stock(title,d,i));
		 }


		 a.close();
		 return sto;
	};

int Stock::listastock(){
	cout<<"nome: "<<title<<endl;
	cout<<"preco medio: "<<mediumprice<<endl;
	cout<<"quantidade: "<<amount<<endl;
}
