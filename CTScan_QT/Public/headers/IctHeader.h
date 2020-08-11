// -----------------------------------------------------------------------------
// ��ҵCT���ݲɼ�/�����ļ�ͷ����(V2.2)
// �����ѧICT�о�����,���ӿƼ��ֹ�˾.								2005.01.19
// V2.3�汾��ʼ��Ϊ�������Ƽ��ɷ����޹�˾�����ļ���ʽ				2010.05.19
// ������άCTɨ�����												2006.04.20

// 2007.07.13�޸�����:
// 1. ��SpaceBetweenLayer(���CT���)��LayerThicknessOfDR(DR�ֲ���)�ϲ�ΪLayerThickness(�ֲ���)
// 2. ����TotalLayers2(�ڶ���DRɨ���ܲ���)
// 3. ����FirstSectStartCoordinateOfDR(��һ��DRɨ����ʼ����X1),SecondSectStartCoordinateOfDR(�ڶ���DRɨ����ʼ����X3)

// 2007.07.26�޸�����:
// 1. �����ؽ�����

// 2007.10.04�޸�����:
// 1. ��LayerThickness�����޸�ΪSpaceBetweenLayer
// 2. ����2��ɨ���ؽ�����: NumberOfGraduationOfCt2,SerialOfGraduationOfCt2
// 3. ����3��ɨ����ʼ�ֶȺ�: graduationBase
// 3. ��������ƽ�淽������̽�������SerialNo1OfMiddleHorizontalDetector/SerialNo2OfMiddleHorizontalDetector
//    ��������У��ʱȷ���м�̽����(������������ͨ��̽����ʱ���1/2��ͬ;
//    ������������ͨ������̽�����м�ʱ,���1/2���1)

// 2008.04.24�޸�����:
//	 ICT_HEADER ��ΪICT_HEADER21��ʾ2.1�汾��ʽ, ��ӦDATAFORMAT21, ����������Ϊ WORD
//   ����ICT_HEADER22��ʾ2.2�汾��ʽ, ��ӦDATAFORMAT22, ������������Ϊ DWORD
//   ɨ�����������NumberOfTable��ʾɨ��ʱʹ�õ�ת̨����

// 2008.10.06���Ӳ��Թ�����Ϣ:
// 1. ���ӹ��������ߺ͹�������������
// 2. Ϊ��ӦDRϵͳ����˫����ģʽ, ���ӹ���2����,���,������,����������Ϣ; 
//   ԭ���Ĺ�������,��ż������Ĺ��������ߺ͹���������������Ϊ����1���й���Ϣ.

// 2009.06.17�޸�����:
// 1. ��ԭCTɨ����ʼ��λ��Azimuth, ��DRɨ�跽ʽ�¶���ΪDRɨ��Ƕ�

// 2010.05.19�޸�:
// 1. �汾�Ŷ���ΪV2.3
// 2. ������ƽ��ͼ��ߴ����Pixels�޸�Ϊֱ�ӱ�ʾ���ظ���
// 3. ���Ӣ��ɨ�迪ʼ/����̽�������BeginSerialNoOfCt2Detector/EndSerialNoOfCt2Detector
// 4. V2.3�в�ʹ��Ԥ��ͬ��������SetupSynchPulseNumber,���ֶα���
// 5. V2.3�в�ʹ�õڶ���DRɨ���ܲ���TotalLayers2,���ֶα���
// 6. V2.3�в�ʹ�õڶ���DRɨ����ʼ����SecondSectStartCoordinateOfDR,���ֶα���

// 2011.12.26�޸�:
// 1. �ڽṹSCANPARAMETER�����Ӵ��ӳ�ɨ���ת����ƫ�ò���LargeViewCenterOffset

// 2012.07.12�޸�:
// 1. �ڽṹSCANPARAMETER�����ӹ���ƫ�ڽǶ�DeflectionAngle

// 2013.03.07�޸�:
// 1. �ڽṹSCANPARAMETER������DRɨ���1��ɨ�跽�����DR1stScanDir(0-����, 1-����), ������������

// 2020.07.23�޸�
// 1.���ɨ������������������ɨ��
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#ifndef __ICTHEADER_H
#define __ICTHEADER_H

#ifndef	ULONG
#define	ULONG	unsigned long
#endif

#ifndef	DWORD
#define	DWORD	unsigned long
#endif

#ifndef	WORD
#define	WORD	unsigned short
#endif

#ifndef	BYTE
#define	BYTE	unsigned char
#endif

#define	MainVersion21	2											//�������汾��
#define	SubVersion21	1											//����ΰ汾��
#define	MainVersion22	2											//�������汾��
#define	SubVersion22	2											//����ΰ汾��
#define	MainVersion23	2											//�������汾��
#define	SubVersion23	3											//����ΰ汾��

