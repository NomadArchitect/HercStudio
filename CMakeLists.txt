cmake_minimum_required(VERSION 3.1.0)

project(HercStudio VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_AUTOUIC_SEARCH_PATHS HercConfiguration HercStudio HercPrinter HercUtilities)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6Core REQUIRED)
find_package(Qt6Network REQUIRED)

add_compile_definitions(QT_DISABLE_DEPRECATED_BEFORE=0x050F00)

# Input
include_directories(HercConfiguration HercStudio HercPrinter HercUtilities ui /usr/include/qt6/QtGui /usr/include/qt6/QtWidgets /usr/include/qt6/QtNetwork /usr/include/qt6/QtCore5Compat)

set(SOURCES 
         HercConfiguration/CardReaderProperties.ui
         HercConfiguration/Configuration.ui
         HercConfiguration/ConsoleProperties.ui
         HercConfiguration/CtcProperties.ui
         HercConfiguration/DasdProperties.ui
         HercConfiguration/Devices.ui
         HercConfiguration/DevicesRename.ui
         HercConfiguration/hercconfiguration.ui
         HercConfiguration/PrinterProperties.ui
         HercConfiguration/PunchProperties.ui
         HercConfiguration/TapeProperties.ui
         HercConfiguration/TerminalProperties.ui
         HercStudio/helpabout.ui
         HercStudio/IplConfig.ui
         HercStudio/MainWindow.ui
         HercStudio/PreferencesWin.ui
         HercStudio/Recovery.ui
         HercUtilities/Dasdcat.ui
         HercUtilities/Dasdconv.ui
         HercUtilities/Dasdcopy.ui
         HercUtilities/DasdInit.ui
         HercUtilities/DasdIsup.ui
         HercUtilities/DasdLoad.ui
         HercUtilities/Dasdls.ui
         HercUtilities/HetGet.ui
         HercUtilities/HetInit.ui
         HercUtilities/HetMap.ui
         HercUtilities/HetUpd.ui
         HercUtilities/TapeCopy.ui
         HercUtilities/TapeMap.ui
         HercUtilities/TapeSplt.ui
         HercUtilities/TapeSpltSubDlg.ui
         HercPrinter/PrinterDialog.ui
         HercPrinter/StationeryDialog.ui
         HercPrinter/DecolationDialog.ui
           HercConfiguration/CardReaderProperties.cpp 
           HercConfiguration/ConfigFile.cpp 
           HercConfiguration/ConfigLine.cpp 
           HercConfiguration/Configuration.cpp 
           HercConfiguration/ConfigurationEditor.cpp 
           HercConfiguration/ConfigurationFreeEditor.cpp 
           HercConfiguration/ConsoleProperties.cpp 
           HercConfiguration/CtcProperties.cpp 
           HercConfiguration/DasdProperties.cpp 
           HercConfiguration/DeviceConfigLine.cpp 
           HercConfiguration/DeviceConfigView.cpp 
           HercConfiguration/DeviceListView.cpp 
           HercConfiguration/DeviceMenuProcessor.cpp 
           HercConfiguration/DevicesPane.cpp 
           HercConfiguration/DevicesRename.cpp 
           HercConfiguration/DevicesWidget.cpp 
           HercConfiguration/DeviceTypes.cpp 
           HercConfiguration/Extended_Ui_CardReaderProperties.cpp 
           HercConfiguration/GenericDeviceProperties.cpp 
           HercConfiguration/NewReaderFile.cpp 
           HercConfiguration/PrinterProperties.cpp 
           HercConfiguration/PunchProperties.cpp 
           HercConfiguration/ReaderFileListView.cpp 
           HercConfiguration/StatusUpdateCollector.cpp
           HercConfiguration/SysgProperties.cpp 
           HercConfiguration/SystemConfigLine.cpp 
           HercConfiguration/TapeProperties.cpp 
           HercConfiguration/TerminalProperties.cpp 
           HercConfiguration/VisualizedDeviceEntry.cpp 
           HercStudio/Arguments.cpp 
           HercStudio/CommandLine.cpp 
           HercStudio/Environment.cpp 
           HercStudio/FieldTip.cpp 
           HercStudio/FontPreferences.cpp 
           HercStudio/Fonts.cpp 
           HercStudio/HelpAbout.cpp 
           HercStudio/HerculesExecutor.cpp 
           HercStudio/IplConfig.cpp 
           HercStudio/LogRunner.cpp 
           HercStudio/LogWidget.cpp 
           HercStudio/main.cpp 
           HercStudio/MainPanel.cpp 
           HercStudio/MainPanelClassic.cpp 
           HercStudio/MainPanelModern.cpp 
           HercStudio/MainWindow.cpp 
           HercStudio/Mips.cpp 
           HercStudio/MipsGauge.cpp 
           HercStudio/MipsLed.cpp 
           HercStudio/NamedPipe.cpp 
           HercStudio/PanelButton.cpp 
           HercStudio/Preferences.cpp 
           HercStudio/PreferencesWin.cpp 
           HercStudio/Psw.cpp 
           HercStudio/Recovery.cpp 
           HercStudio/Regs32.cpp 
           HercStudio/Regs64.cpp 
           HercStudio/Runner.cpp 
           HercStudio/StatusRunner.cpp 
           HercStudio/SynchronizedQueue.cpp 
           HercStudio/Watchdog.cpp 
           HercUtilities/Dasdcat.cpp 
           HercUtilities/Dasdconv.cpp 
           HercUtilities/Dasdcopy.cpp 
           HercUtilities/DasdInit.cpp 
           HercUtilities/DasdIsup.cpp 
           HercUtilities/DasdLoad.cpp 
           HercUtilities/Dasdls.cpp 
           HercUtilities/DasdTab.cpp 
           HercUtilities/GenericUtility.cpp 
           HercUtilities/HetGet.cpp 
           HercUtilities/HetInit.cpp
           HercUtilities/HetMap.cpp
           HercUtilities/HetUpd.cpp 
           HercUtilities/LineEditWithFocus.cpp 
           HercUtilities/SystemUtils.cpp 
           HercUtilities/TapeCopy.cpp 
           HercUtilities/TapeMap.cpp 
           HercUtilities/TapeSplt.cpp 
           HercUtilities/UtilityExecutor.cpp 
           HercUtilities/UtilityRunner.cpp 
           HercPrinter/PrinterDialog.cpp 
           HercPrinter/DecolationRules.cpp 
           HercPrinter/StationeryDialog.cpp 
           HercPrinter/Stationery.cpp 
           HercPrinter/Trigger.cpp 
           HercPrinter/PagePrinter.cpp 
           HercPrinter/PrintRunner.cpp 
           HercPrinter/PrinterItem.cpp 
           HercStudio/StringedObject.cpp 
           HercPrinter/PrinterController.cpp 
           HercPrinter/DecolationDialog.cpp 
           HercStudio/IpValidator.cpp 
           HercPrinter/PrinterInterface.cpp
           HercStudio/HercStudio.qrc
)	

add_executable(HerculesStudio ${SOURCES} )
target_link_libraries(HerculesStudio PUBLIC Qt6::Widgets PUBLIC Qt6::Network)

include(GNUInstallDirs)
install (PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/HerculesStudio
 DESTINATION ${CMAKE_INSTALL_BINDIR})

add_custom_target(deb
            DEPENDS package)

if (TARGET deb)
      install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/HerculesStudio
      COMPONENT linapp
      DESTINATION "/usr/local/bin/"  
      )
      set(CPACK_GENERATOR "DEB")
      set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Jacob Dekel") 
      set(CPACK_PACKAGE_VERSION_MAJOR "1")
      set(CPACK_PACKAGE_VERSION_MINOR "6")
      set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6widgets6, libqt6network6, qt6-wayland, qt6-qpa-plugins")
endif()
INCLUDE(CPack)

