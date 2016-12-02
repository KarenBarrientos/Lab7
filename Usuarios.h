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
	public:
		Usuarios(string Nom_Usuario,string Correo,string Password);
		string getNom_Usuario();
		string getCorreo();
		string getPassword();
		virtual ~Usuarios();
		virtual string toString();
};