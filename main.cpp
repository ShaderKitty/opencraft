#include <iostream>

#include <geodesuka/engine.h>

#include <opencraft.h>

// Using entry point for app.
int main(int argc, char* argv[]) {
	geodesuka::engine Engine(argc, argv);
	if (Engine.is_ready()) {
		opencraft OpenCraft(&Engine, argc, argv);
		Engine.run(&OpenCraft);
	}
	return 0;
}