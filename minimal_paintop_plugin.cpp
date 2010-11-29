/*
 * Copyright (c) 2008 Lukáš Tvrdý (lukast.dev@gmail.com)
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
#include "minimal_paintop_plugin.h"


#include <klocale.h>
#include <kiconloader.h>
#include <kcomponentdata.h>
#include <kstandarddirs.h>
#include <krita_debug.h>
#include <kpluginfactory.h>

#include <krita_paintop_registry.h>


#include "krita_minimal_paintop.h"
#include "krita_simple_paintop_factory.h"

#include "krita_global.h"

K_PLUGIN_FACTORY(MinimalPaintOpPluginFactory, registerPlugin<MinimalPaintOpPlugin>();)
K_EXPORT_PLUGIN(MinimalPaintOpPluginFactory("krita"))


MinimalPaintOpPlugin::MinimalPaintOpPlugin(QObject *parent, const QVariantList &)
        : QObject(parent)
{
    //
    //setComponentData(MinimalPaintOpPluginFactory::componentData());
    KritaPaintOpRegistry *r = KritaPaintOpRegistry::instance();
    r->add(new KritaSimplePaintOpFactory<KritaMinimalPaintOp, KritaMinimalPaintOpSettings, KritaMinimalPaintOpSettingsWidget>("minimalbrush", i18n("Minimal brush"), 
                                                                                                                KritaPaintOpFactory::categoryExperimental(), "krita-minimal.png"));

}

MinimalPaintOpPlugin::~MinimalPaintOpPlugin()
{
}

#include "minimal_paintop_plugin.moc"