// ̽�����ṹ��ʽ������
#ifndef	_DETECTOR_STRUCT_NAME
#define	_DETECTOR_STRUCT_NAME
enum{
	ARC_DETECTOR	=	0,											//����̽����
	LINE_DETECTOR,													//ֱ��̽����
	PANEL_DETECTOR													//ƽ��̽����
};
#endif

// ɨ�跽ʽ: 0-���ɨ��,1-���ɨ��,2-���ɨ��,3-DRɨ�裬4-�ֲ�ɨ��,5-����ɨ��,6-׶��ɨ��,7-׶������ɨ��
// ɨ��ģʽ����������
#ifndef	_SCAN_MODE_NAME
#define	_SCAN_MODE_NAME
enum{
	NO_SCAN		=	-1,												//��ɨ�����
	CT1_SCAN,														//���ɨ�� 0
	CT2_SCAN,														//���ɨ�� 1 
	CT3_SCAN,														//���ɨ�� 2
	DR_SCAN,														//DRɨ��   3
	LOCAL_SCAN,														//�ֲ�ɨ�� 4
	HELIX_SCAN,														//����ɨ�� 5
	CONE_SCAN,														//׶��ɨ�� 6
	CONEHELIX_SCAN,													//׶������ɨ�� 7
	BKG_SCAN,														//����У��ɨ��(�̶��ɼ�512���ֶ�) 8
	AIR_SCAN,														//����У��ɨ��(�̶��ɼ�512���ֶ�) 9
	CAL_LAYER_ZERO_SCAN,											//�궨�ֲ����ɨ��(�̶��ɼ�400��) 10
	CAL_CENTER_SCAN,												//�궨��ת����ɨ�� 11
	LARGE_VIEW_SCAN,												//���ӳ�ɨ��(��ת����ƫ��ɨ��) 12
	_MAX_SCANMODE_ITEM
};
#endif

// ������������
enum{
	CHARDATA	=	1,												//�ַ���
	INTDATA,														//����
	LONGDATA,														//������
	FLOATDATA,														//������
	DOUBLEDATA														//˫������
};

// ����ɨ�跽ʽ
enum
{
	MIDFAN_360 = 0,     // ������ 360��
	MIDFAN_180,			// ������ 180��
	MIDFAN_180_INTER,   // ������ 180����
	INERFAN_360         // ���� 360��
};

#define	PWDLEN		128												//�������봮����

//****** ����,ʱ����Ϣ 20 bytes *********************************************************
typedef struct  _DATE_TIME{
	char	Date[11];					     						//��ʽ:2003/07/10,��ASCIZ����
	char	Time[9];					     						//��ʽ:16:35:12,��ASCIZ����
}DATE_TIME;

//****** ����������Ϣ 256 bytes *********************************************************
typedef	struct	_TASKMESSAGE{
	DATE_TIME DateTime;												//�������ڼ�ʱ��(20�ֽ�:2003/07/10 16:35:12 )
	char	Number[32];												//����������(32�ֽ�)
	char	Name[64];												//������������(64�ֽ�),��ʽ:������λ��
	char	Toastmaster[16];										//����������(16�ֽ�),��ʽ:������λ��
	char	SubmitUnit[64];											//�ͼ쵥λ(64�ֽ�)

	BYTE	reserved[60];											//�����ֽ�
}TASKMESSAGE;

//****** ���Թ�����Ϣ 640 bytes *********************************************************
//V2.3��ǰ�汾ʹ��
typedef	struct	_WORKPIECEMESSAGE{
	char	WorkpieceName[32];										//����1����, ��ʽ:������λ��
	char	WorkpieceSort[32];										//����1���, ��ʽ:������λ��
	char	WorkpieceNumber[32];									//����1���, ��ʽ:������λ��
	char	WorkpieceModel[32];										//����1�ͺ�, ��ʽ:������λ��
	char	WorkpieceBatch[32];										//����1����, ��ʽ:������λ��
	char	WorkpieceShellMaterial[64];  							//����1�������, ��ʽ:������λ��
	char	WorkpieceFillMaterial[64];								//����1������, ��ʽ:������λ��
	char	WorkpieceManufacturer[64]; 								//����1���쵥λ, ��ʽ:������λ��
	char	TestPosition[32];										//����1��ⲿλ, ��ʽ:������λ��
	char	ZeroPointDefineAlongAxis[32];							//����1����������ֶ���, ��ʽ:������λ��
	char	ZeroPointDefineAlongCircle[64];							//����1Բ��������ֶ���, ��ʽ:������λ��
	float	WorkpieceZeroPointAlongAxis;							//����1�����������(�����ϵͳ�������)
	float	WorkpieceMaxDiameter;									//����1���ֱ��, ��λ:mm
	float	WorkpieceDiameter;										//����1��ⲿλ�⾶, ��λ:mm
	float	WorkpieceLength;										//����1����, ��λ:mm
	float	WorkpieceBeginCoordinate;								//����1��ʼ����ֵ
	float	WorkpieceEndCoordinate;									//����1��������ֵ
	float	WorkpieceWeight;										//����1����, ��λ:kg
	float	MaxDensity;												//����1����ܶ�, ��λ:g/cm3

	//2008.10.6����
	char	WorkpieceProductLine[16];								//����1������(¯��..)
	char	WorkpieceMakeDate[16];									//����1��������
	char	Workpiece2Name[16];										//����2����, ��ʽ:������λ��
	char	Workpiece2Number[16];									//����2���, ��ʽ:������λ��
	char	Workpiece2ProductLine[16];								//����2���쵥λ/������(¯��..)
	char	Workpiece2MakeDate[16];									//����2��������

	BYTE	reserved[32];											//�����ֽ�
}WORKPIECEMESSAGE;

