#include "Plugins/stdwx.h"
#include "PluginItf/wxGuiPluginBase.h"
#include "Plugins/GuiPropViewerPlugin.h"

PLUGIN_EXPORTED_API wxGuiPluginBase * CreatePlugin()
{
	return new GuiPropViewerPlugin;
}

PLUGIN_EXPORTED_API void DeletePlugin(wxGuiPluginBase * plugin)
{
	wxDELETE(plugin);
}
