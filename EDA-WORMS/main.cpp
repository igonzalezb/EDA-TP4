#include <iostream>
#include <cstdint>
#include "Position.h"
#include "Graphics.h"


int main(int argc, char* argv[])
{
	srand(time(NULL));
	Graphics g;
	g.GraphicsMain();
	//FALTA DESINSTALAR ALLEGRO Y DESTRUIR TODO
	return 0;
}