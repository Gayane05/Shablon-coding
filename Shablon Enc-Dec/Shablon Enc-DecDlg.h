
// Shablon Enc-DecDlg.h : header file
//

#pragma once


// CShablonEncDecDlg dialog
class CShablonEncDecDlg : public CDialogEx
{
// Construction
public:
	CShablonEncDecDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHABLONENCDEC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Source_Data;
	CString Encrypted_Data;
	CString Decrypted_String;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
