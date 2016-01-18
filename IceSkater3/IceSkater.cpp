#include "IceSkater.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

IceSkater::IceSkater()
{
    id = pos1 = pos2 = vel = totalmoves = -1;
}


int IceSkater::get_id()
{
    return id;
}

int IceSkater::get_totalmove()
{
    return totalmoves;
}

void IceSkater::moves(int m, int l){}

void IceSkater::crash(){}

void IceSkater::print_type(){}

int IceSkater::check_maxfall()
{
    return (maxfall == 3);
}

void IceSkater::get_pos(int &posa, int &posb)
{
    posa = pos1;
    posb = pos2;
}

void IceSkater::add_move()
{
    totalmoves++;
}

void IceSkater::add_time()
{
    ltime++;
}

int IceSkater::check_time(int t)
{
    return t == ltime;
}


//--------------------------------------------------


Amateur::Amateur(int ido, int posa, int posb, int lt)
{
    totalmoves = 0;
    id = ido;
    vel = 1;
    pos1 = posa;
    pos2 = posb;
    ltime = lt;
    maxfall = 0;
}

void Amateur::get_pos(int &posa, int &posb)
{
    posa = pos1;
    posb = pos2;
}

void Amateur::moves(int m, int l)
{
    int posa,posb, r;
    m++;
    l++;
    totalmoves++;
    pos1++;
    pos2++;
    posa = pos1;
    posb = pos2;
    float x = (float)m*1/10, y = (float)l*1/10;
    // stroggulopoihseis
    if(x - (int)x>=0.5 || m <= 4)
        x = (int)x + 1;
	else
        x = (int)x;
    if(y - (int)y>=0.5 || l <= 4)
        y = (int)y + 1;
	else
        y = (int)y;
    if(pos1 <= x && pos2 <= y)
    {
        r = rand()%4+2;
        if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posa<=0 || posb<=0)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x && pos2 > l-y)
    {
        r = rand()%4+4;
        if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posb++;
            posa++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posb>l)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x)
    {
        r = rand()%5+3;
        if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posa++;
            posb++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posa >x)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 <= y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb--;
        }
        else if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }

        if(posa>m || posb<= 0)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 > l-y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb++;
        }
        else if(r == 1)
        {
            posa++;
        }
        else if(r == 2)
        {
            posa++;
            posb--;
        }
        else if(r == 3)
        {
            posb--;
        }
        if(posa>m ||posb>l)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x)
    {
        r = rand()%5;
        if(r == 0)
        {
            posa++;
        }
        else if(r == 1)
        {
            posa++;
            posb--;
        }
        else if(r == 2)
        {
            posb--;
        }
        else if(r == 3)
        {
            posa--;
            posb--;
        }
        else if(r == 4)
        {
            posa--;
        }
        if(posa>m || posa<=m-x)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 <= y)
    {
        r = rand()%5+1;
        if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posb<=0 || posb>y)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 > l-y)
    {
        r = rand()%5;
        if(r == 0)
        {
            posb++;
        }
        else if(r == 1)
        {
            posa++;
            posb++;
        }
        else if(r == 2)
        {
            posa++;
        }
        else if(r == 3)
        {
            posa++;
            posb--;
        }
        else if(r == 4)
        {
            posb--;
        }
        if(posb>l || posb<=l-y)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    pos1--;
    pos2--;
}

void Amateur::print_type()
{
    cout<<"A";
}

void Amateur::crash()
{
    cout<<"I just fell but nice to meet you!"<<endl;
}

