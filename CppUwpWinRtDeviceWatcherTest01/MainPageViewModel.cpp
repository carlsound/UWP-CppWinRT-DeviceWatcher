#include "pch.h"
#include "MainPageViewModel.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    Windows::Devices::Enumeration::DeviceInformation MainPageViewModel::AudioInputDevice()
    {
        throw hresult_not_implemented();
    }

    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> MainPageViewModel::AudioInputDevices()
    {
        throw hresult_not_implemented();
    }
}
