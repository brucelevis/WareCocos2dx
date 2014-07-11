#include "DragonBoneAnimation.h"
#include "StringUtility.h"

NS_CC_ENGINE_BEGIN

CDragonBoneAnimation::CDragonBoneAnimation(void)
: m_nState(0)
, m_fSpeed(0.0f)
, m_pArmatureAni(NULL)
{

}
//-------------------------------------------------------------------------
CDragonBoneAnimation::~CDragonBoneAnimation(void)
{

}
//-------------------------------------------------------------------------
/**
@brief ���ö�����Դ
@param pAnimation ��������
*/
void CDragonBoneAnimation::setAnimationRes( extension::CCArmatureAnimation* pAnimation )
{
	m_pArmatureAni = pAnimation;
}
//-------------------------------------------------------------------------
/**
@brief ���ö������Żص�
@param
*/
void CDragonBoneAnimation::setAniCallback( IAnimationCallback* pAniCallBack, void* pContext )
{
	m_pAniCallBack = pAniCallBack;
	m_pCallBackContext = pContext;

	if( NULL != m_pArmatureAni )
	{
		m_pArmatureAni->setMovementEventCallFunc( this, (extension::SEL_MovementEventCallFunc)(&CDragonBoneAnimation::onMovementEventCallFunc) );
		m_pArmatureAni->setFrameEventCallFunc( this, (extension::SEL_FrameEventCallFunc)(&CDragonBoneAnimation::onFrameEventCallFunc) );
	}
}
//-------------------------------------------------------------------------
/**
@brief ���Ŷ��� ����ö�������ֹͣ״̬�����������
@param[in] szAniName ��������
@param[in] fSpeed �����ٶ�
@param[in] nLoops ѭ������
@param[in] bForceUpdate �Ƿ�ǿ�Ƹ��¶�������(�������²���)
*/
void CDragonBoneAnimation::play( const std::string& strAniName, float fSpeed, int nLoops, bool bForceUpdate )
{
	if( m_pArmatureAni == NULL )
	{
		return;
	}

	m_pArmatureAni->play(strAniName.c_str());
	m_pArmatureAni->setSpeedScale( fSpeed );

	m_strCurActionName = strAniName;
}
//-------------------------------------------------------------------------
/**
@brief ���ò����ٶ�
@param fSpeed �����ٶ�
*/
void CDragonBoneAnimation::speed( float fSpeed )
{
	if( m_pArmatureAni == NULL )
	{
		return;
	}

	m_pArmatureAni->setSpeedScale( fSpeed );
}
//-------------------------------------------------------------------------
/**
@brief ��ȡ�����ٶ�
@param fSpeed �����ٶ�
*/
float CDragonBoneAnimation::getSpeed()
{
	if( m_pArmatureAni == NULL )
	{
		return 1.0f;
	}

	return m_pArmatureAni->getSpeedScale();
}

/**
@brief ֹͣ����
@param
*/
void CDragonBoneAnimation::stop(void)
{
	if( m_pArmatureAni == NULL )
	{
		return;
	}

	return m_pArmatureAni->stop();
}

/**
@brief ֹͣ����
@param
*/
void CDragonBoneAnimation::pause(void)
{
	if( m_pArmatureAni == NULL )
	{
		return;
	}

	return m_pArmatureAni->pause();
}
//-------------------------------------------------------------------------
/**
@brief �Ƿ����ָ�����ƵĶ���
@param strAniName ��������
@return ����ָ�������������
*/
bool CDragonBoneAnimation::isExistClip( const std::string& strAniName )
{
	if( m_pArmatureAni == NULL )
	{
		return false;
	}

	extension::CCAnimationData* pAniData = m_pArmatureAni->getAnimationData();
	if( pAniData == NULL )
	{
		return false;
	}

	if( pAniData->movementNames.empty() )
	{
		return false;
	}

	size_t size = pAniData->movementNames.size();
	for( size_t i = 0; i < size; ++i )
	{
		if( pAniData->movementNames[i] == strAniName )
		{
			return true;
		}
	}

	return false;
}
//-------------------------------------------------------------------------
/**
@brief ��ȡ�����б�
@param[inout] animations �����б�
*/
void CDragonBoneAnimation::getAnimationList( std::list< std::string >& animations )
{
	//animations.clear();

	if( m_pArmatureAni == NULL )
	{
		return;
	}

	extension::CCAnimationData* pAniData = m_pArmatureAni->getAnimationData();
	if( pAniData == NULL )
	{
		return;
	}

	if( pAniData->movementNames.empty() )
	{
		return;
	}

	size_t size = pAniData->movementNames.size();
	for( size_t i = 0; i < size; ++i )
	{
		animations.push_back( pAniData->movementNames[i] );
	}
}
//-------------------------------------------------------------------------
/**
@brief �����ص�
@param pArmature ����
@param eMovementEventType ��������
@param szEventName �ص��¼�����
*/
void CDragonBoneAnimation::onMovementEventCallFunc(extension::CCArmature* pArmature, extension::MovementEventType eMovementEventType, const char * szEventName )
{
	if( m_pAniCallBack )
	{
		SAnimationCallbackInfo sAnimationCallbackInfo;

		sAnimationCallbackInfo.fFrameTime = 0;
		switch( eMovementEventType )
		{
		case extension::START:
			{
				StringUtility::sstrcpyn( sAnimationCallbackInfo.szName, "start", sizeof(sAnimationCallbackInfo.szName) );
				break;
			}
		case extension::COMPLETE:
		case extension::LOOP_COMPLETE:
			{
				StringUtility::sstrcpyn( sAnimationCallbackInfo.szName, "end", sizeof(sAnimationCallbackInfo.szName) );
				break;
			}
		}

		StringUtility::sstrcpyn( sAnimationCallbackInfo.szActName, m_strCurActionName.c_str(), sizeof(sAnimationCallbackInfo.szActName) );
		
		m_pAniCallBack->onAnimaitonCallback( sAnimationCallbackInfo, m_pCallBackContext );
	}
}
//-------------------------------------------------------------------------
/**
@brief ֡�¼��ص�
@param pBone ����
@param pFrameEventName ֡�¼�����
@param nFrameID ֡ID
@param nTime �ص�ʱ��
*/
void CDragonBoneAnimation::onFrameEventCallFunc(extension::CCBone* pBone, const char* pFrameEventName, int nFrameID, int nTime )
{
	if( m_pAniCallBack )
	{
		SAnimationCallbackInfo sAnimationCallbackInfo;

		sAnimationCallbackInfo.fFrameTime = nTime;
		StringUtility::sstrcpyn( sAnimationCallbackInfo.szActName, m_strCurActionName.c_str(), sizeof(sAnimationCallbackInfo.szActName) );
		StringUtility::sstrcpyn( sAnimationCallbackInfo.szActName, pFrameEventName, sizeof(sAnimationCallbackInfo.szActName) );

		m_pAniCallBack->onAnimaitonCallback( sAnimationCallbackInfo, m_pCallBackContext );
	}
}

NS_CC_ENGINE_END