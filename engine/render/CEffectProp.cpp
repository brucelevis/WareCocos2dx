#include "CEffectProp.h"
#include "IEffectUnitProp.h"
#include "CEffectPropManager.h"
#include "WareFileRead.h"
#include "WareFileWrite.h"
#include "CTextureAnimationProp.h"
#include "CParticleSystemProp.h"

NS_CC_ENGINE_BEGIN

CEffectProp::CEffectProp( uint32 uID )
: m_uTotalTime(0)
, m_strCustomName("")
, m_bValid(false)
, m_uID(uID)
{
}

CEffectProp::~CEffectProp()
{
	size_t size = m_vecEffectUnitProp.size();
	for( size_t i = 0; i < size; ++i )
	{
		if( m_vecEffectUnitProp[i] )
			releaseEffectUnitProp( m_vecEffectUnitProp[i]->pEffectUnitProp );

		delete m_vecEffectUnitProp[i];
	}
}
//-------------------------------------------------------------------------
/**
@brief �ͷ�
@param 
*/
void CEffectProp::release()
{
	if( isSingleReference() )
	{
		CEffectPropManager::Instance().releaseEffectProp( this );
	}
	//else
	//{
		CCObject::release();
	//}	
}
//-------------------------------------------------------------------------
/// ��Դ���ݲ���(ֻ����һ�����ǿ��Էŵ���һ���߳�ȥ����)
int32 CEffectProp::loadRes()
{
	CWareFileRead File;
	if( !File.open( m_strFileName.c_str() ) )
	{
		CCLOG("�� %s ��Ч�ļ�%sʧ�ܣ�", m_strFileName.c_str() );
		return 0;
	}
	int32 nStamp = 0;
	File.read( &nStamp, sizeof(int32) );
	if( nStamp != MAKEFOURCC( 'E', 'F', 'X', 0 ) )
	{
		CCLOG(" %s ��Ч�ļ���ʽ����", m_strFileName.c_str() );
		return 0;
	}

	m_vecEffectUnitProp.clear();

	int32 nTrackSize = 0;
	int32 nType = 0;
	SEffectUnitPropTrack* pTrack = NULL;
	File.read( &nTrackSize, sizeof(int32) );
	for( int32 i = 0; i < nTrackSize; ++i )
	{
		pTrack = new SEffectUnitPropTrack;
		File.read( &nType, sizeof(int32) );

		CEffectUnitProp* pProp = createEffectUnitProp( nType );
		pProp->registerProp();   /// ע����Ҫ������

		pTrack->pEffectUnitProp = pProp;

		if( pTrack->pEffectUnitProp )
		{
			File.read( &pTrack->fStartPos, sizeof(float32) );
			File.read( &pTrack->fEndPos, sizeof(float32) );
			pTrack->pEffectUnitProp->loadProp( File );
		}

		m_vecEffectUnitProp.push_back( pTrack );
	}

	File.read( &m_uTotalTime, sizeof(uint32) );

	File.close();

	m_bValid = true;

	return 0;
}

///// ��Դ���ݲ���
//int32 CEffectProp::UnloadRes()
//{
//	m_bValid = VFALSE;
//	return 0;
//}
//
///// ���ݲ���������Ϻ�Ļص�
//bool CEffectProp::OnResLoaded()
//{
//	m_bValid = VTRUE;
//	return VTRUE;
//}

bool CEffectProp::saveRes( const char* szFileName )
{
	CWareFileWrite File;
	if( !File.open( szFileName ) )
	{
		return false;
	}

	int32 nStamp = MAKEFOURCC( 'E', 'F', 'X', 0 );
	File.write( &nStamp, sizeof(int32) );

	int32 nType = 0;
	size_t size = m_vecEffectUnitProp.size();
	File.write( &size, sizeof(int32) );
	for( size_t i = 0; i < size; ++i )
	{
		if( m_vecEffectUnitProp[i]->pEffectUnitProp )
		{
			nType = m_vecEffectUnitProp[i]->pEffectUnitProp->getType();
			File.write( &nType, sizeof(int32) );
			File.write( &m_vecEffectUnitProp[i]->fStartPos, sizeof(float32) );
			File.write( &m_vecEffectUnitProp[i]->fEndPos, sizeof(float32) );

			m_vecEffectUnitProp[i]->pEffectUnitProp->saveProp( File );
		}
		else
		{
			nType = 0;
			File.write( &nType, sizeof(int32) );
		}
	}

	File.write( &m_uTotalTime, sizeof(uint32) );

	File.close();

	return true;
}

