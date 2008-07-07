/*
 *      Zona.h
 *      
 *      Copyright 2008 	Jorge Carlos Mendiola <wrtfix@gmail.com> &
 * 						Manuel Alonso <manuel.alonso.d@gmail.com>
 *      
 *
 * Este programa es de libre distribución; puedes distribuirlo y/o modificarlo
 * bajo los términos de la GNU General Public License como se publicó por la
 * Free Software Foundation; bien la versión 2 de la licencia o,  bajo tu
 * criterio, cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil, pero
 * SIN NINGUNA GARANTÏA; sin, incluso, ninguna garantía implicada por
 * MERCANCIBILIDAD o POR ALGÜN PROPÓSITO PARTICULAR. Lee la
 * GNU General Public License para más información.
 *
 * Deberías haber recibido una copia de la GNU General Public License
 * junto con este programa. Si no es así escribe a Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */


#ifndef ZONA_H
#define ZONA_H

#include "Balde.h"

class Zona
{
	public:
		Zona(int,int,int,int,int,int);
		~Zona();
		
		void set_x1(int);
		void set_y1(int);
		void set_z1(int);
		void set_x2(int);
		void set_y2(int);
		void set_z2(int);
		
		int get_x1();
		int get_y1();
		int get_z1();
		int get_x2();
		int get_y2(); 
		int get_z2();
	
		Balde* getBalde();
		void setBalde(Balde*);
		Zona* divAccion(int);
		Zona* divPrecio(int);
		bool pertenece(int,int,int);
		
		void imprimir();
	
	private:
		//Desde (x1,y1) hasta (x2,y2)
		int x1;
		int y1;
		int z1;
		int x2;
		int y2;
		int z2;
		
		//Balde al que apunta la Zona
		Balde* balde;
};

#endif // ZONA_H
