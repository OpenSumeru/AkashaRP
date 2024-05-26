add_requires("poco")
add_languages("cxx23")

target("AkashaRP")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")
    set_pcxxheader("include/pch.hpp")
    add_packages("poco")
target_end()
