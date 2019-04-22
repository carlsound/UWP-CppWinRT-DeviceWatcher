#include "pch.h"
#include "MainPage.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	MainPage::MainPage()
    {
        InitializeComponent();
    }

	/*
	MainPage::~MainPage()
    {
	    
    }
	*/

	void MainPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs e)
	{
		//m_coreDispatcher = std::make_shared<Windows::UI::Core::CoreDispatcher>(Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher());
		//m_viewModel = winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::MainPageViewModel>(*m_coreDispatcher);
		//m_viewModel = winrt::make<CppUwpWinRtDeviceWatcherTest01::implementation::MainPageViewModel>(Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher());
		m_viewModel.OnNavigatedTo(e);
	}

    /*void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }*/

	CppUwpWinRtDeviceWatcherTest01::MainPageViewModel MainPage::ViewModel()
	{
		return m_viewModel;
		//throw hresult_not_implemented();
	}

	Windows::UI::Xaml::Controls::ListBox MainPage::AudioInputsListBox()
	{
		return this->audioInputDevicesDynamicListBox();
		//throw hresult_not_implemented();
	}
}
