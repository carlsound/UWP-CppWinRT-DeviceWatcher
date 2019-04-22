#pragma once

#include "MainPageViewModel.g.h"
#include "AudioDeviceWatcher.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel>
    {
		MainPageViewModel() = delete;
        MainPageViewModel(Windows::UI::Core::CoreDispatcher const dispatcher);
		~MainPageViewModel();

		void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e);

        CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher AudioInputs();
        //void AudioInputs(CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher const& value);

    private:
		void CollectionChanged(auto_revoke_t, winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs const& e) const;
        Windows::UI::Core::CoreDispatcher m_coreDispatcher;
		//std::shared_ptr<AudioDeviceWatcher> m_audioInputsDeviceWatcher;
		//CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher m_audioInputsDeviceWatcher{ CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input }; //{ CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input, nullptr };
		CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher m_audioInputsDeviceWatcher; //{ winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::AudioDeviceWatcher>( CppUwpWinRtDeviceWatcherTest01::AudioDeviceType::Input ) };
		//std::shared_ptr<CppUwpWinRtDeviceWatcherTest01::AudioDeviceWatcher> m_audioInputsDeviceWatcher;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct MainPageViewModel : MainPageViewModelT<MainPageViewModel, implementation::MainPageViewModel>
    {
    };
}
