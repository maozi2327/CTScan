#include "PESiPanel.h"
#include "../Public/util/IULog.h"


#define ACQ_SNAP 8
#define SAFE_DELETE(PTR) if(PTR != 0){ free(PTR); PTR = 0; }
PESiPanel* ptrPESiPanel;
//TODO_DJ��BinMode��ʼ��
PESiPanel::PESiPanel() : d_binModeName(
	{{ BinMode::BinMode1, {QString("1x1"), 1}},
	 { BinMode::BinMode2, {QString("1x1"), 1}},
	 { BinMode::BinMode3, {QString("1x1"), 1}},
	 { BinMode::BinMode4, {QString("1x1"), 1}},
	 { BinMode::BinMode5, {QString("1x1"), 1}}})
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
	unsigned int uiNumSensors;			// ̽��������
	unsigned int iRet;

	if ((iRet = Acquisition_EnumSensors(&uiNumSensors, 1, FALSE)) != HIS_ALL_OK)
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_EnumSensors", iRet);
		return false;
	}

	ACQDESCPOS Pos = 0;
	HACQDESC hAcqDesc = NULL;

	do
	{
		if ((iRet = Acquisition_GetNextSensor(&Pos, &hAcqDesc)) != HIS_ALL_OK)
			LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_GetNextSensor", iRet);
	} 
	while (Pos != 0);
	
	UINT nChannelType;
	int nChannelNr;
	
	if ((iRet = Acquisition_GetCommChannel(hAcqDesc, &nChannelType, &nChannelNr)) != HIS_ALL_OK) 
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_GetCommChannel", iRet);
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

	//��ȡ̽�������ͼ����
	LOG_INFO("channel type : %d  ChannelNr : %d", nChannelType, nChannelNr);
	
	switch (nChannelType) 
	{
	case HIS_BOARD_TYPE_ELTEC_XRD_FGE_Opto:
		LOG_INFO("%s%d", "HIS_BOARD_TYPE_ELTEC_XRD_FGE_Opto:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC_XRD_FGX:
		LOG_INFO("%s%d", "HIS_BOARD_TYPE_ELTEC_XRD_FGX:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC:
		LOG_INFO("%s%d", "HIS_BOARD_TYPE_ELTEC:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC_GbIF:
		LOG_INFO("%s%d", "HIS_BOARD_TYPE_ELTEC_GbIF:", nChannelType);
		break;
	case HIS_BOARD_TYPE_ELTEC_EMBEDDED:
		LOG_INFO("%s%d", "HIS_BOARD_TYPE_ELTEC_EMBEDDED:", nChannelType);
		break;
	default:
		LOG_INFO("%s%d", "Unknown ChanelType:", nChannelType);
		break;
	}
	//��ȡ̽��������
	if ((iRet = Acquisition_GetConfiguration(hAcqDesc, 0, &d_height, &d_width, 0,
											0, 0, 0, 0, 0, 0)) != HIS_ALL_OK) 
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_GetConfiguration", iRet);
		return false;
	}
	
	if ((iRet = Acquisition_SetCallbacksAndMessages(hAcqDesc, NULL, 0,
		0, ::OnEndPESiDetFrameCallback, ::OnEndPESiDetAcqCallback)) != HIS_ALL_OK)		//���òɼ��ص�����
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_SetCallbacksAndMessages", iRet);
		return false;
	}

	hPESiAcqDesc = hAcqDesc;
	return true;
}
void PESiPanel::OnEndPESiDetFrameCallback(HACQDESC hAcqDesc)
{
	if (d_frameCount == 0)
		d_copyBuffer = (unsigned char*)malloc(d_frameSize);

	memcpy(d_copyBuffer + d_frameSize * d_frameCount++, pPESiDetAcqBuffer, d_frameSize);

	if (d_frameCount == d_frames)
		d_imageQueue.push(d_copyBuffer);

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
bool PESiPanel::setSampleTime(int in_milliseconds)
{
	unsigned int nRet;

	if ((nRet = Acquisition_SetCameraMode(hPESiAcqDesc, d_sampleTime)) == HIS_ALL_OK)
	{
		LOG_INFO("�����ع�ʱ��:%d", d_sampleTime);
	}
	else 
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_SetCameraMode", nRet);
	}

	return true;
}
bool PESiPanel::setBinMode(BinMode in_binMode)
{
	unsigned int nRet;
	unsigned short binFmt;

	auto it = d_binModeName.find(in_binMode);
	binFmt = std::get<1>(it->second);

	if ((nRet = Acquisition_SetCameraBinningMode(hPESiAcqDesc, binFmt)) == HIS_ALL_OK)
	{
		LOG_INFO("���úϲ�ģʽ:%s", std::get<1>(it->second));
		d_binMode = in_binMode;
		return true;
	}
	else
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_SetCameraBinningMode", nRet);
		return false;
	}

}
bool PESiPanel::setSampleMode(SampleMode in_sampleMode)
{
	unsigned int nRet;
	QString errorMsg;
	//����̽����ΪDDD(Date Delivered on Demand)�޼�϶������ʽ
	if ((nRet = Acquisition_SetCameraTriggerMode(hPESiAcqDesc, 1)) == HIS_ALL_OK)
	{

		if ((nRet = Acquisition_SetFrameSyncTimeMode(hPESiAcqDesc,
			d_sampleTime, //0~7
			d_cycleTime)) == HIS_ALL_OK)
			LOG_INFO("�����ӳ�ʱ��:%d ms", d_cycleTime);
		else
		{
			LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_SetFrameSyncTimeMode", nRet);
			return false;
		}
		
		//�����ⴥ���źŸ�ʽ
		if ((nRet = Acquisition_SetTriggerOutSignalOptions(hPESiAcqDesc,
			4 /* 4 - DDD_Pulse*/,
			0, 0, 0, 0, 0,
			d_cycleTime,	//�ӳ�ʱ��
			0, 0)) == HIS_ALL_OK)
		{
			LOG_INFO("����TriggerOut�ӳ�:%d ms", d_cycleTime);
		}
		else 
		{
			LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_SetTriggerOutSignalOptions", nRet);
			return false;
		}

	}
	else 
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_SetCameraTriggerMode", nRet);
		return false;
	}

	return true;
}
bool PESiPanel::setGainFactor(int in_gainFactor)
{
	unsigned int nRet;
	
	if ((nRet = Acquisition_SetCameraGain(hPESiAcqDesc, d_gainFactor)) == HIS_ALL_OK)
	{
		LOG_INFO("����̽������:%d", d_gainFactor);
		return true;
	}
	else
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_SetCameraGain", nRet);
		return false;
	}
}
//TODO_DJ:������ʲɼ�������ڴ�ܴ����ڲɼ���ɻ���ֹͣ�ɼ������pPESiDetAcqBuffer
bool PESiPanel::beginAcquire(unsigned short d_quantity)
{
	unsigned int nRet;
	unsigned long dwDemoParam = ACQ_SNAP;

	if (Acquisition_SetAcqData(hPESiAcqDesc, (void*)&dwDemoParam) != HIS_ALL_OK)
	{
		LOG_INFO("Acquisition_SetAcqData ʧ�ܣ�");
		return false;
	}
	
	//����ɼ��ڴ�,���û�����

	if (d_frameSize != d_PESiDetBufferSize)
	{
		if (pPESiDetAcqBuffer != 0)
			SAFE_DELETE(pPESiDetAcqBuffer);

		pPESiDetAcqBuffer = (unsigned short*)malloc(d_frameSize);
	}
	
	nRet = Acquisition_DefineDestBuffers(hPESiAcqDesc, pPESiDetAcqBuffer, d_frames,
		d_height, d_width);

	if (nRet != HIS_ALL_OK)
	{
		LOG_ERROR("%s ʧ�ܣ������룺%d", "Acquisition_DefineDestBuffers", nRet);
		return false;
	}
	
	unsigned int bHisSeqFlag;
	
	if (d_PESiContinusSingleMode == PESICON_SINGLE_MODE::Continus)
		bHisSeqFlag = HIS_SEQ_CONTINUOUS;
	else if (d_PESiContinusSingleMode == PESICON_SINGLE_MODE::Single)
		bHisSeqFlag = HIS_SEQ_ONE_BUFFER;

	nRet = Acquisition_Acquire_Image(hPESiAcqDesc, d_frames, 0, bHisSeqFlag, 0, 0, 0);
	
	if (nRet != HIS_ALL_OK)
	{
		LOG_ERROR("Acquisition_Acquire_Imageʧ�ܣ�������%d", nRet);
		return false;
	}

	if (d_sampleMode == SampleMode::softTrigger) {
		nRet = Acquisition_SetFrameSync(hPESiAcqDesc);
		
		if (nRet != HIS_ALL_OK)
		{
			LOG_ERROR("Acquisition_SetFrameSyncʧ�ܣ�������%d", nRet);
			return false;
		}
	}

	return true;
}
void PESiPanel::stopAcquire()
{
	Acquisition_Abort(hPESiAcqDesc);
	d_imageQueue.clear();
}
