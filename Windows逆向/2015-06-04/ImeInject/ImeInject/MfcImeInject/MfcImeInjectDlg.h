// MfcImeInjectDlg.h : ͷ�ļ�
//

#pragma once


// CMfcImeInjectDlg �Ի���
class CMfcImeInjectDlg : public CDialog
{
// ����
public:
	CMfcImeInjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCIMEINJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedAttach();
    afx_msg void OnBnClickedDettach();

    HKL m_hImeFile;
    HKL m_retV;
};
