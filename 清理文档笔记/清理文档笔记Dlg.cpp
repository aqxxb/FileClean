
// 清理文档笔记Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "清理文档笔记.h"
#include "清理文档笔记Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C清理文档笔记Dlg 对话框



C清理文档笔记Dlg::C清理文档笔记Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C清理文档笔记Dlg::IDD, pParent)
	, m_Edit1(_T(""))
	, m_Edit2(_T(".obj.tlog.lastbuildstate.idb.pdb.pch.res.ilk.exe.sdf.ipch.log"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON3);
}

void C清理文档笔记Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_LIST1, m_ListBox1);
	DDX_Control(pDX, IDC_LIST2, m_ListBox2);
}

BEGIN_MESSAGE_MAP(C清理文档笔记Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C清理文档笔记Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C清理文档笔记Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C清理文档笔记Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C清理文档笔记Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// C清理文档笔记Dlg 消息处理程序

BOOL C清理文档笔记Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C清理文档笔记Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C清理文档笔记Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//打开文件
void C清理文档笔记Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szPath1[MAX_PATH] = {};            //定义一个TCHAR类型数组szPath1
	BROWSEINFO bi = {};                   
	
	//以带有颜色区分的格式查看复制到剪贴板

	typedef  struct  _browseinfo {           //包含本程序功能参数和接收用户选择的文件夹的信息。
	HWND                  hwndOwner;         //对话框的所有者窗口的句柄
	PCIDLIST_ABSOLUTE     pidlRoot;			 //初始根目录
	LPTSTR                pszDisplayName;	 //用来保存用户选中的目录字符串的内存地址
	LPCTSTR               lpszTitle;		 //该浏览文件夹对话框的显示文本
	UINT                  ulFlags;			 //指定对话框选项的标志
	BFFCALLBACK           lpfn;				 //该标志位描述了对话框的选项。
	LPARAM                lParam;			 //对话框传递给回调函数的一个参数指针
	int                   iImage;			 //与选中目录相关的图像。该图像将被指定为系统图像列表中的索引值
	} BROWSEINFO, *PBROWSEINFO, *LPBROWSEINFO;

	// 文件夹选择对话框所属窗口句柄
	bi.hwndOwner = m_hWnd;
	bi.pszDisplayName = szPath1;
	// 窗口说明信息
	bi.lpszTitle = L"打开要遍历的文件夹";
	// 对话框带编辑框
	bi.ulFlags = BIF_EDITBOX;
	LPITEMIDLIST pid;
	// 返回标识文件夹路径的“PIDL”，用它找到文件夹路径
	pid = SHBrowseForFolder(&bi);       //显示一个对话框，该对话框允许用户选择shell文件夹。
	SHGetPathFromIDList(pid, szPath1);  //
	// 把路径更新到路径显示编辑框内
	m_Edit1 = szPath1;
	// 把路径更新到路径显示ListBox内
	if (LB_ERR == m_ListBox1.FindString(0, m_Edit1))
	{// 如果m_ListBox里面没有这个新的文件夹路径，再添加进m_ListBox
		m_ListBox1.AddString(m_Edit1);
	}
	// 把变量内容更新到对话框
	UpdateData(FALSE);
	// 用完释放掉之前的“PID”
	CoTaskMemFree(pid);
}

//更新后缀
void C清理文档笔记Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}

void C清理文档笔记Dlg::TraverseFile(
	TCHAR  szPath[MAX_PATH], // 要遍历的文件路径
	const CString &strFilter,// 过滤的文件后缀
	vector<CString> &vecPath)// 保存遍历到的文件
{
	// 向文件夹末尾添加\\*，遍历所有文件
	CString strPath = szPath;
	strPath += L"\\*";
	WIN32_FIND_DATA fi = {};
	// 找到的文件信息放到fi里面
	HANDLE hFile = FindFirstFile(strPath, &fi);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return;
	}
	do
	{
		// 判断是否当前目录或上级目录
		if (!lstrcmp(fi.cFileName, L".") || !lstrcmp(fi.cFileName, L".."))
		{
			continue;
		}
		// 判断是否是文件夹，若是，递归遍历
		if (fi.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			CString strDIr = szPath;
			strDIr += L"\\";
			strDIr += fi.cFileName;
			TraverseFile(strDIr.GetBuffer(), strFilter, vecPath);
			continue;
		}
		// 获取文件扩展名，用于判断是否垃圾文件后缀
		TCHAR *p = PathFindExtension(fi.cFileName);
		// Find返回查找的子串p在m_Delete中的索引，若找不到返回-1
		if (-1 == strFilter.Find(p))
		{
			continue;
		}
		// 经过重重筛选，终于找到要删除的文件名了，和之前的路径构造成完整路径
		CString strDIr = szPath;
		strDIr += L"\\";
		strDIr += fi.cFileName;
		// 保存进路径向量里
		vecPath.push_back(strDIr);
	} while (FindNextFile(hFile, &fi));

}

//开始遍历
void C清理文档笔记Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	// 遍历之前先清空之前遍历的文件信息和列表框内容
	m_vecFileDelete.clear();
	m_ListBox2.ResetContent();
	// 获取要遍历的文件夹数目
	int nCount = m_ListBox1.GetCount();
	for (int i = 0; i < nCount; i++)
	{
		CString test;
		// 获取ListBox控件内的文件夹路径
		m_ListBox1.GetText(i, test);
		// 遍历文件夹内的所有文件和子文件夹
		TraverseFile(test.GetBuffer(), m_Edit2, m_vecFileDelete);
	}
	// 将遍历到的要删除文件添加到ListBox内显示出来
	for (DWORD i = 0; i < m_vecFileDelete.size(); i++)
	{
		m_ListBox2.AddString(m_vecFileDelete[i]);
		m_ListBox2.SelectString(i, m_vecFileDelete[i]);

	}
}

//开始删除
void C清理文档笔记Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	for (DWORD i = 0; i < m_vecFileDelete.size(); i++)
	{
		DeleteFile(m_vecFileDelete[i].GetBuffer());
		m_ListBox2.DeleteString(0);
	}
	m_vecFileDelete.swap(vector<CString>());
}
