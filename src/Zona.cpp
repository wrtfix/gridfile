/*
 *      Zona.cpp
 *      
 *      Copyright 2008 	Jorge Carlos Mendiola <wrtfix@gmail.com> &
 * 						Manuel Alonso <piratAttack@gmail.com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include "Zona.h"
#include <math.h>


Zona::Zona(int x1,int y1,int z1, int x2,int y2,int z2) {
	
	//desde			//hasta
	this->set_x1(x1);	this->set_x2(x2);
	this->set_y1(y1);	this->set_y2(y2);
	this->set_z1(z1);	this->set_z2(z2);	
}

void Zona::set_x1(int x){
	this->x1 = x;
} 

void Zona::set_y1(int y){
	this->y1 = y;
} 

void Zona::set_z1(int z){
	this->z1 = z;
}

void Zona::set_x2(int x){
	this->x2 = x;
} 

void Zona::set_y2(int y){
	this->y2 = y;
} 

void Zona::set_z2(int z){
	this->z2 = z;
}

int Zona::get_x1(){
	return this->x1;
} 

int Zona::get_y1(){
	return this->y1;
} 

int Zona::get_z1(){
	return this->z1;
}

int Zona::get_x2(){
	return this->x2;
} 

int Zona::get_y2(){
	return this->y2;
} 

int Zona::get_z2(){
	return this->z2;
}

Balde* Zona::getBalde() {
	return this->balde;
}

void Zona::setBalde(Balde* balde) {
	this->balde = balde;
}
		

Zona::~Zona() {
	
}

/*
 * divide la Zona respecto a la variable X
 *  DEPENDE DE DIVIDIR BALDE.
 * alpha
 */
Zona* Zona::divAccion() {
	
	int x3 = ceil((this->get_x2() + this->get_x1())/2);
		
	//creo una nueva Zona
	Zona *zn = new Zona(x3+1,this->get_y1(),this->get_z1(),this->get_x2(),this->get_y2(),this->get_z2());
	
	//creo un nuevo Balde
	Balde *bn = new Balde();
	
	//Asigno el nuevo balde a la nueva zona
	zn->setBalde(bn);
	
	//la Zona se achica respecto a la variable X (accion)
	this->set_x2(x3);

	return zn;
}

bool Zona::pertenece(int x,int y, int z) {
	
	bool ifx,ify,ifz;
	 
	ifx = ((x + this->get_x1()) <= this->get_x2());
	if (ifx)
		ify = ((y + this->get_y1()) <= this->get_y2());
			if (ify)
				ifz = ((z + this->get_z1()) <= this->get_z2());
					if (ifz)
						return true;
	return false;
}

void Zona::imprimir()
{
     cout << "Zona " << endl;
     cout << " desde: " << x1 << "," << y1 << "," << z1 << endl;
     cout << " hasta: " << x2 << "," << y2 << "," << z2 << endl;
}
