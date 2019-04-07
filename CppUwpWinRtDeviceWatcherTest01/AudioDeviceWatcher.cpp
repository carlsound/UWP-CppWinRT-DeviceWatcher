#include "pch.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	/*
	AudioDeviceWatcher::AudioDeviceWatcher():
		m_deviceWatcher{ nullptr },
		m_deviceType{ AudioDeviceType::Input },
		m_coreDispatcher{ nullptr },
		m_deviceInformationList{ std::make_shared<Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation>>(winrt::single_threaded_observable_vector<Windows::Devices::Enumeration::DeviceInformation>()) },
		m_deviceInformationCollection{ std::shared_ptr<Windows::Devices::Enumeration::DeviceInformationCollection>() }
	{
		initializeWatcher(m_deviceType);
	}
	*/

	///////////////////////////////////////////////////////////////////////////////////////////

	/*
	AudioDeviceWatcher::AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType):
		//m_deviceWatcher{ nullptr },
		m_deviceType{ ioType } //,
		//m_coreDispatcher{ nullptr },
		//m_deviceInformationList{ std::make_shared<Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation>>(winrt::single_threaded_observable_vector<Windows::Devices::Enumeration::DeviceInformation>()) },
		//m_deviceInformationCollection{ std::shared_ptr<Windows::Devices::Enumeration::DeviceInformationCollection>() }
	{
		initializeWatcher(m_deviceType);
	}
	*/

	///////////////////////////////////////////////////////////////////////////////////////////

	/*
    AudioDeviceWatcher::AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const dispatcher): 
		//m_deviceWatcher{ nullptr },
		m_deviceType{ ioType }, 
		m_coreDispatcher {std::make_shared<Windows::UI::Core::CoreDispatcher>(dispatcher) },
		m_deviceInformationList{ std::make_shared<Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation>>( winrt::single_threaded_observable_vector<Windows::Devices::Enumeration::DeviceInformation>() ) },
		m_deviceInformationCollection{ std::shared_ptr<Windows::Devices::Enumeration::DeviceInformationCollection>() }
    {
		initializeWatcher(m_deviceType);

        //throw hresult_not_implemented();
    }
	*/

	///////////////////////////////////////////////////////////////////////////////////////////

	/*
	AudioDeviceWatcher::~AudioDeviceWatcher()
    {
		m_deviceInformationList = nullptr;
		m_coreDispatcher = nullptr;
		m_deviceSelectorString = nullptr;
		m_deviceWatcher = nullptr;

		m_deviceInformationCollection = nullptr;

		//m_deviceWatcherAddedRevoker = nullptr;
		//m_deviceWatcherRemovedRevoker = nullptr;
		//m_deviceWatcherUpdatedRevoker = nullptr;
    }
	*/

	///////////////////////////////////////////////////////////////////////////////////////////

	void AudioDeviceWatcher::initializeWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType)
	{
		switch (ioType)
		{
			case AudioDeviceType::Input:
			{
				//m_deviceSelectorString = Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector();
				this->SelectorString(Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector());
				break;
			}

			case AudioDeviceType::Output:
			{
				//m_deviceSelectorString = Windows::Media::Devices::MediaDevice::GetAudioRenderSelector();
				this->SelectorString(Windows::Media::Devices::MediaDevice::GetAudioRenderSelector());
				break;
			}
			default:
			{
				break;
			}
		}

		//m_deviceWatcher = Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(m_deviceSelectorString);
		this->Watcher( Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(this->SelectorString) );

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
	}

	///////////////////////////////////////////////////////////////////////////////////////////

	/*
    void AudioDeviceWatcher::StartWatching()
    {
		m_deviceWatcher->Start();
        //throw hresult_not_implemented();
    }
	*/

	///////////////////////////////////////////////////////////////////////////////////////////

	void AudioDeviceWatcher::StartWatching(Windows::UI::Core::CoreDispatcher const& dispatcher)
	{
		m_coreDispatcher = dispatcher;

		/*
		if ( (m_deviceType != AudioDeviceType::Input) || (m_deviceType != AudioDeviceType::Output) )
		{
			m_deviceType = AudioDeviceType::Input;
		}
		*/

		//initializeWatcher(m_deviceType);
		initializeWatcher(this->IoType());

		//m_deviceWatcher.Start();
		this->Watcher(StartWatching());
	}

	///////////////////////////////////////////////////////////////////////////////////////////

    void AudioDeviceWatcher::StopWatching()
    {
		//m_deviceWatcher.Stop();
		this->Watcher(StopWatching());
        //throw hresult_not_implemented();
    }

	/////////////////////////////////////////////////////////////////////////////////////////////

	CppUwpWinRtDeviceWatcherTest01::AudioDeviceType AudioDeviceWatcher::IoType()
	{
		throw hresult_not_implemented();
	}

	void AudioDeviceWatcher::IoType(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& value)
	{
		throw hresult_not_implemented();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////

	hstring AudioDeviceWatcher::SelectorString()
	{
		throw hresult_not_implemented();
	}

	void AudioDeviceWatcher::SelectorString(hstring const& value)
	{
		throw hresult_not_implemented();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Devices::Enumeration::DeviceWatcher AudioDeviceWatcher::Watcher()
	{
		throw hresult_not_implemented();
	}

	void AudioDeviceWatcher::Watcher(Windows::Devices::Enumeration::DeviceWatcher const& value)
	{
		throw hresult_not_implemented();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Devices::Enumeration::DeviceInformationCollection AudioDeviceWatcher::Devices()
	{
		throw hresult_not_implemented();
	}

	void AudioDeviceWatcher::Devices(Windows::Devices::Enumeration::DeviceInformationCollection const& value)
	{
		throw hresult_not_implemented();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////

	/*
	Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> AudioDeviceWatcher::DeviceInformationList()
    {
		return m_deviceInformationList;
        //throw hresult_not_implemented();
    }
	*/

	////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> AudioDeviceWatcher::FindDevicesAsync()
    {
	    return Windows::Devices::Enumeration::DeviceInformation::FindAllAsync(m_deviceSelectorString);
    }

	///////////////////////////////////////////////////////////////////////////////////////////

	void AudioDeviceWatcher::UpdateDevicesAsync()
    {
		m_deviceInformationCollection = Windows::Devices::Enumeration::DeviceInformationCollection( FindDevicesAsync().GetResults() );

		m_deviceInformationList.Clear();
		//this->DeviceInformationList().Clear;

		for (Windows::Devices::Enumeration::DeviceInformation deviceInformation : m_deviceInformationCollection)
		{
			m_deviceInformationList.Append(deviceInformation);
			//this->DeviceInformationList().Append(deviceInformation);
		}
    }

	///////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Foundation::IAsyncAction AudioDeviceWatcher::DeviceWatcherAddedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result)
    {
	    return m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::High, [this](){ UpdateDevicesAsync(); });
    }

	Windows::Foundation::IAsyncAction AudioDeviceWatcher::DeviceWatcherRemovedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
		return m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::High, [this]() { UpdateDevicesAsync(); });
    }

	Windows::Foundation::IAsyncAction AudioDeviceWatcher::DeviceWatcherUpdatedAsync(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
		return m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::High, [this]() { UpdateDevicesAsync(); });
    }

	///////////////////////////////////////////////////////////////////////////////////////////////

	winrt::event_token AudioDeviceWatcher::CollectionChanged(Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler const& handler)
	{
		throw hresult_not_implemented();
	}

	///////////////////////////////////////////////////////////////////////////////////////////////

	void AudioDeviceWatcher::CollectionChanged(winrt::event_token const& token) noexcept
	{
		throw hresult_not_implemented();
	}
}
