#include "pch.h"
#include "MainPage.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::CppUwpWinRtDeviceWatcherTest01::implementation
{
	MainPage::MainPage() : 
		m_coreDispatcher{ Windows::UI::Core::CoreWindow::GetForCurrentThread().Dispatcher() }, 
		m_viewModel{ m_coreDispatcher }
    {
        InitializeComponent();
    }

	/*
	MainPage::~MainPage()
    {
	    
    }
	*/

	/*
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */ //)
    /*
    {
        throw hresult_not_implemented();
    }
	*/

    /*void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }*/

	CppUwpWinRtDeviceWatcherTest01::MainPageViewModel MainPage::ViewModel()
	{
		throw hresult_not_implemented();
	}

	void MainPage::ViewModel(CppUwpWinRtDeviceWatcherTest01::MainPageViewModel const& value)
	{
		throw hresult_not_implemented();
	}
}
