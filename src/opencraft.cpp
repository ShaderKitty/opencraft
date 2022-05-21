#include "opencraft.h"

#include <geodesuka/engine.h>

#include <iostream>

opencraft::opencraft(geodesuka::engine* aEngine, int argc, char* argv[]) : geodesuka::core::app(aEngine, argc, argv) {

	// Get GPU
	size_t DeviceCount = 0;
	device** Device = Engine->get_device_list(&DeviceCount);

	// Search for device that is discrete gpu.
	for (size_t i = 0; i < DeviceCount; i++) {
		if (Device[i]->get_properties().deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			Context = new context(Engine, Device[i], 0, NULL, system_window::RequiredContextExtension.size(), (const char**)system_window::RequiredContextExtension.data());
		}
	}

	system_display* SystemDisplay = this->Engine->get_primary_display();
	window::prop WindowProperty = window::prop();
	system_window::swapchain::prop SwapchainProperty = system_window::swapchain::prop();

	WindowProperty.UserFocused = 0;

	SwapchainProperty.Count				= 3;
	SwapchainProperty.ColorSpace		= system_window::colorspace::SRGB_NONLINEAR;
	SwapchainProperty.Usage				= texture::usage::COLOR_ATTACHMENT;
	SwapchainProperty.CompositeAlpha	= system_window::composite::ALPHA_OPAQUE;
	SwapchainProperty.PresentMode		= system_window::present_mode::FIFO;
	SwapchainProperty.Clipped			= true;

	Window = new system_window(
		this->Engine,
		Context,
		SystemDisplay,
		WindowProperty,
		SwapchainProperty,
		VkFormat::VK_FORMAT_B8G8R8A8_SRGB,
		640,
		480,
		"cock"
	);

	Window1 = new system_window(
		this->Engine,
		Context,
		SystemDisplay,
		WindowProperty,
		SwapchainProperty,
		VkFormat::VK_FORMAT_B8G8R8A8_SRGB,
		640,
		480,
		"cock"
	);

	//Triangle = new triangle(Engine, Context);

}

opencraft::~opencraft() {
	delete Window;
	delete Window2;
}

void opencraft::gameloop() {

	system_display* SystemDisplay = this->Engine->get_primary_display();
	window::prop WindowProperty = window::prop();

	WindowProperty.UserFocused = 0;

	system_window::swapchain::prop SwapchainProperty = system_window::swapchain::prop();
	SwapchainProperty.Count				= 3;
	SwapchainProperty.ColorSpace		= system_window::colorspace::SRGB_NONLINEAR;
	SwapchainProperty.Usage				= texture::usage::COLOR_ATTACHMENT;
	SwapchainProperty.CompositeAlpha	= system_window::composite::ALPHA_OPAQUE;
	SwapchainProperty.PresentMode		= system_window::present_mode::FIFO;
	SwapchainProperty.Clipped			= true;

	Window2 = new system_window(
		this->Engine,
		Context,
		SystemDisplay,
		WindowProperty,
		SwapchainProperty,
		VkFormat::VK_FORMAT_B8G8R8A8_SRGB,
		640,
		480,
		"cock"
	);

	while (!ExitApp.load()) {

		core::logic::waitfor(10);
		ExitApp.store(true);
	}

	delete Window1;

}
