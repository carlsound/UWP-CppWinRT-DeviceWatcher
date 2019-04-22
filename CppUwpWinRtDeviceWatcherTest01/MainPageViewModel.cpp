#include "pch.h"
#include "MainPageViewModel.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	MainPageViewModel::MainPageViewModel(Windows::UI::Core::CoreDispatcher dispatcher) :
		m_coreDispatcher{ dispatcher },
		m_audioInputsDeviceWatcher{ winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::AudioDeviceWatcher>(CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input, dispatcher) }
	{
		
	}

	MainPageViewModel::~MainPageViewModel()
	{
		m_audioInputsDeviceWatcher = nullptr;
		m_coreDispatcher = nullptr;
	}

	void MainPageViewModel::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e)
	{
		//m_audioInputsDeviceWatcher.StartWatching();
		//m_audioInputsDeviceWatcher.StartWatching(m_coreDispatcher);
	}

    CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher MainPageViewModel::AudioInputs()
    {
		return m_audioInputsDeviceWatcher;
    }

	void CollectionChanged(auto_revoke_t, winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs const& e)
	{

	}
}
