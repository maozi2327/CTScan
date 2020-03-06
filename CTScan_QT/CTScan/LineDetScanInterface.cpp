#include "stdafx.h"
#include "LineDetScanInterface.h"

LineDetScanInterface::~LineDetScanInterface()
{

}

void LineDetScanInterface::setGenerialFileHeader()
{
	char strDeviceModel[32];

	CString str;													//字符串变量
	int	i;															//整数变量

	//设置版本信息
	ictHeader.MainVersion = MainVersion23;							//定义数据文件头主版本号
	ictHeader.SubVersion = SubVersion23;							//定义数据文件头次版本号

	ictHeader.DataFormat.graduationBase = 0;						//3代扫描起始分度
	ictHeader.DataFormat.DataType = LONGDATA;						//数据类型: 长整型
	ictHeader.DataFormat.dataColAtRow
		= setupData.geometryPara.NumberOfSystemHorizontalDetector;	//系统探测器数量
	ictHeader.DataFormat.appendColAtRow = 2;						//每行附加数据个数

	strcpy_s(ictHeader.SystemParameter.ModelOfCT, setupData.geometryPara.szDeviceModel);//CT设备型号
	ictHeader.SystemParameter.RaySort = setupData.rayDefine;		//射线源定义(TUBE/ACCELERATOR/ISOTOPE);
	ictHeader.SystemParameter.RayEngery = setupData.rayEnergy / 1000;	//射线能量(MeV)
	ictHeader.SystemParameter.RayDosage = setupData.rayDoseRate;	//射线剂量率(cGy/min/m)
	i = setupData.syncFreqCurSel;									//获取同步频率(Hz)
	if (i < 0)														//未选择同步频率, 则设置为250Hz
		ictHeader.SystemParameter.SynchFrequency = 250;
	else
		ictHeader.SystemParameter.SynchFrequency = setupData.syncFreqDefine[i];
	ictHeader.SystemParameter.AmplifyMultiple = setupData.AmplifyMultiple;//采样放大倍数
	if (sysStatus.s.bRaySourceSel)
		ictHeader.SystemParameter.IntegralTime = setupData.IntegralTime2;//采样积分时间(us)
	else
		ictHeader.SystemParameter.IntegralTime = setupData.IntegralTime;//采样积分时间(us)

	//设置扫描参数
	//1. 几何结构参数
	ictHeader.ScanParameter.DetectorStyle							//当前使用的探测器结构(0-弧形, 1-直线, 2-平板)
		= setupData.geometryPara.DetectorInUse;
	ictHeader.ScanParameter.NumberOfSystemHorizontalDetector		//射线平面方向系统探测器数(此参数为探测器总数)
		= setupData.geometryPara.NumberOfSystemHorizontalDetector;
	ictHeader.ScanParameter.SerialNo1OfMiddleHorizontalDetector		//射线平面方向中心探测器序号1(弧形/直线探测器, 从0开始计算)
		= setupData.geometryPara.SerialNo1OfMiddleHorizontalDetector;
	ictHeader.ScanParameter.SerialNo2OfMiddleHorizontalDetector		//射线平面方向中心探测器序号2(弧形/直线探测器, 从0开始计算)
		= setupData.geometryPara.SerialNo2OfMiddleHorizontalDetector;
	ictHeader.ScanParameter.NumberofSystemVerticalDetector			//射线平面垂直方向系统探测器数(平板探测器专用, 此参数为探测器总数)
		= setupData.geometryPara.NumberofSystemVerticalDetector;
	ictHeader.ScanParameter.SpaceOfHorizontalDetector				//射线平面方向探测器间距(mm, 平板探测器专用)
		= setupData.geometryPara.SpaceOfHorizontalDetector;
	ictHeader.ScanParameter.SpaceOfVerticalDetector					//射线平面垂直方向探测器间距(mm, 平板探测器专用)
		= setupData.geometryPara.SpaceOfVerticalDetector;
	ictHeader.ScanParameter.HorizontalSectorAngle					//射线平面方向扇角(°,与系统探测器数相关, 定义为两侧探测器中心线之间夹角)
		= setupData.geometryPara.HorizontalSectorAngle;
	ictHeader.ScanParameter.VerticalSectorAngle						//射线平面垂直方向扇角(°,与系统探测器数相关, 定义为两侧探测器中心线之间夹角)
		= setupData.geometryPara.VerticalSectorAngle;

	int j = setupData.scanModeCurSel;									//获取扫描模式代号
	int Mode = setupData.scanModeDefine[j];								//Mode为扫描模式代号

	if (Mode == CT2_SCAN)
		ictHeader.ScanParameter.RadialPosition = 700;							//焦点到旋转中心距离Q(径向位置)(mm)    
	else
		ictHeader.ScanParameter.RadialPosition							//焦点到旋转中心距离Q(径向位置)(mm)    
		= setupData.geometryPara.RadialPosition;
	ictHeader.ScanParameter.SourceDetectorDistance					//焦点到探测器距离P(mm)
		= setupData.geometryPara.SourceDetectorDistance;
	ictHeader.ScanParameter.BeginSerialNoOfCt2Detector				//Ⅱ代扫描开始探测器序号(从0开始), V2.3中新增
		= setupData.geometryPara.BeginSerialNoOfCt2Detector;
	ictHeader.ScanParameter.EndSerialNoOfCt2Detector				//Ⅱ代扫描结束探测器序号(从0开始), V2.3中新增
		= setupData.geometryPara.EndSerialNoOfCt2Detector;

	i = setupData.collimateCurSel;									//获取准直器代号
	i = setupData.collimateDefine[i];
	ictHeader.ScanParameter.CollimationSize = i;					//准直器尺寸代号:0,1,2...   准直器宽度
	i = setupData.layerThickCurSel;									//获取断层厚度
	ictHeader.ScanParameter.LayerThickness							//断层厚度(mm)(准直器高度)
		= setupData.layerThickDefine[i];

	//	ictHeader.ScanParameter.SetupSynchPulseNumber = 0;				//预置同步脉冲数(加速器情况, 在V2.3版本中不再使用)
	i = setupData.sampleTimeCurSel;									//获取采样时间
	ictHeader.ScanParameter.SampleTime 								//采样时间, 单位:秒
		= (float)setupData.sampleTimeDefine[i] / 1000;				//ms转换为s
	ictHeader.ScanParameter.SetupSynchPulseNumber					//预置脉冲数
		= (WORD)(ictHeader.ScanParameter.SampleTime * ictHeader.SystemParameter.SynchFrequency);

	//设置测试任务信息
	//设置测试日期及时间(20字节:2003-07-10 16:35:12 )
	CTime tm = CTime::GetCurrentTime();								//取得当前时间

	str = tm.Format("%Y-%m-%d");
	//新建两变量格式转换一下
	wchar_t strWChar[50];
	char strChar[50];
	wcscpy_s(strWChar, str);
	//注意：转换长度=字符串长度+1;
	//WChar2Char(strWChar,wcslen(strWChar)+1,strChar,wcslen(strWChar)+1);
	myWChar2Char((CString)strWChar, strChar);
	strcpy_s(ictHeader.Task.DateTime.Date, strChar);

	str = tm.Format("%H:%M:%S");
	wcscpy_s(strWChar, str);
	//注意：转换长度=字符串长度+1;
	//WChar2Char(strWChar,wcslen(strWChar)+1,strChar,wcslen(strWChar)+1);
	myWChar2Char((CString)strWChar, strChar);
	strcpy_s(ictHeader.Task.DateTime.Time, strChar);


	myWChar2Char((CString)setupData.m_testUnit, ictHeader.Task.SubmitUnit);
	myWChar2Char((CString)setupData.m_testTaskNumber, ictHeader.Task.Number);
	myWChar2Char((CString)setupData.m_testTaskName, ictHeader.Task.Name);
	myWChar2Char((CString)setupData.m_testStaff, ictHeader.Task.Toastmaster);

	myWChar2Char((CString)setupData.workPiece.WorkpieceName, ictHeader.Workpiece.WorkpieceName);
	myWChar2Char((CString)setupData.workPiece.WorkpieceModel, ictHeader.Workpiece.WorkpieceModel);
	myWChar2Char((CString)setupData.workPiece.WorkpieceNumber, ictHeader.Workpiece.WorkpieceNumber);
	myWChar2Char((CString)setupData.workPiece.WorkpieceBatch, ictHeader.Workpiece.WorkpieceBatch);
	myWChar2Char((CString)setupData.workPiece.WorkpieceShellMaterial, ictHeader.Workpiece.WorkpieceShellMaterial);
	myWChar2Char((CString)setupData.workPiece.WorkpieceFillMaterial, ictHeader.Workpiece.WorkpieceFillMaterial);
	myWChar2Char((CString)setupData.workPiece.WorkpieceManufacturer, ictHeader.Workpiece.WorkpieceManufacturer);
	myWChar2Char((CString)setupData.workPiece.WorkpieceMakeDate, ictHeader.Workpiece.WorkpieceMakeDate);
	myWChar2Char((CString)setupData.workPiece.WorkpieceTestPosition, ictHeader.Workpiece.WorkpieceTestPosition);

	myWChar2Char((CString)setupData.workPiece2.WorkpieceName, ictHeader.Workpiece.WorkpieceName2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceModel, ictHeader.Workpiece.WorkpieceModel2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceNumber, ictHeader.Workpiece.WorkpieceNumber2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceBatch, ictHeader.Workpiece.WorkpieceBatch2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceShellMaterial, ictHeader.Workpiece.WorkpieceShellMaterial2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceFillMaterial, ictHeader.Workpiece.WorkpieceFillMaterial2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceManufacturer, ictHeader.Workpiece.WorkpieceManufacturer2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceMakeDate, ictHeader.Workpiece.WorkpieceMakeDate2);
	myWChar2Char((CString)setupData.workPiece2.WorkpieceTestPosition, ictHeader.Workpiece.WorkpieceTestPosition2);
	//文件信息
	strcpy_s(ictHeader.ScanParameter.FilenameTemperature, "");		//探测系统实时温度记录文件名
	strcpy_s(ictHeader.ScanParameter.FilenameOfCTdata, "");			//CT数据文件名,按Windows文件名定义的字符串(用于存放CT、DR、锥束扫描数据)
	strcpy_s(ictHeader.ScanParameter.FilenameOf2CTdata, "");			//Ⅱ代数据边采边传文件名(即数据文件名加上编号(00-31))
	strcpy_s(ictHeader.ScanParameter.FilenameOfPictureData, "");		//图像数据文件名, 按Windows文件名定义的字符串

	return(TRUE);
}
