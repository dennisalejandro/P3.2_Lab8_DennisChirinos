#pragma once
#include <iostream>
#include <string>
#include "Personal.h"
using namespace std;
class Administrador : public Personal {
	private: 
		int Despedidos;
		int Contratados;
	public: 
		Administrador(string, string, string, int, string, string, string, double, int, int);
		void  setDespedidos(int);
		void  setContratados(int);
		int getDespedidos();
		int getContratados();
		virtual string RefID();
		virtual int getType();
		virtual void Special(int);
};
