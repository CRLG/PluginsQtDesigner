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

#ifndef QVCURSOR_H
#define QVCURSOR_H

#include <Qt>
#include <QWidget>
#include <QtGui>
#include <QtDesigner/QDesignerExportWidget>


class QDESIGNER_WIDGET_EXPORT QVCursor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor colorBg READ colorBg WRITE setColorBg);
    Q_PROPERTY(QColor colorValue READ colorValue WRITE setColorValue);
    Q_PROPERTY(QColor colorScale READ colorScale WRITE setColorScale);
    Q_PROPERTY(int valueDim READ valueDim WRITE setValueDim);
    Q_PROPERTY(int scaleDim READ scaleDim WRITE setScaleDim);
    Q_PROPERTY(double min READ minValue WRITE setMinValue);
    Q_PROPERTY(double max READ maxValue WRITE setMaxValue);
    Q_PROPERTY(int precision READ precValue WRITE setPrecValue);

    QColor colorBg() const
    {
        return colBack;
    }
    QColor colorValue() const
    {
        return colValue;
    }
    QColor colorScale() const
    {
        return colScale;
    }
    int valueDim() const
    {
        return dimVal;
    }
    int scaleDim() const
    {
        return dimScale;
    }
    double minValue() const
    {
        return min;
    }
    double maxValue() const
    {
        return max;
    }
    int precValue() const
    {
        return precision;
    }

public:

    QVCursor(QWidget *parent = 0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;


signals:

    void valueChanged(double);


public slots:

    void setColorBg(QColor);
    void setColorScale(QColor);
    void setColorValue(QColor);
    void setValueDim(int);
    void setScaleDim(int);
    void setPrecValue(int);
    void setMinValue(double);
    void setMaxValue(double);
    

protected:

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintBorder();
    void paintCursor();
    void paintScale();
    void paintValue();


private:

    double cy;
    double min;
    double max;
    int precision;
    int dimVal;
    int dimScale;
    QColor colBack;
    QColor colScale;
    QColor colValue;


};

#endif
