#include "Plugins/stdwx.h"
#include "PluginItf/wxGuiPluginBase.h"
#include "Plugins/GuiPlugin2.h"

PLUGIN_EXPORTED_API wxGuiPluginBase * CreatePlugin()
{
	return new GuiPlugin2;
}

PLUGIN_EXPORTED_API void DeletePlugin(wxGuiPluginBase * plugin)
{
	wxDELETE(plugin);
}
