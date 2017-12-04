#include "Mesero.h"
#include <iostream>
#include <string>
#include <vector>
#include "Personal.h"
using namespace std;
	Mesero::Mesero(string Username, string Password, string Nombre, int Edad, string ID, string Telefono, string Ano, double Sueldo) : Personal (Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo) { 
		vector<string>* Platillos = new vector<string>();
		setPlatillos(Platillos);
	}
	void Mesero::setPlatillos(vector<string>* a) {
		this->Platillos = a;
	}
	vector<string>* Mesero::getPlatillos() {
		return this->Platillos;
	}
	string Mesero::RefID() {
		string ref = "4:";
		ref += getUsername() + ";";
		ref += getPassword() + ";";
		ref += getNombre() + ";";
		ref += to_string(getEdad()) + ";";
		ref += getID() + ";";
		ref += getTelefono() + ";";
		ref += getAno() + ";";
		ref += to_string(getSueldo()) + ";";
		return ref;
	}
	int Mesero::getType() {
		return 4;
	}
	string Mesero::toString() {
		string ref = "";
		ref += "Usuario: " + getUsername() + ", ";
		ref += "Nombre: " + getNombre() + ", ";
		ref += "Edad: " + to_string(getEdad()) + ", ";
		ref += "ID: " + getID() + ", ";
		ref += "Telefono: " + getTelefono() + ", ";
		ref += "Fecha de contratacion: " + getAno() + ", ";
		ref += to_string(getSueldo()) + "";
		return ref;
	}
	void Mesero::Special(int a) {
		for (int i = 0;i<getPlatillos()->size();i++) {
			cout << getPlatillos()->at(i) << "\n";
		}
	}
