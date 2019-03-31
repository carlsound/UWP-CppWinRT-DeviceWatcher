#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
        //AudioDeviceWatcher() = delete;
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const dispatcher);
		~AudioDeviceWatcher();

        void StartWatching();
        void StopWatching();

        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> DeviceInformationList();

        Windows::Devices::Enumeration::DeviceInformation SelectedAudioDevice();
        void SelectedAudioDevice(Windows::Devices::Enumeration::DeviceInformation const& value);

    private:
		Windows::Foundation::IAsyncAction UpdateDevices();

		Windows::Foundation::IAsyncAction DeviceWatcherAdded(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result);
		Windows::Foundation::IAsyncAction DeviceWatcherRemoved(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);
		Windows::Foundation::IAsyncAction DeviceWatcherUpdated(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);

		Windows::Devices::Enumeration::DeviceWatcher::Added_revoker m_deviceWatcherAddedRevoker;
		Windows::Devices::Enumeration::DeviceWatcher::Removed_revoker m_deviceWatcherRemovedRevoker;
		Windows::Devices::Enumeration::DeviceWatcher::Updated_revoker m_deviceWatcherUpdatedRevoker;

		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformation> deviceWatcherAddedHandler;
		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherRemovedHandler;
		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherUpdatedHandler;

		//Windows::Devices::Enumeration::DeviceInformationCollection m_deviceInformationCollection;
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
