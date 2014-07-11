//*************************************************************************
//	��������:	2013-9-6   15:10
//	�ļ�����:	CMaskSprite.h
//  �� �� ��:   Rare	
//	��Ȩ����:	www.cocos2dres.com
//	˵    ��:	���־���(���ڲ�����ͼ����Ⱦ, ����С��ͼ�����ܰ�ť��)
//*************************************************************************
#ifndef _CMASKSPRITE_H__
#define _CMASKSPRITE_H__

#include "cocos2d.h"
#include <string>
#include <map>
#include <list>
#include <vector>

NS_CC_BEGIN

class CMaskSprite : public CCNode
{
	struct SPointInfo
	{
		int			nPointSize;
		ccColor4B	color;
		CCPoint		pos;

		SPointInfo( int size, const ccColor4B& c, const CCPoint& p ) : nPointSize(size), color(c), pos(p)
		{
		}

		SPointInfo() : nPointSize(3), color(ccc4(255,255,255,255)), pos(ccp(0,0))
		{
		}
	};

	struct SSpriteInfo
	{
		CCPoint		m_ptOffset;
		CCSprite*	m_pSprite;

		SSpriteInfo( CCSprite* pSprite, const CCPoint& p ) : m_pSprite(pSprite), m_ptOffset(p)
		{
		}

		SSpriteInfo() : m_pSprite(NULL)
		{
		}
	};

	typedef std::map< int, SPointInfo > PointMap;
	typedef std::list< SSpriteInfo >	SpriteList;

public:
	CMaskSprite(void);
	virtual ~CMaskSprite(void);

	/** Initializes an sprite with a texture and a rect in points, optionally rotated.
	The offset will be (0,0).
	IMPORTANT: This is the designated initializer.
	*/
	bool initMask(const char *pszMaskFileName);

	bool addSprite( const char *pszSpriteName, const CCPoint& offset );
	//virtual void draw(void);

	virtual void update(float delta);

	void	setOffset( const CCPoint& ptOffset );

	CCPoint	getOffset()	{ return m_ptOffset; }

	/// ���ִ�С
	CCSize	getMaskSize() { return m_maskSize; }
	/// Դ��С
	//CCSize	getSrcSize()  { return m_srcSize; }

	/**
	@brief ��ӵ�
	@param
	*/
	int					addPoint( int nPointSize, const ccColor4B color, const CCPoint& pos );

	/**
	@brief ɾ���� 
	@param
	*/
	void				removePoint( int nPointID );

	/**
	@brief �޸ĵ�λ��
	@param
	*/
	void				changePointPos( int nPointID, cocos2d::CCPoint& pos );

	/**
	@brief ��ȡָ����λ��
	@param
	*/
	void				getPointPos( int nPointID, CCPoint& pos );

	/**
	@brief �����
	@param
	*/
	void				clearPoint();

	/**
	@brief ���ø���
	@param
	*/
	void				setUpdate();

	/**
	* Creates an empty sprite without texture. You can call setTexture method subsequently.
	*
	* @return An empty sprite object that is marked as autoreleased.
	*/
	static CMaskSprite* create( const char *pszMaskFileName );

private:

	CCTexture2D*	m_pmaskTexture;

	CCPoint			m_ptOffset;		/// ƫ��

	CCSize			m_maskSize;		/// ���ִ�С
	//CCSize			m_srcSize;		/// ԴͼƬ��С

	CCSprite*		m_pSprite;		/// ͼƬ�������

	CCSprite*		m_pMaskSprite;	/// ���ֲ�
	//CCSprite*		m_pSrcSprite;	/// Դͼ��

	bool			m_bUpdate;		/// �Ƿ���Ҫ����

	std::string		m_strSrcImage;
	std::string		m_strMaskImage;

	SpriteList		m_lstSprite;	/// �����б�
	PointMap		m_mapPoint;
};

NS_CC_END

#endif // _CMASKSPRITE_H__