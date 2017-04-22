/***************************************************************************
 *   Copyright (C) 2008 - Giuseppe Cigala                                  *
 *   g_cigala@virgilio.it                                                  *
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

#include "qpotmet.h"
#include "qpotmetplugin.h"

#include <QtCore/QtPlugin>

QPotMetPlugin::QPotMetPlugin(QObject *parent)
        : QObject(parent)
{
    initialized = false;
}

void QPotMetPlugin::initialize(QDesignerFormEditorInterface *)
{
    if (initialized)
        return;

    initialized = true;
}

bool QPotMetPlugin::isInitialized() const
{
    return initialized;
}

QWidget *QPotMetPlugin::createWidget(QWidget *parent)
{
    return new QPotMet(parent);
}

QString QPotMetPlugin::name() const
{
    return "QPotMet";
}

QString QPotMetPlugin::group() const
{
    return "Lab Widgets";
}

QIcon QPotMetPlugin::icon() const
{
    return QIcon(":qpotmet.png");
}

QString QPotMetPlugin::toolTip() const
{
    return "";
}

QString QPotMetPlugin::whatsThis() const
{
    return "";
}

bool QPotMetPlugin::isContainer() const
{
    return false;
}

QString QPotMetPlugin::domXml() const
{
    return "<widget class=\"QPotMet\" name=\"qpotmet\">\n"
           " <property name=\"geometry\">\n"
           "  <rect>\n"
           "   <x>0</x>\n"
           "   <y>0</y>\n"
           "   <width>100</width>\n"
           "   <height>100</height>\n"
           "  </rect>\n"
           " </property>\n"
           " <property name=\"toolTip\" >\n"
           "  <string> Potentiometer</string>\n"
           " </property>\n"
           " <property name=\"whatsThis\" >\n"
           "  <string>Potentiometer</string>\n"
           " </property>\n"
           " </widget>\n";
}

QString QPotMetPlugin::includeFile() const
{
    return "qpotmet.h";
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(customwidgetplugin, QPotMetPlugin)
#endif // QT_VERSION < 0x050000