void Amateur::crash_pos(int m, int l, int &posa, int &posb)
{
    int r;
    m++;
    l++;
    posa++;
    posb++;
    pos1++;
    pos2++;
    float x = (float)m*1/10, y = (float)l*1/10;
    // stroggulopoihseis
    if(x - (int)x>=0.5 || m <= 4)
        x = (int)x + 1;
	else
        x = (int)x;
    if(y - (int)y>=0.5 || l <= 4)
        y = (int)y + 1;
	else
        y = (int)y;
    if(pos1 <= x && pos2 <= y)
    {
        r = rand()%4+2;
        if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posa<=0 || posb<=0)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x && pos2 > l-y)
    {
        r = rand()%4+4;
        if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posb++;
            posa++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posb>l)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x)
    {
        r = rand()%5+3;
        if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posa++;
            posb++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posa >x)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 <= y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb--;
        }
        else if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }

        if(posa>m || posb<= 0)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 > l-y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb++;
        }
        else if(r == 1)
        {
            posa++;
        }
        else if(r == 2)
        {
            posa++;
            posb--;
        }
        else if(r == 3)
        {
            posb--;
        }
        if(posa>m ||posb>l)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x)
    {
        r = rand()%5;
        if(r == 0)
        {
            posa++;
        }
        else if(r == 1)
        {
            posa++;
            posb--;
        }
        else if(r == 2)
        {
            posb--;
        }
        else if(r == 3)
        {
            posa--;
            posb--;
        }
        else if(r == 4)
        {
            posa--;
        }
        if(posa>m || posa<=m-x)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 <= y)
    {
        r = rand()%5+1;
        if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posb<=0 || posb>y)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 > l-y)
    {
        r = rand()%5;
        if(r == 0)
        {
            posb++;
        }
        else if(r == 1)
        {
            posa++;
            posb++;
        }
        else if(r == 2)
        {
            posa++;
        }
        else if(r == 3)
        {
            posa++;
            posb--;
        }
        else if(r == 4)
        {
            posb--;
        }
        if(posb>l || posb<=l-y)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    pos1--;
    pos2--;
    posa = pos1;
    posb = pos2;
}

void Amateur::leave()
{
    cout<<"Bye bye..."<<endl;
}


//-----------------------------------------------------------


Kid::Kid(int ido, int posa, int posb, int lt)
{
    totalmoves = 0;
    maxfall = 0;
    id = ido;
    vel = 1;
    pos1 = posa;
    pos2 = posb;
    ltime = lt;
    maxfall = 0;
}

void Kid::print_type()
{
    cout<<"K";
}


void Kid::get_pos(int &posa, int &posb)
{
    posa = pos1;
    posb = pos2;
}


void Kid::moves(int m, int l)
{
    int posa,posb, r;
    m++;
    l++;
    totalmoves++;
    pos1++;
    pos2++;
    posa = pos1;
    posb = pos2;
    float x = (float)m*1/10, y = (float)l*1/10;
    // stroggulopoihseis
    if(x - (int)x>=0.5 || m <= 4)
        x = (int)x + 1;
	else
        x = (int)x;
    if(y - (int)y>=0.5 || l <= 4)
        y = (int)y + 1;
	else
        y = (int)y;
    if(pos1 <= x && pos2 <= y)
    {
        r = rand()%4+2;
        if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posa<=0 || posb<=0)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x && pos2 > l-y)
    {
        r = rand()%4+4;
        if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posb++;
            posa++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posb>l)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x)
    {
        r = rand()%5+3;
        if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posa++;
            posb++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posa >x)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 <= y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb--;
        }
        else if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }

        if(posa>m || posb<= 0)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 > l-y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb++;
        }
        else if(r == 1)
        {
            posa++;
        }
        else if(r == 2)
        {
            posa++;
            posb--;
        }
        else if(r == 3)
        {
            posb--;
        }
        if(posa>m ||posb>l)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x)
    {
        r = rand()%5;
        if(r == 0)
        {
            posa++;
        }
        else if(r == 1)
        {
            posa++;
            posb--;
        }
        else if(r == 2)
        {
            posb--;
        }
        else if(r == 3)
        {
            posa--;
            posb--;
        }
        else if(r == 4)
        {
            posa--;
        }
        if(posa>m || posa<=m-x)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 <= y)
    {
        r = rand()%5+1;
        if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posb<=0 || posb>y)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 > l-y)
    {
        r = rand()%5;
        if(r == 0)
        {
            posb++;
        }
        else if(r == 1)
        {
            posa++;
            posb++;
        }
        else if(r == 2)
        {
            posa++;
        }
        else if(r == 3)
        {
            posa++;
            posb--;
        }
        else if(r == 4)
        {
            posb--;
        }
        if(posb>l || posb<=l-y)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    pos1--;
    pos2--;
}

void Kid::crash()
{
    maxfall++;
    cout<<"Crying..."<<endl;
}

