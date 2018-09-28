import qbs

StaticLibrary {
    files: [
        "include/luna/decoder.hpp",
    ]
    name: "libLuna"

    Depends { name: "cpp" }
    cpp.cxxLanguageVersion: "c++14"
    cpp.includePaths: ["include/luna"]

    Export {
        Depends { name: "cpp" }
        cpp.cxxLanguageVersion: "c++14"
        cpp.includePaths: [product.sourceDirectory + "/include"]
    }

    Group {
        name: "headers"
        prefix: "include/luna/"
        files: [
            "client/Decoder.hpp",
            "client/Encoder.hpp",
            "client/Listener.hpp",
            "server/Decoder.hpp",
            "server/Encoder.hpp",
            "server/Listener.hpp",
            "server/StrandDecoder.hpp",
            "BitDepth.hpp",
            "ByteStream.hpp",
            "ColorChannels.hpp",
            "Encoder.hpp",
            "Defragmenter.hpp",
            "Packets.hpp",
            "Strand.hpp",
            "StreamSink.hpp",
        ]
    }

    Group {
        name: "sources"
        files: [
            "client/Decoder.cpp",
            "client/Encoder.cpp",
            "server/Decoder.cpp",
            "server/Encoder.cpp",
            "Defragmenter.cpp",
            "StrandDecoder.cpp",
        ]
    }
}
