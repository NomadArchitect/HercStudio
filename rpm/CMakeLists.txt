cmake_minimum_required(VERSION 3.1.0)

project(HercStudio VERSION 1.0.0 LANGUAGES CXX)

message("src:" ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/../HercConfiguration 
       ${CMAKE_SOURCE_DIR}/../HercStudio 
       ${CMAKE_SOURCE_DIR}/../HercPrinter 
       ${CMAKE_SOURCE_DIR}/../HercUtilities)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6Core REQUIRED)
find_package(Qt6Network REQUIRED)

add_compile_definitions(QT_DISABLE_DEPRECATED_BEFORE=0x050F00)

# Input
include_directories(${CMAKE_SOURCE_DIR}//../HercConfiguration 
       ${CMAKE_SOURCE_DIR}//../HercStudio 
       ${CMAKE_SOURCE_DIR}//../HercPrinter 
       ${CMAKE_SOURCE_DIR}//../HercUtilities 
       ui /usr/include/qt6/QtGui /usr/include/qt6/QtWidgets /usr/include/qt6/QtNetwork /usr/include/qt6/QtCore5Compat)

set(SOURCES 
	${CMAKE_SOURCE_DIR}/../HercConfiguration/CardReaderProperties.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/Configuration.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/ConsoleProperties.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/CtcProperties.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/DasdProperties.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/Devices.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/DevicesRename.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/hercconfiguration.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/PrinterProperties.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/PunchProperties.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/TapeProperties.ui
        ${CMAKE_SOURCE_DIR}/../HercConfiguration/TerminalProperties.ui
         ${CMAKE_SOURCE_DIR}/../HercStudio/helpabout.ui
         ${CMAKE_SOURCE_DIR}/../HercStudio/IplConfig.ui
         ${CMAKE_SOURCE_DIR}/../HercStudio/MainWindow.ui
         ${CMAKE_SOURCE_DIR}/../HercStudio/PreferencesWin.ui
         ${CMAKE_SOURCE_DIR}/../HercStudio/Recovery.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdcat.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdconv.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdcopy.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/DasdInit.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/DasdIsup.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/DasdLoad.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdls.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/HetGet.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/HetInit.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/HetMap.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/HetUpd.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/TapeCopy.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/TapeMap.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/TapeSplt.ui
         ${CMAKE_SOURCE_DIR}/../HercUtilities/TapeSpltSubDlg.ui
         ${CMAKE_SOURCE_DIR}/../HercPrinter/PrinterDialog.ui
         ${CMAKE_SOURCE_DIR}/../HercPrinter/StationeryDialog.ui
         ${CMAKE_SOURCE_DIR}/../HercPrinter/DecolationDialog.ui
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/CardReaderProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/ConfigFile.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/ConfigLine.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/Configuration.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/ConfigurationEditor.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/ConfigurationFreeEditor.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/ConsoleProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/CtcProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DasdProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DeviceConfigLine.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DeviceConfigView.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DeviceListView.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DeviceMenuProcessor.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DevicesPane.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DevicesRename.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DevicesWidget.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/DeviceTypes.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/Extended_Ui_CardReaderProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/GenericDeviceProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/NewReaderFile.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/PrinterProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/PunchProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/ReaderFileListView.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/StatusUpdateCollector.cpp
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/SysgProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/SystemConfigLine.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/TapeProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/TerminalProperties.cpp 
           ${CMAKE_SOURCE_DIR}/../HercConfiguration/VisualizedDeviceEntry.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Arguments.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/CommandLine.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Environment.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/FieldTip.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/FontPreferences.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Fonts.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/HelpAbout.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/HerculesExecutor.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/IplConfig.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/LogRunner.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/LogWidget.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/main.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/MainPanel.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/MainPanelClassic.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/MainPanelModern.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/MainWindow.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Mips.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/MipsGauge.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/MipsLed.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/NamedPipe.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/PanelButton.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Preferences.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/PreferencesWin.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Psw.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Recovery.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Regs32.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Regs64.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Runner.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/StatusRunner.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/SynchronizedQueue.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/Watchdog.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdcat.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdconv.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdcopy.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/DasdInit.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/DasdIsup.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/DasdLoad.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/Dasdls.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/DasdTab.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/GenericUtility.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/HetGet.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/HetInit.cpp
           ${CMAKE_SOURCE_DIR}/../HercUtilities/HetMap.cpp
           ${CMAKE_SOURCE_DIR}/../HercUtilities/HetUpd.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/LineEditWithFocus.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/SystemUtils.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/TapeCopy.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/TapeMap.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/TapeSplt.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/UtilityExecutor.cpp 
           ${CMAKE_SOURCE_DIR}/../HercUtilities/UtilityRunner.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/PrinterDialog.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/DecolationRules.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/StationeryDialog.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/Stationery.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/Trigger.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/PagePrinter.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/PrintRunner.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/PrinterItem.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/StringedObject.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/PrinterController.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/DecolationDialog.cpp 
           ${CMAKE_SOURCE_DIR}/../HercStudio/IpValidator.cpp 
           ${CMAKE_SOURCE_DIR}/../HercPrinter/PrinterInterface.cpp
           ${CMAKE_SOURCE_DIR}/../HercStudio/HercStudio.qrc
)	

add_executable(HerculesStudio ${SOURCES} )
target_link_libraries(HerculesStudio PUBLIC Qt6::Widgets PUBLIC Qt6::Network)

include(GNUInstallDirs)
install (PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/HerculesStudio
 DESTINATION ${CMAKE_INSTALL_BINDIR})

add_custom_target(rpm
            DEPENDS package)

if (TARGET rpm) 
	SET(CPACK_GENERATOR "RPM")
	set(CPACK_RPM_PACKAGE_DEPENDS "libqt6widgets6, libqt6network6, qt6-wayland, qt6-qpa-plugins")
	set(CPACK_PACKAGE_NAME "HercStudio")
       set(CPACK_PACKAGE_VERSION "1.6")
        set(CPACK_PACKAGE_RELEASE "0")
	set(CPACK_PACKAGE_CONTACT "dekel35@walla.com")
	set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
	set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
endif()
INCLUDE(CPack)

