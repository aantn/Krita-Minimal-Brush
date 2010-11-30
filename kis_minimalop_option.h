/*
 *  Copyright (c) YEAR YOUR_NAME <YOUR_EMAIL>
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
#ifndef KIS_MINIMALOP_OPTION_H
#define KIS_MINIMALOP_OPTION_H

#include <kis_paintop_option.h>
#include <krita_export.h>

const QString MINIMAL_RADIUS = "Minimal/radius";
const QString MINIMAL_INK_DEPLETION = "Minimal/inkDepletion";
const QString MINIMAL_USE_OPACITY = "Minimal/opacity";
const QString MINIMAL_USE_SATURATION = "Minimal/saturation";

class KisMinimalOpOptionsWidget;

class KisMinimalOpOption : public KisPaintOpOption
{
public:
    KisMinimalOpOption();
    ~KisMinimalOpOption();

    void setRadius(int radius) const;
    int radius() const;

    bool inkDepletion() const; 
    bool saturation() const;
    bool opacity() const;
    
    void writeOptionSetting(KisPropertiesConfiguration* setting) const;
    void readOptionSetting(const KisPropertiesConfiguration* setting);


private:

    KisMinimalOpOptionsWidget * m_options;

};

class MinimalProperties{
public:
    int radius;
    bool inkDepletion;
    bool useOpacity;
    bool useSaturation;
    
    void readOptionSetting(const KisPropertiesConfiguration* settings){
            radius = settings->getInt(MINIMAL_RADIUS);
            inkDepletion = settings->getBool(MINIMAL_INK_DEPLETION);
            useOpacity = settings->getBool(MINIMAL_USE_OPACITY);
            useSaturation = settings->getBool(MINIMAL_USE_SATURATION);
    }
};

#endif
