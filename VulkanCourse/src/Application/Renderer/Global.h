#pragma once

#include <vulkan/vulkan.h>
#include <vulkan/vk_enum_string_helper.h>

#include "Logger.h"

#include <limits>

inline void check_vk_result(VkResult result, uint32_t lineNum, std::string funcName, std::string fileName)
{
    if (result != VK_SUCCESS)
    {
        std::string resultStr = string_VkResult(result);
        std::string msg = "VkResult is " + resultStr + " (line: " + std::to_string(lineNum) + ", function: " + funcName + ", file: " + fileName + ")";
        FATAL(msg);
    }
}

#define VK_CHECK(result) check_vk_result(result, __LINE__, __func__, __FILE__);

#define MAX_UINT16 std::numeric_limits<uint16_t>::max()
#define MIN_UINT16 std::numeric_limits<uint16_t>::min()
#define MAX_UINT32 std::numeric_limits<uint32_t>::max()
#define MIN_UINT32 std::numeric_limits<uint32_t>::min()
#define MAX_UINT64 std::numeric_limits<uint64_t>::max()
#define MIN_UINT64 std::numeric_limits<uint64_t>::min()

#define MAX_INT16 std::numeric_limits<int16_t>::max()
#define MIN_INT16 std::numeric_limits<int16_t>::min()
#define MAX_INT32 std::numeric_limits<int32_t>::max()
#define MIN_INT32 std::numeric_limits<int32_t>::min()
#define MAX_INT64 std::numeric_limits<int64_t>::max()
#define MIN_INT64 std::numeric_limits<int64_t>::min()