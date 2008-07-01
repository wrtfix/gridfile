#ifndef BALDE_H_
#define BALDE_H_

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
		bool get(int);
};

#endif /* BALDE_H_ */
