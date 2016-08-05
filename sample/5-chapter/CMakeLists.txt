add_executable(factorymethod factorymethod.cpp)
target_link_libraries(factorymethod ${LIBRARIES})

add_executable(nonpolymorphism nonpolymorphism.cpp)
target_link_libraries(nonpolymorphism ${LIBRARIES})

add_executable(nonpurevirtual nonpurevirtual.cpp)
target_link_libraries(nonpurevirtual ${LIBRARIES})

add_executable(one2onefunc one2onefunc.cpp)
target_link_libraries(one2onefunc ${LIBRARIES})

add_executable(polymorphism polymorphism.cpp)
target_link_libraries(polymorphism ${LIBRARIES})

add_executable(templatefactory templatefactory.cpp)
target_link_libraries(templatefactory ${LIBRARIES})
