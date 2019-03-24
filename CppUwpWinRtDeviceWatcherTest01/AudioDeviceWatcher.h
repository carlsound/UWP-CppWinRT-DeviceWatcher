﻿#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
        AudioDeviceWatcher() = delete;
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const& dispatcher);

        void StartWatching();
        void StopWatching();
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> DeviceInformationList();
        Windows::Devices::Enumeration::DeviceInformation SelectedAudioDevice();
        void SelectedAudioDevice(Windows::Devices::Enumeration::DeviceInformation const& value);

    private:
		void UpdateDevices();

		event_token Added(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> const& handler);
		void Added(event_token const& cookie);

		event_token Removed(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler);
		void Removed(event_token const& cookie);

		event_token Updated(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler);
		void Updated(event_token const& cookie);

		/*Windows::Foundation::IAsyncAction*/ void deviceWatcherAdded(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result);
		/*Windows::Foundation::IAsyncAction*/ void deviceWatcherRemoved(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);
		/*Windows::Foundation::IAsyncAction*/ void deviceWatcherUpdated(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);

		//void DeviceWatcherRemoved();
		//void DeviceWatcherAdded();
		//void DeviceWatcherUpdated();

		Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformation> deviceWatcherAddedHandler;
		Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherRemovedHandler;
		Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherUpdatedHandler;

		Windows::Devices::Enumeration::DeviceInformationCollection m_deviceInformationCollection;
		Windows::Devices::Enumeration::DeviceWatcher m_deviceWatcher;
		hstring m_deviceSelectorString;
		Windows::UI::Core::CoreDispatcher m_coreDispatcher;
		AudioDeviceType m_deviceType;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher, implementation::AudioDeviceWatcher>
    {
    };
}
