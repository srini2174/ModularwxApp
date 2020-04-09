#pragma once

#include "PluginItf/wxGuiPluginBase.h"
#include "./GuiPVPlugindllExp.h"

class WXDLLIMPEXP_GUIPV GuiPropViewerPlugin : public wxGuiPluginBase
{
    wxDECLARE_DYNAMIC_CLASS(GuiPropViewerPlugin);
public:
	GuiPropViewerPlugin();
	GuiPropViewerPlugin(wxEvtHandler * handler);
	virtual ~GuiPropViewerPlugin();

	virtual wxString GetName() const;
	virtual wxString GetId() const;
	virtual wxWindow * CreatePanel(wxWindow * parent);
};
