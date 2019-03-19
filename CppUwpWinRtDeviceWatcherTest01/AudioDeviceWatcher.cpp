#include "pch.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    AudioDeviceWatcher::AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType)
    {
        throw hresult_not_implemented();
    }

    Windows::Devices::Enumeration::DeviceInformation AudioDeviceWatcher::AudioDevice()
    {
        throw hresult_not_implemented();
    }
}
