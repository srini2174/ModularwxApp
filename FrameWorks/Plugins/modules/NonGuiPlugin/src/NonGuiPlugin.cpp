#include "Plugins/NonGuiPlugin.h"

IMPLEMENT_DYNAMIC_CLASS(NonGuiPlugin, wxObject)


NonGuiPlugin::NonGuiPlugin()
{
}

NonGuiPlugin::~NonGuiPlugin()
{
}

int NonGuiPlugin::Work()
{
	return 10;
}
