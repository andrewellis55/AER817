﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "MainPage.xaml.h"

void ::ReaderWriter::MainPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///MainPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::ReaderWriter::MainPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->muse_list_combobox = safe_cast<::Windows::UI::Xaml::Controls::ComboBox^>(__target);
            }
            break;
        case 2:
            {
                this->refresh_button = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->refresh_button))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::ReaderWriter::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::refresh_button_clicked);
            }
            break;
        case 3:
            {
                this->connect_button = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->connect_button))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::ReaderWriter::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::connect_button_clicked);
            }
            break;
        case 4:
            {
                this->disconnect_button = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->disconnect_button))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::ReaderWriter::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::disconnect_button_clicked);
            }
            break;
        case 5:
            {
                this->connection_status_label = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 6:
            {
                this->connection_status = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 7:
            {
                this->test_status_label = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 8:
            {
                this->test_status = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::ReaderWriter::MainPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


