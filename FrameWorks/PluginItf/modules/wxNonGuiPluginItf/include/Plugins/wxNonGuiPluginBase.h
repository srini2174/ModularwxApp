#pragma once

#include "./wxNonGuiPluginExports.h"
#include "PluginItf/stdwx.h"

class WXDLLIMPEXP_NGUIITF wxNonGuiPluginBase : public wxObject
{
    DECLARE_ABSTRACT_CLASS(wxNonGuiPluginBase)

public:
    wxNonGuiPluginBase();
    virtual ~wxNonGuiPluginBase();
	
    virtual int Work() = 0;
};

typedef wxNonGuiPluginBase * (*CreatePlugin_function)();
typedef void (*DeletePlugin_function)(wxNonGuiPluginBase * plugin);
