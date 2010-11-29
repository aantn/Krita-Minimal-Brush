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
#include "krita_minimalop_option.h"

#include "ui_wdgminimaloptions.h"

class KritaMinimalOpOptionsWidget: public QWidget, public Ui::WdgMinimalOptions
{
public:
    KritaMinimalOpOptionsWidget(QWidget *parent = 0)
            : QWidget(parent) {
        setupUi(this);
    }
};

KritaMinimalOpOption::KritaMinimalOpOption()
        : KritaPaintOpOption(i18n("Brush size"), KritaPaintOpOption::brushCategory(), false)
{
    m_checkable = false;
    m_options = new KritaMinimalOpOptionsWidget();
    connect(m_options->radiusSpinBox, SIGNAL(valueChanged(int)), SIGNAL(sigSettingChanged()));
    connect(m_options->inkDepletionCHBox, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));
    connect(m_options->opacity, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));
    connect(m_options->saturation, SIGNAL(clicked(bool)), SIGNAL(sigSettingChanged()));

    setConfigurationPage(m_options);
}

KritaMinimalOpOption::~KritaMinimalOpOption()
{
    // delete m_options;
}

int KritaMinimalOpOption::radius() const
{
    return m_options->radiusSpinBox->value();
}


void KritaMinimalOpOption::setRadius(int radius) const
{
    m_options->radiusSpinBox->setValue( radius );
}



bool KritaMinimalOpOption::inkDepletion() const
{
    return m_options->inkDepletionCHBox->isChecked();
}



bool KritaMinimalOpOption::opacity() const
{
    return m_options->opacity->isChecked();
}


bool KritaMinimalOpOption::saturation() const
{
    return m_options->saturation->isChecked();
}


void KritaMinimalOpOption::writeOptionSetting(KritaPropertiesConfiguration* setting) const
{
    setting->setProperty(MINIMAL_RADIUS, radius());
    setting->setProperty(MINIMAL_INK_DEPLETION, inkDepletion());
    setting->setProperty(MINIMAL_USE_OPACITY, opacity());
    setting->setProperty(MINIMAL_USE_SATURATION, saturation());
}

void KritaMinimalOpOption::readOptionSetting(const KritaPropertiesConfiguration* setting)
{
    m_options->radiusSpinBox->setValue(setting->getInt(MINIMAL_RADIUS));
    m_options->inkDepletionCHBox->setChecked(setting->getBool(MINIMAL_INK_DEPLETION));
    m_options->opacity->setChecked(setting->getBool(MINIMAL_USE_OPACITY));
    m_options->saturation->setChecked(setting->getBool(MINIMAL_USE_SATURATION));
}


