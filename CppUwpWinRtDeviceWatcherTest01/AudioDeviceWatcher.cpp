#include "pch.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    AudioDeviceWatcher::AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const dispatcher): 
		m_deviceWatcher{ nullptr },
		m_deviceType{ ioType }, 
		m_coreDispatcher {dispatcher},
		m_deviceInformationList{ winrt::single_threaded_observable_vector<Windows::Devices::Enumeration::DeviceInformation>() }
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
				this->DeviceWatcherAdded(sender, args);
		});

		m_deviceWatcherRemovedRevoker = m_deviceWatcher.Removed(winrt::auto_revoke, [this](Windows::Devices::Enumeration::DeviceWatcher const& sender, Windows::Devices::Enumeration::DeviceInformationUpdate const& args)
			{
				this->DeviceWatcherRemoved(sender, args);
			});

		m_deviceWatcherUpdatedRevoker = m_deviceWatcher.Updated(winrt::auto_revoke, [this](Windows::Devices::Enumeration::DeviceWatcher const& sender, Windows::Devices::Enumeration::DeviceInformationUpdate const& args)
			{
				this->DeviceWatcherUpdated(sender, args);
			});

        //throw hresult_not_implemented();
    }

	///////////////////////////////////////////////////////////////////////////////////////////

	/*
	AudioDeviceWatcher::~AudioDeviceWatcher()
    {
	    
    }
	*/

	///////////////////////////////////////////////////////////////////////////////////////////

    void AudioDeviceWatcher::StartWatching()
    {
		m_deviceWatcher.Start();
        //throw hresult_not_implemented();
    }

    void AudioDeviceWatcher::StopWatching()
    {
		m_deviceWatcher.Stop();
        //throw hresult_not_implemented();
    }

	/////////////////////////////////////////////////////////////////////////////////////////////

	Windows::Foundation::Collections::IObservableVector<Windows::Devices::Enumeration::DeviceInformation> AudioDeviceWatcher::DeviceInformationList()
    {
		return m_deviceInformationList;
        //throw hresult_not_implemented();
    }

	////////////////////////////////////////////////////////////////////////////////////////////

	/* Windows::Foundation::IAsyncAction */ void AudioDeviceWatcher::UpdateDevices()
    {
		Windows::Devices::Enumeration::DeviceInformationCollection m_deviceInformationCollection = Windows::Devices::Enumeration::DeviceInformation::FindAllAsync(m_deviceSelectorString).get();

		m_deviceInformationList.Clear();
		//this->DeviceInformationList().Clear;

		for (Windows::Devices::Enumeration::DeviceInformation deviceInformation : m_deviceInformationCollection)
		{
			m_deviceInformationList.Append(deviceInformation);
			//this->DeviceInformationList().Append(deviceInformation);
		}
    }

	///////////////////////////////////////////////////////////////////////////////////////////////

	/* Windows::Foundation::IAsyncAction */ void AudioDeviceWatcher::DeviceWatcherAdded(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result)
    {
	    m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::High, [this](){ UpdateDevices(); });
    }

	/* Windows::Foundation::IAsyncAction */ void AudioDeviceWatcher::DeviceWatcherRemoved(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
		m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::High, [this]() { UpdateDevices(); });
    }

	/* Windows::Foundation::IAsyncAction */ void AudioDeviceWatcher::DeviceWatcherUpdated(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
		m_coreDispatcher.RunAsync(Windows::UI::Core::CoreDispatcherPriority::High, [this]() { UpdateDevices(); });
    }
}
