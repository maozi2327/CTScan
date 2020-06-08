#pragma once
#include <QObject>
#include <memory>
#include <condition_variable>
#include <mutex>
#include <vector>
class TcpServer;
#define	CTOSRTBUF_NUM	20						//�������/���ͻ���������
#define	CTOSRTBUF_LEN	256						//�������/���ͻ���������

//ͨ�������ֽṹ
struct CMD_STRUCT
{
	unsigned int cmd_len;				//����λ����
	unsigned int cmd;					//�������
	unsigned int cmd_param;				//�������
	unsigned int respond_type;			//���ر�־
};

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

//״̬/�����붨��					
enum 
{
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

struct LineDetList
{
	unsigned long* d_item;
	LineDetList* d_prev;
	LineDetList* d_next;
};
struct RowList
{
private:
	LineDetList* d_listHead;
	LineDetList* d_ptr;
	int d_size;
	int d_graduationNum;
public:
	RowList()
	{
		d_ptr = d_listHead = 0;
		d_size = 0;
		d_graduationNum = 0;
	}
	~RowList()
	{
		clear();
	}
	void push_back(unsigned long* in_mem)
	{
		if (d_size == 0)
		{
			d_ptr = new LineDetList;
			d_listHead = d_ptr;
			d_ptr->d_item = in_mem;
			d_ptr->d_prev = 0;
			d_ptr->d_next = 0;
			++d_graduationNum;
		}
		else
		{
			d_ptr->d_next = new LineDetList;
			d_ptr->d_next->d_prev = d_ptr;
			d_ptr = d_ptr->d_next;
			d_ptr->d_item = in_mem;
			d_ptr->d_next = 0;

			if (d_ptr->d_item[0] != d_ptr->d_prev->d_item[0])
				++d_graduationNum;
		}

		++d_size;
	}

	void clear()
	{
		d_ptr = d_listHead;

		while(d_ptr != 0)
		{ 
			delete[] d_ptr->d_item;
			d_ptr = d_ptr->d_next;
			delete d_ptr->d_prev;
		}

		d_size = 0;
		d_graduationNum = 0;
	}

	LineDetList* getList()
	{
		return d_listHead;
	}
};

class LineDetNetWork : public QObject
{
	Q_OBJECT
private:
	std::unique_ptr<TcpServer> d_server;
	enum DataType
	{
		CMD = 0,
		PARAMETER,
		DATA
	};
	bool d_connected;
	std::condition_variable d_con;
	std::mutex d_mutex;
	DataType d_recvType;
	unsigned int d_cmdType;
	unsigned int d_return64;
	unsigned int d_returnSize;           //�������ݴ�С

	unsigned int d_smallBoardNum;        //С��������
	unsigned int d_smallBoardChannel;    //С����ͨ������64
	unsigned int d_ampSize;
	unsigned int d_intTime;
	unsigned int d_delayTime;
	
	int d_dataSizePerPulse;
	int d_channelNum;
	RowList d_dataList;

	//����̽����ÿ�η������ݸ�ʽ
	//									���ݳ���|
	//��һ�������(�ֶȺ�|�����|64��ͨ��|У���)|�ڶ��������|......|���һ�������|
	//		  (----------------------��һ������������------------------------------------)
	//        ------------------------������������-----------------------------------
	//        -----------------------���һ����������-----------------------------------
	std::vector<unsigned int> d_nonBlockModuleMap;

public slots:
	void netWorkStatusSlot(bool sts);

signals:
	void netWorkStatusSignal(bool sts);
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
	bool SetAmpSize(int in_ampSize);
	bool SetIntTime(int in_intTime);
	bool SetDelayTime(int in_delayTime);
	bool ReadAmpSize();
	bool ReadIntTime();
	bool ReadDelayTime();
	bool startExtTrigAcquire();
	void DecodePackages(char* in_buff, int in_size);
	int getGraduationCount();
	int CollectUsefulData(char * in_buff, int in_size);
	LineDetList* getRowList();
	void clearRowList();

	bool getConnected();
	LineDetNetWork(unsigned short in_port);
	~LineDetNetWork();
};

