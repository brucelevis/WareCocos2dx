#include "CEffect.h"
#include "CEffectProp.h"
#include "CEffectUnit.h"
#include "CTextureAnimation.h"
#include "CParticleSystem.h"
#include "IEffectUnitProp.h"
#include "CEffectPropManager.h"
#include "WareTime.h"

NS_CC_ENGINE_BEGIN

CEffect::CEffect(uint32 uID)
: m_pEffectProp(NULL)
, m_uID(uID)
, m_uEffectUnitID(0)
, m_uStartTime(0)
, m_strEffectName("")
{
}

CEffect::~CEffect(void)
{
}
//-------------------------------------------------------------------------
/**
@brief �ͷ�
@param 
*/
void CEffect::release()
{
	if( isSingleReference() )
	{
		if( m_pEffectProp )
			m_pEffectProp->release();

		size_t size = m_vecEffectUnitTrack.size();
		for( size_t i = 0; i < size; ++i )
		{
			if( m_vecEffectUnitTrack[i] )
				releaseEffectUnit( m_vecEffectUnitTrack[i]->pEffectUnit );
			SAFE_DELETE( m_vecEffectUnitTrack[i] );
		}
	}

	CCObject::release();
}
//-------------------------------------------------------------------------
/**
@brief ����
@param szPicFileName ��Դ�ļ���
@param ptOffset ƫ��ֵ
@return ���ش����ɹ�����ʶ
*/
bool CEffect::create( const char* szEffectFileName, CCPoint ptOffset )
{
	if( szEffectFileName == NULL )
	{
		return false;
	}

	if( szEffectFileName )
	{
		m_strEffectName = szEffectFileName;
	}

	if( !CEffectPropManager::Instance().createEffectProp( szEffectFileName, &m_pEffectProp ) )
	{
		CCLOG( "create effect %s failed!", szEffectFileName );
		return false;
	}

	scheduleUpdate();

	return true;
}
//-------------------------------------------------------------------------
void CEffect::update( float dt )
{
	CEffectProp* pProp = static_cast<CEffectProp*>( m_pEffectProp );
	if( !pProp )
	{
		return;
	}

	uint32 uCurTime = WareTime::getTickCount();
	if( m_uStartTime == 0 )
	{
		m_uStartTime = uCurTime;
	}

	float32 fElapseTime = static_cast<float32>( uCurTime - m_uStartTime );
	float32 fTotalTime = static_cast<float32>( pProp->m_uTotalTime );
	float32 fPos = fElapseTime / fTotalTime;
	if( fPos == 0.00000f )
	{
		fPos = 0.0f;
	}
	else
	{
		fPos = fPos - floor( fPos );
	}

	CEffectUnit* pEffectUnit = NULL;
	size_t size = m_vecEffectUnitTrack.size();
	for( size_t i = 0; i < size; ++i )
	{
		if( m_vecEffectUnitTrack[i]->pEffectUnit )
		{
			pEffectUnit = static_cast<CEffectUnit*>( m_vecEffectUnitTrack[i]->pEffectUnit );

			if( fPos >= m_vecEffectUnitTrack[i]->fStartPos && fPos <= m_vecEffectUnitTrack[i]->fEndPos )
			{
				pEffectUnit = static_cast<CEffectUnit*>( m_vecEffectUnitTrack[i]->pEffectUnit );
				if( !m_vecEffectUnitTrack[i]->bActive )
				{
					pEffectUnit->setStartTime( uCurTime );

					m_vecEffectUnitTrack[i]->bActive = true;

					/// ���˳���ǲ�ι�ϵ
					addChild( pEffectUnit, i, pEffectUnit->getID() );
				}

				pEffectUnit->update( dt );
			}
			else
			{
				pEffectUnit->setStartTime( 0 );
				m_vecEffectUnitTrack[i]->bActive = false;

				//if( pEffectUnit->getType() != EFFECTUNIT_TYPE_PARTICLESYS )
				//{
				removeChildByTag( pEffectUnit->getID() );
				//}
			}
		}
	}

	return;
}

