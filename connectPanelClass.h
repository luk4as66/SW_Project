/* 
 * File:   connectPanelClass.h
 * Author: lukasz
 *
 * Created on 9 wrzesień 2012, 00:38
 */

#ifndef CONNECTPANELCLASS_H
#define	CONNECTPANELCLASS_H
#include <QtGui>
#include <string>

using namespace std;

class connectPanelClass: public QDialog{
public:
    connectPanelClass(string *list,QWidget *parent=0);
    virtual ~connectPanelClass();
public slots:
    void connectWithDevice();
private:
    QListWidget *lw;
    QPushButton *connectWith;
};

#endif	/* CONNECTPANELCLASS_H */

