#pragma once
#include "Usuarios.h"

#include <iostream>
#include <string>
using std::string;

class Usuarios{
	private:
		string Nom_Usuario;
		string Correo;
		string Password;
		string Tipo;
	public:
		Usuarios(string Nom_Usuario,string Correo,string Password,string Tipo);
		string getNom_Usuario();
		string getCorreo();
		string getPassword();
		string getTipo();
		virtual ~Usuarios();
		virtual string toString();
};