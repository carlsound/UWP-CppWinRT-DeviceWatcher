#include "pch.h"
#include "MainPageViewModel.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	MainPageViewModel::MainPageViewModel(Windows::UI::Core::CoreDispatcher dispatcher) : m_coreDispatcher{ dispatcher }, m_audioInputsDeviceWatcher{ AudioDeviceWatcher(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input, m_coreDispatcher) }
	{
		
	}

	MainPageViewModel::~MainPageViewModel()
	{
		
	}

    CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher MainPageViewModel::AudioInputs()
    {
        throw hresult_not_implemented();
    }

    void MainPageViewModel::AudioInputs(CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher const& value)
    {
        throw hresult_not_implemented();
    }
}
