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

        //int32_t MyProperty();
        //void MyProperty(int32_t value);

		CppUwpWinRtDeviceWatcherTest01::MainPageViewModel ViewModel();
		//void ViewModel(CppUwpWinRtDeviceWatcherTest01::MainPageViewModel const& value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

    private:
		//std::shared_ptr<Windows::UI::Core::CoreDispatcher> m_coreDispatcher;
		//std::shared_ptr<MainPageViewModel> m_viewModel;
		//CppUwpWinRtDeviceWatcherTest01::MainPageViewModel m_viewModel{ nullptr };
		CppUwpWinRtDeviceWatcherTest01::MainPageViewModel m_viewModel{ winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::MainPageViewModel>( Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher() ) };
    };
}

namespace winrt::CppUwpWinRtDeviceWatcherTest01::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