//int32 CEffectProp::Grab()
//{
//	WARE_ASSERT( m_pEffectPropManager, "���ش���:��Ч��Դ������Ϊ��." );
//	return m_pEffectPropManager->ApplyEffect( this );
//}
//
//int32 CEffectProp::Drop()
//{
//	WARE_ASSERT( m_pEffectPropManager, "���ش���:��Ч��Դ������Ϊ��." );
//	m_pEffectPropManager->ReleaseEffectProp( this );
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////
int32 CEffectProp::addEffectUnitProp( int32 nEffectUnitType )
{
	SEffectUnitPropTrack* pTrack = new SEffectUnitPropTrack;

	CEffectUnitProp* pProp = createEffectUnitProp( nEffectUnitType );
	if( pProp )
		pProp->registerProp();   /// ע����Ҫ������

	pTrack->pEffectUnitProp = pProp;

	m_vecEffectUnitProp.push_back( pTrack );

	return static_cast<int32>( m_vecEffectUnitProp.size() - 1 );
}

void CEffectProp::insertEffectUnitProp( int32 nIndex, int32 nEffectUnitType )
{								
	if( nIndex >= static_cast<int32>( m_vecEffectUnitProp.size() ) )
		nIndex = static_cast<int32>( m_vecEffectUnitProp.size() ) - 1;

	SEffectUnitPropTrack* pTrack = new SEffectUnitPropTrack;

	CEffectUnitProp* pProp = createEffectUnitProp( nEffectUnitType );
	if( pProp )
		pProp->registerProp();   /// ע����Ҫ������

	pTrack->pEffectUnitProp = pProp;

	EffectUnitTrack::iterator iter = m_vecEffectUnitProp.begin();
	m_vecEffectUnitProp.insert( iter + nIndex, 1, pTrack );
}

void CEffectProp::setEffectUnitProp( int32 nIndex, int32 nEffectUnitType )
{
	if( nIndex >= static_cast<int32>( m_vecEffectUnitProp.size() ) )
		return;

	if( !m_vecEffectUnitProp[nIndex] )
		return;

	releaseEffectUnitProp( m_vecEffectUnitProp[nIndex]->pEffectUnitProp );

	CEffectUnitProp* pProp = createEffectUnitProp( nEffectUnitType );
	if( pProp )
		pProp->registerProp();   /// ע����Ҫ������

	m_vecEffectUnitProp[nIndex]->pEffectUnitProp = pProp;
}

SEffectUnitPropTrack* CEffectProp::getEffectTrack( int32 nIndex )
{
	if( nIndex < 0 || nIndex >= static_cast<int32>( m_vecEffectUnitProp.size() ) )
		return NULL;

	return m_vecEffectUnitProp[nIndex];
}

void CEffectProp::removeEffectUnitProp( int32 nIndex ) 
{
	if( nIndex >= static_cast<int32>( m_vecEffectUnitProp.size() ) )
		return;

	EffectUnitTrack::iterator iter = m_vecEffectUnitProp.begin();
	iter += nIndex;

	if( m_vecEffectUnitProp[nIndex] )
		releaseEffectUnitProp( m_vecEffectUnitProp[nIndex]->pEffectUnitProp );
	delete m_vecEffectUnitProp[nIndex];

	m_vecEffectUnitProp.erase( iter );
}

//void CEffectProp::SetManager( CEffectPropManager* pEffectPropManager )
//{
//	m_pEffectPropManager = pEffectPropManager;
//}

//////////////////////////////////////////////////////////////////////////
CEffectUnitProp* CEffectProp::createEffectUnitProp( int32 nType )
{
	switch( nType )
	{
	case EFFECTUNIT_TYPE_TEXTUREANI:
		return new CTextureAnimationProp();
	case EFFECTUNIT_TYPE_PARTICLESYS:
		return new CParticleSystemProp();
	default:
		return NULL;
	}
}

void CEffectProp::releaseEffectUnitProp( IEffectUnitProp* pEffectUnitProp )
{
	if( !pEffectUnitProp )
		return;

	int32 nType = pEffectUnitProp->getType();

	if( nType == EFFECTUNIT_TYPE_TEXTUREANI )
	{
		CTextureAnimationProp* pProp = (CTextureAnimationProp*)pEffectUnitProp;
		delete pProp;
	}
	else if( nType == EFFECTUNIT_TYPE_PARTICLESYS )
	{
		CParticleSystemProp* pProp = (CParticleSystemProp*)pEffectUnitProp;
		delete pProp;
	}
}

NS_CC_ENGINE_END