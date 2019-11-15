#pragma once
class CTDispose
{
public:
	CTDispose();
	~CTDispose();

	void dispose(unsigned short* in_image);
	void disposeAndSave(unsigned short*, QString in_fileName);
};

