#include "CTextureAnimationProp.h"

NS_CC_ENGINE_BEGIN

CTextureAnimationProp::CTextureAnimationProp(void)
: m_nTotalTime(0)
, m_nWidth(0)
, m_nHeight(0)
, m_nRenderMode(0)
{
	m_strEffectUnitName = "��ͼ����";
	m_uAdvancePropFlag = EFFECT_ADVANCE_OFFSET | EFFECT_ADVANCE_TEXTURE | EFFECT_ADVANCE_SIZE | EFFECT_ADVANCE_COLOR | EFFECT_ADVANCE_ALPHA;
	m_mapOffset[0.0f] = CCPointZero;
	m_mapOffset[1.0f] = CCPointZero;
	m_mapAlpha[0.0f] = 1.0f;
	m_mapAlpha[1.0f] = 1.0f;
	m_mapSize[0.0f] = 1.0f;
	m_mapSize[1.0f] = 1.0f;
	m_mapColor[0.0f] = ccc4(255,255,255,255);
	m_mapColor[1.0f] = ccc4(255,255,255,255);
	m_nTotalTime = 3000;
}

CTextureAnimationProp::~CTextureAnimationProp(void)
{
	DeleteVecObj( m_vecProp );
}

void CTextureAnimationProp::registerProp()
{
	m_vecProp.clear();
	
	//m_vecProp.push_back( new EffectProp( "���", m_nWidth ) );
	//m_vecProp.push_back( new EffectProp( "�߶�", m_nHeight ) );
	m_vecProp.push_back( new EffectProp( "��������ʱ��", m_nTotalTime ) );
	//m_vecProp.push_back( new EffectProp( "λ��", m_Pos ) );
	//m_vecProp.push_back( new EffectProp( "�ļ���", m_strEffectUnitName, true ) );
}


bool CTextureAnimationProp::loadProp( CWareFileRead& File )
{
	CEffectUnitProp::loadProp( File );

	File.read( &m_nTotalTime, sizeof(int32) );
	//File.read( &m_nWidth, sizeof(int32) );
	//File.read( &m_nHeight, sizeof(int32) );

	return true;
}

void CTextureAnimationProp::saveProp( CWareFileWrite& File )
{
	CEffectUnitProp::saveProp( File );

	File.write( &m_nTotalTime, sizeof(int32) );
	//File.write( &m_nWidth, sizeof(int32) );
	//File.write( &m_nHeight, sizeof(int32) );
}

int32 CTextureAnimationProp::setProp( std::vector< EffectProp* >& PropList )
{
	int32 nIndex = CEffectUnitProp::setProp( PropList );

	size_t size = PropList.size();
	size_t i = static_cast<size_t>( nIndex );
	for( ; i < size; ++i )
	{
		//if( PropList[i]->Name() == "���" ) { m_nWidth = PropList[i]->GetData().Int(); continue; }
		//if( PropList[i]->Name() == "�߶�" ) { m_nHeight = PropList[i]->GetData().Int(); continue; }
		if( PropList[i]->Name() == "��������ʱ��" ) { m_nTotalTime = PropList[i]->GetData().Int(); continue; }
		//if( m_vecProp[i]->Name() == "λ��" ) { m_vecProp[i]->GetData().Vector2( m_Pos ); continue; }
		//if( m_vecProp[i]->Name() == "�ļ���" ) { m_vecProp[i]->GetData().String( m_strEffectUnitName ); continue; }
	}

	return static_cast<int32>( i );
}

void CTextureAnimationProp::getProp( std::vector< EffectProp* >& PropList )
{
	CEffectUnitProp::getProp( PropList );

	size_t size = m_vecProp.size();
	for( size_t i = 0; i < size; ++i )
	{
		//if( m_vecProp[i]->Name() == "���" ) { m_vecProp[i]->GetData() = m_nWidth; PropList.push_back(m_vecProp[i]); continue; }
		//if( m_vecProp[i]->Name() == "�߶�" ) { m_vecProp[i]->GetData() = m_nHeight; PropList.push_back(m_vecProp[i]); continue; }
		if( m_vecProp[i]->Name() == "��������ʱ��" ) { m_vecProp[i]->GetData() = m_nTotalTime; PropList.push_back(m_vecProp[i]); continue; }
		//if( m_vecProp[i]->Name() == "λ��" ) { m_vecProp[i]->GetData() = m_Pos; PropList.push_back( m_vecProp[i] ); continue; }
		//if( m_vecProp[i]->Name() == "�ļ���" ) { m_vecProp[i]->GetData() = m_strEffectUnitName; PropList.push_back( m_vecProp[i] ); continue; }
	}
}

uint32 CTextureAnimationProp::getAdvanceProp( OffsetMap& Offset, NameMap& Texture,SizeMap& Size, ColorMap& Color, AlphaMap& Alpha )
{
	CEffectUnitProp::getAdvanceProp( Offset, Texture, Size, Color, Alpha );

	return m_uAdvancePropFlag;
}

NS_CC_ENGINE_END
