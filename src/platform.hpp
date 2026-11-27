#pragma once

#include <cstdint>

namespace olivia
{
    enum Result : uint8_t;

} // namespace olivia


namespace olivia::platform
{
    Result init(const char* title, uint32_t width, uint32_t height);

    void quit();

    bool is_running();

    void poll_events();

} // namespace olivia::platform