#pragma once
//ת̨�����ߣ�̽�⣬�ֱ���������ƽ�ƣ����������˶�
//����λ�����ƴ��棬�������ת̨���ֵΪ011(3)������ӵ��ƽ�ƺ;��������˶���ʽ
//������������λ�����Ʊ�ʾ������11(3)��ʾ���������У�01(2)��ʾֻ����������Դ1����Դ2ͬ��
//ʹ��xxxxxxx��λ�ֱ��ʾ����Դ��̽������ת̨�����ߣ�̽�⣬�����ֵ��ƫ�ڣ��������������������Բ�д
#include <map>
#include <string>
#define TYPE33346
#define WROX225
#define COMET450
#ifdef TYPE11344 //˫��������������ת̨�����ᣬ������Դ�ᣬɽ�������豸����
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define DETLAYER
#define ACTIONABLEAXISNUMBER 5
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE11244 //˫��������������ת̨�����ᣬ������ҵ/861�豸����
#define TABLEROT
#define TABLETRANSLATION
#define RAYLAYER
#define DETLAYER
#define ACTIONABLEAXISNUMBER 4
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE11240 //����������������ת̨�����ᣬֻʹ������������7801����
#define TABLEROT
#define TABLETRANSLATION
#define RAYLAYER
#define ACTIONABLEAXISNUMBER 3
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE11044 //˫��������������ת̨ƽ�ƾ������������ֵ���人�ŵ�����
#define TABLEROT
#define RAYLAYER
#define DETLAYER
#define ACTIONABLEAXISNUMBER 4
#define LINEDETINTERPOLATE
#define RAY1
#define LINEDECTOR
#endif

#ifdef TYPE12001 //��������ֻ��������ת̨�����ᣬ��̽�⾶���ᣬ����ά���豸����
#define TABLEROT
#define TABLERADIAL
#define DETTRANSLATION
#define ACTIONABLEAXISNUMBER 3
#define RAY1
#define PANELDECTOR
#endif

#ifdef TYPE1234101  //��������ֻ��������ת̨�����ᣬ��ת̨ƽ���ᣬ��̽�⾶���ᣬ��ƫ�ڣ�9Ժ300bx����
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define ACTIONABLEAXISNUMBER 4
#define LAYERDEFLECTION
#define RAY1
#define PANELDECTOR
#endif

#ifdef TYPE12341  //��������ֻ��������ת̨�����ᣬ��ת̨ƽ���ᣬ��̽�⾶���ᣬ��ƫ�ڣ�9Ժ300bx����
#define TABLEROT
#define TABLETRANSLATION
#define TABLERADIAL
#define RAYLAYER
#define LAYERDEFLECTION
#define ACTIONABLEAXISNUMBER 5
#define RAY1
#define PANELDECTOR
#endif

#ifdef TYPE13346  //˫������˫̽��������ת̨�����ᣬ��ת̨ƽ���ᣬ��̽�⾶���ᣬ��Դ˫̽���ͣ�170�����豸
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

#ifdef TYPE33346  //˫������˫̽��������ת̨�����ᣬ��ת̨ƽ���ᣬ��̽�⾶���ᣬ˫Դ˫̽���ͣ����ϵ��Ժ�����豸
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

#ifdef TYPE347  //˫������˫̽��������ת̨�����ᣬ��ת̨ƽ���ᣬ��̽�⾶���ᣬ��̽��ƽ���ᣬ���������豸
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