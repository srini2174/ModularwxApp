#pragma once

#include "wxModularCore/wxModularCore.h"
#include "Plugins/wxNonGuiPluginBase.h"
#include "PluginItf/wxGuiPluginBase.h"

// We need to know which DLL produced the specific plugin object.
WX_DECLARE_HASH_MAP(wxNonGuiPluginBase*, wxDynamicLibrary*, \
					wxPointerHash, wxPointerEqual, \
					wxNonGuiPluginToDllDictionary);
WX_DECLARE_HASH_MAP(wxGuiPluginBase*, wxDynamicLibrary*, \
					wxPointerHash, wxPointerEqual, \
					wxGuiPluginToDllDictionary);
// And separate list of loaded plugins for faster access.
WX_DECLARE_LIST(wxNonGuiPluginBase, wxNonGuiPluginBaseList);
WX_DECLARE_LIST(wxGuiPluginBase, wxGuiPluginBaseList);

class ReferencePluginManager : public wxModularCore
{
public:
	virtual ~ReferencePluginManager();
	virtual bool LoadAllPlugins(bool forceProgramPath);
	virtual bool UnloadAllPlugins();

	const wxNonGuiPluginBaseList & GetNonGuiPlugins() const;
	const wxGuiPluginBaseList & GetGuiPlugins() const;
private:
	wxNonGuiPluginToDllDictionary m_MapNonGuiPluginsDll;
	wxNonGuiPluginBaseList m_NonGuiPlugins;
	wxGuiPluginToDllDictionary m_MapGuiPluginsDll;
	wxGuiPluginBaseList m_GuiPlugins;
};
