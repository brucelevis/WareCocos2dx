#include "CParticleSystem.h"
#include "CParticleSystemProp.h"

NS_CC_ENGINE_BEGIN

CParticleSystem::CParticleSystem(IEffectUnitProp* pEffectUnitProp,uint32 uID)
: CEffectUnit(pEffectUnitProp,uID)
{
}

CParticleSystem::~CParticleSystem(void)
{
}


bool CParticleSystem::create()
{
	return true;
}


void CParticleSystem::update( float32 dt )
{
	CParticleSystemProp* pProp = (CParticleSystemProp*)m_pEffectUnitProp;
	//// ֻ�Ƿ������ĸ���(���ǲ�������) ���ӵĸ���(��Ӱ��������)�ŵ�EffectManager��ȥ
	//pProp->modeA.

	return;
}

NS_CC_ENGINE_END
