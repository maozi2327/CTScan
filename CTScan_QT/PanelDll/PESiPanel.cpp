#include "PESiPanel.h"
#include "../Public/util/IULog.h"


PESiPanel::PESiPanel()
{
}


PESiPanel::~PESiPanel()
{
}

bool PESiPanel::initialise()
{
	unsigned int uiNumSensors;			// ÃΩ≤‚∆˜∏ˆ ˝
	HIS_RETURN iRet;
	if ((iRet = Acquisition_EnumSensors(&uiNumSensors, 1, FALSE)) != HIS_ALL_OK)
	{
		QString errorMsg;
		errorMsg.sprintf("%s  ß∞‹£°¥ÌŒÛ¬Î£∫%d", "Acquisition_EnumSensors", iRet);
		LOG_ERROR(errorMsg);
		return false;
	}

	ACQDESCPOS Pos = 0;
	HACQDESC hAcqDesc = NULL;

	do
	{
		if ((iRet = Acquisition_GetNextSensor(&Pos, &hAcqDesc)) != HIS_ALL_OK) 
		{
			QString errorMsg;
			errorMsg.sprintf("%s  ß∞‹£°¥ÌŒÛ¬Î£∫%d", "Acquisition_GetNextSensor", iRet);
			LOG_ERROR(errorMsg);
		}
	} 
	while (Pos != 0);
	
	//ºÏ≤‚ «∑Ò1621¡¨Ω”
	UINT nChannelType;
	int nChannelNr;
	if ((iRet = Acquisition_GetCommChannel(hAcqDesc, &nChannelType, &nChannelNr)) != HIS_ALL_OK) 
	{
		QString errorMsg;
		errorMsg.sprintf("%s  ß∞‹£°¥ÌŒÛ¬Î£∫%d", "Acquisition_GetCommChannel", iRet);
		LOG_ERROR(errorMsg);
		return false;
	}
	if (nChannelType == HIS_BOARD_TYPE_ELTEC_XRD_FGX ||
		nChannelType == HIS_BOARD_TYPE_ELTEC_XRD_FGE_Opto) 
	{
		CHwHeaderInfo Info;
		CHwHeaderInfoEx InfoEx; // new Header 1621

		if ((iRet = Acquisition_GetHwHeaderInfoEx(hAcqDesc, &Info, &InfoEx)) == HIS_ALL_OK) 
		{
			if (Info.dwHeaderID == 14 && InfoEx.wCameratype >= 1) {
				unsigned short *pOffsetBufferBinning1 = NULL, *pOffsetBufferBinning2 = NULL;
				WORD wBinning = 1;
				int timings = 8;
				// create lists to receive timings for different binning modes
				double* m_pTimingsListBinning1;
				double* m_pTimingsListBinning2;
				m_pTimingsListBinning1 = (double*)malloc(timings * sizeof(double));
				m_pTimingsListBinning2 = (double*)malloc(timings * sizeof(double));

				//  set detector timing and gain
				Acquisition_SetCameraMode(hAcqDesc, 0);
				Acquisition_SetCameraGain(hAcqDesc, 1);
				// set detector to default binning mode
				Acquisition_SetCameraBinningMode(hAcqDesc, wBinning);
				// get int times for selected binning mode
				Acquisition_GetIntTimes(hAcqDesc, m_pTimingsListBinning1, &timings);
			}
		}
	}

	//ªÒ»°ÃΩ≤‚∆˜¿‡–Õº∞±‡∫≈
	QString errorMsg;
	errorMsg.sprintf("channel type : %d  ChannelNr : %d", nChannelType, nChannelNr);
	LOG_INFO(errorMsg);
	
	switch (nChannelType) 
	{
	case HIS_BOARD_TYPE_ELTEC_XRD_FGE_Opto:
		errorMsg.sprintf("%s%d", "HIS_BOARD_TYPE_ELTEC_XRD_FGE_Opto:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC_XRD_FGX:
		errorMsg.sprintf("%s%d", "HIS_BOARD_TYPE_ELTEC_XRD_FGX:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC:
		errorMsg.sprintf("%s%d", "HIS_BOARD_TYPE_ELTEC:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC_GbIF:
		errorMsg.sprintf("%s%d", "HIS_BOARD_TYPE_ELTEC_GbIF:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC_EMBEDDED:
		errorMsg.sprintf("%s%d", "HIS_BOARD_TYPE_ELTEC_EMBEDDED:", nChannelType);
		break;
	default:
		errorMsg.sprintf("%s%d", "Unknown ChanelType:", nChannelType);
		break;
	}
	LOG_INFO(errorMsg);
	//ªÒ»°ÃΩ≤‚∆˜≈‰÷√
	if ((iRet = Acquisition_GetConfiguration(hAcqDesc, 0, &d_height, &d_width, 0,
											0, 0, 0, 0, 0, 0)) != HIS_ALL_OK) 
	{
		QString errorMsg;
		errorMsg.sprintf("%s  ß∞‹£°¥ÌŒÛ¬Î£∫%d", "Acquisition_GetConfiguration", iRet);
		LOG_ERROR(errorMsg);
		return false;
	}
	
	std::function<void (HACQDESC hAcqDesc)> frameFun = 
		std::bind(&PESiPanel::OnEndPESiDetFrameCallback, this, d_hAcqDesc);
	std::function<void(HACQDESC hAcqDesc)> acqFun =
		std::bind(&PESiPanel::OnEndPESiDetAcqCallback, this, d_hAcqDesc);
	
	if ((iRet = Acquisition_SetCallbacksAndMessages(hAcqDesc, NULL, 0,
		0, frameFun.target, acqFun.target)) != HIS_ALL_OK)		//…Ë÷√≤…ºØªÿµ˜∫Ø ˝
	{
		QString errorMsg;
		errorMsg.sprintf("%s  ß∞‹£°¥ÌŒÛ¬Î£∫%d", "Acquisition_SetCallbacksAndMessages", iRet);
		LOG_ERROR(errorMsg);
		return false;
	}
}
void CALLBACK PESiPanel::OnEndPESiDetFrameCallback(HACQDESC hAcqDesc)
{

}
void CALLBACK PESiPanel::OnEndPESiDetAcqCallback(HACQDESC hAcqDesc)
{

}