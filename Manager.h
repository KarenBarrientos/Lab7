#pragma once
#include "Usuarios.h"
#include "Manager.h"

#include <iostream>
#include <string>
using std::string;

class Manager: public Usuarios{
	private:
		double Sueldo;
	public:
		Manager(string,string,string,string,double);
		virtual ~Manager();
		virtual string toString();
};