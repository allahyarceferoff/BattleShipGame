#include <iostream>
#include"Start.h"
using namespace std;



void Run() {
	bool b = PlaySound(TEXT("Modern Warships Menu Theme Version 1 [MV] [Nightcore].wav"), NULL, SND_ASYNC);
	Start();
	system("pause");
}


void main() {
	Run();
}



