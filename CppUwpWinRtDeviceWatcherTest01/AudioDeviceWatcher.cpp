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

		*m_deviceWatcher->Added += Windows::Devices::Enumeration::DeviceWatcher::Added;
		*m_deviceWatcher->Removed += Windows::Devices::Enumeration::DeviceWatcher::Removed;
		*m_deviceWatcher->Updated += Windows::Devices::Enumeration::DeviceWatcher::Updated;
		*m_deviceWatcher->EnumerationCompleted += Windows::Devices::Enumeration::DeviceWatcher::EnumerationCompleted;

        //throw hresult_not_implemented();
    }

	AudioDeviceWatcher::~AudioDeviceWatcher()
    {
		*m_deviceWatcher->Added -= Windows::Devices::Enumeration::DeviceWatcher::Added;
		*m_deviceWatcher->Removed -= Windows::Devices::Enumeration::DeviceWatcher::Removed;
		*m_deviceWatcher->Updated -= Windows::Devices::Enumeration::DeviceWatcher::Updated;
		*m_deviceWatcher->EnumerationCompleted -= Windows::Devices::Enumeration::DeviceWatcher::EnumerationCompleted;
		*m_deviceWatcher = nullptr;
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
