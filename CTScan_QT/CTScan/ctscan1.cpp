<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>CTScanClass</class>
 <widget class="QMainWindow" name="CTScanClass">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>715</width>
    <height>568</height>
   </rect>
  </property>
  <property name="contextMenuPolicy">
   <enum>Qt::CustomContextMenu</enum>
  </property>
  <property name="windowTitle">
   <string>CTScan</string>
  </property>
  <widget class="QWidget" name="centralWidget">
   <widget class="QPushButton" name="pushButton">
    <property name="geometry">
     <rect>
      <x>380</x>
      <y>80</y>
      <width>75</width>
      <height>23</height>
     </rect>
    </property>
    <property name="text">
     <string>PushButton</string>
    </property>
   </widget>
  </widget>
  <widget class="QMenuBar" name="menuBar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>715</width>
     <height>23</height>
    </rect>
   </property>
   <property name="defaultUp">
    <bool>false</bool>
   </property>
  </widget>
  <widget class="QToolBar" name="mainToolBar">
   <attribute name="toolBarArea">
    <enum>TopToolBarArea</enum>
   </attribute>
   <attribute name="toolBarBreak">
    <bool>false</bool>
   </attribute>
  </widget>
  <widget class="QStatusBar" name="statusBar"/>
 </widget>
 <layoutdefault spacing="6" margin="11"/>
 <resources>
  <include location="ctscan.qrc"/>
 </resources>
 <connections/>
</ui>
