// MfcImeInjectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MfcImeInject.h"
#include "MfcImeInjectDlg.h"
#include <imm.h>

#pragma comment(lib,"imm32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcImeInjectDlg �Ի���




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


// CMfcImeInjectDlg ��Ϣ�������

BOOL CMfcImeInjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMfcImeInjectDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMfcImeInjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcImeInjectDlg::OnBnClickedAttach()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    //�õ�Ĭ�ϵ����뷨���������
    ::SystemParametersInfo(
        SPI_GETDEFAULTINPUTLANG,
        0,
        &m_retV,
        0);

    //copy��systemĿ¼��ֻ��ime�ļ���system32�²���װ�سɹ�
    CopyFile(
        _T("D:\\MyDll\\ImeInject\\Debug\\MyImeDll.ime"),
        _T("C:\\WINDOWS\\system32\\MyImeDll.ime"),
        FALSE);

    //װ�����뷨
    m_hImeFile = ImmInstallIME(
        _T("MyImeDll.ime"), 
        _T("�ҵ����뷨"));

    if( ImmIsIME(m_hImeFile) )
    {
        //����ΪĬ�����뷨
        SystemParametersInfo(
            SPI_SETDEFAULTINPUTLANG,
            0,
            &m_hImeFile,
            SPIF_SENDWININICHANGE);
        MessageBox(_T("��װ���뷨�ɹ�"));
    }
}

void CMfcImeInjectDlg::OnBnClickedDettach()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    ::SystemParametersInfo(
        SPI_SETDEFAULTINPUTLANG,
        0,
        &m_retV,
        SPIF_SENDWININICHANGE);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    if (UnloadKeyboardLayout(m_hImeFile))
    {
        MessageBox(_T("���뷨ж�سɹ�"));
    }
}
