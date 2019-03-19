#pragma once

#include "MainPageViewModel.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel>
    {
        MainPageViewModel() = default;

        Windows::Devices::Enumeration::DeviceInformation AudioInputDevice();
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> AudioInputDevices();
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel, implementation::MainPageViewModel>
    {
    };
}
