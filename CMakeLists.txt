cmake_minimum_required(VERSION 3.0.0)

project(libLuna)

set(CMAKE_CXX_STANDARD 14)
add_library(${PROJECT_NAME} STATIC
    "include/luna/client/Decoder.hpp"
    "include/luna/client/Encoder.hpp"
    "include/luna/client/Listener.hpp"
    "include/luna/server/Decoder.hpp"
    "include/luna/server/Encoder.hpp"
    "include/luna/server/Listener.hpp"
    "include/luna/server/StrandDecoder.hpp"
    "include/luna/BitDepth.hpp"
    "include/luna/ByteStream.hpp"
    "include/luna/ColorChannels.hpp"
    "include/luna/ColorSpace.hpp"
    "include/luna/Encoder.hpp"
    "include/luna/Defragmenter.hpp"
    "include/luna/Packets.hpp"
    "include/luna/Point.hpp"
    "include/luna/Strand.hpp"
    "include/luna/StrandConfiguration.hpp"
    "include/luna/StreamSink.hpp"

    "client/Decoder.cpp"
    "client/Encoder.cpp"
    "server/Decoder.cpp"
    "server/Encoder.cpp"
    "server/StrandDecoder.cpp"
    "Defragmenter.cpp"
)

target_include_directories(${PROJECT_NAME}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/luna"
)