//****** ���Թ�����Ϣ 640 bytes *********************************************************
//V2.3�汾ʹ��
typedef	struct	_WORKPIECEMESSAGE23{
	char	WorkpieceName[32];										//����1����
	char	WorkpieceModel[32];										//����1�ͺ�
	char	WorkpieceNumber[32];									//����1���
	char	WorkpieceBatch[32];										//����1����
	char	WorkpieceShellMaterial[32];  							//����1�������
	char	WorkpieceFillMaterial[32];								//����1������
	char	WorkpieceManufacturer[32]; 								//����1���쵥λ/������(¯��..)
	char	WorkpieceMakeDate[16];									//����1��������
	char	WorkpieceTestPosition[32];								//����1��ⲿλ

	char	WorkpieceName2[32];										//����2����
	char	WorkpieceModel2[32];									//����2�ͺ�
	char	WorkpieceNumber2[32];									//����2���
	char	WorkpieceBatch2[32];									//����2����
	char	WorkpieceShellMaterial2[32];  							//����2�������
	char	WorkpieceFillMaterial2[32];								//����2������
	char	WorkpieceManufacturer2[32]; 							//����2���쵥λ/������(¯��..)
	char	WorkpieceMakeDate2[16];									//����2��������
	char	WorkpieceTestPosition2[32];								//����2��ⲿλ

	BYTE	reserved[96];											//�����ֽ�
}WORKPIECEMESSAGE23;

