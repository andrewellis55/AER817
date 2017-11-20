// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from muse_file.djinni

#pragma once

#include <functional>

namespace interaxon { namespace bridge {

/**
 * \if IOS_ONLY
 * \file
 * \endif
 * Represents all possible MuseData message data types in a .muse file.
 * This enum corresponds to the DataType enum in the protobuf schema.
 * For more information on the file format see: http://developer.choosemuse.com/file-formats/muse
 */
enum class MessageType : int {
    /** A message containing eeg data. */
    EEG,
    /** A message containing quantization data. */
    QUANTIZATION,
    /** A message containing accelerometer data. */
    ACCELEROMETER,
    /** A message containing battery data. */
    BATTERY,
    /** A message containing version data. */
    VERSION,
    /** A message containing configuration data. */
    CONFIGURATION,
    /** A message containing annotation data. */
    ANNOTATION,
    /** A message containing histogram data. */
    HISTOGRAM,
    /** A message containing algorithm data. */
    ALG_VALUE,
    /** A message containing dsp data. */
    DSP,
    /** A message containing device data. */
    COMPUTING_DEVICE,
    /** A message containing dropped eeg data. */
    EEG_DROPPED,
    /** A message containing dropped acc data. */
    ACC_DROPPED,
    /** A message containing data from the calm application. */
    CALM_APP,
    /** A message containing data from the calm algorithm. */
    CALM_ALG,
    /** A message containing muse element data. */
    MUSE_ELEMENTS,
    /** A message containing gyro data. */
    GYRO,
    /** A message containing artifact packet. */
    ARTIFACT,
};

} }  // namespace interaxon::bridge

namespace std {

template <>
struct hash<::interaxon::bridge::MessageType> {
    size_t operator()(::interaxon::bridge::MessageType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
