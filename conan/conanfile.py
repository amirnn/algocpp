from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class algocpp(ConanFile):
    name = "algocpp"
    version = "0.1"
    package_type = "application"

    # Optional metadata
    license = "MIT"
    author = "Amir Nourinia amir.nouri.nia@gmail.com"
    url = "https://github.com/amirnn/algocpp"
    description = "Algorithms in C++"
    topics = ("Algorithms", "C++")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def layout(self):
        cmake_layout(self, src_folder="..", build_folder="../build")

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.user_presets_path = "ConanPresets.json"
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def requirements(self):
        self.requires("boost/[~1]")
        self.requires("eigen/[~3]")
        self.requires("doctest/[~2]")