//****** ɨ�������Ϣ 380 bytes **********************************************************
typedef	struct	_SCANPARAMETER23{
	WORD	ScanMode;												// ɨ�跽ʽ: 0-���ɨ��,1-���ɨ��,2-���ɨ��,3-DRɨ�裬4-�ֲ�ɨ��,5-����ɨ��,6-׶��ɨ��
	
	// 2��ɨ��ģʽ:
	// 0 �� ������ 360��
	// 1 :  ������ 180��,
	// 2 :  ������ 180�㣬���
	// 3 :  ���� 360��
	WORD	Ct2ScanMode;
																
	// ���ɨ��ʱ,˫���ʾƽ��Ϊ������������ɼ�����
	// ���ɨ��ʱ,˫���ʾ���������ֵ�����෴
	// DRɨ��ʱ,˫���ʾ�ֲ�Ϊ������������ɼ�����
	WORD	ScanDirectionMode;										//ɨ�跽��: 0-����,1-˫��
	

	WORD	DataTransferMode;										//���ݴ��ͷ�ʽ: 0-���崫��, 1-��ɨ��ߴ���

	WORD	Pixels;													//V2.3�ж���Ϊ����ƽ��ͼ�����ظ���(ͶӰ��), ȡ��V2.2�д��ű�ʾ��ʽ
	float	ViewDiameter;											//�ӳ�ֱ��(mm)
	float	RadialDistanceInLocal;									//�ֲ�ɨ��ʱɨ���ӳ���������ת���ľ���(mm)
	float	AngleInLocal;											//�ֲ�ɨ��ʱ��ת������ɨ���ӳ���������������ƽ����������ʼ�н�(��)

	WORD	CollimationSize;										//׼ֱ���ߴ����:0,1,2...   ׼ֱ�����
	float	LayerThickness;											//�ϲ���(mm)(׼ֱ���߶�)
	WORD	DetectorStyle;											//��ǰʹ�õ�̽�����ṹ(0-����, 1-ֱ��, 2-ƽ��)
	WORD	NumberOfSystemHorizontalDetector;						//����ƽ�淽��ϵͳ̽������(�˲���Ϊ̽��������)
	WORD	NumberOfValidHorizontalDetector;						//����ƽ�淽����Ч̽������(�ӳ���Χ�ڵ�̽��������)
	WORD	SerialNo1OfMiddleHorizontalDetector;					//����ƽ�淽������̽�������1(����/ֱ��̽����, ��0��ʼ����)
	WORD	SerialNo2OfMiddleHorizontalDetector;					//����ƽ�淽������̽�������2(����/ֱ��̽����, ��0��ʼ����)
	WORD	NumberofSystemVerticalDetector;							//����ƽ�洹ֱ����ϵͳ̽������(ƽ��̽����ר��, �˲���Ϊ̽��������)
	WORD	NumberofValidVerticalDetector;							//����ƽ�洹ֱ������Ч̽������(ƽ��̽����ר��)
	float	SpaceOfHorizontalDetector;								//����ƽ�淽��̽�������(mm, ƽ��̽����ר��)
	float	SpaceOfVerticalDetector;								//����ƽ�洹ֱ����̽�������(mm, ƽ��̽����ר��)
	float	HorizontalSectorAngle;									//����ƽ�淽���Ƚ�(��,��ϵͳ̽���������, ����Ϊ����̽����������֮��н�)
	float	VerticalSectorAngle;									//����ƽ�洹ֱ�����Ƚ�(��,��ϵͳ̽���������, ����Ϊ����̽����������֮��н�)
	float	RadialPosition;											//���㵽��ת���ľ���(����λ��)(mm)    
	float	SourceDetectorDistance;									//���㵽̽��������(mm)
	float	Azimuth;												//CTɨ��ʱ�ֶ���ʼ��λ��(��),��DRɨ��Ƕ�
	WORD	GraduationDirection;									//�ֶȷ���:N_DIR-˳ʱ��(������),P_DIR-��ʱ��(������)
	WORD	NumberOfGraduation;										//�ֶȴ���(ָ���ݾࡢ׶��ɨ�衢���άCT��תһ�ֶܷ���)
	WORD	InterpolationFlag;										//��ֵ����־:0-��׼��ֵ,1-��ֵ����1
	WORD	NumberOfInterpolation;									//��ֵ����(��׼��ֵ����)
	WORD	NumberOfTranslation;									//ƽ�Ʋ�������
	WORD	DelaminationMode;										//CT�ֲ㷽ʽ:0-�Ȳ��,1-���Ȳ��,2-��ǰ���
	float	HelixScanPitch;											//����ɨ���ݾ��С,��λ:mm
	WORD	TotalLayers;											//CTɨ���ܲ������һ��DRɨ���ܲ���,��Χ:1-9999
	WORD	TotalLayers2;											//�ڶ���DRɨ���ܲ���,��Χ:0-9999,ֻ��һ��DRɨ��ʱ��д0. V2.3�汾����
	float	CurrentLayerCoordinate;									//��ǰ������,��λ:mm
	float	SpaceBetweenLayer;										//CT���/DR�ֲ���(����,����DRɨ��ʱÿ�β�����ͬ),��λ:mm
	float	FirstSectStartCoordinateOfDR;							//��һ��DRɨ����ʼ����X1, ��λ:mm
	float	SecondSectStartCoordinateOfDR;							//�ڶ���DRɨ����ʼ����X3, ��λ:mm
	WORD	SetupSynchPulseNumber;									//Ԥ��ͬ��������(���������, ��V2.3�汾�в���ʹ��)
	float	SampleTime;												//����ʱ��, ��λ:��
	WORD	UsedScanTime;											//ʵ��ɨ��ʱ��(s)
	float	TemperatureValue;										//̽��ϵͳ�����¶�ֵ(��)
	char	FilenameTemperature[32];								//̽��ϵͳʵʱ�¶ȼ�¼�ļ���
	char	FilenameOfCTdata[32];									//CT�����ļ���,��Windows�ļ���������ַ���(���ڴ��CT��DR��׶��ɨ������)
	char	FilenameOf2CTdata[32];									//������ݱ߲ɱߴ��ļ���(�������ļ������ϱ��(00-31))
	char	FilenameOfPictureData[32];								//ͼ�������ļ���, ��Windows�ļ���������ַ���
	WORD	NumberOfTable;											//ɨ����ʹ�õ�ת̨����(ȱʡΪ1, 2��ʾ����ת̨)
	
	WORD	BeginSerialNoOfCt2Detector;								//���ɨ�迪ʼ̽�������(��0��ʼ), V2.3������
	WORD	EndSerialNoOfCt2Detector;								//���ɨ�����̽�������(��0��ʼ), V2.3������
    //2013.4.1
	WORD	DR1stScanDir;											//DRɨ���1��ɨ�跽��(0-����, 1-����)
	//Ϊ�˱��ֱ���ʱ����
	BYTE	reserved1[2];											//�����ֽ�
	float	LargeViewCenterOffset;									//���ӳ�ɨ���ת����ƫ��(mm)
	float	DeflectionAngle;										//ƫ�ڽǶ�(��)	
	BYTE	reserved2[102];											//�����ֽ�

}SCANPARAMETER23;
//˵��:
//(1) ����ƽ�淽�򵥸�̽�����н�Ah=����ƽ�淽���Ƚ�/(����ƽ�淽��ϵͳ̽������-1)
//(2) ����ƽ�洹ֱ���򵥸�̽�����н�Av=����ƽ�洹ֱ�����Ƚ�/(����ƽ�洹ֱ����ϵͳ̽������-1)
//(3) ���ɨ��ʱ, ����ƽ�淽����Ч̽������Nv���ӳ�ֱ��D�ļ��㷽��(D���ȴӽ�������):
//		1) ת̨���Ĵ�̽������Ч���t=����ƽ�淽�򵥸�̽�����н�Ah*���㵽��ת���ľ���Q
//		2) Nv = UINT(D/t)		UINT(.)Ϊ����ȡ������.
//			̽����������������ʱ(SerialNo1OfMiddleHorizontalDetector==SerialNo2OfMiddleHorizontalDetector), 
//			���յ���Ч̽������ȡ��С��Nv������;����ȡż��.
//		3) �����Nv���D��������: 
//			D = 2*Q*sin[(Nv-1)/2*Ah]
//(4) ��׼��ֵ��=UINT(����ƽ��ͼ�����ظ���Pixels/����ƽ�淽��ϵͳ̽������Na), UINT(.)Ϊ����ȡ������.
//(5) ���þ�ϸɨ��ʱ, ����ƽ��ͼ�����ظ���Pixels(��ͶӰ��)�ӱ�, ��ֵ������(4)����
//(6) ���ɨ��ʹ�õ�̽������N2=���ɨ�����̽������� - ���ɨ�迪ʼ̽������� + 1
//(7) ���ɨ���Ƚ�=���ɨ��ʹ�õ�̽������N2*����ƽ�淽�򵥸�̽�����н�Ah
//����ȡ������y=UINT(x)����:
//		if INT(x)==x
//			y = x;
//		else
//			y = INT(x)+1
//****** ɨ�������Ϣ 380 bytes **********************************************************
typedef	struct	_SCANPARAMETER22{
	WORD	ScanMode;										//ɨ�跽ʽ: 0-���ɨ��,1-���ɨ��,2-���ɨ��,3-DRɨ�裬4-�ֲ�ɨ��,5-����ɨ��,6-׶��ɨ��
	WORD	Ct2ScanMode;									//2��ɨ��ģʽ:  0-360��,1-180��,2-180����
		//���ɨ��ʱ,˫���ʾƽ��Ϊ������������ɼ�����
		//���ɨ��ʱ,˫���ʾ���������ֵ�����෴
		//DRɨ��ʱ,˫���ʾ�ֲ�Ϊ������������ɼ�����
	WORD	ScanDirectionMode;							//ɨ�跽��: 0-����,1-˫��
	WORD	DataTransferMode;								//���ݴ��ͷ�ʽ: 0-���崫��, 1-��ɨ��ߴ���

	WORD	Pixels;											//ˮƽͼ��ߴ����: 0-64,1-128,2-256,3-512,4-1024,5-2048,6-4096
	float	ViewDiameter;									//�ӳ�ֱ��(mm)
	float	RadialDistanceInLocal;						//�ֲ�ɨ��ʱɨ���ӳ���������ת���ľ���(mm)
	float	AngleInLocal;									//�ֲ�ɨ��ʱ��ת������ɨ���ӳ�����������ˮƽ��������ʼ�н�(��)

	WORD	CollimationSize;								//׼ֱ���ߴ����:0,1,2...   ׼ֱ�����
	float CollimationThickness;						//׼ֱ���߶�/�ϲ���(mm)
	WORD  DetectorStyle;                         //��ǰʹ�õ�̽�����ṹ(0-����, 1-ֱ��, 2-ƽ��)
	WORD	NumberOfSystemHorizontalDetector;		//ˮƽ����ϵͳ̽ͷ��(����, ����/ֱ��̽����)
	WORD	NumberOfValidHorizontalDetector;			//ˮƽ������Ч̽ͷ��(����, ����/ֱ��̽����)
	WORD	SerialNo1OfMiddleHorizontalDetector;	//ˮƽ��������̽�������1(����, ����/ֱ��̽����, ��0��ʼ����)
	WORD	SerialNo2OfMiddleHorizontalDetector;	//ˮƽ��������̽�������2(����, ����/ֱ��̽����, ��0��ʼ����)
	WORD  NumberofSystemVerticalDetector;			//��ֱ����ϵͳ̽������(����)
	WORD  NumberofValidVerticalDetector;			//��ֱ������Ч̽������(����)
	float	SpaceOfHorizontalDetector;					//ˮƽ������Ч̽�������(mm)
	float	SpaceOfVerticalDetector;					//��ֱ������Ч̽�������(mm)(����ɨ�����̽�����ϲ�ʹ�������Ϊ����������������̽��������)
	float	HorizontalSectorAngle;						//ˮƽ������Ч�Ƚ�ֵ(��)	
	float VerticalSectorAngle;							//��ֱ������Ч�Ƚ�ֵ(��)
	float	RadialPosition;								//���㵽��ת���ľ���(����λ��)(mm)    
	float SourceDetectorDistance;						//���㵽̽��������(mm)
	float	Azimuth;											//ɨ��ʱ�ֶ���ʼ��λ��(��)
	WORD	GraduationDirection;							//�ֶȷ���:0-˳ʱ��,1-��ʱ��(������)
	WORD	NumberOfGraduation;							//�ֶȴ���(ָ���ݾࡢ׶��ɨ�衢���άCT��תһ�ֶܷ���)
	WORD	InterpolationFlag;							//��ֵ����־:0-��׼��ֵ,1-��ֵ����1
	WORD	NumberOfInterpolation;						//��ֵ����(��׼��ֵ����)
	WORD	NumberOfTranslation;							//ƽ�Ʋ�������
	WORD	DelaminationMode;								//CT�ֲ㷽ʽ:0-�Ȳ��,1-���Ȳ��,2-��ǰ���
	float HelicalScanPitch;								//����ɨ���ݾ��С,��λ:mm
	WORD	TotalLayers;									//CTɨ���ܲ������һ��DRɨ���ܲ���,��Χ:1-9999
	WORD	TotalLayers2;									//�ڶ���DRɨ���ܲ���,��Χ:0-9999,ֻ��һ��DRɨ��ʱ��д0
	float	CurrentLayerCoordinate;						//��ǰ������,��λ:mm
	float	SpaceBetweenLayer;							//CT���/DR�ֲ���(����,����DRɨ��ʱÿ�β�����ͬ),��λ:mm
	float	FirstSectStartCoordinateOfDR;				//��һ��DRɨ����ʼ����X1, ��λ:mm
	float	SecondSectStartCoordinateOfDR;			//�ڶ���DRɨ����ʼ����X3, ��λ:mm
	WORD	SetupSynchPulseNumber;						//Ԥ��ͬ��������(���������)
	float	SampleTime;										//��������ʱ��, ��λ:��
	WORD	UsedScanTime;									//ʵ��ɨ��ʱ��(s)
	float	TemputreValue;									//̽��ϵͳ�����¶�ֵ(��)
	char	FilenameTemperature[32];					//̽��ϵͳʵʱ�¶ȼ�¼�ļ���
	char	FilenameOfCTdata[32];						//CT�����ļ���,��Windows�ļ���������ַ���(���ڴ��CT��DR��׶��ɨ������)
	char	FilenameOf2CTdata[32];						//������ݱ߲ɱߴ��ļ���(�������ļ������ϱ��(00-31))
	char	FilenameOfPictureData[32];					//ͼ�������ļ���, ��Windows�ļ���������ַ���
	WORD	NumberOfTable;									//ɨ����ʹ�õ�ת̨����(ȱʡΪ1, 2��ʾ����ת̨)

	BYTE	reserved[122];									//�����ֽ�
}SCANPARAMETER22;
//****** ϵͳ������Ϣ 192 bytes ***********************************************************
typedef	struct	_SYSTEMPARAMETER{
	char	ModelOfCT[32];											//CT�豸�ͺ�
	WORD	RaySort;												//����Դ����:0-X���,1-������,2-��60,3-�137
	float	RayEngery;												//��������(MeV)
	float	RayDosage;												//���߼�����(cGy/min/m)
	WORD	SynchFrequency;											//ͬ��Ƶ��(Hz)
	WORD	AmplifyMultiple;										//�����Ŵ���
	WORD	IntegralTime;											//��������ʱ��(us)

	BYTE	reserved[140];											//�����ֽ�
}SYSTEMPARAMETER;

