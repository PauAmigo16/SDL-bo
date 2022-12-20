#include "GameEngine.h"

int main(int argc, char* args[]) {
	GameEngine game(448,480);
	game.Init();
	game.Run();
	game.Quit();
	return 0;
}




