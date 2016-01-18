#include <iostream>

using namespace std;


class IceSkater {
	int distance;
	int ID;
	int color;
	int skill;
public:
	IceSkater(int dist = -1, int id = -1, int color_ = -1, int skill_ = -1){
		distance = dist;
		ID = id;
		color = color_;
		skill = skill_;
	}
	IceSkater(const IceSkater& i):distance(i.distance), ID(i.ID), color(i.color), skill(i.skill){}

	~IceSkater(){
	}
	void perform(){
		if(skill == 0)
			cout<<"My skill is jump ";
		else
		    cout<<"My skill is spin ";
		}
	void finale(int l){
		cout<<"ID: "<<ID;
		if (color == 0)
			cout<<" Color: Black ";
		else
		    cout<<" Color: White ";
			int plithos;
			plithos = l/distance;
			if (distance*plithos < l){
				plithos++;
			}
		    cout<<"Skate(s): "<<plithos<<endl;
	}
	int get_color(){
		return color;
	}
	int get_id(){
		return ID;
	}
	int get_distance(){
		return distance;
	}
	int get_skill(){
		return skill;
	}
	void show(){
        cout<<distance<<" "<<ID<<" "<<color<<" "<<skill<<endl;
	}
};


class List {
	struct Node {
		IceSkater data;
		Node*  next;
		Node (IceSkater& s, Node* n = NULL) : data(s), next(n) {}
	};
	Node* _start;
	int   _size;
public:
	List () : _start(NULL), _size(0) {}
	int size () { return _size; }
	void pushFront (IceSkater s){
		_start = new Node (s, _start);
		_size++;
	}
	bool popAt (int pos){
		if ( pos < 0 || pos >= _size ) return false;
		Node* t = _start;
		if ( pos == 0 ){
			_start = _start->next;
		}
		else{
			for (int i = 0 ; i < pos - 1 ; i++) t = t->next;
			Node* t2 = t->next;
			t->next = t->next->next;
			t = t2;
		}
		delete t;
		_size--;
		return true;
	}
	void at (IceSkater* ice, int pos){
		Node* t = _start;
		for (int i = 0 ; i < pos ; i++) t = t->next;
		*ice = t->data;
	}
	void end (IceSkater *ice){
        Node* t = _start;
		for (int i = 0 ; i < _size - 1 ; i++) t = t->next;
		*ice = t->data;
	}
};

	
	
