#include <afxwin.h>
//#include <iostream>
//#include <fstream>
#include "resource.h"
#include "lua.hpp"

//using namespace std;

double ExecuteTaxCalculationFromLua(const char* functionName, double annualIncome) {
	//For Lua 5.4.2
	//ofstream errorFile("errors.txt");

	double tax = 0.0;
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	int result = luaL_dofile(L, "tax_calculation.lua");
	if (result != LUA_OK) {
		const char* error = lua_tostring(L, -1);
		//errorFile << "compilation error";
		//errorFile << error;
	}
	else {
		lua_getglobal(L, functionName);  
		lua_pushnumber(L, annualIncome); 
		result = lua_pcall(L, 1, 1, 0);  
		if (result != LUA_OK) {
			const char* error = lua_tostring(L, -1);
			//errorFile << "runtime error";
			//errorFile << error;
		}
		else if (lua_isnumber(L, -1)) {
			tax = lua_tonumber(L, -1);
		}
	}
	lua_close(L);
	//errorFile.close();
	return tax;
}

class CIncomeTaxCalculatorDlg : public CDialog {
public:
	enum { IDD = IDD_DIALOG_INCOME_TAX_CALCULATOR };
	CIncomeTaxCalculatorDlg();
	~CIncomeTaxCalculatorDlg();
protected:
	virtual BOOL OnInitDialog();
	double CalculateIncomeTaxForNormalCitizen(double annualIncome);
	double CalculateIncomeTaxForSeniorCitizen(double annualIncome);
	double CalculateIncomeTaxForSuperSeniorCitizen(double annualIncome);
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
	afx_msg void OnCheckBoxBnClicked();
protected:
	CString m_strMonthlyIncome;
	CString m_strAnnualIncome;
	BOOL m_isLuaEmbeddingEnabled;
public:
	afx_msg void OnEnSetfocusEditAnnualIncome();
	afx_msg void OnEnSetfocusEditMonthlySalary();
};

CIncomeTaxCalculatorDlg::CIncomeTaxCalculatorDlg() :
CDialog(CIncomeTaxCalculatorDlg::IDD)
, m_strMonthlyIncome(_T(""))
, m_strAnnualIncome(_T(""))
, m_isLuaEmbeddingEnabled(TRUE)
{
}

CIncomeTaxCalculatorDlg::~CIncomeTaxCalculatorDlg() {
}

double CIncomeTaxCalculatorDlg::CalculateIncomeTaxForNormalCitizen(double annualIncome)
{
	if (m_isLuaEmbeddingEnabled) {
		return ExecuteTaxCalculationFromLua("calculate_income_tax_for_normal_citizen", annualIncome);
	}
	double incomeTax = 0.0;
	//OutputDebugStringA("Hello");
	if (annualIncome <= 250000.0)
	{
		//slab 0
		incomeTax = 0.0;
	}
	else if (annualIncome > 250000.0 && annualIncome <= 500000.0){
		//slab 1
		incomeTax = (annualIncome - 250000.0)*0.1;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 500000.0 && annualIncome <= 1000000.0){
		//slab 2
		incomeTax = 25000.0;
		incomeTax += (annualIncome - 500000.0)*0.2;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 1000000.0 && annualIncome <= 10000000.0){
		//slab 3
		incomeTax = 125000.0;
		incomeTax += (annualIncome - 1000000.0)*0.3;
		incomeTax += 0.03 * incomeTax;
	}
	else{
		//slab 4
		incomeTax = 2825000.0;
		incomeTax += (annualIncome - 10000000.0)*0.3;
		incomeTax += 0.15 * incomeTax;
		incomeTax += 0.03 * incomeTax;
	}
	return incomeTax;
}

