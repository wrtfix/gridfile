#ifndef BALDE_H_
#define BALDE_H_

//#include <vector.h>

//Este numero debe ser mayor o igual a 10.
#define CAPACIDAD_BALDE 25

class Balde {
	private:
		//vector<int> elementos;
	public:
		Balde();
		virtual ~Balde();
		bool add(int);
		int get(int);
};

#endif /* BALDE_H_ */
