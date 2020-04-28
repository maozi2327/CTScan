#pragma once
//转台，射线，探测，分别有升降，平移，径向三种运动
//用三位二进制代替，例如对于转台如果值为011(3)，代表拥有平移和径向两种运动方式
//面阵线阵用两位二进制表示，例如11(3)表示线阵面阵都有，01(2)表示只有线阵，射线源1射线源2同理
//使用xxxxxxx五位分别表示射线源，探测器，转台，射线，探测，物理插值，偏摆，如果不包含后面两轴可以不写
#include <map>
#include <string>
#define TYPE33346
#define WROX225
#define COMET450
#ifdef TYPE11344 //双立柱，无面阵，有转台径向轴，单射线源轴，山东电力设备类型
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define DETLAYER
#define ACTIONABLEAXISNUMBER 5
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE11244 //双立柱，无面阵，无转台径向轴，西北工业/861设备类型
#define TABLEROT
#define TABLETRANSLATION
#define RAYLAYER
#define DETLAYER
#define ACTIONABLEAXISNUMBER 4
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE11240 //单立柱，无面阵，无转台径向轴，只使用射线升降，7801类型
#define TABLEROT
#define TABLETRANSLATION
#define RAYLAYER
#define ACTIONABLEAXISNUMBER 3
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE11044 //双立柱，无面阵，无转台平移径向，线阵物理插值，武汉磁电类型
#define TABLEROT
#define RAYLAYER
#define DETLAYER
#define ACTIONABLEAXISNUMBER 4
#define LINEDETINTERPOLATE
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE12001 //无立柱，只有面阵，有转台径向轴，有探测径向轴，自研维焦设备类型
#define TABLEROT
#define TABLERADIAL
#define DETTRANSLATION
#define ACTIONABLEAXISNUMBER 3
#define RAY1
#define PANELDECTOR
#endif

#ifdef TYPE1234101  //单立柱，只有面阵，有转台径向轴，有转台平移轴，有探测径向轴，有偏摆，9院300bx类型
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define ACTIONABLEAXISNUMBER 4
#define LAYERDEFLECTION
#define RAY1
#define PANELDECTOR
#endif

#ifdef TYPE12341  //单立柱，只有面阵，有转台径向轴，有转台平移轴，有探测径向轴，有偏摆，9院300bx类型
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define LAYERDEFLECTION
#define ACTIONABLEAXISNUMBER 5
#define RAY1
#define PANELDECTOR
#endif

#ifdef TYPE13346  //双立柱，双探测器，有转台径向轴，有转台平移轴，有探测径向轴，单源双探类型，170类型设备
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define DETLAYER
#define DETRADIAL
#define ACTIONABLEAXISNUMBER 5
#define RAY1
#define LINEDECTOR
#define PANELDECTOR
#endif

#ifdef TYPE33346  //双立柱，双探测器，有转台径向轴，有转台平移轴，有探测径向轴，双源双探类型，河南电科院类型设备
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define DETLAYER
#define DETRADIAL
#define DETLAYER
#define ACTIONABLEAXISNUMBER 6
#define RAY
#define RAY2
#define LINEDECTOR
#define PANELDECTOR
#endif

#ifdef TYPE347  //双立柱，双探测器，有转台径向轴，有转台平移轴，有探测径向轴，有探测平移轴，黎明类型设备
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define DETLAYER
#define DETTRANSLATION
#define DETRADIAL
#define ACTIONABLEAXISNUMBER 7
#define RAY1
#define RAY2
#define LINEDECTOR
#define PANELDECTOR
#endif

enum class Axis
{
	objRotation = 0,
#ifdef TABLETRANSLATION
	objTranslation = 1,
#endif 
#ifdef RAYLAYER
	rayLayer = 3,
#endif
#ifdef DETLAYER
	detLayer = 4,
#endif
#ifdef TABLERADIAL
	objRadial = 5,
#endif
	detRadial = 11,
	detTranslation = 12
};

const std::map<const char*, Axis> AxisNameMap
{
	{"ObjRotation", Axis::objRotation}, 
	{"ObjTranslaiton", Axis::objTranslation},
	{"ObjRadial", Axis::objRadial},
	{"RayLayer", Axis::rayLayer},
	{"DetLayer", Axis::detLayer},
	{"DetTranslation", Axis::detTranslation},
	{"DetRadial", Axis::detRadial}
};