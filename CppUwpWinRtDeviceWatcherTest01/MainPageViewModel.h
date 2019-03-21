#pragma once

#include "MainPageViewModel.g.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel>
    {
        MainPageViewModel() = default;

        CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher AudioInputs();
        void AudioInputs(CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher const& value);
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel, implementation::MainPageViewModel>
    {
    };
}
