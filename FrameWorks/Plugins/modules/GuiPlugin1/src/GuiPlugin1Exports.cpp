#include "Plugins/stdwx.h"
#include "Plugins/GuiPlugin1.h"

PLUGIN_EXPORTED_API wxGuiPluginBase * CreatePlugin()
{
	return new GuiPlugin1;
}

PLUGIN_EXPORTED_API void DeletePlugin(wxGuiPluginBase * plugin)
{
	wxDELETE(plugin);
}
