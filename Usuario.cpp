#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;
	Usuario::Usuario(string Username, string Password, string Nombre, int Edad, string ID, string Telefono) { 
		setUsername(Username);
		setPassword(Password);
		setNombre(Nombre);
		setEdad(Edad);
		setID(ID);
		setTelefono(Telefono);
	}
	void Usuario::setUsername(string a) {
		this->Username = a;
	}
	void Usuario::setPassword(string a) {
		this->Password = a;
	}
	void Usuario::setNombre(string a) {
		this->Nombre = a;
	}
	void Usuario::setEdad(int a) {
		this->Edad = a;
	}
	void Usuario::setID(string a) {
		this->ID = a;
	}
	void Usuario::setTelefono(string a) {
		this->Telefono = a;
	}
	string Usuario::getUsername() {
		return this->Username;
	}
	string Usuario::getPassword() {
		return this->Password;
	}
	string Usuario::getNombre() {
		return this->Nombre;
	}
	int Usuario::getEdad() {
		return this->Edad;
	}
	string Usuario::getID() {
		return this->ID;
	}
	string Usuario::getTelefono() {
		return this->Telefono;
	}