double CIncomeTaxCalculatorDlg::CalculateIncomeTaxForSeniorCitizen(double annualIncome)
{
	if (m_isLuaEmbeddingEnabled){
		return ExecuteTaxCalculationFromLua("calculate_income_tax_for_senior_citizen", annualIncome);
	}
	double incomeTax = 0.0;
	if (annualIncome <= 300000.0)
	{
		//slab 0
		incomeTax = 0.0;
	}
	else if (annualIncome > 300000.0 && annualIncome <= 500000.0){
		//slab 1
		incomeTax = (annualIncome - 250000.0)*0.1;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 500000.0 && annualIncome <= 1000000.0){
		//slab 2
		incomeTax = 20000.0;
		incomeTax += (annualIncome - 500000.0)*0.2;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 1000000.0 && annualIncome <= 10000000.0){
		//slab 3
		incomeTax = 120000.0;
		incomeTax += (annualIncome - 1000000.0)*0.3;
		incomeTax += 0.03 * incomeTax;
	}
	else{
		//slab 4
		incomeTax = 2820000.0;
		incomeTax += (annualIncome - 10000000.0)*0.3;
		incomeTax += 0.15 * incomeTax;
		incomeTax += 0.03 * incomeTax;
	}
	return incomeTax;
}

double CIncomeTaxCalculatorDlg::CalculateIncomeTaxForSuperSeniorCitizen(double annualIncome)
{
	if (m_isLuaEmbeddingEnabled){
		return ExecuteTaxCalculationFromLua("calculate_income_tax_for_super_senior_citizen", annualIncome);
	}
	double incomeTax = 0.0;
	if (annualIncome <= 500000.0)
	{
		//slab 0
		incomeTax = 0.0;
	}
	else if (annualIncome > 500000.0 && annualIncome <= 1000000.0){
		//slab 1
		incomeTax = (annualIncome - 500000.0)*0.2;
		incomeTax += 0.03 * incomeTax;
	}
	else if (annualIncome > 1000000.0 && annualIncome <= 10000000.0){
		//slab 2
		incomeTax = 100000.0;
		incomeTax += (annualIncome - 1000000.0)*0.3;
		incomeTax += 0.03 * incomeTax;
	}
	else{
		//slab 3
		incomeTax = 2800000.0;
		incomeTax += (annualIncome - 10000000.0)*0.3;
		incomeTax += 0.15 * incomeTax;
		incomeTax += 0.03 * incomeTax;
	}
	return incomeTax;
}


BOOL CIncomeTaxCalculatorDlg::OnInitDialog() {
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON2));
	SetIcon(hIcon, FALSE);
	CheckRadioButton(
		IDC_RADIO_NORMAL_CITIZEN,
		IDC_RADIO_SUPER_SENIOR_CITIZEN,
		IDC_RADIO_NORMAL_CITIZEN);
	CheckRadioButton(
		IDC_RADIO_MONTHLY_INCOME,
		IDC_RADIO_ANNUAL_INCOME,
		IDC_RADIO_MONTHLY_INCOME);
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	pBtn->SetCheck(1);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CIncomeTaxCalculatorDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CIncomeTaxCalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &CIncomeTaxCalculatorDlg::OnCheckBoxBnClicked)
	ON_EN_SETFOCUS(IDC_EDIT_ANNUAL_INCOME, &CIncomeTaxCalculatorDlg::OnEnSetfocusEditAnnualIncome)
	ON_EN_SETFOCUS(IDC_EDIT_MONTHLY_SALARY, &CIncomeTaxCalculatorDlg::OnEnSetfocusEditMonthlySalary)
END_MESSAGE_MAP()

void CIncomeTaxCalculatorDlg::OnEnSetfocusEditAnnualIncome()
{
	// TODO: Add your control notification handler code here
	CheckRadioButton(
		IDC_RADIO_MONTHLY_INCOME,
		IDC_RADIO_ANNUAL_INCOME,
		IDC_RADIO_ANNUAL_INCOME);
}

void CIncomeTaxCalculatorDlg::OnEnSetfocusEditMonthlySalary()
{
	// TODO: Add your control notification handler code here
	CheckRadioButton(
		IDC_RADIO_MONTHLY_INCOME,
		IDC_RADIO_ANNUAL_INCOME,
		IDC_RADIO_MONTHLY_INCOME);
}

