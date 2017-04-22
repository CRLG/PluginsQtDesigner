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

#include "qgauge.h"
#include "qgaugeplugin.h"

#include <QtCore/QtPlugin>

QGaugePlugin::QGaugePlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void QGaugePlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}

bool QGaugePlugin::isInitialized() const
{
    return initialized;
}

QWidget *QGaugePlugin::createWidget(QWidget *parent)
{
    return new QGauge(parent);
}

QString QGaugePlugin::name() const
{
    return "QGauge";
}

QString QGaugePlugin::group() const
{
    return "Lab Widgets";
}

QIcon QGaugePlugin::icon() const
{
    return QIcon(":qgauge.png");
}

QString QGaugePlugin::toolTip() const
{
    return "";
}

QString QGaugePlugin::whatsThis() const
{
    return "";
}

bool QGaugePlugin::isContainer() const
{
    return false;
}

QString QGaugePlugin::domXml() const
{
    return "<widget class=\"QGauge\" name=\"qGauge\">\n"
           " <property name=\"geometry\">\n"
           "  <rect>\n"
           "   <x>0</x>\n"
           "   <y>0</y>\n"
           "   <width>80</width>\n"
           "   <height>180</height>\n"
           "  </rect>\n"
           " </property>\n"
           " <property name=\"toolTip\" >\n"
           "  <string>Gauge</string>\n"
           " </property>\n"
           " <property name=\"whatsThis\" >\n"
           "  <string>Gauge widget</string>\n"
           " </property>\n"                   
           " <property name=\"minValue\" >\n"
           "  <double>0</double>\n"
           " </property>\n"                   
            " <property name=\"maxValue\" >\n"
           "  <double>100</double>\n"
           " </property>\n"                   
           " <property name=\"value\" >\n"
           "  <double>0</double>\n"
           " </property>\n"          
           " <property name=\"orientation\" >\n"
           "  <enum>QGauge::Vertical</enum>\n"
           " </property>\n"              
           " <property name=\"alarmEnabled\" >\n"
           "  <bool>false</bool>\n"
           " </property>\n"   
           " <property name=\"alarmThreshold\" >\n"
           "  <double>0</double>\n"
           " </property>\n"                                                                  
           "</widget>\n";
}

QString QGaugePlugin::includeFile() const
{
    return "qgauge.h";
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(customwidgetplugin, QGaugePlugin)
#endif // QT_VERSION < 0x050000