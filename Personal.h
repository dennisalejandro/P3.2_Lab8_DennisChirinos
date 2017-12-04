#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"
using namespace std;
class Personal : public Usuario {
	protected: 
		string Ano;
		double Sueldo;
	public: 
		Personal(string, string, string, int, string, string, string, double);
		void  setAno(string);
		void  setSueldo(double);
		string getAno();
		double getSueldo();
		virtual string RefID();
		virtual int getType();
		virtual string toString();
		virtual void Special(int);
};