void CIncomeTaxCalculatorDlg::OnCheckBoxBnClicked() {
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	UINT nCheck = pBtn->GetState();
	if ((nCheck & BST_CHECKED) != 0) {
		m_isLuaEmbeddingEnabled = TRUE;
	}
	else {
		m_isLuaEmbeddingEnabled = FALSE;
	}
}

void CIncomeTaxCalculatorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	double annualIncome = 0.0;
	double monthlyIncome = 0.0;
	switch (GetCheckedRadioButton(
		IDC_RADIO_MONTHLY_INCOME,
		IDC_RADIO_ANNUAL_INCOME))
	{ 
	case IDC_RADIO_MONTHLY_INCOME:
		GetDlgItemText(IDC_EDIT_MONTHLY_SALARY, m_strMonthlyIncome);
		monthlyIncome = _tstof(m_strMonthlyIncome);
		if (monthlyIncome < 0.0){
			MessageBox(_T("Income must not be less than zero"));
			return;
		}
		annualIncome = 12.0 * monthlyIncome;
		//set yearly income
		{
			CString s;
			s.Format(_T("%0.2f"), annualIncome);
			SetDlgItemText(IDC_EDIT_ANNUAL_INCOME, s);
		}
		break;
	case IDC_RADIO_ANNUAL_INCOME:
		GetDlgItemText(IDC_EDIT_ANNUAL_INCOME, m_strAnnualIncome);
		annualIncome = _tstof(m_strAnnualIncome);
		if (annualIncome < 0.0){
			MessageBox(_T("Income must not be less than zero"));
			return;
		}
		monthlyIncome = annualIncome / 12.0;
		//set monthly income
		{
			CString s;
			s.Format(_T("%f"), monthlyIncome);
			SetDlgItemText(IDC_EDIT_MONTHLY_SALARY, s);
		}
		break;
	}

	double incomeTax = 0.0;
	switch(GetCheckedRadioButton(
		IDC_RADIO_NORMAL_CITIZEN, 
		IDC_RADIO_SUPER_SENIOR_CITIZEN))
	{
	case IDC_RADIO_NORMAL_CITIZEN:
		incomeTax = CalculateIncomeTaxForNormalCitizen(annualIncome);
		break;
	case IDC_RADIO_SENIOR_CITIZEN:
		incomeTax = CalculateIncomeTaxForSeniorCitizen(annualIncome);
		break;
	case IDC_RADIO_SUPER_SENIOR_CITIZEN:
		incomeTax = CalculateIncomeTaxForSuperSeniorCitizen(annualIncome);
	}
	CString strIncomeTax;
	strIncomeTax.Format(_T("%0.2f"), incomeTax);
	SetDlgItemText(IDC_EDIT_YEARLY_INCOME_TAX, strIncomeTax);
	double netMonthlyIncome = (annualIncome - incomeTax) / 12.0;
	//
	CString strNetMonthlyIncome;
	strNetMonthlyIncome.Format(_T("%0.2f"), netMonthlyIncome);
	SetDlgItemText(IDC_EDIT_NET_MONTHLY_INCOME, strNetMonthlyIncome);

	 

	//::OpenClipboard(m_hWnd);
	//::EmptyClipboard();
	//HANDLE hData = ::GlobalAlloc(GMEM_MOVEABLE, ::lstrlen(strIncomeTax) + 1);
	//LPWSTR pData = (LPWSTR) ::GlobalLock(hData);
	//::lstrcpy(pData, strIncomeTax);
	//::GlobalUnlock(hData);
	//::SetClipboardData(CF_TEXT, hData);
	//::CloseClipboard();

	//CDialog::OnOK();
}

/////////////////////////////////////////////////////////////////////////////////////////////
class CIncomeTaxCalculator : public CWinApp {
public:
	BOOL InitInstance();
};

BOOL CIncomeTaxCalculator::InitInstance() {
	CIncomeTaxCalculatorDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return TRUE;
}
CIncomeTaxCalculator MyApp; 
/////////////////////////////////////////////////////////////////////////////////////////////







