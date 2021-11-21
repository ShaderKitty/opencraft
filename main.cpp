#include <iostream>

#include <geodesuka/engine.h>

#include <opencraft.h>

int main(int argc, char* argv[]) {
	geodesuka::engine Engine(argc, argv);
	if (Engine.is_ready()) {
		opencraft OpenCraft(&Engine, argc, argv);
		Engine.run(&OpenCraft);
	}
	return 0;
}