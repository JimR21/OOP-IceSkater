#include <iostream>
#include <stdlib.h>     /* atoi */

using namespace std;


struct Mountains{
	Mountains(){
		cout<<"Mountains were just created!"<<endl<<endl;
	}
	~Mountains(){
		cout<<"Mountains are about to be destroyed"<<endl<<endl;
	}
};

struct Trees{
	Trees(){
		cout<<"Trees were just created!"<<endl<<endl;
	}
	~Trees(){
		cout<<"Trees are about to be destroyed"<<endl<<endl;
	}
};

struct Little_house {
	Little_house(){
		cout<<"A little house was just created!"<<endl<<endl;
	}
	~Little_house(){
		cout<<"A little house is about to be destroyed"<<endl<<endl;
	}
};

class Background {
	Mountains m;
	Trees t;
	Little_house h;
public:
	Background(){
		cout<<"Background was just created!"<<endl<<endl;
	}
	~Background(){
		cout<<"Background is about to be destroyed"<<endl<<endl;
	}
};


class IceSkater {
	int distance;
	int pos;
public:
	IceSkater(int dist){
		distance = dist;
		pos = 0;
		cout<<"An IceSkater participates"<<endl<<endl;
	}
	~IceSkater(){
		cout<<"An IceSkater will be discarted!"<<endl<<endl;
	}
	void start(){
		cout<<"Here I am ..."<<endl<<endl;
	}
	void skate(int d){
		int plithos;
		pos = pos + d;
		plithos = d/distance;
		if (distance*plithos < d){
			plithos++;
		}
		cout<<"An IceSkater skates"<<endl<<"Number of skates " <<plithos<<endl<<endl;
	}
	void rotate(){
		cout<<"An IceSkater spins on position " <<pos<<endl<<endl;
	}
	void jump(){
		cout<<"An IceSkater jumps on position " <<pos<<endl<<endl;
	}
};


class Lake{
	int mhkos;
	enum {dark, light} lights;
public:
	Lake(int l){
  mhkos = l;
		lights = dark;
		cout<<"A lake appears"<<endl<<endl;
	}
	~Lake(){
		cout<<"A lake will disappear!"<<endl<<endl;
	}
	void light_up(){
		lights = light;
		cout<<"Lights on!"<<endl<<endl;
	}
	void darken(){
		lights = dark;
		cout<<"Lights off!"<<endl<<endl;
	}
	void rotate(){
		cout<<"Lake rotated!"<<endl<<endl;
	}
	int get_mhkos(){
		return mhkos;
	}
};


class Scene{
	Background back;
	IceSkater ice;
	Lake lake;
public:
	Scene(int l, int dist):ice(dist), lake(l){
		cout<<"Scene was just created!"<<endl<<endl;
	}
	~Scene(){
		cout<<"Scene is about to be destroyed"<<endl<<endl;
	}
	int plot(){
		int x = lake.get_mhkos();
		lake.light_up();
		ice.start();
		ice.skate(x/2);
		ice.rotate();
		ice.jump();
		ice.skate(x/2);
		lake.rotate();
		lake.darken();
	}
};

int main(int argc,char*argv[]){
	int L, dist;
	L=atoi(argv[1]);
	dist=atoi(argv[2]);
	Scene scene(L,dist);
	scene.plot();
}
