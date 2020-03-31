#pragma once
#include <memory>
#include <condition_variable>
#include <mutex>
class TcpServer;
#pragma pack(4)
#define	CTOSRTBUF_NUM	20						//定义接收/发送缓冲区个数
#define	CTOSRTBUF_LEN	256						//定义接收/发送缓冲区长度

typedef struct tagAQE_HEADER {
	SOCKET sServer;								//服务器端套接字
	SOCKET sClient;								//与客户端建立连接的套接字
	char			*cIPAddr;					//IP地址字符串指针
	unsigned short	nServerPort;				//服务器端口地址
	BYTE    clientServerMode;					//主程序工作方式（CLIENTMODE-作为客户端;SERVERMODE-作为服务器;SERVERDEBUGMODE-作为服务器调试模式）
	int		*txHeader, *txTailer;				//服务器-客户端通信发送缓冲区头尾指针
	BYTE(*txBuf)[CTOSRTBUF_LEN];			//服务器-客户端通信发送缓冲区指针

	unsigned int channel_mask;					//通道选择掩码(对应位为1有效，为0屏蔽)
	unsigned int channel_depth;					//FIFO深度, 典型值为64
	unsigned int amp_size;						//放大倍数
	unsigned int int_time;						//积分时间
	unsigned int delay_time;					//延迟时间
	unsigned int control_flag;					//内触发测试的控制标志(仅用于调试阶段,0:STOP,8/9:START)
	//以下4个变量由内部函数设置
	unsigned int valid_channel_num;				//有效FIFO通道数, 由函数ChannelSelect(AQE_HEADER *ahInfo)根据通道掩码设置
	unsigned int onepulse_rawdatabytenum;		//单次采集所有FIFO通道的原始数据量, 由函数ChannelDepthSet(AQE_HEADER *ahInfo)设置
	unsigned int onepulse_validdatabytenum;		//单次采集所有FIFO通道的有效数据量, 由函数ChannelDepthSet(AQE_HEADER *ahInfo)设置
	unsigned int onechannel_rawdatabytenum;		//单FIFO通道的原始数据量, 由函数ChannelDepthSet(AQE_HEADER *ahInfo)设置
	unsigned int onechannel_validdatabytenum;	//单FIFO通道的有效数据量, 由函数ChannelDepthSet(AQE_HEADER *ahInfo)设置
	//以下4个变量由内部函数修改, 调用程序应先对其清0
	unsigned int sample_count;					//采样总计数, 由内部函数recvEx_DATA(.,.)根据接收数据进行设置
	unsigned int graduation_count;				//分度总计数, 由内部函数recvEx_DATA(.,.)根据接收数据进行设置
	unsigned int sample_per_layer;				//单层采样次数, 由内部函数recvEx_DATA(.,.)根据接收数据进行设置
	unsigned int graduation_per_layer;			//单层采样分度数, 由内部函数recvEx_DATA(.,.)根据接收数据进行设置

	bool         SaveOrNot;						//采集循环控制 TRUE:退出采集循环 FALSE:继续循环
	ROWLIST		 *beginItem;					//数据存储链表首指针
	unsigned int hSysDetectorAmount;			//系统探测器数量
	int			 *pBlockMapTable;				//模块映射表指针
	BYTE	     bComb;							//合并采样数据标志(TRUE:合并, FALSE:不合并)
}AQE_HEADER, *pAQE_HEADER;
#pragma pack()
//通信命令字结构
typedef struct tagCMD_STRUCT {
	unsigned int cmd_len;				//命令位长度
	unsigned int cmd;					//命令代码
	unsigned int cmd_param;				//命令参数
	unsigned int respond_type;			//返回标志
}CMD_STRUCT, *pCMD_STRUCT;

//自检类命令

#define CMD_DETECTOR_TEST 0x0000		//探测系统检测
#define CMD_ARM_TEST 0x0a00				//ARM检测
#define CMD_FPGA_TEST					//FPGA检测

//控制类命令
#define CMD_INTERNAL_COLLECT	0x0007	//内信号触发采集(不需要控制脉冲)
#define CMD_CHANNEL_SELECT		0x0100	//FIFO通道选择
#define CMD_CHANNEL_DEPTH_SET	0x0200	//FIFO通道深度设置
#define CMD_START_CI			0x0800	//启动传输板
#define CMD_NET_QUIT			0x0900	//断开网络

