project(roblox)

find_package(OpenSSL REQUIRED)

add_executable(
    roblox
    src/main.c
    src/app/app.c
    src/controller/controller.c
    src/tool/rsa.c
    src/tool/certificate.c
)

target_include_directories(roblox PRIVATE ${OPENSSL_INCLUDE_DIR})

target_link_libraries(roblox PRIVATE OpenSSL::SSL OpenSSL::Crypto)