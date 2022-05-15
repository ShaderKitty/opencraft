#include <geodesuka/engine.h>

#include <opencraft.h>

// Using entry point for app.
int main(int aCmdArgCount, char* aCmdArgList[]) {

	// Instance Layers & Extensions.
	std::vector<const char*> Layer = {
		"VK_LAYER_KHRONOS_validation"
	};

	std::vector<const char*> Ext = {

	};

	geodesuka::engine Engine(aCmdArgCount, (const char**)aCmdArgList, Layer.size(), Layer.data(), 0, NULL);
	//geodesuka::engine Engine(0, NULL, 0, NULL, 0, NULL);
	if (Engine.is_ready()) {
		opencraft OpenCraft(&Engine, aCmdArgCount, aCmdArgList);
		Engine.run(&OpenCraft);
	}
	return 0;
}