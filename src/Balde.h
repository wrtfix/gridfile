#ifndef BALDE_H_
#define BALDE_H_

#include <iostream>
#include <vector>

//Este numero debe ser mayor o igual a 10.
#define CAPACIDAD_BALDE 25

using namespace std;

class Balde {
	private:
		vector<int> elementos;
	public:
		Balde();
		~Balde();
		bool add(int);
		int get(int);
		int size();
		bool full();
		void imprimir();
		
};

#endif /* BALDE_H_ */
