#pragma once
#include <iostream>
#include <string>
#include "Personal.h"
using namespace std;
class Lavaplatos : public Personal {
	private: 
		int Motivacion;
	public: 
		Lavaplatos(string, string, string, int, string, string, string, double, int);
		void  setMotivacion(int);
		int getMotivacion();
		virtual int getType();
		virtual string RefID();
		virtual string toString();
};
