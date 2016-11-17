#include "client.h"
#include "header.h"


void Client::pushVecPosses(Posses *cmp){
	this->posses.push_back(*cmp);
}

void Client::pushVecVenda(Venda *vnd){
	this->sells.push_back(*vnd);
}
