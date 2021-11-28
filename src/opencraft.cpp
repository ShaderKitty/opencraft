#include "opencraft.h"

#include <geodesuka/engine.h>

#include <iostream>

opencraft::opencraft(geodesuka::engine* aEngine, int argc, char* argv[]) : geodesuka::core::app(aEngine, argc, argv) {

	int DeviceCount = 0;
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
	SwapchainProperty.ColorSpace		= swapchain::colorspace::SRGB_NONLINEAR;
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

	Triangle = new triangle(Engine, Context);

}

opencraft::~opencraft() {
	delete Window;
	delete Window2;
}

void opencraft::gameloop() {

	/*
	
	// Binds a list of descriptor sets to match pipeline layout.
	vkCmdBindDescriptorSets()

	*/
	
	//VkResult Result = VkResult::VK_SUCCESS;
	//VkDescriptorPoolCreateInfo DPCI{};
	//VkDescriptorPool DP;

	//VkDescriptorPoolSize DPS[3];

	//VkDescriptorSetLayoutBinding DSLB[3][3];

	//DPS[0].type				= VkDescriptorType::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
	//DPS[0].descriptorCount	= 3;

	//DPS[1].type				= VkDescriptorType::VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;
	//DPS[1].descriptorCount	= 1;

	//DPS[2].type				= VkDescriptorType::VK_DESCRIPTOR_TYPE_SAMPLER;
	//DPS[2].descriptorCount	= 2;

	//DPCI.sType				= VkStructureType::VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	//DPCI.pNext				= NULL;
	//DPCI.flags				= 0;
	//DPCI.maxSets			= 4;
	//DPCI.poolSizeCount		= 3;
	//DPCI.pPoolSizes			= DPS;

	//Result = vkCreateDescriptorPool(this->Context->handle(), &DPCI, NULL, &DP);

	//VkDescriptorSetAllocateInfo DSAI{};

	//DSAI.sType					= VkStructureType::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	//DSAI.pNext					= NULL;
	//DSAI.descriptorPool			= DP;
	//DSAI.descriptorSetCount		= 3;
	//DSAI.pSetLayouts			;

	//VkAttachmentDescription Att = this->Window->Texture[0].description(
	//	texture::loadop::LOAD, texture::storeop::STORE,
	//	texture::loadop::DONT_CARE, texture::storeop::DONT_CARE,
	//	texture::layout::UNDEFINED, texture::layout::COLOR_ATTACHMENT
	//);

	system_display* SystemDisplay = this->Engine->get_primary_display();
	window::prop WindowProperty = window::prop();
	swapchain::prop SwapchainProperty = swapchain::prop();

	WindowProperty.UserFocused = GLFW_FALSE;


	SwapchainProperty.Count				= 3;
	SwapchainProperty.ColorSpace		= swapchain::colorspace::SRGB_NONLINEAR;
	SwapchainProperty.Usage				= texture::usage::COLOR_ATTACHMENT;
	SwapchainProperty.CompositeAlpha	= swapchain::composite::ALPHA_OPAQUE;
	SwapchainProperty.PresentMode		= swapchain::mode::FIFO;
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
