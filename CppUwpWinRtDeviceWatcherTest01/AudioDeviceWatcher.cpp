#include "pch.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    AudioDeviceWatcher::AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType)
    {
		//m_deviceWatcher = nullptr;
		if(AudioDeviceType::Input == ioType)
		{
			*m_deviceWatcher = Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector());
			//Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(Windows::Media::Devices::MediaDevice::GetAudioCaptureSelector());
		}
		else if (AudioDeviceType::Output == ioType)
		{
			*m_deviceWatcher = Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(Windows::Media::Devices::MediaDevice::GetAudioRenderSelector());
			//Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(Windows::Media::Devices::MediaDevice::GetAudioRenderSelector());
		}

        //throw hresult_not_implemented();
    }

	/*AudioDeviceWatcher::~AudioDeviceWatcher()
    {
		*m_deviceWatcher = nullptr;
    }*/

	event_token AudioDeviceWatcher::Added(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> const& handler)
    {
		return m_deviceAdded.add(handler);
    }
	
	void AudioDeviceWatcher::Added(event_token const& cookie)
	{
		m_deviceAdded.remove(cookie);
	}

	event_token AudioDeviceWatcher::Removed(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler)
	{
		return m_deviceRemoved.add(handler);
	}
	
	void AudioDeviceWatcher::Removed(event_token const& cookie)
	{
		m_deviceRemoved.remove(cookie);
	}

	event_token AudioDeviceWatcher::Updated(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler)
	{
		return m_deviceUpdated.add(handler);
	}
	
	void AudioDeviceWatcher::Updated(event_token const& cookie)
	{
		m_deviceUpdated.remove(cookie);
	}

	async void deviceWatcherAdded(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result)
    {
	    
    }

	async void deviceWatcherRemoved(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
	    
    }

	async void deviceWatcherUpdated(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
    {
	    
    }

    void AudioDeviceWatcher::StartWatching()
    {
		m_deviceWatcher->Start();
        //throw hresult_not_implemented();
    }

    void AudioDeviceWatcher::StopWatching()
    {
		m_deviceWatcher->Stop();
        //throw hresult_not_implemented();
    }

    Windows::Devices::Enumeration::DeviceInformationCollection AudioDeviceWatcher::AudioDevicesCollection()
    {
        throw hresult_not_implemented();
    }

    Windows::Devices::Enumeration::DeviceInformation AudioDeviceWatcher::SelectedAudioDevice()
    {
        throw hresult_not_implemented();
    }

    void AudioDeviceWatcher::SelectedAudioDevice(Windows::Devices::Enumeration::DeviceInformation const& value)
    {
        //throw hresult_not_implemented();
    }
}
