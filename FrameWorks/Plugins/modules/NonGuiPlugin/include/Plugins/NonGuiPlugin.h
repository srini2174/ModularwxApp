#pragma once
#include "./NonGuiPlugindllExp.h"
#include "Plugins/wxNonGuiPluginBase.h"

class WXDLLIMPEXP_NONGUIPLUGIN NonGuiPlugin : public wxNonGuiPluginBase
{
    DECLARE_DYNAMIC_CLASS(NonGuiPlugin)
public:
	NonGuiPlugin();
	virtual ~NonGuiPlugin();
	
	virtual int Work();
};
