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


Zona::Zona(int x1,int y1,int z1, int x2,int y2,int z2,Balde *balde) {
	
	//desde			//hasta
	this->set_x1(x1);	this->set_z2(x2);
	this->set_y1(y1);	this->set_z2(y2);
	this->set_z1(z1);	this->set_z2(z2);
	
	this->balde = balde;
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

Zona::~Zona() {
	
}

Zona* Zona::dividirX() {
	int x3 = (this->get_x2() + this->get_x1())/2;
	//int y = (this->get_y2() + this->get_y1())/2;
	//int z = (this->get_z2() + this->get_z1())/2;
	
	Balde *bNuevo = new Balde();
	Zona *zNueva = new Zona(x3,
							this->get_y1(),
							this->get_z1(),
							
							this->get_x2(),
							this->get_y2(),
							this->get_z2(),
							bNuevo);
	
	this->set_x2(x3-1);
	
	return zNueva;
}