void Kid::crash_pos(int m, int l, int &posa, int &posb)
{
    int r;
    m++;
    l++;
    posa++;
    posb++;
    pos1++;
    pos2++;
    float x = (float)m*1/10, y = (float)l*1/10;
    // stroggulopoihseis
    if(x - (int)x>=0.5 || m <= 4)
        x = (int)x + 1;
	else
        x = (int)x;
    if(y - (int)y>=0.5 || l <= 4)
        y = (int)y + 1;
	else
        y = (int)y;
    if(pos1 <= x && pos2 <= y)
    {
        r = rand()%4+2;
        if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posa<=0 || posb<=0)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x && pos2 > l-y)
    {
        r = rand()%4+4;
        if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posb++;
            posa++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posb>l)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x)
    {
        r = rand()%5+3;
        if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posa++;
            posb++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posa >x)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 <= y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb--;
        }
        else if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }

        if(posa>m || posb<= 0)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 > l-y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb++;
        }
        else if(r == 1)
        {
            posa++;
        }
        else if(r == 2)
        {
            posa++;
            posb--;
        }
        else if(r == 3)
        {
            posb--;
        }
        if(posa>m ||posb>l)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x)
    {
        r = rand()%5;
        if(r == 0)
        {
            posa++;
        }
        else if(r == 1)
        {
            posa++;
            posb--;
        }
        else if(r == 2)
        {
            posb--;
        }
        else if(r == 3)
        {
            posa--;
            posb--;
        }
        else if(r == 4)
        {
            posa--;
        }
        if(posa>m || posa<=m-x)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 <= y)
    {
        r = rand()%5+1;
        if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posb<=0 || posb>y)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 > l-y)
    {
        r = rand()%5;
        if(r == 0)
        {
            posb++;
        }
        else if(r == 1)
        {
            posa++;
            posb++;
        }
        else if(r == 2)
        {
            posa++;
        }
        else if(r == 3)
        {
            posa++;
            posb--;
        }
        else if(r == 4)
        {
            posb--;
        }
        if(posb>l || posb<=l-y)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    pos1--;
    pos2--;
    posa = pos1;
    posb = pos2;
}


void Kid::leave()
{
    cout<<"I want to stay longer..."<<endl;
}

//---------------------------------------------------------


Normal::Normal(int ido, int posa, int posb, int lim1,int vel1, int lt)
{
    pos1 = posa;
    pos2 = posb;
    lim = lim1;
    totalmoves = 0;
    id = ido;
    vel = vel1;
    ltime = lt;
    maxfall = 0;
}

void Normal::print_type()
{
    cout<<"N";
}

void Normal::get_pos(int &posa, int &posb)
{
    posa = pos1;
    posb = pos2;
}

void Normal::moves(int m, int l)
{
    m++;
    l++;
    totalmoves++;
    pos1++;
    pos2++;
    float x = (float)m*3/10, y = (float)l*3/10;
    // stroggulopoihseis
    if(x - (int)x>=0.5 || m <= 4)
        x = (int)x + 1;
	else
        x = (int)x;
    if(y - (int)y>=0.5 || l <= 4)
        y = (int)y + 1;
	else
        y = (int)y;

    if (pos1 == lim && pos2 + lim <= l)
    {
        pos2 = pos2 + vel;
        if(pos2 + lim > l)
            pos2 = l + 1 - lim;
    }
    else if(pos1 == m + 1 - lim && pos2 > lim)
    {
        pos2 = pos2 - vel;
        if(pos2 < lim)
            pos2 = lim;
    }
    else if(pos2 == lim && pos1 > lim)
    {
        pos1 = pos1 - vel;
        if(pos1 < lim)
            pos1 = lim;
    }
    else if(pos2 == l + 1 - lim && pos1 + lim <= m)
    {
        pos1 = pos1 + vel;
        if(pos1 + lim > m)
            pos1 = m + 1 - lim;
    }
    pos1--;
    pos2--;
}

void Normal::crash()
{
    cout<<"I just fell but nice to meet you!"<<endl;
}


