; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=gamepass
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "demo2.h"

ClassCount=10
Class1=CDemo2App
Class2=CDemo2Dlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_DIALOG_hajime
Resource2=IDR_MAINFRAME
Class4=newday
Class5=CMsgDlg
Resource3=IDD_DEMO2_DIALOG
Class6=hapwarn30
Resource4=IDD_ABOUTBOX
Class7=warn30result
Resource5=IDD_DIALOG_low_hap_warn
Class8=hajime
Resource6=IDD_DIALOG_gameover
Class9=gameover
Resource7=IDD_DIALOG_low_hap_result
Class10=gamepass
Resource8=IDD_DIALOG_gamepass

[CLS:CDemo2App]
Type=0
HeaderFile=demo2.h
ImplementationFile=demo2.cpp
Filter=N

[CLS:CDemo2Dlg]
Type=0
HeaderFile=demo2Dlg.h
ImplementationFile=demo2Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_day

[CLS:CAboutDlg]
Type=0
HeaderFile=demo2Dlg.h
ImplementationFile=demo2Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_DEMO2_DIALOG]
Type=1
Class=CDemo2Dlg
ControlCount=18
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_day,edit,1484849280
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_happy,edit,1484849280
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_score,edit,1484849280
Control9=IDC_EDIT_output,edit,1484849284
Control10=IDC_BUTTON_class,button,1342242816
Control11=IDC_BUTTON_rest,button,1342242816
Control12=IDC_BUTTON_outplay,button,1342242816
Control13=IDC_BUTTON_selfstudy,button,1342242816
Control14=IDC_EDIT_random,edit,1484849284
Control15=IDC_EDIT_change,edit,1484849280
Control16=IDC_BUTTON4,button,1342251008
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT_alert,edit,1484849280

[CLS:newday]
Type=0
HeaderFile=newday.h
ImplementationFile=newday.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CMsgDlg]
Type=0
HeaderFile=MsgDlg.h
ImplementationFile=MsgDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:hapwarn30]
Type=0
HeaderFile=hapwarn30.h
ImplementationFile=hapwarn30.cpp
BaseClass=CDialog
Filter=D

[CLS:warn30result]
Type=0
HeaderFile=warn30result.h
ImplementationFile=warn30result.cpp
BaseClass=CDialog
Filter=D

[CLS:hajime]
Type=0
HeaderFile=hajime.h
ImplementationFile=hajime.cpp
BaseClass=CDialog
Filter=D

[CLS:gameover]
Type=0
HeaderFile=gameover.h
ImplementationFile=gameover.cpp
BaseClass=CDialog
Filter=D

[CLS:gamepass]
Type=0
HeaderFile=gamepass.h
ImplementationFile=gamepass.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DIALOG_gamepass]
Type=1
Class=gamepass
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_gameover]
Type=1
Class=gameover
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_hajime]
Type=1
Class=hajime
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_low_hap_result]
Type=1
Class=warn30result
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_low_hap_warn]
Type=1
Class=hapwarn30
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

