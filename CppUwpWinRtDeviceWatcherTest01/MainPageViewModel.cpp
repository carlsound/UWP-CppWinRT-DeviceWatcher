#include "pch.h"
#include "MainPageViewModel.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	MainPageViewModel::MainPageViewModel(Windows::UI::Core::CoreDispatcher dispatcher) : 
		m_coreDispatcher{ std::make_shared<Windows::UI::Core::CoreDispatcher>(dispatcher) },
		m_audioInputsDeviceWatcher{ std::make_shared<AudioDeviceWatcher>(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input, *m_coreDispatcher) }
	{
		m_audioInputsDeviceWatcher->StartWatching();
	}


	MainPageViewModel::~MainPageViewModel()
	{
		m_audioInputsDeviceWatcher->StopWatching();
		m_audioInputsDeviceWatcher = nullptr;
		m_audioInputsDeviceWatcher = nullptr;
		m_coreDispatcher = nullptr;
	}

    CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher MainPageViewModel::AudioInputs()
    {
		return *m_audioInputsDeviceWatcher;
        //throw hresult_not_implemented();
    }

    /*
	void MainPageViewModel::AudioInputs(CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher const& value)
    {
        throw hresult_not_implemented();
    }
	*/
}
