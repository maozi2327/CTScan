#pragma once
#include <memory>
#include <condition_variable>
#include <mutex>
class TcpServer;
#pragma pack(4)
#define	CTOSRTBUF_NUM	20						//�������/���ͻ���������
#define	CTOSRTBUF_LEN	256						//�������/���ͻ���������

typedef struct tagAQE_HEADER {
	SOCKET sServer;								//���������׽���
	SOCKET sClient;								//��ͻ��˽������ӵ��׽���
	char			*cIPAddr;					//IP��ַ�ַ���ָ��
	unsigned short	nServerPort;				//�������˿ڵ�ַ
	BYTE    clientServerMode;					//����������ʽ��CLIENTMODE-��Ϊ�ͻ���;SERVERMODE-��Ϊ������;SERVERDEBUGMODE-��Ϊ����������ģʽ��
	int		*txHeader, *txTailer;				//������-�ͻ���ͨ�ŷ��ͻ�����ͷβָ��
	BYTE(*txBuf)[CTOSRTBUF_LEN];			//������-�ͻ���ͨ�ŷ��ͻ�����ָ��

	unsigned int channel_mask;					//ͨ��ѡ������(��ӦλΪ1��Ч��Ϊ0����)
	unsigned int channel_depth;					//FIFO���, ����ֵΪ64
	unsigned int amp_size;						//�Ŵ���
	unsigned int int_time;						//����ʱ��
	unsigned int delay_time;					//�ӳ�ʱ��
	unsigned int control_flag;					//�ڴ������ԵĿ��Ʊ�־(�����ڵ��Խ׶�,0:STOP,8/9:START)
	//����4���������ڲ���������
	unsigned int valid_channel_num;				//��ЧFIFOͨ����, �ɺ���ChannelSelect(AQE_HEADER *ahInfo)����ͨ����������
	unsigned int onepulse_rawdatabytenum;		//���βɼ�����FIFOͨ����ԭʼ������, �ɺ���ChannelDepthSet(AQE_HEADER *ahInfo)����
	unsigned int onepulse_validdatabytenum;		//���βɼ�����FIFOͨ������Ч������, �ɺ���ChannelDepthSet(AQE_HEADER *ahInfo)����
	unsigned int onechannel_rawdatabytenum;		//��FIFOͨ����ԭʼ������, �ɺ���ChannelDepthSet(AQE_HEADER *ahInfo)����
	unsigned int onechannel_validdatabytenum;	//��FIFOͨ������Ч������, �ɺ���ChannelDepthSet(AQE_HEADER *ahInfo)����
	//����4���������ڲ������޸�, ���ó���Ӧ�ȶ�����0
	unsigned int sample_count;					//�����ܼ���, ���ڲ�����recvEx_DATA(.,.)���ݽ������ݽ�������
	unsigned int graduation_count;				//�ֶ��ܼ���, ���ڲ�����recvEx_DATA(.,.)���ݽ������ݽ�������
	unsigned int sample_per_layer;				//�����������, ���ڲ�����recvEx_DATA(.,.)���ݽ������ݽ�������
	unsigned int graduation_per_layer;			//��������ֶ���, ���ڲ�����recvEx_DATA(.,.)���ݽ������ݽ�������

	bool         SaveOrNot;						//�ɼ�ѭ������ TRUE:�˳��ɼ�ѭ�� FALSE:����ѭ��
	ROWLIST		 *beginItem;					//���ݴ洢������ָ��
	unsigned int hSysDetectorAmount;			//ϵͳ̽��������
	int			 *pBlockMapTable;				//ģ��ӳ���ָ��
	BYTE	     bComb;							//�ϲ��������ݱ�־(TRUE:�ϲ�, FALSE:���ϲ�)
}AQE_HEADER, *pAQE_HEADER;
#pragma pack()
//ͨ�������ֽṹ
typedef struct tagCMD_STRUCT {
	unsigned int cmd_len;				//����λ����
	unsigned int cmd;					//�������
	unsigned int cmd_param;				//�������
	unsigned int respond_type;			//���ر�־
}CMD_STRUCT, *pCMD_STRUCT;

//�Լ�������

#define CMD_DETECTOR_TEST 0x0000		//̽��ϵͳ���
#define CMD_ARM_TEST 0x0a00				//ARM���
#define CMD_FPGA_TEST					//FPGA���

