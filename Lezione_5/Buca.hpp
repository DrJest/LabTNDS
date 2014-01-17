#ifndef _Buca_h_
#define _Buca_h_

#include "FunzioneBase.hpp"

class Buca: public FunzioneBase {
public:
	Buca();
	Buca(int);
	~Buca();
	double Eval(double x) const;
};

#endif
