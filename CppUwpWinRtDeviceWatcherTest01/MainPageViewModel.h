#pragma once

#include "MainPageViewModel.g.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel>
    {
        MainPageViewModel(Windows::UI::Core::CoreDispatcher const dispatcher);
		//~MainPageViewModel();

        CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher AudioInputs();
        void AudioInputs(CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher const& value);

    private:
        Windows::UI::Core::CoreDispatcher m_coreDispatcher;
		AudioDeviceWatcher m_audioInputsDeviceWatcher;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel, implementation::MainPageViewModel>
    {
    };
}
