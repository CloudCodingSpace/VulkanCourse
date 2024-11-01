#pragma once

#include <vulkan/vulkan.h>

#include <Window/Window.h>
#include <limits>
#include <vector>

struct VulkanQueueFamilyProps
{
	uint32_t pQueueIdx = std::numeric_limits<uint32_t>::max();
	uint32_t tQueueIdx = std::numeric_limits<uint32_t>::max();
	uint32_t gQueueIdx = std::numeric_limits<uint32_t>::max();

	inline bool IsFull() {
		return pQueueIdx != std::numeric_limits<uint32_t>::max() && gQueueIdx != std::numeric_limits<uint32_t>::max() && tQueueIdx != std::numeric_limits<uint32_t>::max();
	}
};

struct VulkanScCaps
{
	VkSurfaceCapabilitiesKHR caps;
	std::vector<VkPresentModeKHR> modes;
	std::vector<VkSurfaceFormatKHR> formats;
};


struct VkCtx
{
	VkInstance instance = VK_NULL_HANDLE;
	VkSurfaceKHR surface = VK_NULL_HANDLE;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VulkanQueueFamilyProps queueProps{};
	VkQueue gQueue = VK_NULL_HANDLE;
	VkQueue pQueue = VK_NULL_HANDLE;
	VkQueue tQueue = VK_NULL_HANDLE;
	VkDevice device = VK_NULL_HANDLE;
	VulkanScCaps scCaps{};
	VkExtent2D scExtent;
	VkPresentModeKHR scMode;
	VkSurfaceFormatKHR scFormat;
	VkSwapchainKHR swapchain = VK_NULL_HANDLE;

#if defined(_DEBUG) || !defined(NDEBUG)
	VkDebugUtilsMessengerEXT debugger;
#endif
};

class VkCtxHandler
{
public:
	static void InitCtx(Window& window);
	static void DestroyCtx();

	static void SetCrntCtx(VkCtx& ctx);
	static VkCtx* GetCrntCtx();
};