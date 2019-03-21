#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
        //AudioDeviceWatcher() = delete;
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType);
		~AudioDeviceWatcher();

        void StartWatching();
        void StopWatching();
        Windows::Devices::Enumeration::DeviceInformationCollection AudioDevicesCollection();
        Windows::Devices::Enumeration::DeviceInformation SelectedAudioDevice();
        void SelectedAudioDevice(Windows::Devices::Enumeration::DeviceInformation const& value);

    private:
		//Windows::Devices::Enumeration::DeviceInformation m_deviceInformation;
		Windows::Devices::Enumeration::DeviceWatcher *m_deviceWatcher;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher, implementation::AudioDeviceWatcher>
    {
    };
}
