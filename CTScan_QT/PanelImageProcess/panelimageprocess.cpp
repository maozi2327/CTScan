#include "stdafx.h"
#include <QFileInfo>
#include "panelimageprocess.h"
#include "../Public/headers/MicroDataCorrection.h"
#include "../Public/headers/tiffio.h"
#include "panelimageprocessinstance.h"

std::unique_ptr<PanelImageProcess> PanelImageProcessFactory::getPanelImageProcess()
{
	return std::unique_ptr<PanelImageProcess>(new PanelImageProcessInstance);
}