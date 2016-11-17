/*
 * menu.h
 *
 *  Created on: 12/11/2016
 *      Author: FranciscoSilva
 */
#ifndef MENU_H_
#define MENU_H_

#pragma once
#include "header.h"
#include "date.h"
#include "stock.h"
#include "client.h"
#include "market.h"
#include "order.h"

int menu2(Market *CR7, Client *username){
	// a este ponto o cliente passou pelo login e poder� fazer transac�oes:
int c;
			cout<<"1:comprar acoes."<<endl;
			cout<<"2:Vender acoes."<<endl;
			cout<<"3:Visualizar vendas da minha Conta"<<endl;
			cout<<"4:Visualizar compras(posses) da minha Conta"<<endl;// com os dois historico de vendas e compras o objectivo � listar ambos os vecs de compras e vendas do cliente como sendo um historico;
			cout<<"5:Visualizar stocks no mercado"<<endl;
			cout<<"6:logout..."<<endl;
			cin>>c;
			cin.clear();

			switch(c){
			case 1:{
				//ainda n sei...
				break;}

			case 2:{
				double minup; // preco minimo p/ unidade de venda
				int amount; //quantidade de acoes a vender
				string title; //titulo da acao que quer vender ou comprar
				string data;
				Date dat;
				unsigned int exp = 0;
				int i;
				int escolha, quantidade;


				do{
					for(i=0; i < username->getPosses().size(); i++){
						cin.clear();
						cout << i << ": Titulo -> " << username->getPosses()[i].gettitulo() << "; Unidades -> " << username->getPosses()[i].getquantidade() << endl;
					}

					cout << "\nEscolha quais as acoes que quer vender de 0 a " << i-1 << endl;
					cin >> escolha;
					quantidade = username->getPosses()[escolha].getquantidade();

				}while(escolha > i || escolha < 0 || cin.fail() || escolha > i);
				title = username->getPosses()[escolha].gettitulo();

				//se o titulo for uma acao do mercado, continua
				//se o cliente tiver essa acao comprada, continua

				do{cout<<"Digite a data actual:"<<endl; // nao concordo muito com isto num mercado de bolsa os clientes nao dizem a data a que querem vender simplesmente poe a vender.
				cin>>data;
				cin.clear();

				try{
					Date dat(data);
					}
					catch(datainvalida<int> &e){
						    		cerr<<"O" << e.tipo << "fornecido" << e.pardate << " está errado, por favor insira um ano maior que 0"<< endl;
						    		exp = 1;}
						    		} while(exp != 0); // se quiseres a data isto poderse a fazer so qe irei precisar de depois utilizar a funcao data que fiz;


				do{cout<<"Digite o preco minimo p/ unidade de venda:"<<endl;
				cin.clear();
				cin>>minup;
				}while(cin.fail());

				do{
					cout<<"Digite a quantidade:"<<endl;//depois tbm se podem criar funcoes que verifiquem se a acao em questao pertence ao cliente ou se existe, e tbm uma funcao para verificar se o cliente tem quant suficiente de acoes para vender;
					cin.clear();
					cin>>amount;


				}while(amount > quantidade || cin.fail());

				Date dt(data);
				cout << escolha;
				Venda *vnd = new Venda(minup, amount, title, dt); // ainda nao tou a ver como inserir esta venda no vector de vendas do cliente qe pertence ao mercado CR7
				username->delPosses(escolha, amount); // elimina a posse do cliente (ou subtrai quantidade ou elimina as acoes desse tipo que comprou anteriormente)
				username->pushVecVenda(vnd);
				CR7->pushVecVenda(vnd); //faz o pushback para guardar o historico de vendas
				CR7->changeStocks(title, amount);

				cout << "\nVenda efectuada com sucesso!" << endl;

				menu2(CR7, username);
				break;}

			case 3:{

				for(unsigned int i=0; i < username->retornavendas().size(); i++){
				cout << "Titulo -> " << username->retornavendas()[i].gettitle() << "; Data-> " << username->retornavendas()[i].getdate().getdata() << "; Quantidade-> " << username->retornavendas()[i].getamount() <<  endl;
				}
				menu2(CR7, username);
				break;}
			case 4:{
				int i;
				for(i=0; i < username->getPosses().size(); i++){
						cout << i << ": Titulo -> " << username->getPosses()[i].gettitulo() << "; Unidades -> " << username->getPosses()[i].getquantidade() << endl;
					}
				break;}

			case 5:{
				for(unsigned int i=0; i < CR7->getstocks().size(); i++){
						cout << i << ": Titulo -> " << CR7->getstocks()[i].gettitle() << "; Preco Medio -> " << CR7->getstocks()[i].getmediumprice() << "; Qnt de acoes a Venda -> " << CR7->getstocks()[i].getamount()  << endl;
						}
				break;}

			case 6:{
				cout<<"Obrigado pela sua visita"<<endl;
				break;}


}
return 0;
}

int menu(Market *CR7){
	int b;

	cout<<"Escolha a opcao:"<<endl;
	cout<<"1:Criar cliente."<<endl;
	cout<<"2:Login."<<endl;
	cout<<"3:fechar programa"<<endl;
	cin>>b;
	cin.clear();

	string name;
	long int NIF;
	string password1;
	string password2;
	string username;

	switch(b){
	case 1:{	//criacao do cliente adicionei parcela ao cliente password se nao gostares tira

		cout<<"Digite o username pretendido"<<endl;
		cin>>username;
		cin.clear();

		while(CR7->verificausername(username)!=-1){//funcao presente na class market apenas verifica se o username ja existe
			cerr<<"O username "<<username<<" ja existe por favor digite outro"<<endl;
			cin>>username;
			cin.clear();
		};

		do{
			cout<<"Digite a sua password"<<endl;
			cin>>password1;
			cin.clear();
			cout<<"Digite a password outra vez"<<endl;
			cin>>password2;
			cin.clear();

			if(password1!=password2) cerr<<"password nao coincide"<<endl;

			}while(password1!=password2);

		cin.clear();
		cin.ignore();
		cout<<"Digite o seu nome"<<endl;
		getline(cin, name);
		cin.clear();

		cout<<"Digite o seu NIF"<<endl;
		cin>>NIF;
		cin.clear();

		Client *o = new Client(name, NIF, username, password1);
		CR7->pushVecClients(o);
		cout<<"Utilizador criado com successo"<<endl;
		menu(CR7);

		}
		break;

	case 2:{
		do{
			cout<<"Introduza o seu username"<<endl;
			cin>>username;
			cin.clear();
			cout<<"Digite a sua password"<<endl;
			cin>>password1;
			cin.clear();

			if(CR7->verificausername(username)==-1){
				cerr<<"User n�o existe!"<<endl;// posso adicionar aqui algo tbm para qe se a pessoa n quiser tar a introduzir credenciais ate acertar retornar ao menu principal;
			}

			else if(CR7->verificausername(username)!=-1 && CR7->verificapassword(username,password1)==false){
				cerr<<"A password est� errada"<<endl;
			}

		}while(CR7->verificausername(username)==-1 || CR7->verificapassword(username,password1)==false);
		// a este ponto o cliente passou pelo login e poder� fazer transac�oes:
		Client *user = new Client(CR7->getclients()[CR7->verificausername(username)]);

		menu2(CR7, user);
		break;
	}
	case 3:{
		return 0;
		break;

	}
		}



return 0;



}




#endif /* MENU_H_ */