IEffectProp* CEffect::getEffectProp()
{
	return m_pEffectProp;
}
//-------------------------------------------------------------------------
/**
@brief 
@param
*/
void CEffect::onExit()
{
	size_t size = m_vecEffectUnitTrack.size();
	for( size_t i = 0; i < size; ++i )
	{
		if( m_vecEffectUnitTrack[i]->bActive )
		{
			removeChild( m_vecEffectUnitTrack[i]->pEffectUnit );
		}
	}
}
//-------------------------------------------------------------------------
/**
@brief �������ɫ
@param
*/
void CEffect::setColor( const ccColor3B& color )
{
	//size_t size = m_vecEffectUnitTrack.size();
	//for( size_t i = 0; i < size; ++i )
	//{
	//	m_vecEffectUnitTrack[i]->pEffectUnit->setColor( color );
	//}
}
//-------------------------------------------------------------------------
/**
@brief ����͸����
@param byAlpha ͸����
*/
void CEffect::setOpacity( BYTE byAlpha )
{
	//size_t size = m_vecEffectUnitTrack.size();
	//for( size_t i = 0; i < size; ++i )
	//{
	//	m_vecEffectUnitTrack[i]->pEffectUnit->setOpacity( byAlpha );
	//}
}
//-------------------------------------------------------------------------
/**
@brief ��ȡ�ö����������(ȫ��Ψһ)
@param strFeature ������
*/
void CEffect::getFeatureString( std::string& strFeature )
{
	strFeature = m_strEffectName;
}
//-------------------------------------------------------------------------
/**
@brief ��ײ���
@param
*/
bool CEffect::hitTest( const CCPoint& pt )
{
	size_t size = m_vecEffectUnitTrack.size();
	for( size_t i = 0; i < size; ++i )
	{
		CCRect rect = m_vecEffectUnitTrack[i]->pEffectUnit->boundingBox();
		return rect.containsPoint( pt );
	}

	return false;
}
//-------------------------------------------------------------------------
/**
@brief ��ײ���
@param
*/
bool CEffect::hitTest( const CCRect& rect )
{
	size_t size = m_vecEffectUnitTrack.size();
	for( size_t i = 0; i < size; ++i )
	{
		CCRect rect = m_vecEffectUnitTrack[i]->pEffectUnit->boundingBox();
		return rect.intersectsRect( rect );
	}

	return false;
}
//-------------------------------------------------------------------------
/**
@brief ��ȡ�����Χ��
@param
*/
bool CEffect::getBoundingBox( CCRect& boundBox )
{
	boundBox = boundingBoxReal();
	boundBox = CCRectApplyAffineTransform(boundBox, nodeToParentTransform());

	return true; 
}
//-------------------------------------------------------------------------
/**
@brief ��ȡƫ��
@param
*/
void CEffect::setOffset( CCPoint& ptOffet )
{
	setPosition( ptOffet );
}
//-------------------------------------------------------------------------
/**
@brief ��ȡƫ��
@param
*/
void CEffect::getOffset( CCPoint& ptOffet )
{
	ptOffet = getPosition();
}


//////////////////////////////////////////////////////////////////////////
bool CEffect::createEffect( IEffectProp* pEffectProp )
{
	if( !pEffectProp )
	{
		return false;
	}

	if( m_pEffectProp )
	{
		m_pEffectProp->release();
	}

	m_pEffectProp = pEffectProp;
	pEffectProp->retain();

	///
	CEffectProp* pProp = static_cast<CEffectProp*>( pEffectProp );
	const EffectUnitTrack& Track = pProp->getEffectUnitTracks();

	size_t size = Track.size();
	SEffectTrack* pTrack = NULL;
	for( size_t i = 0; i < size; ++i )
	{
		pTrack = new SEffectTrack();
		pTrack->fStartPos = Track[i]->fStartPos;
		pTrack->fEndPos = Track[i]->fEndPos;
		
		CEffectUnit* pEffectUnit = NULL;
		if( Track[i]->pEffectUnitProp )
		{
			pEffectUnit = createEffectUnit( Track[i]->pEffectUnitProp );
			pEffectUnit->create();
		}

		pTrack->pEffectUnit = pEffectUnit;

		m_vecEffectUnitTrack.push_back( pTrack );
	}

	scheduleUpdate();

	return true;
}

CEffectUnit* CEffect::createEffectUnit( IEffectUnitProp* pEffectUnitProp )
{
	int32 nType = pEffectUnitProp->getType();

	if( ++m_uEffectUnitID == 0 )
	{
		++m_uEffectUnitID;
	}
	if( nType == EFFECTUNIT_TYPE_TEXTUREANI )
	{
		return new CTextureAnimation( pEffectUnitProp,m_uEffectUnitID );
	}
	else if( nType == EFFECTUNIT_TYPE_PARTICLESYS )
	{
		return new CParticleSystem( pEffectUnitProp,m_uEffectUnitID );
	}

	return NULL;
}

void CEffect::releaseEffectUnit( IEffectUnit* pEffectUnit )
{
	if( !pEffectUnit )
		return;

	CEffectUnit* pEffectUnitRef = static_cast<CEffectUnit*>(pEffectUnit);
	int32 nType = pEffectUnitRef->getType();
	
	if( nType == EFFECTUNIT_TYPE_TEXTUREANI )
	{
		CTextureAnimation* pTextureAnim = static_cast<CTextureAnimation*>(pEffectUnit);
		SAFE_DELETE( pTextureAnim );
	}
	else if( nType == EFFECTUNIT_TYPE_PARTICLESYS )
	{
		CParticleSystem* pParticleSystem = static_cast<CParticleSystem*>(pEffectUnit);
		SAFE_DELETE( pParticleSystem );
	}
}

NS_CC_ENGINE_END