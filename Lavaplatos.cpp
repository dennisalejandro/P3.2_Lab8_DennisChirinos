#include "Lavaplatos.h"
#include <iostream>
#include <string>
using namespace std;
	Lavaplatos::Lavaplatos(string Username, string Password, string Nombre, int Edad, string ID, string Telefono, string Ano, double Sueldo, int Motivacion) : Personal(Username, Password, Nombre, Edad, ID, Telefono, Ano, Sueldo) { 
		setMotivacion(Motivacion);
	}
	void Lavaplatos::setMotivacion(int a) {
		this->Motivacion = a;
	}
	int Lavaplatos::getMotivacion() {
		return this->Motivacion;
	}
	string Lavaplatos::RefID() {
		string ref = "3:";
		ref += getUsername() + ";";
		ref += getPassword() + ";";
		ref += getNombre() + ";";
		ref += to_string(getEdad()) + ";";
		ref += getID() + ";";
		ref += getTelefono() + ";";
		ref += getAno() + ";";
		ref += to_string(getSueldo()) + ";";
		ref += to_string(getMotivacion()) + ";";
		return ref;
	}
	string Lavaplatos::toString() {
		string ref = "";
		ref += "Usuario: " + getUsername() + ", ";
		ref += "Nombre: " + getNombre() + ", ";
		ref += "Edad: " + to_string(getEdad()) + ", ";
		ref += "ID: " + getID() + ", ";
		ref += "Telefono: " + getTelefono() + ", ";
		ref += "Fecha de contratacion: " + getAno() + ", ";
		ref += to_string(getSueldo()) + "$, ";
		ref += "Motivacion" +to_string(getMotivacion()) + "";
		return ref;
	}
	int Lavaplatos::getType() {
		return 3;
	}
