#pragma once

#include "PluginItf/wxGuiPluginBase.h"
#include "./GuiPlugin2dllExp.h"

class WXDLLIMPEXP_GUI2 GuiPlugin2 : public wxGuiPluginBase
{
	DECLARE_DYNAMIC_CLASS(GuiPlugin2)
public:
	GuiPlugin2();
	GuiPlugin2(wxEvtHandler * handler);
	virtual ~GuiPlugin2();

	virtual wxString GetName() const;
	virtual wxString GetId() const;
	virtual wxWindow * CreatePanel(wxWindow * parent);
};
