#include "opencraft.h"

#include <geodesuka/engine.h>

using namespace geodesuka::core;
using namespace gcl;
using namespace object;

#include <iostream>

opencraft::opencraft(geodesuka::engine* aEngine, int argc, char* argv[]) : geodesuka::core::app(aEngine, argc, argv) {

	size_t DeviceCount = 0;
	device** Device = Engine->get_device_list(&DeviceCount);
	//context* Context2 = nullptr;
	for (size_t i = 0; i < DeviceCount; i++) {
		if (Device[i]->get_properties().deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			this->Context = new context(this->Engine, Device[i], system_window::RequiredExtension.size(), (const char**)system_window::RequiredExtension.data());
		}
	}

	/*
	size_t DeviceCount = 0;
	device** Device = Engine->get_device_list(&DeviceCount);
	context* Context = nullptr;
	//context* Context2 = nullptr;
	for (size_t i = 0; i < DeviceCount; i++) {
		if (Device[i]->get_properties().deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			// Provide required extensions to allow context to create system windows.
			//std::cout << "Transfer Index: " << Device[i]->qfi(device::qfs::PRESENT);
			Context = new context(this->Engine, Device[i], system_window::RequiredExtension.size(), (const char**)system_window::RequiredExtension.data());
			//Context2 = new context(&Engine, Device[i], system_window::RequiredExtension.size(), (const char**)system_window::RequiredExtension.data());
		}
	}

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

	system_window* SystemWindow1 = new system_window(
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

	system_window* SystemWindow2 = new system_window(
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

	system_window* SystemWindow3 = new system_window(
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

	*/
}

opencraft::~opencraft() {

}

void opencraft::run() {
	std::cout << "App thread running" << std::endl;
	while(true){}
}
