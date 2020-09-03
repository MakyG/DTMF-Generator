import qbs

Project {
    id: project
    property stringList flags: ["-Wall", "-Werror", "-std=c99"]
    property stringList sources: ["src/*.c", "src/*.h"]
    property string installDir: "bin"

    CppApplication {
        consoleApplication: true
        name: "DTMF_generator"

        Group {
            files: project.sources
        }

        cpp.cFlags: project.flags

        cpp.dynamicLibraries: {
            var flagDefines = [];
            flagDefines.push("pthread");
            if (qbs.targetOS.contains("linux"))
                flagDefines.push("m");
            return flagDefines;
        }

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
            qbs.installDir: project.installDir
        }

        Properties {
            condition: qbs.buildVariant == "debug"
            cpp.defines: "DEBUG"
        }
    }

    CppApplication {
        consoleApplication: true
        name: "tests"

        Group {
            files: project.sources
            excludeFiles: "src/main.c"
        }

        // test sources
        Group {
            files: ["tests/*"]
        }

        cpp.cFlags: project.flags

        cpp.dynamicLibraries: {
            var flagDefines = [];
            flagDefines.push("pthread");
            if (qbs.targetOS.contains("linux"))
                flagDefines.push("m");
            return flagDefines;
        }

        cpp.defines: {
            var defines = [];
            if (qbs.targetOS.contains("linux"))
                defines.push("_POSIX_C_SOURCE=199309L");
            return defines;
        }

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
            qbs.installDir: project.installDir
        }
    }

}

