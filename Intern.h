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
		int getNum_Dias();
		virtual ~Intern();
		virtual string toString();
};