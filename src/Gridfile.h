#ifndef GRIDFILE_H_
#define GRIDFILE_H_

class Gridfile {

public:
	Gridfile();
	~Gridfile();
	void cargarBIN();
	void add(short int,short int,float,int);
};

#endif /* GRIDFILE_H_ */
