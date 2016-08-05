add_executable(abstractfactory abstractfactory.cpp)
target_link_libraries(abstractfactory ${LIBRARIES})

add_executable(product product.cpp)
target_link_libraries(product ${LIBRARIES})

add_executable(prototype_abstractfactory prototype_abstractfactory.cpp)
target_link_libraries(prototype_abstractfactory ${LIBRARIES})

add_executable(singleton_abstractfactory singleton_abstractfactory.cpp)
target_link_libraries(singleton_abstractfactory ${LIBRARIES})

add_executable(uname_cmp uname_cmp.cpp)
target_link_libraries(uname_cmp ${LIBRARIES})

add_executable(upgrade_product upgrade_product.cpp)
target_link_libraries(upgrade_product ${LIBRARIES})
