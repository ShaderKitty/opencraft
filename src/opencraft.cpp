#include "opencraft.h"

#include <geodesuka/engine.h>

#include <iostream>

opencraft::opencraft(geodesuka::engine* aEngine, int argc, char* argv[]) : geodesuka::core::app(aEngine, argc, argv) {

	size_t DeviceCount = 0;
	device** Device = Engine->get_device_list(&DeviceCount);

	// Search for device that is discrete gpu.
	for (size_t i = 0; i < DeviceCount; i++) {
		if (Device[i]->get_properties().deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			Context = new context(Engine, Device[i], system_window::RequiredExtension.size(), (const char**)system_window::RequiredExtension.data());
		}
	}

	system_display* SystemDisplay = this->Engine->get_primary_display();
	window::prop WindowProperty = window::prop();
	swapchain::prop SwapchainProperty = swapchain::prop();

	WindowProperty.UserFocused = GLFW_FALSE;


	SwapchainProperty.Count				= 3;
	SwapchainProperty.ColorSpace		= VkColorSpaceKHR::VK_COLORSPACE_SRGB_NONLINEAR_KHR;
	SwapchainProperty.Usage				= texture::usage::COLOR_ATTACHMENT;
	SwapchainProperty.CompositeAlpha	= swapchain::composite::ALPHA_OPAQUE;
	SwapchainProperty.PresentMode		= swapchain::mode::FIFO;
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

}

opencraft::~opencraft() {

}

void opencraft::run() {

	system_display* SystemDisplay = this->Engine->get_primary_display();
	window::prop WindowProperty = window::prop();
	swapchain::prop SwapchainProperty = swapchain::prop();

	WindowProperty.UserFocused = GLFW_FALSE;


	SwapchainProperty.Count = 3;
	SwapchainProperty.ColorSpace = VkColorSpaceKHR::VK_COLORSPACE_SRGB_NONLINEAR_KHR;
	SwapchainProperty.Usage = texture::usage::COLOR_ATTACHMENT;
	SwapchainProperty.CompositeAlpha = swapchain::composite::ALPHA_OPAQUE;
	SwapchainProperty.PresentMode = swapchain::mode::FIFO;
	SwapchainProperty.Clipped = true;

	system_window *Window2 = new system_window(
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

	// App loop
	while (!Engine->Shutdown.load()) {

		core::logic::waitfor(3);
		Engine->Shutdown.store(true);
	}

	delete Window2;


}
