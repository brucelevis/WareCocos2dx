//*************************************************************************
//	��������:	2013-7-4   20:33
//	�ļ�����:	ImageLayer.h	
//	��Ȩ����:	Cocos2DRes.com
//	˵    ��:	ͼƬ��
//*************************************************************************
#ifndef _IMAGELAYER_H_
#define _IMAGELAYER_H_

#include "cocos2dx_types.h"
#include "cocos2dx_macros.h"
#include "cocos2d.h"
#include "WareFileWrite.h"
#include "WareFileRead.h"
#include "SceneLayer.h"
#include <string>
#include <set>
#include <map>

NS_CC_ENGINE_BEGIN

class CImageLayer : public CSceneLayer
{
	//typedef std::map<uint32,STerrainObj>	TerrainObjMap;
public:
	CImageLayer(void);
	~CImageLayer(void);

	/** create one layer */
	static CImageLayer *create(std::vector<std::string>& vecImages);

	/**
	@brief ��ʼ��
	@param 
	*/
	bool	init(std::vector<std::string>& vecImages);

	/**
	@brief ���ò�ID
	@param nLayerID ��ID
	*/
	void	setLayerID( int nLayerID ) { m_nLayerID = nLayerID; }

	/**
	@brief ��ȡ��ID
	@param
	*/
	int		getLayerID() { return m_nLayerID; }

	/**
	 @brief ��ȡ��С
	 @param 
	*/
	void	getSize( cocos2d::CCSize& size ) { size = m_size; }

private:

	int					m_nLayerID;			/// ��ID
	cocos2d::CCSize		m_size;				/// ��С

};

NS_CC_ENGINE_END

#endif // _IMAGELAYER_H_

