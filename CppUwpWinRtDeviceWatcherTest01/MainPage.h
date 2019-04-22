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

		void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs e);

		CppUwpWinRtDeviceWatcherTest01::MainPageViewModel ViewModel();

		Windows::UI::Xaml::Controls::ListBox AudioInputsListBox();

        //void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

    private:
		CppUwpWinRtDeviceWatcherTest01::MainPageViewModel m_viewModel{ winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::MainPageViewModel>( Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher() ) };
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