class Lake{
	int mhkos;
	List dl, dr, ur, ul;                          //dl = downleft stack, dr = downright, ur = upright, ul = upleft
public:
	Lake(int l):mhkos(l){
		cout<<"A lake appears"<<endl<<endl;
	}
	~Lake(){
		cout<<"A lake will disappear!"<<endl<<endl;
	}
	void gemisma_stoives(List main){
		int id;
		while(main.size()>0){
            if(dl.size()==0){
				id = oura_stoiva(&main,&dl);
				cout<<"Adding IceSkater "<<id<<" to the Down Left Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
			else if(sugkrish_ouras_stoivas(main, dl) != 1){
				id = oura_stoiva(&main,&dl);
				cout<<"Adding IceSkater "<<id<<" to the Down Left Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
			if(dr.size()==0){
				id = oura_stoiva(&main,&dr);
				cout<<"Adding IceSkater "<<id<<" to the Down Right Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
			else if(sugkrish_ouras_stoivas(main, dr) != 1){
				id = oura_stoiva(&main,&dr);
				cout<<"Adding IceSkater "<<id<<" to the Down Right Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
			if(ur.size()==0){
				id = oura_stoiva(&main,&ur);
				cout<<"Adding IceSkater "<<id<<" to the Upper Right Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
			else if(sugkrish_ouras_stoivas(main, ur) != 1){
				id = oura_stoiva(&main,&ur);
				cout<<"Adding IceSkater "<<id<<" to the Upper Right Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
			if(ul.size()==0){
				id = oura_stoiva(&main,&ul);
				cout<<"Adding IceSkater "<<id<<" to the Upper Left Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
			else if(sugkrish_ouras_stoivas(main, ul) != 1){
				id = oura_stoiva(&main,&ul);
				cout<<"Adding IceSkater "<<id<<" to the Upper Left Stack"<<endl;
				cout<<"Deleting IceSkater "<<id<<" from MainQueue"<<endl;
				if(main.size()==0) break;
			}
		}
	}
	void final(){                                                               // sunarthsh gia thn telikh eksodo twn IceSkater
		while(dl.size()>0 || dr.size()>0 || ur.size()>0 || ul.size()>0){
			if(dl.size()>0)
				eksagwgh_iceskater(&dl);
			if(dr.size()>0)
			    eksagwgh_iceskater(&dr);
			if(ur.size()>0)
				eksagwgh_iceskater(&ur);
			if(ul.size()>0)
			    eksagwgh_iceskater(&ul);
			}
		}
	int get_mhkos(){
		return mhkos;
	}
	int sugkrish_ouras_stoivas(List o, List s){                   // sunarthsh gia th sugkrhsh tou xrwmatos tou 1ou IceSkater mias ouras k tou teleutaiou mias stoivas
		IceSkater a,b;
		o.end(&a);
		s.at(&b, 0);
		return sugkrish_color(a,b);
	}
	int oura_stoiva(List* o, List* s){                          //sunartish gia na eksagei apo thn oura k na eisagei se stoiva k na epistrefei to id tou IceSkater
		IceSkater a;
		o->end(&a);
		o->popAt(o->size() - 1);
		s->pushFront(a);
		return a.get_id();
	}
	void eksagwgh_iceskater(List* s){                         // sunarthsh gia thn telikh eksagwgh twn IceSkater
		IceSkater i;
		s->at(&i, 0);
		s->popAt(0);
		i.perform();
		i.finale(mhkos);
	}
	int sugkrish_color(IceSkater i, IceSkater j){
		return (i.get_color() == j.get_color());
	}
};



class Scene{
	List MainQueue, SubQueue;
	Lake lake;
public:
	Scene(int l, int n): lake(l){
		int col, col1, id, skill, dist, b = 0, w = 0;
		IceSkater s;
		for(int k = 1; k <= n; k++){
            dist = rand()%l+1;
            id = k;
			col = rand()%2;                   // 0 = black, 1 = white
			skill = rand()%2;                 // 0 = jump, 1 = spin
			if(col == 0){
				if(b >= n/2) col = 1;         // elegxos gia to an ta maura einai parapano apo ta misa
				b++;
			}
			else {
				if(w >= n/2) col = 0;          // elegxos gia ta leuka
				w++;
				}
			if(k == 1) col1 = col;
			if(n%2 == 1 && k == n) col = col1;      // elegxos gia na mpei kai to teleutaio xrwma sthn MainQueue se periptwsh perittou n
			IceSkater i(dist, id, col, skill);
			if(MainQueue.size()>0){
				MainQueue.at(&s, 0);
			}
			if (sugkrish_color(i, s)!= 1){
				MainQueue.pushFront(i);
				if(SubQueue.size()>0){
					SubQueue.end(&s);
					if (sugkrish_color(i, s)!= 1 && SubQueue.size() > 0){
						SubQueue.popAt(SubQueue.size() - 1);
						MainQueue.pushFront(s);
				}
			}
			}
			else{
				SubQueue.pushFront(i);
			}
		}
		lake.gemisma_stoives(MainQueue);
		lake.final();
		cout<<"Scene was just created!"<<endl<<endl;
	}
	~Scene(){
		cout<<"Scene is about to be destroyed"<<endl<<endl;
	}
	int sugkrish_color(IceSkater i, IceSkater j){
		return (i.get_color() == j.get_color());
	}
};



int main(int argc,char*argv[]){
	int L, N;
	L=atoi(argv[1]);
	N=atoi(argv[2]);
    srand(time(NULL));
	Scene scene(L,N);
	}
