/***************************************************************************
 *   Copyright (C) 2008 by P. Sereno                                       *
 *   http://www.sereno-online.com                                          *
 *   http://www.qt4lab.org                                                 *
 *   http://www.qphoton.org                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef QGAUGE_H
#define QGAUGE_H

#include <Qt>
#include <QWidget>
#include <QtDesigner/QDesignerExportWidget>


class QColor;

class QDESIGNER_WIDGET_EXPORT QGauge : public QWidget
{
 Q_OBJECT
    Q_ENUMS( GaugeOrientation )
	Q_PROPERTY(double value READ value WRITE setValue);
	Q_PROPERTY(double minValue READ minValue WRITE setMinValue);
	Q_PROPERTY(double maxValue READ maxValue WRITE setMaxValue);
	Q_PROPERTY(GaugeOrientation orientation READ orientation WRITE setOrientation);
	Q_PROPERTY(bool alarmEnabled READ alarmEnabled WRITE enableAlarm);
	Q_PROPERTY(double alarmThreshold READ alarmThreshold WRITE setAlarmThreshold);
	Q_PROPERTY(int numTicks READ numTicks WRITE setNumTicks);
	Q_PROPERTY(int precision READ precision WRITE setPrecision);

public: 
    enum GaugeOrientation {Horizontal,Vertical};
    QGauge(QWidget *parent = 0);
    double value() const { return m_value; }
    double minValue() const { return m_minValue; }
    double maxValue() const { return m_maxValue; }
    GaugeOrientation orientation() const { return m_orientation; }
    bool alarmEnabled() const { return m_alarmEnabled; }
    double alarmThreshold() const { return m_alarmThreshold; }
    double numTicks() const { return m_numTicks; }
    int precision() const { return m_precision; }     
    QSize sizeHint() const {return QSize(80,180);}
    QSize minimumSizeHint() const {return sizeHint();}
    
public slots:
	void setValue(double);
	void setValue(int);
	void setMinValue(double);	
	void setMaxValue(double);
    void setOrientation(GaugeOrientation);
    void enableAlarm(bool);
    void setAlarmThreshold(double);
    void setAlarmThreshold(int);
    void setNumTicks(int);
    void setPrecision(int);
    
protected:
  
    bool m_alarmEnabled;
    double m_alarmThreshold;
    double m_value,m_minValue,m_maxValue;
    int m_numTicks;
    int m_precision;
    GaugeOrientation m_orientation;
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    int mousePressX,mousePressY;


signals:
   void thresholdAlarm(bool upper);

};

#endif
