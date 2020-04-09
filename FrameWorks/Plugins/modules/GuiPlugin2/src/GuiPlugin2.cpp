#include "Plugins/stdwx.h"
#include "Plugins/GuiPlugin2.h"
#include "Plugins/GuiPluginWindow2.h"

IMPLEMENT_DYNAMIC_CLASS(GuiPlugin2, wxObject)

GuiPlugin2::GuiPlugin2()
: wxGuiPluginBase(NULL)
{

}

GuiPlugin2::GuiPlugin2(wxEvtHandler * handler)
: wxGuiPluginBase(handler)
{
}

GuiPlugin2::~GuiPlugin2()
{
}

wxString GuiPlugin2::GetName() const
{
	return _("GUI Plugin 2");
}

wxString GuiPlugin2::GetId() const
{
	return wxT("{1B226C84-6436-4092-9AB8-B2B0D6731EBE}");
}

wxWindow * GuiPlugin2::CreatePanel(wxWindow * parent)
{
	return new GuiPluginWindow2(this, parent);
}