//****** II��CT�ؽ���Ϣ 128 bytes *********************************************************
typedef	struct	_RECONSTRUCTMESSAGE{
	BYTE	Ct2ReconstructPara[64];									//2��CTɨ��ֶ��ؽ���־(ÿ���ֶ�1�ֽ�,0-�÷ֶ�δ�ؽ�,1-�÷ֶ����ؽ�)
	float	Zmax;													//FDK�����ؽ���
	float	Zmin;													//FDK�����ؽ���
	float	RotationAngle;											//�����ؽ�ͼ����ת�Ƕ�
	float	PixelMax;												//ԭʼ�ؽ�ͼ�����ֵ
	float	PixelMin;												//ԭʼ�ؽ�ͼ����Сֵ
	WORD	VolumeLayer;											//��ά�ؽ�����
	WORD	VolumeWidth;											//��ά�ؽ����
	float	SpaceBetweenPixel;										//����֮����
	BYTE	NumberOfGraduationOfCt2;								//�ֶ�����(2��CTɨ��, 2007.10.04����)
	BYTE	SerialOfGraduationOfCt2;								//�ֶ����(2��CTɨ��, 2007.10.04����)
	BYTE	reserved[32];											//�����ֽ�
}RECONSTRUCTMESSAGE;

//****** ͼ��ʶ����Ϣ 64 bytes ***********************************************************
typedef	struct	_IDENTIFYMESSAGE{
	WORD	DefectMode;												//ȱ������: 0-װ��,1-������,2-����(����,�ѷ�,��ճ),Ĭ��Ϊ0
	char	NumberofTemplate[32];									//ʶ��ģ����(�ַ���), ���뷽ʽ����word��ӡҳ���ʽ; ����,1-3��ʾģ���Ŵ�1��3; 1,4,6,8��ʾʶ��ģ��ֱ�Ϊ1,4,6,8
	BYTE	reserved[30];											//�����ֽ�
}IDENTIFYMESSAGE;

