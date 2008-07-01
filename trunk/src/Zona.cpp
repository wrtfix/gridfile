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

Zona::Zona(int x1,int y1,int z1, int x2,int y2,int z3,Balde *balde) {
	
	//desde			//hasta
	this->x1 = x1;	this->x2 = x2;
	this->y1 = y1;	this->y2 = y2;
	this->z1 = z1;	this->z2 = z2;
	
	this->balde = balde;
	
	
}

Zona::~Zona() {
	
}

Zona* Zona::dividir() {
	int x = (this->x2 + this->x1)/2;
	int y = (this->y2 + this->y1)/2;
	int z = (this->y2 + this->y1)/2;
	
	Balde *bNuevo = new Balde();
	Zona *zNueva = new Zona(x,y,z,this->x2,this->y2,this->z2,bNuevo);
	
	return zNueva;
}

