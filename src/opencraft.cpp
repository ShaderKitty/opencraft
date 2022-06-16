#include "opencraft.h"

#include <geodesuka/engine.h>

#include <iostream>

opencraft::opencraft(geodesuka::engine* aEngine, int aCmdArgCount, char* aCmdArgList[]) : geodesuka::core::app(aEngine) {

	this->TimeStep = 0.01;

	// Get GPU
	size_t DeviceCount = 0;
	device** Device = Engine->get_device_list(&DeviceCount);

	// Search for device that is discrete gpu.
	for (size_t i = 0; i < DeviceCount; i++) {
		if (Device[i]->get_properties().deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			Context = new context(Engine, Device[i], 0, NULL, system_window::RequiredContextExtension.size(), (const char**)system_window::RequiredContextExtension.data());
		}
	}

	//Example = new builtin::stage::example(Engine, Context);

}

opencraft::~opencraft() {
	delete Example;

}

void opencraft::run() {

	while (!ExitApp.load()) {

		core::logic::waitfor(5);
		ExitApp.store(true);
	}

}
