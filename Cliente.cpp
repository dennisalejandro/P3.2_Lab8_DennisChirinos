#include "Cliente.h"
#include <iostream>
#include <string>
#include "Usuario.h"
using namespace std;
	Cliente::Cliente(string Username, string Password, string Nombre, int Edad, string ID, string Telefono, string Direccion, int Rating) : Usuario(Username, Password, Nombre, Edad, ID, Telefono) { 
		setDireccion(Direccion);
		setRating(Rating);
	}
	void Cliente::setDireccion(string a) {
		this->Direccion = a;
	}
	void Cliente::setRating(int a) {
		this->Rating = a;
	}
	string Cliente::getDireccion() {
		return this->Direccion;
	}
	int Cliente::getRating() {
		return this->Rating;
	}