//****** ���ݸ�ʽ��Ϣ 32 bytes  (V2.1�汾��)***********************************************************
typedef	struct	_DATAFORMAT21{
	WORD	DataType;												//���ݴ洢����: char=01,int=02,unsigned long=03,float=04,double=05
	WORD	TotalLines;												//����������  
	WORD	dataColAtRow;											//ÿ�����ݸ���(��������������)
	WORD	appendColAtRow;											//ÿ����ǰ���������ݸ���
	WORD	graduationBase;											//3��ɨ��ֶ���ʼ��(2007.10.04����)
	BYTE	reserved[22];											//�����ֽ�
}DATAFORMAT21;

#pragma pack(1)														//���ֽڶ�������
//****** ���ݸ�ʽ��Ϣ 32 bytes  (V2.2�汾��)***********************************************************
typedef	struct	_DATAFORMAT{
	WORD	DataType;												//���ݴ洢����: char=01,int=02,unsigned long=03,float=04,double=05
	DWORD	TotalLines;												//����������  .2008-01-23��WORD��ΪDWORD,ͬʱ�汾�Ŵ�V2.1 ��ΪV2.2
	WORD	dataColAtRow;											//ÿ�����ݸ���(��������������)
	WORD	appendColAtRow;											//ÿ����ǰ���������ݸ���
	WORD	graduationBase;											//3��ɨ��ֶ���ʼ��(2007.10.04����)
	BYTE	reserved[20];											//�����ֽ�
}DATAFORMAT;
//�Ǳ�׼V22���ݸ�ʽ
typedef	struct	_X22DATAFORMAT{
	WORD	DataType;												//���ݴ洢����: char=01,int=02,unsigned long=03,float=04,double=05
	DWORD	TotalLines;												//����������  .2008-01-23��RORD��ΪDWORD,ͬʱ�汾�Ŵ�V2.1 ��ΪV2.2
	WORD	dataColAtRow;											//ÿ�����ݸ���(��������������)
	WORD	appendColAtRow;											//ÿ����ǰ���������ݸ���
	WORD	graduationBase;											//3��ɨ��ֶ���ʼ��(2007.10.04����)
	BYTE	reserved[20];											//�����ֽ�
}X22DATAFORMAT;
#pragma pack(8)														//��ȱʡֵ��������

