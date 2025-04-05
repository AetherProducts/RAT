cmake_minimum_required(VERSION 3.10)
project(roblox)

find_package(OpenSSL REQUIRED)

add_executable(
    roblox
    src/main.c
    src/app/app.c
    src/controller/controller.c
    src/tool/rsa.c
    src/tool/type.c
    src/tool/certificate.c
)

target_include_directories(roblox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(roblox PRIVATE ${OPENSSL_INCLUDE_DIR})

target_link_libraries(roblox PRIVATE OpenSSL::SSL OpenSSL::Crypto)