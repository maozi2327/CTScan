#pragma once
#include <future>
#include <memory>
class Panel;
class CTDispose;
class ControlerInterface;
class ConeScanInterface
{
protected:
	int d_graduation;
	QString d_fileName;
	Panel* d_panel;
	CTDispose* d_ctDispose;
	bool d_is_saveOrg;
	bool d_is_dispose;
	ControlerInterface* d_controller;
	std::unique_ptr<std::promise<bool>> d_ringThreadPromisePtr;
public:
	ConeScanInterface(Panel* in_panel, ControlerInterface* in_controller, CTDispose* in_ctDispose);
	virtual ~ConeScanInterface();
	
	virtual bool setGraduation(int in_graduation) { d_graduation = in_graduation; };
	virtual bool beginScan() = 0;
	virtual bool stopScan() = 0;
	virtual void scanThread() = 0;
	virtual bool saveFile(unsigned short* in_image) = 0;
};