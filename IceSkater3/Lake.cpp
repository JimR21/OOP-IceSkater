#include "Lake.h"
#include "IceSkater.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;


Lake::Lake(int mm, int ll, int nn, int tt)
{
        m = mm;
		l = ll;
		n = nn;
		t = tt;
        plegma = new IceSkater**[m+1];
		for(int i = 0; i <= m; i++){
			plegma[i] = new IceSkater*[l+1];
	 	}
	 	for(int k = 0; k <= m; k++){
			for (int j = 0; j <= l; j++){
				plegma[k][j] =  NULL;
			}
		}
		populate();
        show();
    for(int u = 0; u<t; u++)
    {
        moving(u);
        check();
        show();
    }
}


Lake::~Lake()
{
        for(int i=0;i<=m;i++){
			delete[] plegma[i];
		}
		delete[] plegma;
}


void Lake::show()
{
    for(int i = 0; i <= m; i++){
			for(int j = 0; j<= l; j++){
				if(j == 0){
					if(plegma[i][j] != NULL){
      					plegma[i][j]->print_type();
					}
					else
					    cout<<"+";
				}
				else{
                    if(plegma[i][j] != NULL){
					    cout<<"-----";
         				plegma[i][j]->print_type();
					}
					else{
					    cout<<"-----"<<"+";
					}
				}
			}
			cout<<endl;
			if(i<m){
			for(int k = 0; k <= l; k++){
				if(k == 0){
					cout<<"|";
				}
				else{
					cout<<"     |";
				}
			}
				cout<<endl;
			}
			}
			cout<<endl<<endl;
}

void Lake::populate()
{
    int posa, posb, lim, vel;
    for(int i = 0; i < n; i++)
    {
        int k = rand()%4;
        int lt = rand()%t+1;
        if(k == 0)
        {
            do{
                    pos_Amateur(m,l,posa,posb);
                    if(plegma[posa][posb] == NULL)
                    {
                        plegma[posa][posb] = new Kid(i, posa, posb, lt);
                        break;
                    }
            }while(1==1);
        }
        else if(k == 1)
        {
            do{
                    pos_Amateur(m,l,posa,posb);
                    if(plegma[posa][posb] == NULL)
                    {
                        plegma[posa][posb] = new Amateur(i, posa, posb, lt);
                        break;
                    }
            }while(1==1);
        }
        else if(k == 2)
        {
            do{
                    pos_Normal(m,l,posa,posb, lim, vel);
                    if(plegma[posa][posb] == NULL)
                    {
                        plegma[posa][posb] = new Normal(i, posa, posb, lim, vel, lt);
                        break;
                    }
            }while(1==1);
        }
        else if(k == 3)
        {
            do{
                    pos_Pro(m,l,posa,posb, vel);
                    if(plegma[posa][posb] == NULL)
                    {
                        plegma[posa][posb] = new Pro(i, posa, posb, vel, lt);
                        break;
                    }
            }while(1==1);
        }
    }
}


void Lake::pos_Normal(int m, int l, int &pos1, int &pos2, int &lim, int &vel)
{
    vel = rand()%((m<l)?l:m)+1;
    m++;
    l++;
    float x = (float)m*3/10, y = (float)l*3/10;
    if(x<y) y = x;
    else x = y;
    // stroggulopoihseis
    if(m < 7)
        x = 1;
	else
        x = (int)x;
    if(y < 7)
        y = 1;
	else
        y = (int)y;
    // tuxaies theseis
    pos1 = rand()% m+1;
    if (pos1 <= (int)x || pos1 > m - (int)x)
    {
        pos2 = rand()%l+1;
        if(pos1 <= (int)x)
        {
            if(pos2<pos1 || l+1 - pos2<pos1)
            {
                if(pos2<l+1-pos2)
                    lim = pos2;
                else
                    lim = l+1-pos2;
            }
            else
            {
                lim = pos1;
            }
        }
        else
        {
            if(pos2<m+1-pos1 || l+1-pos2<m+1-pos1)
            {
                if(pos2<l+1-pos2)
                    lim = pos2;
                else
                    lim = l+1-pos2;
            }
            else
            {
                lim = m + 1 - pos1;
            }
        }
    }
    else{
        pos2 = rand()%2;
        if(pos2 == 0)
        {
            pos2 = rand()%(int)y+1;
            lim = pos2;
        }
        else
        {
            pos2 = rand()%(int)y + (l + 1 - (int)y);
            lim = l + 1 - pos2;
        }
    }
    pos1--;
    pos2--;
}

void Lake::pos_Amateur(int m, int l, int &pos1, int &pos2)
{
    m++;
    l++;
    float x = (float)m/10, y = (float)l/10;
    // stroggulopoihseis
    if(x - (int)x>=0.5 || m <= 4)
        x = (int)x + 1;
	else
        x = (int)x;
    if(y - (int)y>=0.5 || l <= 4)
        y = (int)y + 1;
	else
        y = (int)y;

    // tuxaies theseis
    pos1 = rand()% m+1;
    if (pos1 <= (int)x || pos1 > m - (int)x)
        pos2 = rand()%l+1;
    else{
        pos2 = rand()%2;
        if(pos2 == 0)
            pos2 = rand()%(int)y+1;
        else
            pos2 = rand()% (int)y + (l + 1 - (int)y);
    }
    pos1--;
    pos2--;
}

void Lake::pos_Pro(int m, int l, int &pos1, int &pos2, int &vel)
{
    vel = rand()%((m<l)?l:m)+1;
    m++;
    l++;
    pos1 = rand()%m + 1;
    pos2 = rand()%l + 1;
    pos1--;
    pos2--;
}

void Lake::collision(int j, int i, int &posa, int &posb)
{
    plegma[posa][posb]->crash();
    plegma[j][i]->crash();
    plegma[j][i]->crash_pos(m,l,posa,posb);
    if(plegma[posa][posb] != NULL)
    {
        collision(j,i,posa,posb);
    }
}

void Lake::moving(int u)
{
    int posa, posb;
    for(int j = 0; j <= m; j++)
		{
            for(int i = 0; i <= l; i++)
            {
                if(plegma[j][i] != NULL && plegma[j][i]->get_totalmove() == u)
                {
                        plegma[j][i]->moves(m,l);
                        plegma[j][i]->get_pos(posa,posb);
                        if(plegma[posa][posb] != NULL)
                        {
                            if(plegma[posa][posb]->get_totalmove() == t)
                                plegma[posa][posb]->add_move();
                            collision(j, i, posa, posb);
                        }
                        plegma[posa][posb] = plegma[j][i];
                        plegma[j][i] = NULL;
                }
            }
    }
}

void Lake::check()
{
    for(int j = 0; j <= m; j++)
		{
            for(int i = 0; i <= l; i++)
            {
                if(plegma[j][i] != NULL)
                {
                    plegma[j][i]->add_time();
                    if(plegma[j][i]->check_time(t) == 1 || plegma[j][i]->check_maxfall() == 1)
                    {
                        plegma[j][i]->leave();
                        plegma[j][i] = NULL;
                    }
                }
            }
		}
}
