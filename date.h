#pragma once
#include "header.h"

template<class A>
class datainvalida{
public:
	string tipo;
	A pardate;

	datainvalida(string tip, A a){
		tipo=tip;
		pardate = a;
	}
};



class Date{
private:
	int dia;
	int mes;
	int ano;

public:
	Date(){};
	Date(const string &input) {
	    int month;
	    int day;
	    int year;
	    sscanf(input.c_str(), "%d/%d/%d", &day, &month, &year);
	    if(day<1 || day>31){
	    	throw datainvalida<int>("dia",day);
	    	}
	    if(month<1 || month>12){
	    	throw datainvalida<int>("mes",month);
	    		}
	    if(ano<0){
	    	throw datainvalida<int>("ano",year);
	    	}

	    this->mes=month;
	    this->dia=day;
	    this->ano=year;
	    }
	string getdata(){return to_string(dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);};
};