//****** �����ֽڳ��� *******************************************************************
#define	RESERVEDBYTES	2048-4-2-PWDLEN-sizeof(TASKMESSAGE)-sizeof(WORKPIECEMESSAGE)-sizeof(SCANPARAMETER22)-sizeof(SYSTEMPARAMETER)-sizeof(RECONSTRUCTMESSAGE)-sizeof(IDENTIFYMESSAGE)-sizeof(DATAFORMAT)

//****** ͷ�ļ���Ϣ(V2.1�汾ʹ��) *********************************************************************
typedef	struct _ICT_HEADER21{
	BYTE				MainVersion;								//�汾��ʶ(���汾��: 0x02)
	BYTE				SubVersion;									//�汾��ʶ(�ΰ汾��: 0x01)
	BYTE				reserved1[2];								//����
	TASKMESSAGE			Task;										//����������Ϣ
	WORKPIECEMESSAGE	Workpiece;									//���Թ�����Ϣ
	SCANPARAMETER22		ScanParameter;								//ɨ�����
	SYSTEMPARAMETER		SystemParameter;							//ϵͳ����
	RECONSTRUCTMESSAGE	ReconstructParameter;						//�ؽ�����
	IDENTIFYMESSAGE		IdentifyMessage;							//ͼ��ʶ����Ϣ
	DATAFORMAT21		DataFormat;									//���ݸ�ʽ
	BYTE	       		reserved2[RESERVEDBYTES];					//����(316)
	WORD				SizeofHeader;								//�ļ�ͷ�ߴ�: >2048(�ļ�ͷ�ߴ�Ϊ�������)
	BYTE				Password[PWDLEN];							//�����ַ���
}ICT_HEADER21;


