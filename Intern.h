#pragma once
#include "Usuarios.h"
#include "Intern.h"

#include <iostream>
#include <string>
using std::string;

class Intern: public Usuarios{
	private:
		int Num_Dias;
	public:
		Intern(string,string,string,string,int);
		virtual ~Intern();
		virtual string toString();
};