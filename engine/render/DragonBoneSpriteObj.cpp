#include "DragonBoneSpriteObj.h"
#include "StringUtility.h"

NS_CC_ENGINE_BEGIN

std::map< std::string, int >	g_mapArmatureRefrence;	/// �����������ü���

CDragonBoneSpriteObj::CDragonBoneSpriteObj(uint32 uID)
: m_pArmature(NULL)
{
	m_strPicFileName = "";
}
//-------------------------------------------------------------------------
CDragonBoneSpriteObj::~CDragonBoneSpriteObj(void)
{
}
//-------------------------------------------------------------------------
/**
@brief ����
@param szPicFileName ��Դ�ļ���
@param ptOffset ƫ��ֵ
@return ���ش����ɹ�����ʶ
*/
bool CDragonBoneSpriteObj::create( const char* szAniFileName, CCPoint ptOffset )
{
	if( NULL != m_pArmature || szAniFileName == NULL )
	{
		return true;
	}

	m_strPicFileName = szAniFileName;
	/// �����ļ�������������������
	if( g_mapArmatureRefrence.find( m_strPicFileName ) == g_mapArmatureRefrence.end() )
	{
		g_mapArmatureRefrence[m_strPicFileName] = 1;

		std::string strPathName,strFileName,strExtName;
		StringUtility::parseFileName( m_strPicFileName, strPathName, strFileName, strExtName );
		StringUtility::makeLower( strExtName ); /// ת����Сд������������жϴ���
		if( strExtName == "josn" || strExtName == "exportjson" )
		{
			extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(szAniFileName);
		}
		else if( strExtName == "xml" )
		{
			std::string strPngName, strPlistName;
			strPngName = m_strPicFileName;
			strPlistName = m_strPicFileName;
			StringUtility::stringReplace(strPngName,".xml", ".png" );
			StringUtility::stringReplace(strPlistName,".xml", ".plist" );
			extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo( strPngName.c_str(), strPlistName.c_str(), m_strPicFileName.c_str() );
		}
	}
	else
	{
		g_mapArmatureRefrence[m_strPicFileName]++;
	}

	std::string strPathName, strObjName, strExtName;
	StringUtility::parseFileName( m_strPicFileName, strPathName, strObjName, strExtName );
	m_pArmature = extension::CCArmature::create( strObjName.c_str() );
	if( m_pArmature == NULL )
	{
		return false;
	}

	m_Animate.setAnimationRes(m_pArmature->getAnimation());

	addChild( m_pArmature );

	return true;
}
//-------------------------------------------------------------------------
/**
@brief ����
@param
*/
void CDragonBoneSpriteObj::update( float dt )
{

}
//-------------------------------------------------------------------------
/**
@brief 
@param
*/
void CDragonBoneSpriteObj::onExit()
{
	if( m_pArmature ) /// m_pArmature ����autorelease
	{
		if( g_mapArmatureRefrence.find( m_strPicFileName ) != g_mapArmatureRefrence.end() )
		{
			int nRef = g_mapArmatureRefrence[m_strPicFileName];
			if( --nRef == 0 )
			{
				extension::CCArmatureDataManager::sharedArmatureDataManager()->removeArmatureFileInfo(m_strPicFileName.c_str());
				g_mapArmatureRefrence.erase(m_strPicFileName);
			}
			else
			{
				g_mapArmatureRefrence[m_strPicFileName] = nRef;
			}
		}

		removeChild( m_pArmature );
		m_pArmature = NULL;
	}
}
//-------------------------------------------------------------------------
/**
@brief �������ɫ
@param
*/
void CDragonBoneSpriteObj::setColor( const ccColor3B& color )
{
	if( m_pArmature == NULL )
	{
		return;
	}

	m_pArmature->setColor( color );
}
//-------------------------------------------------------------------------
/**
@brief ����͸����
@param byAlpha ͸����
*/
void CDragonBoneSpriteObj::setOpacity( BYTE byAlpha )
{
	if( m_pArmature == NULL )
	{
		return;
	}

	m_pArmature->setOpacity( byAlpha );
}
//-------------------------------------------------------------------------
/**
@brief ��ȡ�ö����������(ȫ��Ψһ)
@param strFeature ������
*/
void CDragonBoneSpriteObj::getFeatureString( std::string& strFeature )
{
	strFeature = m_strPicFileName;
}
//-------------------------------------------------------------------------
/**
@brief ��ײ���
@param
*/
bool CDragonBoneSpriteObj::hitTest( const CCPoint& pt )
{
	if( m_pArmature == NULL )
	{
		return false;
	}

	CCRect rect = m_pArmature->boundingBox();
	return rect.containsPoint( pt );
}
//-------------------------------------------------------------------------
/**
@brief ��ײ���
@param
*/
bool CDragonBoneSpriteObj::hitTest( const CCRect& rect )
{
	if( m_pArmature == NULL )
	{
		return false;
	}

	CCRect rc = m_pArmature->boundingBox();
	return rc.intersectsRect( rect );
}
//-------------------------------------------------------------------------
/**
@brief ��ȡ�����Χ��
@param
*/
bool CDragonBoneSpriteObj::getBoundingBox( CCRect& boundBox )
{
	if( m_pArmature )
	{
		boundBox = m_pArmature->boundingBoxReal();
		boundBox = CCRectApplyAffineTransform(boundBox, nodeToParentTransform());
		return true;
	}

	return false; 
}
//-------------------------------------------------------------------------
/**
@brief ��ȡƫ��
@param
*/
void CDragonBoneSpriteObj::setOffset( CCPoint& ptOffet )
{
	if( m_pArmature )
	{
		m_pArmature->setPosition( ptOffet );
	}
}
//-------------------------------------------------------------------------
/**
@brief ��ȡƫ��
@param
*/
void CDragonBoneSpriteObj::getOffset( CCPoint& ptOffet )
{
	if( m_pArmature )
	{
		ptOffet = m_pArmature->getPosition();
	}
}

NS_CC_ENGINE_END