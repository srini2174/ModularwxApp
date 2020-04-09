#include "Plugins/stdwx.h"
#include "Plugins/NonGuiPlugin.h"

PLUGIN_EXPORTED_API wxNonGuiPluginBase * CreatePlugin()
{
	return new NonGuiPlugin;
}

PLUGIN_EXPORTED_API void DeletePlugin(wxNonGuiPluginBase * plugin)
{
	wxDELETE(plugin);
}
