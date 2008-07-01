/*
 *      Zona.h
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


#ifndef ZONA_H
#define ZONA_H

#include "Balde.h"

class Zona
{
	public:
		Zona(int,int,int,int,int,int,Balde*);
		~Zona();
		Zona* dividir();
	
	private:
		//Desde (x1,y1) hasta (x2,y2)
		int x1,y1,z1,x2,y2,z2;
		
		//Balde al que apunta la Zona
		Balde* balde;
};

#endif // ZONA_H
