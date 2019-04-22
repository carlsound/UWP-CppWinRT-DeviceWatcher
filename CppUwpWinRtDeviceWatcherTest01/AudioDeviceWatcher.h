#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
		AudioDeviceWatcher() = default; //delete;
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const dispatcher);
		~AudioDeviceWatcher();

		winrt::Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> DeviceInformationList();

		winrt::event_token CollectionChanged(Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler const& handler);
		void CollectionChanged(winrt::event_token const& token) noexcept;

    private:
		void initializeWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType);

		void StartWatching();
		void StopWatching();

		winrt::Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> FindDevicesAsync();
		
		winrt::Windows::Foundation::IAsyncAction UpdateDevicesAsync();

		winrt::Windows::Foundation::IAsyncAction DeviceWatcherAddedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result);
		winrt::Windows::Foundation::IAsyncAction DeviceWatcherRemovedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);
		winrt::Windows::Foundation::IAsyncAction DeviceWatcherUpdatedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);

		winrt::Windows::Devices::Enumeration::DeviceWatcher::Added_revoker m_deviceWatcherAddedRevoker;
		winrt::Windows::Devices::Enumeration::DeviceWatcher::Removed_revoker m_deviceWatcherRemovedRevoker;
		winrt::Windows::Devices::Enumeration::DeviceWatcher::Updated_revoker m_deviceWatcherUpdatedRevoker;

		winrt::Windows::Devices::Enumeration::DeviceInformationCollection m_deviceInformationCollection{ nullptr };
		winrt::Windows::Devices::Enumeration::DeviceWatcher m_deviceWatcher{ nullptr };
		winrt::Windows::UI::Core::CoreDispatcher m_coreDispatcher{ nullptr };
		AudioDeviceType m_deviceType{ AudioDeviceType::Input };
		winrt::hstring m_deviceSelectorString{ Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector() };
		winrt::Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> m_deviceInformationList{ winrt::single_threaded_observable_vector<Windows::Devices::Enumeration::DeviceInformation>() };
		winrt::event<Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler> m_collectionChanged;
		winrt::Windows::UI::Xaml::Data::Binding m_UiBinding;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher, implementation::AudioDeviceWatcher>
    {
    };
}
