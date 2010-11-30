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
#include "kis_minimal_paintop_options.h"

#include "ui_wdgminimaloptions.h"

class KisMinimalOpOptionsWidget: public QWidget, public Ui::WdgMinimalOptions
{
public:
    KisMinimalOpOptionsWidget(QWidget *parent = 0)
            : QWidget(parent) {
        setupUi(this);
    }
};

KisMinimalOpOption::KisMinimalOpOption()
        : KisPaintOpOption(i18n("Brush size"), KisPaintOpOption::brushCategory(), false)
{
    m_checkable = false;
    m_options = new KisMinimalOpOptionsWidget();
    connect(m_options->radiusSpinBox, SIGNAL(valueChanged(int)), SIGNAL(sigSettingChanged()));
    connect(m_options->inkDepletionCHBox, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));
    connect(m_options->opacity, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));
    connect(m_options->saturation, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));

    setConfigurationPage(m_options);
}

KisMinimalOpOption::~KisMinimalOpOption()
{
    // delete m_options;
}

int KisMinimalOpOption::radius() const
{
    return m_options->radiusSpinBox->value();
}


void KisMinimalOpOption::setRadius(int radius) const
{
    m_options->radiusSpinBox->setValue( radius );
}



bool KisMinimalOpOption::inkDepletion() const
{
    return m_options->inkDepletionCHBox->isChecked();
}



bool KisMinimalOpOption::opacity() const
{
    return m_options->opacity->isChecked();
}


bool KisMinimalOpOption::saturation() const
{
    return m_options->saturation->isChecked();
}


void KisMinimalOpOption::writeOptionSetting(KisPropertiesConfiguration* setting) const
{
    setting->setProperty(MINIMAL_RADIUS, radius());
    setting->setProperty(MINIMAL_INK_DEPLETION, inkDepletion());
    setting->setProperty(MINIMAL_USE_OPACITY, opacity());
    setting->setProperty(MINIMAL_USE_SATURATION, saturation());
}

void KisMinimalOpOption::readOptionSetting(const KisPropertiesConfiguration* setting)
{
    m_options->radiusSpinBox->setValue(setting->getInt(MINIMAL_RADIUS));
    m_options->inkDepletionCHBox->setChecked(setting->getBool(MINIMAL_INK_DEPLETION));
    m_options->opacity->setChecked(setting->getBool(MINIMAL_USE_OPACITY));
    m_options->saturation->setChecked(setting->getBool(MINIMAL_USE_SATURATION));
}


