#ifndef IceSkater_h
#define IceSkater_h

class IceSkater
{
 protected:
	int id, pos1, pos2, vel, totalmoves, ltime, maxfall;
 public:
	IceSkater();
	int get_id();
	virtual void moves(int m, int l)=0;
	virtual void crash()=0;
	virtual void print_type()=0;
	int check_maxfall();
	virtual void get_pos(int &posa, int &posb)=0;
	int get_totalmove();
	virtual void crash_pos(int m, int l, int &posa, int &posb)=0;       // H thesh meta thn kroush
	void add_move();
	void add_time();
	int check_time(int t);
	virtual void leave()=0;
};



class Amateur: public IceSkater
{
 public:
	Amateur(int ido,int posa, int posb, int lt);
    void get_pos(int &posa, int &posb);
	void moves(int m, int l);
	void print_type();
	void crash();
	void crash_pos(int m, int l, int &posa, int &posb);
	void leave();
};



class Kid: public IceSkater
{
    int maxfall;
public:
    Kid(int ido,int posa, int posb, int lt);
	void print_type();
    void get_pos(int &posa, int &posb);
	void moves(int m, int l);
	void crash();
	void crash_pos(int m, int l, int &posa, int &posb);
	void leave();
};



class Normal: public IceSkater
{
    int lim;
public:
    Normal(int ido, int posa, int posb, int lim1, int vel1, int lt);
    void print_type();
    void get_pos(int &posa, int &posb);
    void moves(int m, int l);
    void crash();
    void crash_pos(int m, int l, int &posa, int &posb);
    void leave();
};



class Pro: public IceSkater
{
public:
    Pro(int ido, int posa, int posb, int vel1, int lt);
    void print_type();
    void get_pos(int &posa, int &posb);
    void moves(int m, int l);
    void crash();
    void crash_pos(int m, int l, int &posa, int &posb);
    void leave();
};
#endif // IceSkater_h
