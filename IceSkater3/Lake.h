#ifndef Lake_h
#define Lake_h
#include "IceSkater.h"





class Lake
{
	int m , l, n, t;
	IceSkater ***plegma;
public:
	Lake(int mm, int ll, int nn, int tt);
	~Lake();
	void show();
	void populate();
	void pos_Normal(int m, int l, int &pos1, int &pos2, int &lim, int &vel);
	void pos_Amateur(int m, int l, int &pos1, int &pos2);
	void pos_Pro(int m, int l, int &pos1, int &pos2, int &vel);
	void collision(int j, int i, int &posa, int &posb);
	void moving(int u);
	void check();
};

#endif
