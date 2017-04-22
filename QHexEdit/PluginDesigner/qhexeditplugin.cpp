#include "../QHexEdit/qhexedit.h"
#include "qhexeditplugin.h"

#include <QtPlugin>

QHexEditPlugin::QHexEditPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QHexEditPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QHexEditPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QHexEditPlugin::createWidget(QWidget *parent)
{
    return new QHexEdit(parent);
}

QString QHexEditPlugin::name() const
{
    return QLatin1String("QHexEdit");
}

QString QHexEditPlugin::group() const
{
    return QLatin1String("Instruments");
}

QIcon QHexEditPlugin::icon() const
{
    return QIcon(QLatin1String(":/qhexedit.png"));
}

QString QHexEditPlugin::toolTip() const
{
    return QLatin1String("Editeur hexa");
}

QString QHexEditPlugin::whatsThis() const
{
    return QLatin1String("Un editeur hexadecimal");
}

bool QHexEditPlugin::isContainer() const
{
    return false;
}

QString QHexEditPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QHexEdit\" name=\"hexEdit\">\n"
                         " <property name=\"geometry\">\n"
                         "  <rect>\n"
                         "   <x>0</x>\n"
                         "   <y>0</y>\n"
                         "   <width>300</width>\n"
                         "   <height>30</height>\n"
                         "  </rect>\n"
                         " </property>\n"
                         " <property name=\"toolTip\" >\n"
                         "  <string>HexEdit</string>\n"
                         " </property>\n"
                         " <property name=\"whatsThis\" >\n"
                         "  <string>HexEdit</string>\n"
                         " </property>\n"
                         "</widget>\n"
                         );
}

QString QHexEditPlugin::includeFile() const
{
    return QLatin1String("qhexedit.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qhexedit, QHexEdit)
#endif // QT_VERSION < 0x050000
