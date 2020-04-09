#include "PluginItf/stdwx.h"
#include "./wxGuiWinBaseExports.h"

DECLARE_EXPORTED_EVENT_TYPE(WXDLLIMPEXP_GUIWINBASE, wxEVT_GUI_PLUGIN_INTEROP, wxEVT_USER_FIRST + 100)
//extern GUI_PLUGIN_EXPORTS_API const wxEventType wxEVT_GUI_PLUGIN_INTEROP;
//DECLARE_LOCAL_EVENT_TYPE(wxEVT_GUI_PLUGIN_INTEROP, wxEVT_USER_FIRST + 100)
//class GuiCustomEvent;
//wxDECLARE_EVENT(wxEVT_GUI_PLUGIN_INTEROP, GuiCustomEvent);
/*
class GuiCustomEvent: public wxCommandEvent
{
public:
	GuiCustomEvent(wxEventType commandType = wxEVT_GUI_PLUGIN_INTEROP, int id = 0)
        		:  wxCommandEvent(commandType, id) { }
 
	// You *must* copy here the data to be transported
	GuiCustomEvent(const GuiCustomEvent& event)
        		:  wxCommandEvent(event) {}
 
	// Required for sending with wxPostEvent()
	wxEvent* Clone() const { return new GuiCustomEvent(*this); }
 
};


typedef void (wxEvtHandler::*GuiCustomEventFunction)(GuiCustomEvent &);
 
#define GuiCustomEventHandler(func) wxEVENT_HANDLER_CAST(GuiCustomEventFunction, func)                    

 
// Optional: define an event table entry
#define EVT_GUICUSTOM(id, func) \
 	wx__DECLARE_EVT1(wxEVT_GUI_PLUGIN_INTER, id, GuiCustomEventHandler(func))
 
// Very optionally, you can do a similar #define for EVT_MYFOO_RANGE.
#define EVT_GUICUSTOM_RANGE(id1,id2, func) \
	wx__DECLARE_EVT2(wxEVT_GUI_PLUGIN_INTER, id1, id2, GuiCustomEventHandler(func))
*/