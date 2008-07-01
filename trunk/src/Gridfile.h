#ifndef GRIDFILE_H_
#define GRIDFILE_H_

#include "Balde.h"
#define MAX_X 10
#define MAX_Y 10
#define MAX_Z 10

class Gridfile {
private:
	Balde* grid[MAX_X][MAX_Y][MAX_Z];

public:
	Gridfile();
	~Gridfile();
	void cargarBIN();
	void add(short int,short int,float,int);
	Balde* get(int,int,int);
};

#endif /* GRIDFILE_H_ */
