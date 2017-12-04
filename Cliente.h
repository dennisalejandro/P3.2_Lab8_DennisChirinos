#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"
using namespace std;
class Cliente : public Usuario {
	private: 
		string Direccion;
		int Rating;
	public: 
		Cliente(string, string, string, int, string, string, string, int);
		void  setDireccion(string);
		void  setRating(int);
		string getDireccion();
		int getRating();
};
