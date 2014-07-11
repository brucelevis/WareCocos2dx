//********************************************************************
//	�ļ�����:	CEffectUnit.h
//	��������:	2014-6-4 17:39
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ��Ч��Ԫ
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CEFFECTUNIT_H_
#define _CEFFECTUNIT_H_

#include "IEffectUnit.h"

NS_CC_ENGINE_BEGIN

struct IEffectUnitProp;

class CEffectUnit : public IEffectUnit
{
public:

	CEffectUnit( IEffectUnitProp* pEffectUnitProp, uint32 uID );
	~CEffectUnit();

	typedef std::map< float32, CCSpriteFrame* >  TextureMap;

	/**
	 @brief ����
	 @param 
	*/
	virtual bool				create();

	/**
	 @brief �ͷ�
	 @param 
	*/
	virtual void				release();

	/**
	 @brief ��ȡ��Ч��ԪID
	 @param 
	*/
	virtual uint32				getID()			{ return m_uID; }

	virtual IEffectUnitProp*	getEffectUnitProp();

	virtual	void				setEffectUnitProp( IEffectUnitProp* pProp );

	void						setStartTime( uint32 uStartTime )	{ m_uStartTime = uStartTime; }

	int32						getType();
	void						createTexture();
	void						releaseAllTexture();
	
protected:

	IEffectUnitProp*			m_pEffectUnitProp;		/// ��Ч��Ԫ����
	TextureMap					m_mapTexture;			/// ��ͼ�б�

	uint32						m_uStartTime;			/// ��ʼʱ��
	int32						m_nEffectUnitType;		/// ��Ч��Ԫ����

	uint32						m_uID;					/// ��Ч��ԪID
};

NS_CC_ENGINE_END

#endif // _CEFFECTUNIT_H_