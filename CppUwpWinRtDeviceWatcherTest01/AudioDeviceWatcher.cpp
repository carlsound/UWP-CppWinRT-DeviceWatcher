﻿#include "pch.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    AudioDeviceWatcher::AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType const& ioType, Windows::UI::Core::CoreDispatcher const& dispatcher)
    {

		m_coreDispatcher = dispatcher;
		m_deviceType = ioType;

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
		m_deviceWatcher.Added(DeviceWatcher_Added);
		m_deviceWatcher.Removed(DeviceWatcher_Removed);

        //throw hresult_not_implemented();
    }

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

    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> AudioDeviceWatcher::DeviceInformationList()
    {
        throw hresult_not_implemented();
    }

    Windows::Devices::Enumeration::DeviceInformation AudioDeviceWatcher::SelectedAudioDevice()
    {
        throw hresult_not_implemented();
    }

    void AudioDeviceWatcher::SelectedAudioDevice(Windows::Devices::Enumeration::DeviceInformation const& value)
    {
        throw hresult_not_implemented();
    }

	event_token AudioDeviceWatcher::Added(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> const& handler)
	{
		deviceWatcherAddedHandler = handler;
		//deviceWatcherAdded(m_deviceWatcher, m_deviceInformation) = handler;
		return m_deviceAdded.add(deviceWatcherAddedHandler);
	}

	void AudioDeviceWatcher::Added(event_token const& cookie)
	{
		m_deviceAdded.remove(cookie);
	}

	event_token AudioDeviceWatcher::Removed(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler)
	{
		deviceWatcherRemovedHandler = handler;
		return m_deviceRemoved.add(deviceWatcherRemovedHandler);
	}

	void AudioDeviceWatcher::Removed(event_token const& cookie)
	{
		m_deviceRemoved.remove(cookie);
	}

	event_token AudioDeviceWatcher::Updated(Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> const& handler)
	{
		deviceWatcherUpdatedHandler = handler;
		return m_deviceUpdated.add(deviceWatcherUpdatedHandler);
	}

	void AudioDeviceWatcher::Updated(event_token const& cookie)
	{
		m_deviceUpdated.remove(cookie);
	}

	/*Windows::Foundation::IAsyncAction deviceWatcherAdded(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformation result)
	{

	}*/

	/*Windows::Foundation::IAsyncAction deviceWatcherRemoved(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
	{

	}*/

	/*Windows::Foundation::IAsyncAction deviceWatcherUpdated(Windows::Devices::Enumeration::DeviceWatcher sender, Windows::Devices::Enumeration::DeviceInformationUpdate result)
	{

	}*/
}
