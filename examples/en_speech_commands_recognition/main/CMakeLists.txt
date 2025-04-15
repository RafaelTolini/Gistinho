set(srcs
    main.c
    music.c
    led.c
    )

set(requires
    esp-sr
    led_strip
    hardware_driver
    mqtt
    )

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS include
                       REQUIRES ${requires})

component_compile_options(-w)