//参数类命令
#define CMD_SET_DELAY_TIME	0x0001		//设置延迟时间
#define CMD_SET_AMP_SIZE	0x0002		//设置放大倍数
#define CMD_SET_INT_TIME	0x0003		//设置积分时间
#define CMD_READ_DELAY_TIME 0x0004		//读延迟时间
#define CMD_READ_AMP_SIZE	0x0005		//读放大倍数
#define CMD_READ_INT_TIME	0x0006		//读积分时间

/////////////////////////////////////////////////////////////
//定义客户端->服务器通信命令
enum {
	CMD_LINEDET_INIT = 0x00,			//初始化线阵探测器命令
	CMD_LINEDET_ARM_TEST,										//CPU测试
	CMD_LINEDET_START_CI,										//启动传输板
	CMD_LINEDET_DETECTOR_TEST,									//系统自检
	CMD_LINEDET_CHANNEL_SELECT,									//FIFO通道选择
	CMD_LINEDET_CHANNEL_DEPTH_SET,								//FIFO通道深度设置
	CMD_LINEDET_SET_DELAY_TIME,									//设置延迟时间
	CMD_LINEDET_SET_AMP_TIME,									//设置放大倍数
	CMD_LINEDET_SET_INT_TIME,									//设置积分时间
	CMD_LINEDET_LOAD_DELAY_TIME,								//上传延迟时间
	CMD_LINEDET_LOAD_AMP_TIME,									//上传放大倍数
	CMD_LINEDET_LOAD_INT_TIME,									//上传积分时间
	CMD_LINEDET_START_INTER_DAQ,								//启动内信采集
//定义服务器->客户端通信状态
	//STS_ARM_TEST_FAULT							= 0x10,			//初始化线阵探测器结果反馈
	//STS_CHANNEL_SEL_FAULT,										//通信选择结果反馈
	//STS_CHANNEL_DEPTH_SET_FAULT,								//通信深度设置结果反馈
	//STS_START_CI_FAULT,											//开启传输板卡结果反馈
	//STS_DET_SELF_TEST_FAULT,											//探测自检结果反馈
	//STS_SET_DELAY_TIME_FAULT,									//设置延迟时间结果反馈
	//STS_SET_INT_TIME_FAULT,										//设置积分时间结果反馈
	//STS_SET_AMP_TIME_FAULT,										//设置放大倍数结果反馈

	STS_LINEDET_DATA_ACQUIRE = 0x20	//指示数据为线阵探测器扫描采集数据
};

//状态/故障码定义					
enum {
	fLD_SUCCESS = 0x00,			//成功					0x00
	fLD_ARM_TEST_FAULT,										//初始化线阵探测器结果反馈
	fLD_CHANNEL_SEL_FAULT,									//通信选择结果反馈
	fLD_CHANNEL_DEPTH_SET_FAULT,							//通信深度设置结果反馈
	fLD_START_CI_FAULT,										//开启传输板卡结果反馈
	fLD_DET_SELF_TEST_FAULT,								//探测自检结果反馈
	fLD_SET_DELAY_TIME_FAULT,								//设置延迟时间结果反馈
	fLD_SET_INT_TIME_FAULT,									//设置积分时间结果反馈
	fLD_SET_AMP_SIZE_FAULT,									//设置放大倍数结果反馈
	fLD_LOAD_DELAY_TIME_FAULT,								//上传延迟时间结果反馈
	fLD_LOAD_INT_TIME_FAULT,								//上传积分时间结果反馈
	fLD_LOAD_AMP_SIZE_FAULT,								//上传放大倍数结果反馈
};

class LineDetNetWork
{
private:
	std::unique_ptr<TcpServer> d_server;
	enum DataType
	{
		CMD = 0,
		PARAMETER,
		DATA
	};
	std::condition_variable d_con;
	std::mutex d_mutex;
	DataType d_recvType;
	unsigned int d_cmdType;
	unsigned int d_return64;

	unsigned int d_channelMask;
	unsigned int d_channelDepth;
	unsigned int d_ampSize;
	unsigned int d_intTime;
	unsigned int d_delayTime;

public:
	bool recvServer_DATA();
	bool NetCheck();
	bool NetSetup();
	bool ARMTest();
	bool ChannelSelect();
	bool ChannelDepthSet();
	bool StartCI();
	bool FPGATest();
	bool DetectorTest();
	bool SetAmpSize();
	bool SetIntTime();
	bool SetDelayTime();
	bool ReadAmpSize();
	bool ReadIntTime();
	bool ReadDelayTime();
	void DecodePackages(char* in_buff, int in_size);
	LineDetNetWork();
	~LineDetNetWork();
};

