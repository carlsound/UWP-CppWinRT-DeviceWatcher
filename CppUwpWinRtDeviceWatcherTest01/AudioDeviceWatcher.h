#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
        //AudioDeviceWatcher() = delete;
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const dispatcher);
		//~AudioDeviceWatcher();

        void StartWatching();
        void StopWatching();

		Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> DeviceInformationList();

    private:
		Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> FindDevicesAsync();
		
    	/* Windows::Foundation::IAsyncAction */ void UpdateDevicesAsync();

		Windows::Foundation::IAsyncAction DeviceWatcherAddedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result);
		Windows::Foundation::IAsyncAction DeviceWatcherRemovedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);
		Windows::Foundation::IAsyncAction DeviceWatcherUpdatedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);

		Windows::Devices::Enumeration::DeviceWatcher::Added_revoker m_deviceWatcherAddedRevoker;
		Windows::Devices::Enumeration::DeviceWatcher::Removed_revoker m_deviceWatcherRemovedRevoker;
		Windows::Devices::Enumeration::DeviceWatcher::Updated_revoker m_deviceWatcherUpdatedRevoker;

		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformation> deviceWatcherAddedHandler;
		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherRemovedHandler;
		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherUpdatedHandler;

		Windows::Devices::Enumeration::DeviceInformationCollection m_deviceInformationCollection;

		Windows::Devices::Enumeration::DeviceWatcher m_deviceWatcher;
		hstring m_deviceSelectorString;
		Windows::UI::Core::CoreDispatcher m_coreDispatcher;
		AudioDeviceType m_deviceType;
		Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> m_deviceInformationList;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher, implementation::AudioDeviceWatcher>
    {
    };
}
