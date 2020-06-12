#include "panel.h"
#ifdef NIMAQPANEL
#include "NimaqPanel.h"
#else
#include "PESiPanel.h"
#endif

Panel::Panel(std::function<void(unsigned short*)> in_imageProcessCallBack)
{
	
}
Panel::~Panel()
{

}
std::unique_ptr<Panel> PanelFactory::getPanel(std::function<void(unsigned short*)> in_imageProcessCallBack)
{
	return std::unique_ptr<Panel>(new REALPANEL(in_imageProcessCallBack));
}