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
#include <QLineEdit>
#include <QTextEdit>

class MainWindow : public QWidget{
public:
    MainWindow(QWidget *parent = 0);
    MainWindow(const MainWindow& orig);
    virtual ~MainWindow();
private:
     QLineEdit *nameLine;
     QTextEdit *addressText;

};

#endif	/* MAINWINDOW_H */

