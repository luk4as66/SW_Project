/* 
 * File:   MainWindow.h
 * Author: lukasz
 *
 * Created on 11 sierpień 2012, 13:10
 * 
 * this class is responsible for display application main window
 * 
 * 
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H
#include <QtGui/QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QMenu>
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QGridLayout>
#include <QApplication>
#include <QAction>
#include <QPushButton>
#include <cstring>
#include "connectPanelClass.h"
#include "SearchDevices.h"

using namespace std;

class MainWindow : public QMainWindow{
    Q_OBJECT
    private:
        bluetooth search;
        
        string logText;
        QAction *SearchDevicesAction;
        QAction *Exit;
        QAction *ViewDevices;
        QAction *Connect;
        QDialog *searchWindow;
        connectPanelClass *connectPanel;
        QMenu *fileMenu;
        QPushButton *widgetMenuSearchDevices;
        QPushButton *widgetMenuViewDevices;
        QPushButton *widgetMenuExit;
         QPushButton *widgetMenuConnect;
        QTextEdit *showDevices;
        QLabel *logLabel;
        QLabel *temperatureLabel;
        QLabel *tempDeegreLabel;
        QLabel *moveAreaLabel;
        string *temp, *temp2;
        string *fakeList;
        
public:
    
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    
    private slots:
            void find();
            void discovered();
            void connectToDevice();

};

#endif	/* MAINWINDOW_H */

