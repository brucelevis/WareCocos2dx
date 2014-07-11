//********************************************************************
//	�ļ�����:	CParticleSystem.h
//	��������:	2014-6-5 10:59
//	��Ȩ��Ϣ: 	www.cocos2dres.com
//	�� �� ��:   Rare
//  ����˵��:   ����ϵͳ
//	�޸ļ�¼:	
//********************************************************************
#ifndef _CPARTICLESYSTEM_H_
#define _CPARTICLESYSTEM_H_

#include "cocos2dx_macros.h"
#include "CEffectUnit.h"

NS_CC_ENGINE_BEGIN

class CParticleSystem : public CEffectUnit
{
public:
	CParticleSystem( IEffectUnitProp* pEffectUnitProp,uint32 uID );
	~CParticleSystem(void);
	
	/**
	 @brief ����
	 @param 
	*/
	virtual bool		create();

	/**
	@brief ����
	@param dt ֡���ʱ��
	*/
	virtual void		update( float32 dt );

};


NS_CC_ENGINE_END

#endif // _CPARTICLESYSTEM_H_
