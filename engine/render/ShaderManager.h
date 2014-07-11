//*************************************************************************
//	��������:	2013-9-5   17:41
//	�ļ�����:	ShaderManager.h
//  �� �� ��:   Rare	
//	��Ȩ����:	www.cocos2dres.com
//	˵    ��:	Shader������
//*************************************************************************
#ifndef _SHADERMANAGER_H__
#define _SHADERMANAGER_H__

#include "cocos2dx_macros.h"
#include "shaders/CCGLProgram.h"
#include <vector>
#include <string>

NS_CC_ENGINE_BEGIN

class CShaderManager
{
private:
	CShaderManager(void);
	~CShaderManager(void);

public:

	static CShaderManager& Instance()
	{
		static CShaderManager _inst;
		return _inst;
	}

	/**
	@brief pszGLProgramName shader�ļ���
	@param
	*/
	CCGLProgram*	getGLProgram( const char* pszGLProgramName );

	/**
	@brief 
	@param
	*/
	void			reloadAllGLProgram();

private:

	/**
	@brief pszGLProgramName shader�ļ���
	@param
	*/
	void			loadGLProgram( CCGLProgram* pProgram, const char* pszGLProgramName );


private:

	std::vector<std::string>	m_vecGLPrograme;		/// Shader������
};

NS_CC_ENGINE_END

#endif // _SHADERMANAGER_H__

