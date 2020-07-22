#include "panel.h"
#ifdef NIMAQPANEL
#include "NimaqPanel.h"
#else
#include "PESiPanel.h"
#endif

Panel::Panel()
{
	
}
Panel::~Panel()
{

}
std::unique_ptr<Panel> PanelFactory::getPanel()
{
	return std::unique_ptr<Panel>(new REALPANEL());
}

