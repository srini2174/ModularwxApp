#pragma once

#include "PluginItf/wxGuiPluginBase.h"
#include "./GuiPlugin1dllExp.h"

class WXDLLIMPEXP_GUI1 GuiPlugin1 : public wxGuiPluginBase
{
	DECLARE_DYNAMIC_CLASS(GuiPlugin1)
public:
	GuiPlugin1();
	GuiPlugin1(wxEvtHandler * handler);
	virtual ~GuiPlugin1();

	virtual wxString GetName() const;
	virtual wxString GetId() const;
	virtual wxWindow * CreatePanel(wxWindow * parent);
};
