/*
 *  Copyright (c) 2008-2010 Lukáš Tvrdý <lukast.dev@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef MINIMAL_BRUSH_H_
#define MINIMAL_BRUSH_H_

#include <QVector>

#include <KoColor.h>

#include "krita_minimalop_option.h"
#include "krita_paint_device.h"

class MinimalBrush
{

public:
    MinimalBrush(const MinimalProperties * properties, KoColorTransformation* transformation);
    ~MinimalBrush();
    void paint(KritaPaintDeviceSP dev, qreal x, qreal y, const KoColor &color);

private:
    KoColor m_inkColor;
    int m_counter;
    const MinimalProperties * m_properties;
    KoColorTransformation* m_transfo;
    int m_saturationId;

};

#endif
