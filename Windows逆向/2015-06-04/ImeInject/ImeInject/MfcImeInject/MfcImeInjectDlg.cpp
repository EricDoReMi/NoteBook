// MfcImeInjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MfcImeInject.h"
#include "MfcImeInjectDlg.h"
#include <imm.h>

#pragma comment(lib,"imm32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcImeInjectDlg 对话框




CMfcImeInjectDlg::CMfcImeInjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMfcImeInjectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcImeInjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcImeInjectDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_ATTACH, &CMfcImeInjectDlg::OnBnClickedAttach)
    ON_BN_CLICKED(IDC_DETTACH, &CMfcImeInjectDlg::OnBnClickedDettach)
END_MESSAGE_MAP()


// CMfcImeInjectDlg 消息处理程序

BOOL CMfcImeInjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMfcImeInjectDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMfcImeInjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcImeInjectDlg::OnBnClickedAttach()
{
    // TODO: 在此添加控件通知处理程序代码
    //得到默认的输入法句柄并保存
    ::SystemParametersInfo(
        SPI_GETDEFAULTINPUTLANG,
        0,
        &m_retV,
        0);

    //copy到system目录，只有ime文件在system32下才能装载成功
    CopyFile(
        _T("D:\\MyDll\\ImeInject\\Debug\\MyImeDll.ime"),
        _T("C:\\WINDOWS\\system32\\MyImeDll.ime"),
        FALSE);

    //装载输入法
    m_hImeFile = ImmInstallIME(
        _T("MyImeDll.ime"), 
        _T("我的输入法"));

    if( ImmIsIME(m_hImeFile) )
    {
        //设置为默认输入法
        SystemParametersInfo(
            SPI_SETDEFAULTINPUTLANG,
            0,
            &m_hImeFile,
            SPIF_SENDWININICHANGE);
        MessageBox(_T("安装输入法成功"));
    }
}

void CMfcImeInjectDlg::OnBnClickedDettach()
{
    // TODO: 在此添加控件通知处理程序代码
    ::SystemParametersInfo(
        SPI_SETDEFAULTINPUTLANG,
        0,
        &m_retV,
        SPIF_SENDWININICHANGE);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    if (UnloadKeyboardLayout(m_hImeFile))
    {
        MessageBox(_T("输入法卸载成功"));
    }
}
