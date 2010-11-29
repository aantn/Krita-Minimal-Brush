/*
 *  Copyright (c) 2008 Lukáš Tvrdý <lukast.dev@gmail.com>
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

#include "krita_minimal_paintop_settings_widget.h"

#include "krita_minimalop_option.h"
#include "krita_minimal_paintop_settings.h"

#include <krita_curve_option_widget.h>
#include <krita_pressure_opacity_option.h>

#include <krita_paintop_options_widget.h>
#include <krita_paint_action_type_option.h>
#include <krita_airbrush_option.h>

KritaMinimalPaintOpSettingsWidget:: KritaMinimalPaintOpSettingsWidget(QWidget* parent)
        : KritaPaintOpOptionsWidget(parent)
{
    m_minimalOption =  new KritaMinimalOpOption();

    addPaintOpOption(m_minimalOption);
    addPaintOpOption(new KritaCurveOptionWidget(new KritaPressureOpacityOption()));
    addPaintOpOption(new KritaAirbrushOption(false));
    addPaintOpOption(new KritaPaintActionTypeOption());
}

KritaMinimalPaintOpSettingsWidget::~ KritaMinimalPaintOpSettingsWidget()
{
}

KritaPropertiesConfiguration*  KritaMinimalPaintOpSettingsWidget::configuration() const
{
    KritaMinimalPaintOpSettings* config = new KritaMinimalPaintOpSettings();
    config->setOptionsWidget(const_cast<KritaMinimalPaintOpSettingsWidget*>(this));
    config->setProperty("paintop", "minimalbrush"); // XXX: make this a const id string
    writeConfiguration(config);
    return config;
}

void KritaMinimalPaintOpSettingsWidget::changePaintOpSize(qreal x, qreal y)
{
    // if the movement is more left<->right then up<->down
    if (qAbs(x) > qAbs(y)){
        m_minimalOption->setRadius( m_minimalOption->radius() + qRound(x) );
    }
}