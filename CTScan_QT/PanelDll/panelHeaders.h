#pragma once

//#define NIMAQPANEL
#ifdef NIMAQPANEL
#define REALPANEL NimaqPanel
#else
#define REALPANEL PESiPanel
#endif
enum class SampleMode
{
	softTrigger,
	exTrigger
};
enum class BinMode
{
	BinMode1,
	BinMode2,
	BinMode3,
	BinMode4,
	BinMode5,
	BinMode6,
};
enum class PESICON_SINGLE_MODE
{
	Continus,
	Single
};