set(srcs
    main.c
    music.c
    led.c
    connection.c
    )

set(requires
    esp-sr
    led_strip
    hardware_driver
    mqtt
    esp_wifi
    nvs_flash
    )

idf_component_register(SRCS ${srcs}
                       INCLUDE_DIRS include
                       REQUIRES ${requires})

component_compile_options(-w)