//����������
#define CMD_INTERNAL_COLLECT	0x0007	//���źŴ����ɼ�(����Ҫ��������)
#define CMD_CHANNEL_SELECT		0x0100	//FIFOͨ��ѡ��
#define CMD_CHANNEL_DEPTH_SET	0x0200	//FIFOͨ���������
#define CMD_START_CI			0x0800	//���������
#define CMD_NET_QUIT			0x0900	//�Ͽ�����

//����������
#define CMD_SET_DELAY_TIME	0x0001		//�����ӳ�ʱ��
#define CMD_SET_AMP_SIZE	0x0002		//���÷Ŵ���
#define CMD_SET_INT_TIME	0x0003		//���û���ʱ��
#define CMD_READ_DELAY_TIME 0x0004		//���ӳ�ʱ��
#define CMD_READ_AMP_SIZE	0x0005		//���Ŵ���
#define CMD_READ_INT_TIME	0x0006		//������ʱ��

/////////////////////////////////////////////////////////////
//����ͻ���->������ͨ������
enum {
	CMD_LINEDET_INIT = 0x00,			//��ʼ������̽��������
	CMD_LINEDET_ARM_TEST,										//CPU����
	CMD_LINEDET_START_CI,										//���������
	CMD_LINEDET_DETECTOR_TEST,									//ϵͳ�Լ�
	CMD_LINEDET_CHANNEL_SELECT,									//FIFOͨ��ѡ��
	CMD_LINEDET_CHANNEL_DEPTH_SET,								//FIFOͨ���������
	CMD_LINEDET_SET_DELAY_TIME,									//�����ӳ�ʱ��
	CMD_LINEDET_SET_AMP_TIME,									//���÷Ŵ���
	CMD_LINEDET_SET_INT_TIME,									//���û���ʱ��
	CMD_LINEDET_LOAD_DELAY_TIME,								//�ϴ��ӳ�ʱ��
	CMD_LINEDET_LOAD_AMP_TIME,									//�ϴ��Ŵ���
	CMD_LINEDET_LOAD_INT_TIME,									//�ϴ�����ʱ��
	CMD_LINEDET_START_INTER_DAQ,								//�������Ųɼ�
//���������->�ͻ���ͨ��״̬
	//STS_ARM_TEST_FAULT							= 0x10,			//��ʼ������̽�����������
	//STS_CHANNEL_SEL_FAULT,										//ͨ��ѡ��������
	//STS_CHANNEL_DEPTH_SET_FAULT,								//ͨ��������ý������
	//STS_START_CI_FAULT,											//��������忨�������
	//STS_DET_SELF_TEST_FAULT,											//̽���Լ�������
	//STS_SET_DELAY_TIME_FAULT,									//�����ӳ�ʱ��������
	//STS_SET_INT_TIME_FAULT,										//���û���ʱ��������
	//STS_SET_AMP_TIME_FAULT,										//���÷Ŵ����������

	STS_LINEDET_DATA_ACQUIRE = 0x20	//ָʾ����Ϊ����̽����ɨ��ɼ�����
};

//״̬/�����붨��					
enum {
	fLD_SUCCESS = 0x00,			//�ɹ�					0x00
	fLD_ARM_TEST_FAULT,										//��ʼ������̽�����������
	fLD_CHANNEL_SEL_FAULT,									//ͨ��ѡ��������
	fLD_CHANNEL_DEPTH_SET_FAULT,							//ͨ��������ý������
	fLD_START_CI_FAULT,										//��������忨�������
	fLD_DET_SELF_TEST_FAULT,								//̽���Լ�������
	fLD_SET_DELAY_TIME_FAULT,								//�����ӳ�ʱ��������
	fLD_SET_INT_TIME_FAULT,									//���û���ʱ��������
	fLD_SET_AMP_SIZE_FAULT,									//���÷Ŵ����������
	fLD_LOAD_DELAY_TIME_FAULT,								//�ϴ��ӳ�ʱ��������
	fLD_LOAD_INT_TIME_FAULT,								//�ϴ�����ʱ��������
	fLD_LOAD_AMP_SIZE_FAULT,								//�ϴ��Ŵ����������
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