void Normal::crash_pos(int m, int l, int &posa, int &posb)
{int r;
    m++;
    l++;
    posa++;
    posb++;
    pos1++;
    pos2++;
    float x = (float)m*3/10, y = (float)l*3/10;
    // stroggulopoihseis
    if(x - (int)x>=0.5 || m <= 4)
        x = (int)x + 1;
	else
        x = (int)x;
    if(y - (int)y>=0.5 || l <= 4)
        y = (int)y + 1;
	else
        y = (int)y;
    if(pos1 <= x && pos2 <= y)
    {
        r = rand()%4+2;
        if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posa<=0 || posb<=0)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x && pos2 > l-y)
    {
        r = rand()%4+4;
        if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posb++;
            posa++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posb>l)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 <= x)
    {
        r = rand()%5+3;
        if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        else if(r == 6)
        {
            posa++;
            posb++;
        }
        else if(r == 7)
        {
            posa++;
        }
        if(posa<=0 || posa >x)
        {
            pos2++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 <= y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb--;
        }
        else if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }

        if(posa>m || posb<= 0)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x && pos2 > l-y)
    {
        r = rand()%4;
        if(r == 0)
        {
            posa++;
            posb++;
        }
        else if(r == 1)
        {
            posa++;
        }
        else if(r == 2)
        {
            posa++;
            posb--;
        }
        else if(r == 3)
        {
            posb--;
        }
        if(posa>m ||posb>l)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos1 > m-x)
    {
        r = rand()%5;
        if(r == 0)
        {
            posa++;
        }
        else if(r == 1)
        {
            posa++;
            posb--;
        }
        else if(r == 2)
        {
            posb--;
        }
        else if(r == 3)
        {
            posa--;
            posb--;
        }
        else if(r == 4)
        {
            posa--;
        }
        if(posa>m || posa<=m-x)
        {
            pos2--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 <= y)
    {
        r = rand()%5+1;
        if(r == 1)
        {
            posb--;
        }
        else if(r == 2)
        {
            posa--;
            posb--;
        }
        else if(r == 3)
        {
            posa--;
        }
        else if(r == 4)
        {
            posa--;
            posb++;
        }
        else if(r == 5)
        {
            posb++;
        }
        if(posb<=0 || posb>y)
        {
            pos1--;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    else if(pos2 > l-y)
    {
        r = rand()%5;
        if(r == 0)
        {
            posb++;
        }
        else if(r == 1)
        {
            posa++;
            posb++;
        }
        else if(r == 2)
        {
            posa++;
        }
        else if(r == 3)
        {
            posa++;
            posb--;
        }
        else if(r == 4)
        {
            posb--;
        }
        if(posb>l || posb<=l-y)
        {
            pos1++;
        }
        else
        {
            pos1 = posa;
            pos2 = posb;
        }
    }
    pos1--;
    pos2--;
    posa = pos1;
    posb = pos2;
}


void Normal::leave()
{
    cout<<"Bye bye..."<<endl;
}

//-----------------------------------------------------------


Pro::Pro(int ido,int posa, int posb, int vel1, int lt)
{
    totalmoves = 0;
    id = ido;
    vel = vel1;
    pos1 = posa;
    pos2 = posb;
    ltime = lt;
    maxfall = 0;
}


void Pro::print_type()
{
    cout<<"P";
}

void Pro::get_pos(int &posa, int &posb)
{
    posa = pos1;
    posb = pos2;
}

void Pro::moves(int m, int l)
{
    int posa, posb, r;
    m++;
    l++;
    totalmoves++;
    pos1++;
    pos2++;
    posa = pos1;
    posb = pos2;
    if(pos1<=m/2 && pos2<=l/2)
    {
        r = rand()%4;
        if(r == 0 && posa != 1)
        {
            posa-=vel;
        }
        else if(r == 1 && posa != 1)
        {
            posa-=vel;
            posb+=vel;
        }
        else if(r == 2)
        {
            posb+=vel;
        }
        else if(r == 3 || posa == 1)
        {
            posa+=vel;
            posb+=vel;
        }
    }
    else if(pos1<=m/2 && pos2 >l/2)
    {
        r = rand()%4;
        if(r == 0 && posb != l)
        {
            posb+=vel;
        }
        else if(r == 1 && posb != l)
        {
            posa+=vel;
            posb+=vel;
        }
        else if(r == 2)
        {
            posa+=vel;
        }
        else if(r == 3 || posb == l)
        {
            posa+=vel;
            posb-=vel;
        }
    }
    else if(pos1>m/2 && pos2<=l/2)
    {
        r = rand()%4;
        if(r == 0 && posb != 1)
        {
            posb-=vel;
        }
        else if(r == 1 && posb != 1)
        {
            posa-=vel;
            posb-=vel;
        }
        else if(r == 2)
        {
            posa-=vel;
        }
        else if(r == 3 || posb == 1)
        {
            posa-=vel;
            posb+=vel;
        }
    }
    else
    {
        r = rand()%4;
        if(r == 0 && posa != m)
        {
            posa+=vel;
        }
        else if(r == 1 && posa != m)
        {
            posa+=vel;
            posb-=vel;
        }
        else if(r == 2)
        {
            posb-=vel;
        }
        else if(r == 3 || posa == m)
        {
            posa-=vel;
            posb-=vel;
        }
    }
    if (posa<=0)
    {
        if (posb>pos2)
        {
            posb = posb + posa - 1;
        }
        else if (posb<pos2)
        {
            posb = posb - posa + 1;
        }
        posa = 1;
    }
    if (posa>m)
    {
        if (posb>pos2)
        {
            posb = posb - (posa - m);
        }
        else if (posb<pos2)
        {
            posb = posb + (posa - m);
        }
        posa = m;
    }
    if (posb<=0)
    {
        if(posa<pos1)
        {
            posa = posa - posb + 1;
        }
        else if(posa>pos1)
        {
            posa = posa + posb - 1;
        }
        posb = 1;
    }
    if (posb>l)
    {
        if(posa<pos1)
        {
            posa = posa + (posb - m);
        }
        else if(posa>pos1)
        {
            posa = posa - (posb - m);
        }
        posb = m;
    }
    pos1 = posa-1;
    pos2 = posb-1;
}

void Pro::crash()
{
    cout<<"I just overcame the situation!"<<endl;
}

void Pro::crash_pos(int m, int l, int &posa, int &posb)
{
    int r;
    m++;
    l++;
    posa++;
    posb++;
    if(posa == m && posb == l)
    {
        r = rand()%3;
        if(r == 0)
        {
            posb--;
        }
        if(r == 1)
        {
            posa--;
            posb--;
        }
        if(r == 2)
        {
            posa--;
        }
    }
    else if(posa == m && posb == 1)
    {
        r = rand()%3;
        if(r == 0)
        {
            posa--;
        }
        if(r == 1)
        {
            posa--;
            posb++;
        }
        if(r == 2)
        {
            posb++;
        }
    }
    else if(posa == m)
    {
        r = rand()%5;
        if(r == 0)
        {
            posb--;
        }
        if(r == 1)
        {
            posa--;
            posb--;
        }
        if(r == 2)
        {
            posa--;
        }
        if(r == 3)
        {
            posa--;
            posb++;
        }
        if(r == 4)
        {
            posb++;
        }
    }
    else if (posa == 1 && posb == l)
    {
        r = rand()%3;
        if(r == 0)
        {
            posb--;
        }
        if(r == 1)
        {
            posa++;
            posb--;
        }
        if(r == 2)
        {
            posa++;
        }
    }
    else if(posa == 1 && posb == 1)
    {
        r = rand()%3;
        if(r == 0)
        {
            posa++;
        }
        if(r == 1)
        {
            posa++;
            posb++;
        }
        if(r == 2)
        {
            posb++;
        }
    }
    else if(posa == 1)
    {
        r = rand()%5;
        if(r == 0)
        {
            posb--;
        }
        if(r == 1)
        {
            posa++;
            posb--;
        }
        if(r == 2)
        {
            posa++;
        }
        if(r == 3)
        {
            posa++;
            posb++;
        }
        if(r == 4)
        {
            posb++;
        }
    }
    else if(posb == 1)
    {
        r = rand()%5;
        if(r == 0)
        {
            posa--;
        }
        if(r == 1)
        {
            posa--;
            posb++;
        }
        if(r == 2)
        {
            posb++;
        }
        if(r == 3)
        {
            posa++;
            posb++;
        }
        if(r == 4)
        {
            posa++;
        }
    }
    else if(posb == l)
        {
            r = rand()%5;
        if(r == 0)
        {
            posa++;
        }
        if(r == 1)
        {
            posa++;
            posb--;
        }
        if(r == 2)
        {
            posb--;
        }
        if(r == 3)
        {
            posa--;
            posb--;
        }
        if(r == 4)
        {
            posa--;
        }
    }
    else
    {
        r = rand()%7;
        if(r == 0)
        {
            posb--;
        }
        if(r == 1)
        {
            posa--;
            posb--;
        }
        if(r == 2)
        {
            posa--;
        }
        if(r == 3)
        {
            posa--;
            posb++;
        }
        if(r == 4)
        {
            posb++;
        }
        if(r == 5)
        {
            posa++;
            posb++;
        }
        if(r == 6)
        {
            posa++;
        }
        if(r == 7)
        {
            posa++;
            posb--;
        }
    }
    posa--;
    posb--;
    pos1 = posa;
    pos2 = posb;
}

void Pro::leave()
{
    cout<<"Bye bye..."<<endl;
}
