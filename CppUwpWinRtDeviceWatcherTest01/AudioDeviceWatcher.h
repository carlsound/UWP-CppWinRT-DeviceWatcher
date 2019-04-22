#pragma once

#include "AudioDeviceWatcher.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher>
    {
		AudioDeviceWatcher() = default; //delete;
		//AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType);
        AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const dispatcher);
		~AudioDeviceWatcher();

		//CppUwpWinRtDeviceWatcherTest01::AudioDeviceType IoType();
		//void IoType(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& value);

		//hstring SelectorString();
		//void SelectorString(hstring const& value);

		//Windows::Devices::Enumeration::DeviceWatcher Watcher();
		//void Watcher(Windows::Devices::Enumeration::DeviceWatcher const& value);

		//Windows::Devices::Enumeration::DeviceInformationCollection Devices();
		//void Devices(Windows::Devices::Enumeration::DeviceInformationCollection const& value);

		Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> DeviceInformationList();

		//winrt::event_token CollectionChanged(Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler const& handler);
		//void CollectionChanged(winrt::event_token const& token) noexcept;

    private:
		void initializeWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType);

		void StartWatching();
		//void StartWatching(Windows::UI::Core::CoreDispatcher const& dispatcher);

		void StopWatching();

		Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> FindDevicesAsync();
		
    	Windows::Foundation::IAsyncAction UpdateDevicesAsync();

		Windows::Foundation::IAsyncAction DeviceWatcherAddedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result);
		Windows::Foundation::IAsyncAction DeviceWatcherRemovedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);
		Windows::Foundation::IAsyncAction DeviceWatcherUpdatedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result);

		Windows::Devices::Enumeration::DeviceWatcher::Added_revoker m_deviceWatcherAddedRevoker;
		Windows::Devices::Enumeration::DeviceWatcher::Removed_revoker m_deviceWatcherRemovedRevoker;
		Windows::Devices::Enumeration::DeviceWatcher::Updated_revoker m_deviceWatcherUpdatedRevoker;

		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformation> deviceWatcherAddedHandler;
		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherRemovedHandler;
		//Windows::Foundation::EventHandler<Windows::Devices::Enumeration::DeviceInformationUpdate> deviceWatcherUpdatedHandler;

		//std::shared_ptr<Windows::Devices::Enumeration::DeviceInformationCollection> m_deviceInformationCollection{ std::shared_ptr<Windows::Devices::Enumeration::DeviceInformationCollection>() };
		Windows::Devices::Enumeration::DeviceInformationCollection m_deviceInformationCollection{ nullptr };
		//std::shared_ptr<Windows::Devices::Enumeration::DeviceWatcher> m_deviceWatcher{ nullptr };
		Windows::Devices::Enumeration::DeviceWatcher m_deviceWatcher{ nullptr };
		//std::shared_ptr<Windows::UI::Core::CoreDispatcher> m_coreDispatcher{ nullptr };
		Windows::UI::Core::CoreDispatcher m_coreDispatcher{ nullptr };
		AudioDeviceType m_deviceType{ AudioDeviceType::Input };
		//std::shared_ptr<hstring> m_deviceSelectorString{ std::make_shared<hstring>(Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector()) };
		hstring m_deviceSelectorString{ Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector() };
		//std::shared_ptr<Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation>> m_deviceInformationList{ std::make_shared<Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation>>(winrt::single_threaded_observable_vector<Windows::Devices::Enumeration::DeviceInformation>()) };
		Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> m_deviceInformationList{ winrt::single_threaded_observable_vector<Windows::Devices::Enumeration::DeviceInformation>() };
		//
		Windows::UI::Xaml::Data::Binding m_UiBinding;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct AudioDeviceWatcher : AudioDeviceWatcherT<AudioDeviceWatcher, implementation::AudioDeviceWatcher>
    {
    };
}
