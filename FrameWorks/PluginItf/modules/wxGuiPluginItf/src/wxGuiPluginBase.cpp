#include "PluginItf/stdwx.h"
#include "PluginItf/wxGuiPluginBase.h"


IMPLEMENT_ABSTRACT_CLASS(wxGuiPluginBase, wxObject)

wxGuiPluginBase::wxGuiPluginBase(wxEvtHandler * handler)
: m_Handler(handler)
{
}

wxGuiPluginBase::~wxGuiPluginBase()
{
}

wxEvtHandler * wxGuiPluginBase::GetEventHandler()
{
	return m_Handler;
}

void wxGuiPluginBase::SetEventHandler(wxEvtHandler * handler)
{
	m_Handler = handler;
}