
// �����ĵ��ʼ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�����ĵ��ʼ�App: 
// �йش����ʵ�֣������ �����ĵ��ʼ�.cpp
//

class C�����ĵ��ʼ�App : public CWinApp
{
public:
	C�����ĵ��ʼ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�����ĵ��ʼ�App theApp;