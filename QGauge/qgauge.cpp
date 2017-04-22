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
  
#include <QColor>
#include <QtGlobal>
#include <QtGui>
#include <QPolygon>


#include "qgauge.h"

QGauge::QGauge(QWidget *parent)
    : QWidget(parent)
{

   setFocusPolicy(Qt::StrongFocus);
   m_numTicks=10;
   m_precision=1;
   m_value=0;
   setMinimumSize(QSize(80,180));
   //setFocusPolicy(Qt::StrongFocus);
   
}

void QGauge::paintEvent(QPaintEvent *)
{
	QPainter painter(this);





    //for each tick in numTicks
  
	int tick;
	
	QString val;
    double step;
    QFontMetrics fm( this->font() );	
    int strLen;
	int stepPixel=(height())/m_numTicks;

	for(tick=0;tick<m_numTicks;tick++)
	{
		step=(m_maxValue-m_minValue)/m_numTicks;
		step=m_maxValue-step*(double)tick;
		val.setNum((step),'f',m_precision);
		
		//strLen=fm.size(Qt::TextSingleLine,val).width();
		painter.setPen(Qt::black);
		painter.drawLine(width()/3,tick*stepPixel+height()/20,width()/3+10,tick*stepPixel+height()/20);
		painter.drawText(6,tick*stepPixel+height()/20+fm.height()/4,val);
	}
	








	painter.setWindow( -500,-500,1000,1000);

    if(hasFocus())
	{
	  QPen pen(Qt::DotLine);
	  painter.setPen(pen);
	  painter.drawRect(-500,-500,999,999);
	}

   
    QPen pen(Qt::SolidLine);
	painter.setPen(pen);
    if(m_orientation==Horizontal)
      painter.rotate(90.0);
	
	QPolygon a(4);
	//QPen pen(QColor(70,70,70));
	a.setPoint(0,100,-449);
    a.setPoint(1,400,-449);
    a.setPoint(2,400,449);
	a.setPoint(3,100,449);	
	  
    QLinearGradient linearGrad(QPointF(100, -449), QPoint(400,-449));
    linearGrad.setColorAt(0, Qt::white);
    linearGrad.setColorAt(0.7, QColor(80,80,80)); 		
   	linearGrad.setColorAt(1, QColor(40,0,0)); 		
		
	QBrush brush(linearGrad);
	painter.setBrush(brush); 	
	painter.drawPolygon(a);

    bool alarm=false;
    if(m_value>m_alarmThreshold &&m_alarmEnabled)
    {	
    	emit thresholdAlarm(true);
    	alarm=true;
    }	
    if(m_value<=m_alarmThreshold &&m_alarmEnabled)
    	emit thresholdAlarm(false);


    if(m_alarmThreshold!=0.0 &&m_alarmEnabled)
    {	
     int threshold_h=(int)(-450+900*((m_alarmThreshold-m_maxValue)/(m_minValue-m_maxValue)));
     QPolygon th(3);
     th.setPoint(0,0,threshold_h-30);
     th.setPoint(1,80,threshold_h);
     th.setPoint(2,0,threshold_h+30);
     //th.setPoint(3,50,threshold_h);
 
     if(alarm)
      painter.setBrush(QBrush(Qt::red)); 
     else
       painter.setBrush(QBrush(Qt::green)); 
     painter.drawPolygon(th);
    
    }
    

    int h=(int)(-450+900*((m_value-m_maxValue)/(m_minValue-m_maxValue)));

    a.setPoint(0,100,h);
	a.setPoint(1,400,h);
	a.setPoint(2,400,449);
	a.setPoint(3,100,449);	
	  
    QLinearGradient linearGrad2(QPointF(100, -449), QPoint(400,-449));
    linearGrad2.setColorAt(0, Qt::white);
    linearGrad2.setColorAt(0.3, QColor(250,10,10)); 		

    linearGrad2.setColorAt(1, QColor(20,0,0)); 			
		
	QBrush brush2(linearGrad2);
	painter.setBrush(brush2); 	
	painter.drawPolygon(a);

	
}


void QGauge::mousePressEvent(QMouseEvent *e)
{
  int x=e->x();
  int y=e->y();
  
  int px=(int)(-450 +(900/width())*x);
  int py=(int)(-450 +(900/height())*y);
  
  int threshold_h=(int)(0.9*height()*((m_alarmThreshold-m_maxValue)/(m_minValue-m_maxValue)));
  
  double threshold_d=(double)threshold_h/100;
  threshold_h=(int)(-450+900*threshold_d); 
  
  
  
  //if(py < threshold_h+50 && y >threshold_h-50)
  	if(px>0 && px<100)
  	{	
      mousePressX=x;
      mousePressY=y;
    }
    else
  	{	
      mousePressX=-1;
      mousePressY=-1;
    }
    	

  
}

void QGauge::mouseMoveEvent(QMouseEvent *e)
{
	double delta;
    if(	mousePressY<0)
  	{	
      return;
    }
		
  int x=e->x();
  int y=e->y();
  
  
  delta=mousePressY-y;
  delta=delta/(double)height();
  delta=delta*(m_maxValue-m_minValue);
 

  m_alarmThreshold=m_alarmThreshold+delta;
  if(m_alarmThreshold<m_minValue)
  	m_alarmThreshold=m_minValue;
  if(m_alarmThreshold>m_maxValue)
  	m_alarmThreshold=m_maxValue;
  	
  mousePressX=x;
  mousePressY=y;
  update();
}


void QGauge::mouseReleaseEvent(QMouseEvent *e)
{
      mousePressX=-1;
      mousePressY=-1;
  
}



void QGauge::setOrientation(GaugeOrientation value)
{
   m_orientation=value;
   update();
}



void QGauge::setValue(double value)
{
    if(value<m_minValue)
   	m_value=m_minValue;
   else
   	if(value>m_maxValue)
   	 m_value=m_maxValue;
   	else 	
     m_value=(double)value;
   update();
}


void QGauge::setValue(int value)
{
 setValue((double)value);
}


void QGauge::setMinValue(double value)
{
   m_minValue=value;
   update();
}



void QGauge::setMaxValue(double value)
{
   m_maxValue=value;
   update();
}


void QGauge::enableAlarm(bool alarmEnable)
{
   m_alarmEnabled=alarmEnable;
   update();
}


void QGauge::setAlarmThreshold(double threshold)
{
   if(threshold<m_minValue)
     threshold=m_minValue;
   if(threshold>m_maxValue)
     threshold=m_maxValue;
   m_alarmThreshold=threshold;
   update();
}


void QGauge::setAlarmThreshold(int threshold)
{
     setAlarmThreshold((double)threshold);	
}


void QGauge::setNumTicks(int numTicks)
{
	if(numTicks>1)
     m_numTicks=numTicks;
     update();
}


void QGauge::setPrecision(int precision)
{
	if(precision>=0 && precision < 6)
     m_precision=precision;
    update();
}
