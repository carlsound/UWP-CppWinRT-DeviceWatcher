#include "pch.h"
#include "MainPageViewModel.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	MainPageViewModel::MainPageViewModel(Windows::UI::Core::CoreDispatcher dispatcher) :
		m_coreDispatcher{ dispatcher },
		m_audioInputsDeviceWatcher{ winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::AudioDeviceWatcher>(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input, dispatcher) }
		//m_audioInputsDeviceWatcher { CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input, * m_coreDispatcher }
		//m_audioInputsDeviceWatcher{ CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input }
	{
		//m_audioInputsDeviceWatcher = winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::AudioDeviceWatcher>( CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input, m_coreDispatcher );
		//auto m_audioInputsDeviceWatcher = winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::AudioDeviceWatcher>(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input);
		
		//m_audioInputsDeviceWatcher.StartWatching();
		//m_audioInputsDeviceWatcher.StartWatching(dispatcher);
		//m_audioInputsDeviceWatcher = std::make_shared<winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::AudioDeviceWatcher>(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input) >();
	}


	MainPageViewModel::~MainPageViewModel()
	{
		this->m_audioInputsDeviceWatcher.StopWatching();
		m_audioInputsDeviceWatcher = nullptr;
		m_audioInputsDeviceWatcher = nullptr;
		m_coreDispatcher = nullptr;
	}

	void MainPageViewModel::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		m_audioInputsDeviceWatcher.StartWatching();
		//m_audioInputsDeviceWatcher.StartWatching(m_coreDispatcher);

		//throw hresult_not_implemented();
	}

    CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher MainPageViewModel::AudioInputs()
    {
		return m_audioInputsDeviceWatcher;
        //throw hresult_not_implemented();
    }

    /*
	void MainPageViewModel::AudioInputs(CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher const& value)
    {
        throw hresult_not_implemented();
    }
	*/
}
