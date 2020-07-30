#include "PESiPanel.h"

#define ACQ_SNAP 8
#define SAFE_DELETE(PTR) if(PTR != 0){ free(PTR); PTR = 0; }
PESiPanel* ptrPESiPanel;

//TODO_DJ：BinMode初始化
PESiPanel::PESiPanel() : d_binModeName(
	{{ BinMode::BinMode1, {QString("1x1"), 1}},
	 { BinMode::BinMode2, {QString("1x1"), 1}},
	 { BinMode::BinMode3, {QString("1x1"), 1}},
	 { BinMode::BinMode4, {QString("1x1"), 1}},
	 { BinMode::BinMode5, {QString("1x1"), 1}}}),
	Panel()
{
	
	ptrPESiPanel = this;
}

PESiPanel::~PESiPanel()
{
}
void OnEndPESiDetFrameCallback(HACQDESC hAcqDesc)
{
	ptrPESiPanel->OnEndPESiDetFrameCallback(hAcqDesc);
}
void OnEndPESiDetAcqCallback(HACQDESC hAcqDesc)
{
	ptrPESiPanel->OnEndPESiDetAcqCallback(hAcqDesc);
}

bool PESiPanel::initialise()
{
	unsigned int uiNumSensors;			// 探测器个数
	unsigned int iRet;

	if ((iRet = Acquisition_EnumSensors(&uiNumSensors, 1, FALSE)) != HIS_ALL_OK)
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_EnumSensors", iRet));
		return false;
	}

	ACQDESCPOS Pos = 0;
	HACQDESC hAcqDesc = NULL;

	do
	{
		if ((iRet = Acquisition_GetNextSensor(&Pos, &hAcqDesc)) != HIS_ALL_OK)
		{
			LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_GetNextSensor", iRet));
		}
			
	} 
	while (Pos != 0);
	
	UINT nChannelType;
	int nChannelNr;
	
	if ((iRet = Acquisition_GetCommChannel(hAcqDesc, &nChannelType, &nChannelNr)) != HIS_ALL_OK) 
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_GetCommChannel", iRet));
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
	//获取探测器类型及编号
	LOG_INFO(makeMessage("channel type : %d  ChannelNr : %d", nChannelType, nChannelNr));
	
	switch (nChannelType) 
	{
	case HIS_BOARD_TYPE_ELTEC_XRD_FGE_Opto:
		LOG_INFO(makeMessage("%s%d", "HIS_BOARD_TYPE_ELTEC_XRD_FGE_Opto:", nChannelType));
		break;
	case HIS_BOARD_TYPE_ELTEC_XRD_FGX:
		LOG_INFO(makeMessage("%s%d", "HIS_BOARD_TYPE_ELTEC_XRD_FGX:", nChannelType));
		break;
	case HIS_BOARD_TYPE_ELTEC:
		LOG_INFO(makeMessage("%s%d", "HIS_BOARD_TYPE_ELTEC:", nChannelType));
		break;
	case HIS_BOARD_TYPE_ELTEC_GbIF:
		LOG_INFO(makeMessage("%s%d", "HIS_BOARD_TYPE_ELTEC_GbIF:", nChannelType));
		break;
	case HIS_BOARD_TYPE_ELTEC_EMBEDDED:
		LOG_INFO(makeMessage("%s%d", "HIS_BOARD_TYPE_ELTEC_EMBEDDED:", nChannelType));
		break;
	default:
		LOG_INFO(makeMessage("%s%d", "Unknown ChanelType::", nChannelType));
		break;
	}
	//获取探测器配置
	if ((iRet = Acquisition_GetConfiguration(hAcqDesc, 0, &d_height, &d_width, 0,
											0, 0, 0, 0, 0, 0)) != HIS_ALL_OK) 
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_GetConfiguration", iRet));
		return false;
	}
	
	if ((iRet = Acquisition_SetCallbacksAndMessages(hAcqDesc, NULL, 0,
		0, ::OnEndPESiDetFrameCallback, ::OnEndPESiDetAcqCallback)) != HIS_ALL_OK)		//设置采集回调函数
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetCallbacksAndMessages", iRet));
		return false;
	}

	hPESiAcqDesc = hAcqDesc;
	return true;
}
void PESiPanel::OnEndPESiDetFrameCallback(HACQDESC hAcqDesc)
{
	if (d_frameCount == 0)
		d_copyBuffer = (unsigned char*)malloc(d_frameSize * d_frames);

	memcpy(d_copyBuffer + d_frameSize * d_frameCount++, pPESiDetAcqBuffer, d_frameSize);

	if (d_frameCount == d_frames)
		d_imageProcCallback((unsigned short*)d_copyBuffer);

	if (d_sampleMode == SampleMode::softTrigger)
	{
		if (d_PESiContinusSingleMode == PESICON_SINGLE_MODE::Continus ||
			d_PESiContinusSingleMode == PESICON_SINGLE_MODE::Single && d_frameCount != d_frames)
			Acquisition_SetFrameSync(hAcqDesc);
	}
}
void CALLBACK PESiPanel::OnEndPESiDetAcqCallback(HACQDESC hAcqDesc)
{

}
bool PESiPanel::getReady()
{
	return false;
}
int PESiPanel::getSampleTime()
{
	return 0;
}
bool PESiPanel::getConnected()
{
	return false;
}
size_t PESiPanel::getFrameSize()
{
	return size_t();
}
bool PESiPanel::setSampleTime(int in_milliseconds)
{
	unsigned int iRet;

	if ((iRet = Acquisition_SetCameraMode(hPESiAcqDesc, d_sampleTime)) == HIS_ALL_OK)
	{
		LOG_INFO(makeMessage("设置曝光时间:%d", d_sampleTime));
	}
	else 
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetCameraMode", iRet));
	}

	return true;
}
bool PESiPanel::setBinMode(BinMode in_binMode)
{
	unsigned int iRet;
	unsigned short binFmt;

	auto it = d_binModeName.find(in_binMode);
	binFmt = std::get<1>(it->second);

	if ((iRet = Acquisition_SetCameraBinningMode(hPESiAcqDesc, binFmt)) == HIS_ALL_OK)
	{
		LOG_INFO(makeMessage("设置合并模式:%d", std::get<1>(it->second)));
		d_binMode = in_binMode;
		return true;
	}
	else
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetCameraBinningMode", iRet));
		return false;
	}

}
bool PESiPanel::setSampleMode(SampleMode in_sampleMode)
{
	unsigned int iRet;
	QString errorMsg;
	//设置探测器为DDD(Date Delivered on Demand)无间隙触发方式
	if ((iRet = Acquisition_SetCameraTriggerMode(hPESiAcqDesc, 1)) == HIS_ALL_OK)
	{
		if ((iRet = Acquisition_SetFrameSyncTimeMode(hPESiAcqDesc, d_sampleTime, d_cycleTime)) == HIS_ALL_OK)
			LOG_INFO(makeMessage("设置延迟时间:%d ms", d_cycleTime));
		else
		{
			LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetCameraBinningMode", iRet));
			return false;
		}
		
		//设置外触发信号格式
		if ((iRet = Acquisition_SetTriggerOutSignalOptions(hPESiAcqDesc,
			4 /* 4 - DDD_Pulse*/,
			0, 0, 0, 0, 0,
			d_cycleTime,	//延迟时间
			0, 0)) == HIS_ALL_OK)
		{
			LOG_INFO(makeMessage("设置TriggerOut延迟:%d ms", d_cycleTime));
		}
		else 
		{
			LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetTriggerOutSignalOptions", iRet));
			return false;
		}

	}
	else 
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetCameraTriggerMode", iRet));
		return false;
	}

	return true;
}
bool PESiPanel::setGainFactor(int in_gainFactor)
{
	unsigned int iRet;
	
	if ((iRet = Acquisition_SetCameraGain(hPESiAcqDesc, d_gainFactor)) == HIS_ALL_OK)
	{
		LOG_INFO(makeMessage("设置探测增益:%d", d_gainFactor));
		return true;
	}
	else
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetCameraGain", iRet));
		return false;
	}
}
//TODO_DJ:如果单次采集分配的内存很大，则在采集完成或者停止采集后清空pPESiDetAcqBuffer
bool PESiPanel::beginAcquire(unsigned short d_quantity)
{
	unsigned int iRet;
	unsigned long dwDemoParam = ACQ_SNAP;

	if (Acquisition_SetAcqData(hPESiAcqDesc, (void*)&dwDemoParam) != HIS_ALL_OK)
	{
		LOG_INFO(makeMessage("Acquisition_SetAcqData 失败！"));
		return false;
	}
	
	//分配采集内存,设置缓冲区

	if (d_frameSize != d_PESiDetBufferSize)
	{
		if (pPESiDetAcqBuffer != 0)
			SAFE_DELETE(pPESiDetAcqBuffer);

		pPESiDetAcqBuffer = (unsigned short*)malloc(d_frameSize);
	}
	
	iRet = Acquisition_DefineDestBuffers(hPESiAcqDesc, pPESiDetAcqBuffer, d_frames,
		d_height, d_width);

	if (iRet != HIS_ALL_OK)
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_DefineDestBuffers", iRet));
		return false;
	}
	
	unsigned int bHisSeqFlag;
	
	if (d_PESiContinusSingleMode == PESICON_SINGLE_MODE::Continus)
		bHisSeqFlag = HIS_SEQ_CONTINUOUS;
	else if (d_PESiContinusSingleMode == PESICON_SINGLE_MODE::Single)
		bHisSeqFlag = HIS_SEQ_ONE_BUFFER;

	iRet = Acquisition_Acquire_Image(hPESiAcqDesc, d_frames, 0, bHisSeqFlag, 0, 0, 0);
	
	if (iRet != HIS_ALL_OK)
	{
		LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_Acquire_Image", iRet));
		return false;
	}

	if (d_sampleMode == SampleMode::softTrigger) {
		iRet = Acquisition_SetFrameSync(hPESiAcqDesc);
		
		if (iRet != HIS_ALL_OK)
		{
			LOG_ERROR(makeMessage("%s失败！错误码%d", "Acquisition_SetFrameSync", iRet));
			return false;
		}
	}

	return true;
}
void PESiPanel::stopAcquire()
{
	Acquisition_Abort(hPESiAcqDesc);
}
bool PESiPanel::setFrames(int in_frames)
{
	d_frames = in_frames;
	d_frameSize = d_width * d_height * d_frames * sizeof(unsigned short);
	return true;
}
float PESiPanel::getPixelSize()
{
	return d_pixelSize;
}
void PESiPanel::setFrameCallback(std::function<void(unsigned short*)> in_imageProcessCallBack)
{
	d_imageProcCallback = in_imageProcessCallBack;
}
bool PESiPanel::getPanelSize(int& out_width, int& out_height)
{
	out_width = d_width;
	out_height = d_height;
	return true;
}

bool PESiPanel::setPanelSize(int in_width, int in_height)
{
	d_width = in_width;
	d_height = in_height;
	return true;
}