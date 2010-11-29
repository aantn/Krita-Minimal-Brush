set(kritaminimalpaintop_PART_SRCS
    minimal_paintop_plugin.cpp
    krita_minimal_paintop.cpp
    krita_minimalop_option.cpp
    krita_minimal_paintop_settings.cpp
    krita_minimal_paintop_settings_widget.cpp
    minimal_brush.cpp	
    )

kde4_add_ui_files(kritaminimalpaintop_PART_SRCS wdgminimaloptions.ui )

kde4_add_plugin(kritaminimalpaintop ${kritaminimalpaintop_PART_SRCS})


target_link_libraries(kritaminimalpaintop kritalibpaintop)

install(TARGETS kritaminimalpaintop  DESTINATION ${PLUGIN_INSTALL_DIR})


########### install files ###############

install( FILES  kritaminimalpaintop.desktop  DESTINATION ${SERVICES_INSTALL_DIR})
install( FILES
    krita-minimal.png DESTINATION ${DATA_INSTALL_DIR}/krita/images)
install( FILES  3d-pencil.obj DESTINATION ${DATA_INSTALL_DIR}/krita/brushmodels )
install( FILES  3d-pencil.mtl DESTINATION ${DATA_INSTALL_DIR}/krita/brushmodels )


