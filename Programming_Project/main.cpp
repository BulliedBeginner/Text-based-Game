#include "Game.h"
#include "StoryLine.h"

int main() {
	Game game;

	Beginning();
	game.initialise();
	AfterInitialise();

	while (!game._hasEnd) {
		game.run();
	}
}
