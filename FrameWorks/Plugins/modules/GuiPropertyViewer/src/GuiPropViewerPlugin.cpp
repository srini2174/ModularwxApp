#include "Plugins/stdwx.h"
#include "Plugins/GuiPropViewerPlugin.h"
#include "Plugins/GuiPropertyPanel.h"

wxIMPLEMENT_DYNAMIC_CLASS(GuiPropViewerPlugin, wxObject);

GuiPropViewerPlugin::GuiPropViewerPlugin()
: wxGuiPluginBase(NULL)
{

}

GuiPropViewerPlugin::GuiPropViewerPlugin(wxEvtHandler * handler)
: wxGuiPluginBase(handler)
{
}

GuiPropViewerPlugin::~GuiPropViewerPlugin()
{
}

wxString GuiPropViewerPlugin::GetName() const
{
    return _("GUI Property Viewer Plugin");
}

wxString GuiPropViewerPlugin::GetId() const
{
	return wxT("{1B226C84-6436-4092-9AB8-B2B0D6731EBE}");
}

wxWindow * GuiPropViewerPlugin::CreatePanel(wxWindow * parent)
{
    wxWindow * propPanel = new GuiPropertyPanel(this, parent);
    return propPanel;
}
