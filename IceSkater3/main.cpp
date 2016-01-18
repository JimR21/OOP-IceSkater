#include <iostream>
#include <cstdlib>
#include <time.h>
#include "IceSkater.h"
#include "Lake.h"


using namespace std;

int main(int argc,char*argv[])
{
    int M = atoi(argv[1]);
    int L = atoi(argv[2]);
    int N = atoi(argv[3]);
    int T = atoi(argv[4]);
    srand(time(NULL));
    Lake l(M,L,N,T);


}
