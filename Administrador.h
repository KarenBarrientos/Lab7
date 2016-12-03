#pragma once
#include "Usuarios.h"
#include "Administrador.h"

#include <iostream>
#include <string>
using std::string;

class Administrador: public Usuarios{
	private:
		string Fecha;
	public:
		Administrador(string,string,string,string,string);
		virtual ~Administrador();
		virtual string toString();
};