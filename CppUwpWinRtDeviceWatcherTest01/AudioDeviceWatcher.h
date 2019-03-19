#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
        AudioDeviceWatcher() = delete;
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType);

        Windows::Devices::Enumeration::DeviceInformation AudioDevice();
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher, implementation::AudioDeviceWatcher>
    {
    };
}
