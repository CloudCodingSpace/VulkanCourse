#include "VulkanCommand.h"

#include "VkCtx.h"
#include "Logger.h"

VulkanCommandPool VulkanCommandPool::Create(VulkanCmdPoolInputData data)
{
    VulkanCommandPool pool;
    VkCtx* ctx = VkCtxHandler::GetCrntCtx();

    if(data.queueFamily == MAX_UINT32)
        ERROR("Expected a queueFamily index to create the vulkan command pool for!")

    VkCommandPoolCreateInfo info{};
    info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    info.queueFamilyIndex = data.queueFamily;
    info.flags = data.flags;

    VK_CHECK(vkCreateCommandPool(ctx->device, &info, nullptr, &pool.m_Handle))

    return pool;
}

void VulkanCommandPool::Destroy()
{
    VkCtx* ctx = VkCtxHandler::GetCrntCtx();
    vkDestroyCommandPool(ctx->device, m_Handle, nullptr);
}

VulkanCmdBuffer VulkanCmdBuffer::Allocate(VulkanCmdBufferInputData data)
{
    VkCtx* ctx = VkCtxHandler::GetCrntCtx();
    VulkanCmdBuffer buff{};
    buff.m_PoolRef = &data.pool;

    VkCommandBufferAllocateInfo info{};
    info.commandBufferCount = 1;
    info.commandPool = data.pool.GetHandle();
    info.level = data.level;
    
    VK_CHECK(vkAllocateCommandBuffers(ctx->device, &info, &buff.m_Handle))

    return buff;
}

void VulkanCmdBuffer::Free()
{
    VkCtx* ctx = VkCtxHandler::GetCrntCtx();
    vkFreeCommandBuffers(ctx->device, m_PoolRef->GetHandle(), 1, &m_Handle);
}