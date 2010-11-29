/*
 *  Copyright (c) 2008,2010 Lukáš Tvrdý <lukast.dev@gmail.com>
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
#ifndef KRITA_MINIMALOP_OPTION_H
#define KRITA_MINIMALOP_OPTION_H

#include <krita_paintop_option.h>
#include <krita_export.h>

const QString MINIMAL_RADIUS = "Minimal/radius";
const QString MINIMAL_INK_DEPLETION = "Minimal/inkDepletion";
const QString MINIMAL_USE_OPACITY = "Minimal/opacity";
const QString MINIMAL_USE_SATURATION = "Minimal/saturation";

class KritaMinimalOpOptionsWidget;

class KritaMinimalOpOption : public KritaPaintOpOption
{
public:
    KritaMinimalOpOption();
    ~KritaMinimalOpOption();

    void setRadius(int radius) const;
    int radius() const;

    bool inkDepletion() const; 
    bool saturation() const;
    bool opacity() const;
    
    void writeOptionSetting(KritaPropertiesConfiguration* setting) const;
    void readOptionSetting(const KritaPropertiesConfiguration* setting);


private:

    KritaMinimalOpOptionsWidget * m_options;

};

class MinimalProperties{
public:
    int radius;
    bool inkDepletion;
    bool useOpacity;
    bool useSaturation;
    
    void readOptionSetting(const KritaPropertiesConfiguration* settings){
            radius = settings->getInt(MINIMAL_RADIUS);
            inkDepletion = settings->getBool(MINIMAL_INK_DEPLETION);
            useOpacity = settings->getBool(MINIMAL_USE_OPACITY);
            useSaturation = settings->getBool(MINIMAL_USE_SATURATION);
    }
};

#endif
