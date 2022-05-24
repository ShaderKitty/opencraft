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

	Display = Engine->get_primary_display();

	Property.Window.Resizable			= true;
	Property.Window.Decorated			= true;
	Property.Window.UserFocused			= true;
	Property.Window.AutoMinimize		= false;
	Property.Window.Floating			= false;
	Property.Window.Maximized			= false;
	Property.Window.Minimized			= false;
	Property.Window.Visible				= true;
	Property.Window.ScaleToMonitor		= false;
	Property.Window.CenterCursor		= false;
	Property.Window.FocusOnShow			= false;

	Property.Swapchain.FrameCount		= 3;
	Property.Swapchain.FrameRate		= 30.0;
	Property.Swapchain.ColorSpace		= system_window::colorspace::SRGB_NONLINEAR;
	Property.Swapchain.Usage			= image::usage::COLOR_ATTACHMENT;
	Property.Swapchain.CompositeAlpha	= system_window::composite::ALPHA_OPAQUE;
	Property.Swapchain.PresentMode		= system_window::present_mode::FIFO;
	Property.Swapchain.Clipped			= true;
	Property.PixelFormat				= VkFormat::VK_FORMAT_B8G8R8A8_SRGB;
	Property.Position					= float3(0, 0, 0);
	Property.Size						= float2(0.3, 0.3);
	Property.Title						= "cock1";

	Window1 = new system_window(Engine, Context, Display, Property);
	core::logic::waitfor(5);
	delete Window1;

	Property.Title = "cock2";

	Window2 = new system_window(Engine, Context, Display, Property);

}

opencraft::~opencraft() {
	delete Window4;
}

void opencraft::gameloop() {

	core::logic::waitfor(5);

	delete Window2;

	Property.Title = "cock3";
	Window3 = new system_window(Engine, Context, Display, Property);
	Property.Title = "cock4";
	Window4 = new system_window(Engine, Context, Display, Property);

	while (!ExitApp.load()) {

		core::logic::waitfor(5);
		ExitApp.store(true);
	}

	delete Window3;

	core::logic::waitfor(5);
}
