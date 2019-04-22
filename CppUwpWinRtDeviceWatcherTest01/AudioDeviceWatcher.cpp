#include "pch.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	///////////////////////////////////////////////////////////////////////////////////////////

    AudioDeviceWatcher::AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const dispatcher): 
		m_deviceType{ ioType }, 
		m_coreDispatcher{dispatcher}
    {
		this->initializeWatcher(m_deviceType);
    }

	///////////////////////////////////////////////////////////////////////////////////////////

	AudioDeviceWatcher::~AudioDeviceWatcher()
    {
		this->StopWatching();

		m_deviceInformationList = nullptr;
		m_coreDispatcher = nullptr;
		m_deviceSelectorString = nullptr;
		m_deviceWatcher = nullptr;

		m_deviceInformationCollection = nullptr;
    }

	///////////////////////////////////////////////////////////////////////////////////////////

	void AudioDeviceWatcher::initializeWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType)
	{
		switch (ioType)
		{
			case AudioDeviceType::Input:
			{
				m_deviceSelectorString = Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector();
				break;
			}

			case AudioDeviceType::Output:
			{
				m_deviceSelectorString = Windows::Media::Devices::MediaDevice::GetAudioRenderSelector();
				break;
			}
			default:
			{
				break;
			}
		}

		m_deviceWatcher = Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(m_deviceSelectorString);

		m_deviceWatcherAddedRevoker = m_deviceWatcher.Added(winrt::auto_revoke, [this](Windows::Devices::Enumeration::DeviceWatcher const& sender, Windows::Devices::Enumeration::DeviceInformation const& args)
			{
				this->DeviceWatcherAddedAsync(sender, args);
			});

		m_deviceWatcherRemovedRevoker = m_deviceWatcher.Removed(winrt::auto_revoke, [this](Windows::Devices::Enumeration::DeviceWatcher const& sender, Windows::Devices::Enumeration::DeviceInformationUpdate const& args)
			{
				this->DeviceWatcherRemovedAsync(sender, args);
			});

		m_deviceWatcherUpdatedRevoker = m_deviceWatcher.Updated(winrt::auto_revoke, [this](Windows::Devices::Enumeration::DeviceWatcher const& sender, Windows::Devices::Enumeration::DeviceInformationUpdate const& args)
			{
				this->DeviceWatcherUpdatedAsync(sender, args);
			});

		if ( (winrt::Windows::Devices::Enumeration::DeviceWatcherStatus::Created == m_deviceWatcher.Status() )
			||
			 (winrt::Windows::Devices::Enumeration::DeviceWatcherStatus::Aborted == m_deviceWatcher.Status() )
			||
			 (winrt::Windows::Devices::Enumeration::DeviceWatcherStatus::Stopped == m_deviceWatcher.Status() )
			)
		{
			this->StartWatching();
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////

    void AudioDeviceWatcher::StartWatching()
    {
		m_deviceWatcher.Start();
    }

	///////////////////////////////////////////////////////////////////////////////////////////

    void AudioDeviceWatcher::StopWatching()
    {
		m_deviceWatcher.Stop();
    }

	/////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> AudioDeviceWatcher::DeviceInformationList()
    {
		return m_deviceInformationList;
    }

	////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> AudioDeviceWatcher::FindDevicesAsync()
    {
		auto list = co_await Windows::Devices::Enumeration::DeviceInformation::FindAllAsync(m_deviceSelectorString);
	    return list;
    }

	///////////////////////////////////////////////////////////////////////////////////////////

	Windows::Foundation::IAsyncAction AudioDeviceWatcher::UpdateDevicesAsync()
    { 
		m_deviceInformationCollection = co_await Windows::Devices::Enumeration::DeviceInformation::FindAllAsync(m_deviceSelectorString);

		m_deviceInformationList.Clear();

		for (Windows::Devices::Enumeration::DeviceInformation deviceInformation : m_deviceInformationCollection)
		{
			m_deviceInformationList.Append(deviceInformation);
		}
    }

	///////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Foundation::IAsyncAction AudioDeviceWatcher::DeviceWatcherAddedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result)
    {
		return m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, [=]() { UpdateDevicesAsync(); });
    }

	Windows::Foundation::IAsyncAction AudioDeviceWatcher::DeviceWatcherRemovedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
		return m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, [=]() { UpdateDevicesAsync(); });
    }

	Windows::Foundation::IAsyncAction AudioDeviceWatcher::DeviceWatcherUpdatedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
		return m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, [=]() { UpdateDevicesAsync(); });
    }

	///////////////////////////////////////////////////////////////////////////////////////////////

	winrt::event_token AudioDeviceWatcher::CollectionChanged(Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler const& handler)
	{
		return m_collectionChanged.add(handler);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	void AudioDeviceWatcher::CollectionChanged(winrt::event_token const& token) noexcept
	{
		m_collectionChanged.remove(token);
	}
}
