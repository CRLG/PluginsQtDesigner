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

#include "q7seg.h"
#include "q7segplugin.h"

#include <QtCore/QtPlugin>

Q7segPlugin::Q7segPlugin(QObject *parent)
        : QObject(parent)
{
    initialized = false;
}

void Q7segPlugin::initialize(QDesignerFormEditorInterface *)
{
    if (initialized)
        return;

    initialized = true;
}

bool Q7segPlugin::isInitialized() const
{
    return initialized;
}

QWidget *Q7segPlugin::createWidget(QWidget *parent)
{
    return new Q7seg(parent);
}

QString Q7segPlugin::name() const
{
    return "Q7seg";
}

QString Q7segPlugin::group() const
{
    return "Lab Widgets";
}

QIcon Q7segPlugin::icon() const
{
    return QIcon(":q7seg.png");
}

QString Q7segPlugin::toolTip() const
{
    return "";
}

QString Q7segPlugin::whatsThis() const
{
    return "";
}

bool Q7segPlugin::isContainer() const
{
    return false;
}

QString Q7segPlugin::domXml() const
{
    return "<widget class=\"Q7seg\" name=\"q7seg\">\n"
           " <property name=\"geometry\">\n"
           "  <rect>\n"
           "   <x>0</x>\n"
           "   <y>0</y>\n"
           "   <width>100</width>\n"
           "   <height>100</height>\n"
           "  </rect>\n"
           " </property>\n"
           " <property name=\"toolTip\" >\n"
           "  <string>7 segment display</string>\n"
           " </property>\n"
           " <property name=\"whatsThis\" >\n"
           "  <string>7 segment display</string>\n"
           " </property>\n"
           " </widget>\n";
}

QString Q7segPlugin::includeFile() const
{
    return "q7seg.h";
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(customwidgetplugin, Q7segPlugin)
#endif // QT_VERSION < 0x050000