//****** ͷ�ļ���Ϣ (V2.2�汾ʹ��)*********************************************************************
typedef	struct _ICT_HEADER22{
	BYTE				MainVersion;								//�汾��ʶ(���汾��: 0x02)
	BYTE				SubVersion;									//�汾��ʶ(�ΰ汾��: 0x02)
	BYTE				reserved1[2];								//����
	TASKMESSAGE			Task;										//����������Ϣ
	WORKPIECEMESSAGE	Workpiece;									//���Թ�����Ϣ
	SCANPARAMETER22		ScanParameter;								//ɨ�����
	SYSTEMPARAMETER		SystemParameter;							//ϵͳ����
	RECONSTRUCTMESSAGE	ReconstructParameter;						//�ؽ�����
	IDENTIFYMESSAGE		IdentifyMessage;							//ͼ��ʶ����Ϣ
	DATAFORMAT			DataFormat;									//���ݸ�ʽ
	BYTE	       		reserved2[RESERVEDBYTES];					//����(316)
	WORD				SizeofHeader;								//�ļ�ͷ�ߴ�: >2048(�ļ�ͷ�ߴ�Ϊ�������)
	BYTE				Password[PWDLEN];							//�����ַ���
}ICT_HEADER22;

//****** �����ֽڳ��� *******************************************************************
#define	RESERVEDBYTES23	2048-4-2-PWDLEN-sizeof(TASKMESSAGE)-sizeof(WORKPIECEMESSAGE23)-sizeof(SCANPARAMETER)-sizeof(SYSTEMPARAMETER)-sizeof(RECONSTRUCTMESSAGE)-sizeof(IDENTIFYMESSAGE)-sizeof(DATAFORMAT)
//****** ͷ�ļ���Ϣ (V2.3�汾ʹ��)*********************************************************************
typedef	struct _ICT_HEADER23{
	BYTE				MainVersion;								//�汾��ʶ(���汾��: 0x02)
	BYTE				SubVersion;									//�汾��ʶ(�ΰ汾��: 0x03)
	BYTE				reserved1[2];								//����
	TASKMESSAGE			Task;										//����������Ϣ
	WORKPIECEMESSAGE23	Workpiece;									//���Թ�����Ϣ
	SCANPARAMETER23		ScanParameter;								//ɨ�����
	SYSTEMPARAMETER		SystemParameter;							//ϵͳ����
	RECONSTRUCTMESSAGE	ReconstructParameter;						//�ؽ�����
	IDENTIFYMESSAGE		IdentifyMessage;							//ͼ��ʶ����Ϣ
	DATAFORMAT			DataFormat;									//���ݸ�ʽ
	BYTE	       		reserved2[RESERVEDBYTES];					//����(316)
	WORD				SizeofHeader;								//�ļ�ͷ�ߴ�: >2048(�ļ�ͷ�ߴ�Ϊ�������)
	BYTE				Password[PWDLEN];							//�����ַ���
}ICT_HEADER23;

//****** ͷ�ļ���Ϣ (V2.2�汾ʹ��---�Ǳ�׼)*********************************************************************
typedef	struct _X22ICT_HEADER{
	BYTE				MainVersion;								//�汾��ʶ(���汾��: 0x02)
	BYTE				SubVersion;									//�汾��ʶ(�ΰ汾��: 0x02)
	BYTE				reserved1[2];								//����
	TASKMESSAGE			Task;										//����������Ϣ
	WORKPIECEMESSAGE	Workpiece;									//���Թ�����Ϣ
	SCANPARAMETER22		ScanParameter;								//ɨ�����
	SYSTEMPARAMETER		SystemParameter;							//ϵͳ����
	RECONSTRUCTMESSAGE	ReconstructParameter;						//�ؽ�����
	IDENTIFYMESSAGE		IdentifyMessage;							//ͼ��ʶ����Ϣ
	X22DATAFORMAT		DataFormat;									//���ݸ�ʽ
	BYTE	       		reserved2[RESERVEDBYTES+sizeof(DATAFORMAT)-sizeof(X22DATAFORMAT)];//����(316)
	WORD				SizeofHeader;								//�ļ�ͷ�ߴ�: >2048(�ļ�ͷ�ߴ�Ϊ�������)
	BYTE				Password[PWDLEN];							//�����ַ���
}X22ICT_HEADER;

//����CTɨ�蹤��ʵ�ʸ߶� = ɨ���ܲ���*�ݾ�
//�ļ�ͷ֮�������к��е�˳�����δ������
//ϵͳ�ṩ���ɸ���̬�⺯����ɸ�������Ϣ�ļ��ܺͽ���
#endif
