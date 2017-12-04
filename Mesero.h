#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
using namespace std;
class Mesero : public Personal {
	private: 
		vector<string>* Platillos;
	public: 
		Mesero(string, string, string, int, string, string, string, double);
		void  setPlatillos(vector<string>*);
		vector<string>* getPlatillos();
		virtual int getType();
		virtual string RefID();
		virtual string toString();
		virtual void Special(int);
};
