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

class MainWindow : public QMainWindow{
    Q_OBJECT
    private:
        QLabel *SearchDevicesLabel;
        QAction *SearchDevicesAction;
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    
    public Q_SLOTS:
            void find();

};

#endif	/* MAINWINDOW_H */

