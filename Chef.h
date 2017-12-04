#pragma once
#include <iostream>
#include <string>
#include "Personal.h"
using namespace std;
class Chef : public Personal {
	private: 
		string Platillo;
	public: 
		Chef(string, string, string, int, string, string, string, double, string);
		void  setPlatillo(string);
		string getPlatillo();
		virtual string RefID();
		virtual int getType();
};
