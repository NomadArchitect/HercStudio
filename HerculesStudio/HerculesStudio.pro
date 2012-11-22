######################################################################
# Automatically generated by qmake (2.01a) Sat Jan 15 21:23:42 2011
######################################################################

TEMPLATE = app
TARGET = HerculesStudio
INCLUDEPATH += HercConfiguration \
	HercStudio \
	ui \
	HercUtilities
UI_DIR = ui
MOC_DIR = moc
OBJECTS_DIR = obj
!win32{
QMAKE_CC   = @echo [c] $< && $$QMAKE_CC
QMAKE_CXX  = @echo [c++] $< && $$QMAKE_CXX
QMAKE_MOC  = @echo [moc] $< && $$QMAKE_MOC
QMAKE_LINK = @echo [link] $$TARGET && $$QMAKE_LINK
#QMAKE_UIC  = @echo [uic ] $< && $$QMAKE_UIC
QMAKE_CXXFLAGS = -pedantic -Wno-long-long
}

# Input
HEADERS += HercConfiguration/CardReaderProperties.h \
		   HercConfiguration/ConfigFile.h \
		   HercConfiguration/ConfigLine.h \
		   HercConfiguration/Configuration.h \
		   HercConfiguration/ConfigurationEditor.h \
           HercConfiguration/ConfigurationFreeEditor.h \
		   HercConfiguration/ConsoleProperties.h \
		   HercConfiguration/CtcProperties.h \
		   HercConfiguration/DasdProperties.h \
		   HercConfiguration/DeviceConfigLine.h \
		   HercConfiguration/DeviceConfigView.h \
		   HercConfiguration/DeviceListView.h \
		   HercConfiguration/DeviceMenuProcessor.h \
		   HercConfiguration/DevicesPane.h \
		   HercConfiguration/DevicesRename.h \
		   HercConfiguration/DevicesWidget.h \
		   HercConfiguration/DeviceTypes.h \
		   HercConfiguration/Extended_Ui_CardReaderProperties.h \
		   HercConfiguration/GenericDeviceProperties.h \
		   HercConfiguration/NewReaderFile.h \
		   HercConfiguration/PrinterProperties.h \
		   HercConfiguration/PunchProperties.h \
		   HercConfiguration/ReaderFileListView.h \
		   HercConfiguration/StatusUpdateCollector.h \
		   HercConfiguration/SysgProperties.h \
		   HercConfiguration/SystemConfigLine.h \
		   HercConfiguration/TapeProperties.h \
		   HercConfiguration/TerminalProperties.h \
		   HercConfiguration/VisualizedDeviceEntry.h \
		   HercStudio/Arguments.h \
		   HercStudio/CommandLine.h \
		   HercStudio/Environment.h \
		   HercStudio/FontPreferences.h \
		   HercStudio/Fonts.h \
		   HercStudio/HelpAbout.h \
		   HercStudio/HerculesExecutor.h \
		   HercStudio/HerculesStudio.h \
		   HercStudio/IplConfig.h \
		   HercStudio/LogRunner.h \
		   HercStudio/LogWidget.h \
		   HercStudio/MainPanel.h \
		   HercStudio/MainPanelClassic.h \
		   HercStudio/MainPanelModern.h \
		   HercStudio/MainWindow.h \
		   HercStudio/Mips.h \
		   HercStudio/MipsGauge.h \
		   HercStudio/MipsLed.h \
		   HercStudio/NamedPipe.h \
		   HercStudio/PanelButton.h \
		   HercStudio/Preferences.h \
		   HercStudio/PreferencesWin.h \
		   HercStudio/Psw.h \
		   HercStudio/Recovery.h \
		   HercStudio/Regs32.h \
		   HercStudio/Regs64.h \
		   HercStudio/Runner.h \
		   HercStudio/StatusRunner.h \
		   HercStudio/StringTokenizer.h \
		   HercStudio/SynchronizedQueue.h \
		   HercStudio/Watchdog.h \
		   HercUtilities/Dasdcat.h \
		   HercUtilities/Dasdconv.h \
		   HercUtilities/Dasdcopy.h \
		   HercUtilities/DasdInit.h \
		   HercUtilities/DasdIsup.h \
		   HercUtilities/DasdLoad.h \
		   HercUtilities/Dasdls.h \
		   HercUtilities/DasdTab.h \
		   HercUtilities/GenericUtility.h \
		   HercUtilities/HetGet.h \
		   HercUtilities/HetInit.h \
		   HercUtilities/HetMap.h \
		   HercUtilities/HetUpd.h \
		   HercUtilities/LineEditWithFocus.h \
		   HercUtilities/SystemUtils.h \
		   HercUtilities/TapeCopy.h \
		   HercUtilities/TapeMap.h \
		   HercUtilities/TapeSplt.h \
		   HercUtilities/UtilityExecutor.h \
		   HercUtilities/UtilityRunner.h 
