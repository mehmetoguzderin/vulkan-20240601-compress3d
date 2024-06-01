#include <vulkan/vulkan_raii.hpp>

#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  try {
    vk::raii::Context context;
    auto applicationInfo = vk::ApplicationInfo("vulkan-20240601-compress3d", 1,
                                               "vulkan-20240601-compress3d", 1,
                                               VK_API_VERSION_1_1);
    auto instanceCreateInfo = vk::InstanceCreateInfo({}, &applicationInfo);
    auto instance = vk::raii::Instance(context, instanceCreateInfo);
    auto physicalDevices = instance.enumeratePhysicalDevices();
    for (size_t i = 0; i < physicalDevices.size(); ++i) {
      auto properties = physicalDevices[i].getProperties();
      std::cout << "Device " << i << ": " << properties.deviceName << "\n";
      auto format = vk::Format::eBc1RgbUnormBlock;
      try {
        auto imageFormatProperties =
            physicalDevices[i].getImageFormatProperties(
                format, vk::ImageType::e3D, vk::ImageTiling::eOptimal,
                vk::ImageUsageFlagBits::eSampled, {});
        std::cout
            << "Device supports BC1 RGB UNORM with 3D when optimal tiling\n";
      } catch (vk::Error &err) {
        std::cout << "Device does not support BC1 RGB UNORM with 3D when "
                     "optimal tiling\n";
      }
    }
  } catch (vk::SystemError &err) {
    std::cout << "vk::SystemError: " << err.what() << "\n";
    exit(-1);
  } catch (std::exception &err) {
    std::cout << "std::exception: " << err.what() << "\n";
    exit(-1);
  } catch (...) {
    std::cout << "unknown error\n";
    exit(-1);
  }

  return 0;
}