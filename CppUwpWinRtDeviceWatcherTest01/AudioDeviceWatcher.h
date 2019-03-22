#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
        //AudioDeviceWatcher() = delete;
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType);
		//~AudioDeviceWatcher();

		event_token Added(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> const& handler);
		void Added(event_token const& cookie);

		event_token Removed(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler);
		void Removed(event_token const& cookie);

		event_token Updated(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler);
		void Updated(event_token const& cookie);

        void StartWatching();
        void StopWatching();

        Windows::Devices::Enumeration::DeviceInformationCollection AudioDevicesCollection();
        Windows::Devices::Enumeration::DeviceInformation SelectedAudioDevice();
        void SelectedAudioDevice(Windows::Devices::Enumeration::DeviceInformation const& value);

    private:
		Windows::Devices::Enumeration::DeviceWatcher *m_deviceWatcher;

		event<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation>> m_deviceAdded;
		event<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate>> m_deviceRemoved;
		event<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate>> m_deviceUpdated;

		async void deviceWatcherAdded(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result);
		async void deviceWatcherRemoved(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);
		async void deviceWatcherUpdated(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);

		Windows::Devices::Enumeration::DeviceInformationCollection *m_deviceInformationCollection;
		Windows::Devices::Enumeration::DeviceInformation *m_deviceInformation;

    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher, implementation::AudioDeviceWatcher>
    {
    };
}
