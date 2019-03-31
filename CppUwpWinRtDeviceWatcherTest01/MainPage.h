//
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "MainPageViewModel.h"

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();
		//~MainPage();

        //int32_t MyProperty();
        //void MyProperty(int32_t value);

		CppUwpWinRtDeviceWatcherTest01::MainPageViewModel ViewModel();
		void ViewModel(CppUwpWinRtDeviceWatcherTest01::MainPageViewModel const& value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

    private:
		Windows::UI::Core::CoreDispatcher m_coreDispatcher;
		MainPageViewModel m_viewModel;
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
