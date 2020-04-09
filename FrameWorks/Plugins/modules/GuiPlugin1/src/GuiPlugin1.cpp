#include "Plugins/stdwx.h"
#include "Plugins/GuiPlugin1.h"
#include "Plugins/GuiPluginWindow1.h"

IMPLEMENT_DYNAMIC_CLASS(GuiPlugin1, wxObject)

GuiPlugin1::GuiPlugin1()
: wxGuiPluginBase(NULL)
{

}

GuiPlugin1::GuiPlugin1(wxEvtHandler * handler)
: wxGuiPluginBase(handler)
{
}

GuiPlugin1::~GuiPlugin1()
{
}

wxString GuiPlugin1::GetName() const
{
	return _("GUI Plugin 1");
}

wxString GuiPlugin1::GetId() const
{
	return wxT("{4E97DF66-5FBB-4719-AF17-76C1C82D3FE1}");
}

wxWindow * GuiPlugin1::CreatePanel(wxWindow * parent)
{
	return new GuiPluginWindow1(this, parent);
}
