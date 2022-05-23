#include <geodesuka/engine.h>

#include <opencraft.h>

// Using entry point for app.
int main(int aCmdArgCount, char* aCmdArgList[]) {

	// Instance Layers & Extensions.
	std::vector<const char*> Layer = {
		"VK_LAYER_KHRONOS_validation"
	};

	std::vector<const char*> Ext = {
		VK_KHR_DISPLAY_EXTENSION_NAME
	};

	//geodesuka::engine Engine(aCmdArgCount, (const char**)aCmdArgList, Layer.size(), Layer.data(), Ext.size(), Ext.data());
	geodesuka::engine Engine(aCmdArgCount, (const char**)aCmdArgList, Layer.size(), Layer.data(), 0, NULL);
	if (Engine.is_ready()) {
		opencraft OpenCraft(&Engine, aCmdArgCount, aCmdArgList);
		Engine.run(&OpenCraft);
	}
	return 0;
}