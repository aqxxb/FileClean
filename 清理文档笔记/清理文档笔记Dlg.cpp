
// �����ĵ��ʼ�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ĵ��ʼ�.h"
#include "�����ĵ��ʼ�Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ĵ��ʼ�Dlg �Ի���



C�����ĵ��ʼ�Dlg::C�����ĵ��ʼ�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�����ĵ��ʼ�Dlg::IDD, pParent)
	, m_Edit1(_T(""))
	, m_Edit2(_T(".obj.tlog.lastbuildstate.idb.pdb.pch.res.ilk.exe.sdf.ipch.log"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON3);
}

void C�����ĵ��ʼ�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_LIST1, m_ListBox1);
	DDX_Control(pDX, IDC_LIST2, m_ListBox2);
}

BEGIN_MESSAGE_MAP(C�����ĵ��ʼ�Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C�����ĵ��ʼ�Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C�����ĵ��ʼ�Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C�����ĵ��ʼ�Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C�����ĵ��ʼ�Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// C�����ĵ��ʼ�Dlg ��Ϣ�������

BOOL C�����ĵ��ʼ�Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�����ĵ��ʼ�Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�����ĵ��ʼ�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//���ļ�
void C�����ĵ��ʼ�Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szPath1[MAX_PATH] = {};            //����һ��TCHAR��������szPath1
	BROWSEINFO bi = {};                   
	
	//�Դ�����ɫ���ֵĸ�ʽ�鿴���Ƶ�������

	typedef  struct  _browseinfo {           //�����������ܲ����ͽ����û�ѡ����ļ��е���Ϣ��
	HWND                  hwndOwner;         //�Ի���������ߴ��ڵľ��
	PCIDLIST_ABSOLUTE     pidlRoot;			 //��ʼ��Ŀ¼
	LPTSTR                pszDisplayName;	 //���������û�ѡ�е�Ŀ¼�ַ������ڴ��ַ
	LPCTSTR               lpszTitle;		 //������ļ��жԻ������ʾ�ı�
	UINT                  ulFlags;			 //ָ���Ի���ѡ��ı�־
	BFFCALLBACK           lpfn;				 //�ñ�־λ�����˶Ի����ѡ�
	LPARAM                lParam;			 //�Ի��򴫵ݸ��ص�������һ������ָ��
	int                   iImage;			 //��ѡ��Ŀ¼��ص�ͼ�񡣸�ͼ�񽫱�ָ��Ϊϵͳͼ���б��е�����ֵ
	} BROWSEINFO, *PBROWSEINFO, *LPBROWSEINFO;

	// �ļ���ѡ��Ի����������ھ��
	bi.hwndOwner = m_hWnd;
	bi.pszDisplayName = szPath1;
	// ����˵����Ϣ
	bi.lpszTitle = L"��Ҫ�������ļ���";
	// �Ի�����༭��
	bi.ulFlags = BIF_EDITBOX;
	LPITEMIDLIST pid;
	// ���ر�ʶ�ļ���·���ġ�PIDL���������ҵ��ļ���·��
	pid = SHBrowseForFolder(&bi);       //��ʾһ���Ի��򣬸öԻ��������û�ѡ��shell�ļ��С�
	SHGetPathFromIDList(pid, szPath1);  //
	// ��·�����µ�·����ʾ�༭����
	m_Edit1 = szPath1;
	// ��·�����µ�·����ʾListBox��
	if (LB_ERR == m_ListBox1.FindString(0, m_Edit1))
	{// ���m_ListBox����û������µ��ļ���·��������ӽ�m_ListBox
		m_ListBox1.AddString(m_Edit1);
	}
	// �ѱ������ݸ��µ��Ի���
	UpdateData(FALSE);
	// �����ͷŵ�֮ǰ�ġ�PID��
	CoTaskMemFree(pid);
}

//���º�׺
void C�����ĵ��ʼ�Dlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}

void C�����ĵ��ʼ�Dlg::TraverseFile(
	TCHAR  szPath[MAX_PATH], // Ҫ�������ļ�·��
	const CString &strFilter,// ���˵��ļ���׺
	vector<CString> &vecPath)// ������������ļ�
{
	// ���ļ���ĩβ���\\*�����������ļ�
	CString strPath = szPath;
	strPath += L"\\*";
	WIN32_FIND_DATA fi = {};
	// �ҵ����ļ���Ϣ�ŵ�fi����
	HANDLE hFile = FindFirstFile(strPath, &fi);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return;
	}
	do
	{
		// �ж��Ƿ�ǰĿ¼���ϼ�Ŀ¼
		if (!lstrcmp(fi.cFileName, L".") || !lstrcmp(fi.cFileName, L".."))
		{
			continue;
		}
		// �ж��Ƿ����ļ��У����ǣ��ݹ����
		if (fi.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			CString strDIr = szPath;
			strDIr += L"\\";
			strDIr += fi.cFileName;
			TraverseFile(strDIr.GetBuffer(), strFilter, vecPath);
			continue;
		}
		// ��ȡ�ļ���չ���������ж��Ƿ������ļ���׺
		TCHAR *p = PathFindExtension(fi.cFileName);
		// Find���ز��ҵ��Ӵ�p��m_Delete�е����������Ҳ�������-1
		if (-1 == strFilter.Find(p))
		{
			continue;
		}
		// ��������ɸѡ�������ҵ�Ҫɾ�����ļ����ˣ���֮ǰ��·�����������·��
		CString strDIr = szPath;
		strDIr += L"\\";
		strDIr += fi.cFileName;
		// �����·��������
		vecPath.push_back(strDIr);
	} while (FindNextFile(hFile, &fi));

}

//��ʼ����
void C�����ĵ��ʼ�Dlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// ����֮ǰ�����֮ǰ�������ļ���Ϣ���б������
	m_vecFileDelete.clear();
	m_ListBox2.ResetContent();
	// ��ȡҪ�������ļ�����Ŀ
	int nCount = m_ListBox1.GetCount();
	for (int i = 0; i < nCount; i++)
	{
		CString test;
		// ��ȡListBox�ؼ��ڵ��ļ���·��
		m_ListBox1.GetText(i, test);
		// �����ļ����ڵ������ļ������ļ���
		TraverseFile(test.GetBuffer(), m_Edit2, m_vecFileDelete);
	}
	// ����������Ҫɾ���ļ���ӵ�ListBox����ʾ����
	for (DWORD i = 0; i < m_vecFileDelete.size(); i++)
	{
		m_ListBox2.AddString(m_vecFileDelete[i]);
		m_ListBox2.SelectString(i, m_vecFileDelete[i]);

	}
}

//��ʼɾ��
void C�����ĵ��ʼ�Dlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (DWORD i = 0; i < m_vecFileDelete.size(); i++)
	{
		DeleteFile(m_vecFileDelete[i].GetBuffer());
		m_ListBox2.DeleteString(0);
	}
	m_vecFileDelete.swap(vector<CString>());
}