FORMS += HercConfiguration/CardReaderProperties.ui \
		 HercConfiguration/Configuration.ui \
		 HercConfiguration/ConsoleProperties.ui \
		 HercConfiguration/CtcProperties.ui \
		 HercConfiguration/DasdProperties.ui \
		 HercConfiguration/Devices.ui \
		 HercConfiguration/DevicesRename.ui \
		 HercConfiguration/hercconfiguration.ui \
		 HercConfiguration/PrinterProperties.ui \
		 HercConfiguration/PunchProperties.ui \
		 HercConfiguration/TapeProperties.ui \
		 HercConfiguration/TerminalProperties.ui \
		 HercStudio/helpabout.ui \
		 HercStudio/IplConfig.ui \
		 HercStudio/MainWindow.ui \
		 HercStudio/PreferencesWin.ui \
		 HercStudio/Recovery.ui \
		 HercUtilities/Dasdcat.ui \
		 HercUtilities/Dasdconv.ui \
		 HercUtilities/Dasdcopy.ui \
		 HercUtilities/DasdInit.ui \
		 HercUtilities/DasdIsup.ui \
		 HercUtilities/DasdLoad.ui \
		 HercUtilities/Dasdls.ui \
		 HercUtilities/HetGet.ui \
		 HercUtilities/HetInit.ui \
		 HercUtilities/HetMap.ui \
		 HercUtilities/HetUpd.ui \
		 HercUtilities/TapeCopy.ui \
		 HercUtilities/TapeMap.ui \
		 HercUtilities/TapeSplt.ui \
		 HercUtilities/TapeSpltSubDlg.ui
SOURCES += HercConfiguration/CardReaderProperties.cpp \
		   HercConfiguration/ConfigFile.cpp \
		   HercConfiguration/ConfigLine.cpp \
		   HercConfiguration/Configuration.cpp \
		   HercConfiguration/ConfigurationEditor.cpp \
           HercConfiguration/ConfigurationFreeEditor.cpp \
		   HercConfiguration/ConsoleProperties.cpp \
		   HercConfiguration/CtcProperties.cpp \
		   HercConfiguration/DasdProperties.cpp \
		   HercConfiguration/DeviceConfigLine.cpp \
		   HercConfiguration/DeviceConfigView.cpp \
		   HercConfiguration/DeviceListView.cpp \
		   HercConfiguration/DeviceMenuProcessor.cpp \
		   HercConfiguration/DevicesPane.cpp \
		   HercConfiguration/DevicesRename.cpp \
		   HercConfiguration/DevicesWidget.cpp \
		   HercConfiguration/DeviceTypes.cpp \
		   HercConfiguration/Extended_Ui_CardReaderProperties.cpp \
		   HercConfiguration/GenericDeviceProperties.cpp \
		   HercConfiguration/NewReaderFile.cpp \
		   HercConfiguration/PrinterProperties.cpp \
		   HercConfiguration/PunchProperties.cpp \
		   HercConfiguration/ReaderFileListView.cpp \
		   HercConfiguration/StatusUpdateCollector.cpp \
		   HercConfiguration/SysgProperties.cpp \
		   HercConfiguration/SystemConfigLine.cpp \
		   HercConfiguration/TapeProperties.cpp \
		   HercConfiguration/TerminalProperties.cpp \
		   HercConfiguration/VisualizedDeviceEntry.cpp \
		   HercStudio/Arguments.cpp \
		   HercStudio/CommandLine.cpp \
		   HercStudio/Environment.cpp \
		   HercStudio/FontPreferences.cpp \
		   HercStudio/Fonts.cpp \
		   HercStudio/HelpAbout.cpp \
		   HercStudio/HerculesExecutor.cpp \
		   HercStudio/IplConfig.cpp \
		   HercStudio/LogRunner.cpp \
		   HercStudio/LogWidget.cpp \
		   HercStudio/main.cpp \
		   HercStudio/MainPanel.cpp \
		   HercStudio/MainPanelClassic.cpp \
		   HercStudio/MainPanelModern.cpp \
		   HercStudio/MainWindow.cpp \
		   HercStudio/Mips.cpp \
		   HercStudio/MipsGauge.cpp \
		   HercStudio/MipsLed.cpp \
		   HercStudio/NamedPipe.cpp \
		   HercStudio/PanelButton.cpp \
		   HercStudio/Preferences.cpp \
		   HercStudio/PreferencesWin.cpp \
		   HercStudio/Psw.cpp \
		   HercStudio/Recovery.cpp \
		   HercStudio/Regs32.cpp \
		   HercStudio/Regs64.cpp \
		   HercStudio/Runner.cpp \
		   HercStudio/StatusRunner.cpp \
		   HercStudio/SynchronizedQueue.cpp \
		   HercStudio/Watchdog.cpp \
		   HercUtilities/Dasdcat.cpp \
		   HercUtilities/Dasdconv.cpp \
		   HercUtilities/Dasdcopy.cpp \
		   HercUtilities/DasdInit.cpp \
		   HercUtilities/DasdIsup.cpp \
		   HercUtilities/DasdLoad.cpp \
		   HercUtilities/Dasdls.cpp \
		   HercUtilities/DasdTab.cpp \
		   HercUtilities/GenericUtility.cpp \
		   HercUtilities/HetGet.cpp \
		   HercUtilities/HetInit.cpp \
		   HercUtilities/HetMap.cpp \
		   HercUtilities/HetUpd.cpp \
		   HercUtilities/LineEditWithFocus.cpp \
		   HercUtilities/SystemUtils.cpp \
		   HercUtilities/TapeCopy.cpp \
		   HercUtilities/TapeMap.cpp \
		   HercUtilities/TapeSplt.cpp \
		   HercUtilities/UtilityExecutor.cpp \
		   HercUtilities/UtilityRunner.cpp 
RESOURCES += HercStudio/HercStudio.qrc
target.path = /usr/bin
INSTALLS += target
CONFIG += warn_on
CONFIG += debug_and_release
macx:RC_FILE = hercstudio.icns
